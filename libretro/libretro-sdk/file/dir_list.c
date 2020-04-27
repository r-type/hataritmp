/* Copyright  (C) 2010-2014 The RetroArch team
 *
 * ---------------------------------------------------------------------------------------
 * The following license statement only applies to this file (dir_list.c).
 * ---------------------------------------------------------------------------------------
 *
 * Permission is hereby granted, free of charge,
 * to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <file/dir_list.h>
#include <file/file_path.h>
#include <compat/strl.h>
#include <compat/posix_string.h>

#if defined(_WIN32)
#ifdef _MSC_VER
#define setmode _setmode
#endif
#ifdef _XBOX
#include <xtl.h>
#define INVALID_FILE_ATTRIBUTES -1
#else
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <windows.h>
#endif
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#endif

/* Some platforms do not set this value.
 * Just assume a value. It's usually 4KiB.
 * Platforms with a known value (like Win32)
 * set this value explicitly in platform specific headers.
 */

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

static int qstrcmp_plain(const void *a_, const void *b_)
{
   const struct string_list_elem *a = (const struct string_list_elem*)a_; 
   const struct string_list_elem *b = (const struct string_list_elem*)b_; 

   return strcasecmp(a->data, b->data);
}

static int qstrcmp_dir(const void *a_, const void *b_)
{
   const struct string_list_elem *a = (const struct string_list_elem*)a_; 
   const struct string_list_elem *b = (const struct string_list_elem*)b_; 
   int a_type = a->attr.i;
   int b_type = b->attr.i;


   /* Sort directories before files. */
   if (a_type != b_type)
      return b_type - a_type;
   return strcasecmp(a->data, b->data);
}

void dir_list_sort(struct string_list *list, bool dir_first)
{
   if (list)
      qsort(list->elems, list->size, sizeof(struct string_list_elem),
            dir_first ? qstrcmp_dir : qstrcmp_plain);
}

void dir_list_free(struct string_list *list)
{
   string_list_free(list);
}

#ifdef _WIN32

struct string_list *dir_list_new(const char *dir,
      const char *ext, bool include_dirs)
{
   char path_buf[PATH_MAX];
   WIN32_FIND_DATA ffd;
   struct string_list *ext_list = NULL, *list = NULL;
   HANDLE hFind = INVALID_HANDLE_VALUE;
   list = string_list_new();
   if (!list)
      return NULL;

   snprintf(path_buf, sizeof(path_buf), "%s\\*", dir);

   if (ext)
      ext_list = string_split(ext, "|");

   hFind = FindFirstFile(path_buf, &ffd);
   if (hFind == INVALID_HANDLE_VALUE)
      goto error;

   do
   {
      union string_list_elem_attr attr;
      char file_path[PATH_MAX];
      const char *name        = ffd.cFileName;
      const char *file_ext    = path_get_extension(name);
      bool is_dir             = ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
      bool is_compressed_file = false;
      bool supported_by_core  = false;
      attr.i                  = RARCH_FILETYPE_UNSET;

      fill_pathname_join(file_path, dir, name, sizeof(file_path));

      if (!is_dir)
      {
         is_compressed_file = path_is_compressed_file(file_path);
         if (string_list_find_elem_prefix(ext_list, ".", file_ext))
            supported_by_core = true;
      }

      if (!include_dirs && is_dir)
         continue;

      if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
         continue;

      if (!is_compressed_file && !is_dir && ext_list && !supported_by_core)
         continue;

      if (is_dir)
         attr.i = RARCH_DIRECTORY;
      if (is_compressed_file)
         attr.i = RARCH_COMPRESSED_ARCHIVE;
      /* The order of these ifs is important.
       * If the file format is explicitly supported by the libretro-core, we
       * need to immediately load it and not designate it as a compressed file.
       *
       * Example: .zip could be supported as a image by the core and as a
       * compressed_file. In that case, we have to interpret it as a image.
       *
       * */
      if (supported_by_core)
         attr.i = RARCH_PLAIN_FILE;

      if (!string_list_append(list, file_path, attr))
         goto error;
   }
   while (FindNextFile(hFind, &ffd) != 0);

   FindClose(hFind);
   string_list_free(ext_list);
   return list;

error:
   if (hFind != INVALID_HANDLE_VALUE)
      FindClose(hFind);
   
   string_list_free(list);
   string_list_free(ext_list);
   return NULL;
}
#else
static bool dirent_is_directory(const char *path,
      const struct dirent *entry)
{
#if defined(PSP)
   return (entry->d_stat.st_attr & FIO_SO_IFDIR) == FIO_SO_IFDIR;
#elif defined(DT_DIR)
   if (entry->d_type == DT_DIR)
      return true;
   else if (entry->d_type == DT_UNKNOWN /* This can happen on certain file systems. */
         || entry->d_type == DT_LNK)
      return path_is_directory(path);
   return false;
#else /* dirent struct doesn't have d_type, do it the slow way ... */
   return path_is_directory(path);
#endif
}

struct string_list *dir_list_new(const char *dir,
      const char *ext, bool include_dirs)
{
   DIR *directory = NULL;
   const struct dirent *entry = NULL;
   struct string_list *ext_list = NULL;
   struct string_list *list = (struct string_list*)string_list_new();

   if (!list)
      return NULL;

   if (ext)
      ext_list = string_split(ext, "|");

   directory = opendir(dir);
   if (!directory)
      goto error;

   while ((entry = readdir(directory)))
   {
      bool is_dir;
      char file_path[PATH_MAX];
      union string_list_elem_attr attr;
      const char *name     = entry->d_name;
      const char *file_ext = path_get_extension(name);
      bool is_compressed_file = false;
      bool supported_by_core  = false;
      attr.i                  = RARCH_FILETYPE_UNSET;

      fill_pathname_join(file_path, dir, name, sizeof(file_path));

      is_dir = dirent_is_directory(file_path, entry);

      if (!is_dir)
      {
         is_compressed_file = path_is_compressed_file(file_path);
         if (string_list_find_elem_prefix(ext_list, ".", file_ext))
            supported_by_core = true;
      }

      if (!include_dirs && is_dir)
         continue;

      if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
         continue;

      if (!is_dir && ext_list && !is_compressed_file && !supported_by_core)
         continue;

      if (is_dir)
         attr.i = RARCH_DIRECTORY;
      if (is_compressed_file)
         attr.i = RARCH_COMPRESSED_ARCHIVE;
      /* The order of these ifs is important.
       * If the file format is explicitly supported by the libretro-core, we
       * need to immediately load it and not designate it as a compressed file.
       *
       * Example: .zip could be supported as a image by the core and as a
       * compressed_file. In that case, we have to interpret it as a image.
       *
       * */
      if (supported_by_core)
         attr.i = RARCH_PLAIN_FILE;

      if (!string_list_append(list, file_path, attr))
         goto error;
   }

   closedir(directory);

   string_list_free(ext_list);
   return list;

error:

   if (directory)
      closedir(directory);

   string_list_free(list);
   string_list_free(ext_list);
   return NULL;
}
#endif
