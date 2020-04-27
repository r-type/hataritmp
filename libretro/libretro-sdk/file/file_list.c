/* Copyright  (C) 2010-2014 The RetroArch team
 *
 * ---------------------------------------------------------------------------------------
 * The following license statement only applies to this file (file_list.c).
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

#include <stdlib.h>
#include <string.h>
#include <file/file_list.h>
#include <compat/strcasestr.h>
#include <compat/posix_string.h>

void file_list_push(file_list_t *list,
      const char *path, const char *label,
      unsigned type, size_t directory_ptr)
{
   if (list->size >= list->capacity)
   {
      list->capacity++;
      list->capacity *= 2;
      list->list = (struct item_file*)realloc(list->list,
            list->capacity * sizeof(struct item_file));
   }

   list->list[list->size].label = strdup(label);
   list->list[list->size].path = strdup(path);
   list->list[list->size].alt = NULL;
   list->list[list->size].type = type;
   list->list[list->size].directory_ptr = directory_ptr;
   list->size++;
}

size_t file_list_get_size(const file_list_t *list)
{
   if (list)
      return list->size;
   return 0;
}

size_t file_list_get_directory_ptr(const file_list_t *list)
{
   size_t size = file_list_get_size(list);
   return list->list[size].directory_ptr;
}


void file_list_pop(file_list_t *list, size_t *directory_ptr)
{
   if (list->size != 0)
   {
      --list->size;
      free(list->list[list->size].path);
      free(list->list[list->size].label);
   }

   if (directory_ptr)
      *directory_ptr = list->list[list->size].directory_ptr;
}

void file_list_free(file_list_t *list)
{
   size_t i;

   if (!list)
      return;

   for (i = 0; i < list->size; i++)
   {
      free(list->list[i].path);
      free(list->list[i].label);
   }
   free(list->list);
   free(list);
}

void file_list_clear(file_list_t *list)
{
   size_t i;

   for (i = 0; i < list->size; i++)
   {
      free(list->list[i].path);
      list->list[i].path = NULL;
      free(list->list[i].label);
      list->list[i].label = NULL;
      free(list->list[i].alt);
      list->list[i].alt = NULL;
   }

   list->size = 0;
}

void file_list_copy(file_list_t *list, file_list_t *list_old)
{
   size_t i;

   list_old->size = list->size;
   list_old->capacity = list->capacity;

   list_old->list = (struct item_file*)realloc(list_old->list,
            list_old->capacity * sizeof(struct item_file));

   for (i = 0; i < list->size; i++)
   {
      list_old->list[i].path = strdup(list->list[i].path);
      list_old->list[i].label = strdup(list->list[i].label);
      if (list->list[i].alt)
         list_old->list[i].alt = strdup(list->list[i].alt);
      list_old->list[i].type = list->list[i].type;
      list_old->list[i].directory_ptr = list->list[i].directory_ptr;
      list_old->list[i].userdata = list->list[i].userdata;
      list_old->list[i].actiondata = list->list[i].actiondata;
   }
}

void file_list_set_label_at_offset(file_list_t *list, size_t idx,
      const char *label)
{
   free(list->list[idx].label);
   list->list[idx].label = strdup(label);
}

void file_list_get_label_at_offset(const file_list_t *list, size_t idx,
      const char **label)
{
   if (label)
      *label = list->list[idx].label ?
         list->list[idx].label : list->list[idx].path;
}

void file_list_set_alt_at_offset(file_list_t *list, size_t idx,
      const char *alt)
{
   free(list->list[idx].alt);
   list->list[idx].alt = strdup(alt);
}

void file_list_get_alt_at_offset(const file_list_t *list, size_t idx,
      const char **alt)
{
   if (alt)
      *alt = list->list[idx].alt ?
         list->list[idx].alt : list->list[idx].path;
}

static int file_list_alt_cmp(const void *a_, const void *b_)
{
   const struct item_file *a = (const struct item_file*)a_;
   const struct item_file *b = (const struct item_file*)b_;
   const char *cmp_a = a->alt ? a->alt : a->path;
   const char *cmp_b = b->alt ? b->alt : b->path;
   return strcasecmp(cmp_a, cmp_b);
}

void file_list_sort_on_alt(file_list_t *list)
{
   qsort(list->list, list->size, sizeof(list->list[0]), file_list_alt_cmp);
}

void *file_list_get_userdata_at_offset(const file_list_t *list, size_t idx)
{
   return list->list[idx].userdata;
}

void *file_list_get_actiondata_at_offset(const file_list_t *list, size_t idx)
{
   if (list)
      return list->list[idx].actiondata;
   return NULL;
}

void *file_list_get_last_actiondata(const file_list_t *list)
{
   if (list)
      return list->list[list->size - 1].actiondata;
   return NULL;
}

void file_list_get_at_offset(const file_list_t *list, size_t idx,
      const char **path, const char **label, unsigned *file_type)
{
   if (path)
      *path      = list->list[idx].path;
   if (label)
      *label     = list->list[idx].label;
   if (file_type)
      *file_type = list->list[idx].type;
}

void file_list_get_last(const file_list_t *list,
      const char **path, const char **label,
      unsigned *file_type)
{
   if (list->size)
      file_list_get_at_offset(list, list->size - 1, path, label, file_type);
}

bool file_list_search(const file_list_t *list, const char *needle, size_t *idx)
{
   size_t i;
   const char *alt;
   bool ret = false;

   for (i = 0; i < list->size; i++)
   {
      const char *str;
      file_list_get_alt_at_offset(list, i, &alt);
      if (!alt)
      {
         file_list_get_label_at_offset(list, i, &alt);
         if (!alt)
            continue;
      }

      str = (const char *)strcasestr(alt, needle);
      if (str == alt)
      {
         /* Found match with first chars, best possible match. */
         *idx = i;
         ret = true;
         break;
      }
      else if (str && !ret)
      {
         /* Found mid-string match, but try to find a match with 
          * first characters before we settle. */
         *idx = i;
         ret = true;
      }
   }

   return ret;
}
