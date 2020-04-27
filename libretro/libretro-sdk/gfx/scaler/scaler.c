/* Copyright  (C) 2010-2014 The RetroArch team
 *
 * ---------------------------------------------------------------------------------------
 * The following license statement only applies to this file (scaler.c).
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

#include <gfx/scaler/scaler.h>
#include <gfx/scaler/scaler_int.h>
#include <gfx/scaler/filter.h>
#include <gfx/scaler/pixconv.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// In case aligned allocs are needed later ...
void *scaler_alloc(size_t elem_size, size_t size)
{
   return calloc(elem_size, size);
}

void scaler_free(void *ptr)
{
   free(ptr);
}

static bool allocate_frames(struct scaler_ctx *ctx)
{
   ctx->scaled.stride = ((ctx->out_width + 7) & ~7) * sizeof(uint64_t);
   ctx->scaled.width  = ctx->out_width;
   ctx->scaled.height = ctx->in_height;
   ctx->scaled.frame  = (uint64_t*)
      scaler_alloc(sizeof(uint64_t),
            (ctx->scaled.stride * ctx->scaled.height) >> 3);
   if (!ctx->scaled.frame)
      return false;

   if (ctx->in_fmt != SCALER_FMT_ARGB8888)
   {
      ctx->input.stride = ((ctx->in_width + 7) & ~7) * sizeof(uint32_t);
      ctx->input.frame = (uint32_t*)
         scaler_alloc(sizeof(uint32_t),
               (ctx->input.stride * ctx->in_height) >> 2);
      if (!ctx->input.frame)
         return false;
   }

   if (ctx->out_fmt != SCALER_FMT_ARGB8888)
   {
      ctx->output.stride = ((ctx->out_width + 7) & ~7) * sizeof(uint32_t);
      ctx->output.frame  = (uint32_t*)
         scaler_alloc(sizeof(uint32_t),
               (ctx->output.stride * ctx->out_height) >> 2);
      if (!ctx->output.frame)
         return false;
   }

   return true;
}

static bool set_direct_pix_conv(struct scaler_ctx *ctx)
{
   if (ctx->in_fmt == ctx->out_fmt)
      ctx->direct_pixconv = conv_copy;
   else if (ctx->in_fmt == SCALER_FMT_0RGB1555
         && ctx->out_fmt == SCALER_FMT_ARGB8888)
      ctx->direct_pixconv = conv_0rgb1555_argb8888;
   else if (ctx->in_fmt == SCALER_FMT_RGB565
         && ctx->out_fmt == SCALER_FMT_ARGB8888)
      ctx->direct_pixconv = conv_rgb565_argb8888;
   else if (ctx->in_fmt == SCALER_FMT_RGB565
         && ctx->out_fmt == SCALER_FMT_BGR24)
      ctx->direct_pixconv = conv_rgb565_bgr24;
   else if (ctx->in_fmt == SCALER_FMT_0RGB1555
         && ctx->out_fmt == SCALER_FMT_RGB565)
      ctx->direct_pixconv = conv_0rgb1555_rgb565;
   else if (ctx->in_fmt == SCALER_FMT_RGB565
         && ctx->out_fmt == SCALER_FMT_0RGB1555)
      ctx->direct_pixconv = conv_rgb565_0rgb1555;
   else if (ctx->in_fmt == SCALER_FMT_BGR24
         && ctx->out_fmt == SCALER_FMT_ARGB8888)
      ctx->direct_pixconv = conv_bgr24_argb8888;
   else if (ctx->in_fmt == SCALER_FMT_ARGB8888
         && ctx->out_fmt == SCALER_FMT_0RGB1555)
      ctx->direct_pixconv = conv_argb8888_0rgb1555;
   else if (ctx->in_fmt == SCALER_FMT_ARGB8888
         && ctx->out_fmt == SCALER_FMT_BGR24)
      ctx->direct_pixconv = conv_argb8888_bgr24;
   else if (ctx->in_fmt == SCALER_FMT_0RGB1555
         && ctx->out_fmt == SCALER_FMT_BGR24)
      ctx->direct_pixconv = conv_0rgb1555_bgr24;
   else if (ctx->in_fmt == SCALER_FMT_ARGB8888
         && ctx->out_fmt == SCALER_FMT_ABGR8888)
      ctx->direct_pixconv = conv_argb8888_abgr8888;
   else if (ctx->in_fmt == SCALER_FMT_YUYV
         && ctx->out_fmt == SCALER_FMT_ARGB8888)
      ctx->direct_pixconv = conv_yuyv_argb8888;
   else if (ctx->in_fmt == SCALER_FMT_RGBA4444
         && ctx->out_fmt == SCALER_FMT_ARGB8888)
      ctx->direct_pixconv = conv_rgba4444_argb8888;
   else
      return false;

   return true;
}

static bool set_pix_conv(struct scaler_ctx *ctx)
{
   switch (ctx->in_fmt)
   {
      case SCALER_FMT_ARGB8888:
         /* No need to convert :D */
         break;

      case SCALER_FMT_0RGB1555:
         ctx->in_pixconv = conv_0rgb1555_argb8888;
         break;

      case SCALER_FMT_RGB565:
         ctx->in_pixconv = conv_rgb565_argb8888;
         break;

      case SCALER_FMT_BGR24:
         ctx->in_pixconv = conv_bgr24_argb8888;
         break;

      case SCALER_FMT_RGBA4444:
         ctx->in_pixconv = conv_rgba4444_argb8888;
         break;

      default:
         return false;
   }

   switch (ctx->out_fmt)
   {
      case SCALER_FMT_ARGB8888:
         /* No need to convert :D */
         break;

      case SCALER_FMT_0RGB1555:
         ctx->out_pixconv = conv_argb8888_0rgb1555;
         break;

      case SCALER_FMT_BGR24:
         ctx->out_pixconv = conv_argb8888_bgr24;
         break;

      default:
         return false;
   }

   return true;
}

bool scaler_ctx_gen_filter(struct scaler_ctx *ctx)
{
   scaler_ctx_gen_reset(ctx);

   if (ctx->in_width == ctx->out_width && ctx->in_height == ctx->out_height)
      ctx->unscaled = true; /* Only pixel format conversion ... */
   else
   {
      ctx->scaler_horiz = scaler_argb8888_horiz;
      ctx->scaler_vert  = scaler_argb8888_vert;
      ctx->unscaled     = false;
   }

   ctx->scaler_special = NULL;

   if (!allocate_frames(ctx))
      return false;

   if (ctx->unscaled)
   {
      if (!set_direct_pix_conv(ctx))
         return false;
   }
   else
   {
      if (!set_pix_conv(ctx))
         return false;
   }

   if (!ctx->unscaled && !scaler_gen_filter(ctx))
      return false;

   return true;
}

void scaler_ctx_gen_reset(struct scaler_ctx *ctx)
{
   scaler_free(ctx->horiz.filter);
   scaler_free(ctx->horiz.filter_pos);
   scaler_free(ctx->vert.filter);
   scaler_free(ctx->vert.filter_pos);
   scaler_free(ctx->scaled.frame);
   scaler_free(ctx->input.frame);
   scaler_free(ctx->output.frame);

   memset(&ctx->horiz, 0, sizeof(ctx->horiz));
   memset(&ctx->vert, 0, sizeof(ctx->vert));
   memset(&ctx->scaled, 0, sizeof(ctx->scaled));
   memset(&ctx->input, 0, sizeof(ctx->input));
   memset(&ctx->output, 0, sizeof(ctx->output));
}

void scaler_ctx_scale(struct scaler_ctx *ctx,
      void *output, const void *input)
{
   if (ctx->unscaled)
   {
      /* Just perform straight pixel conversion. */
      ctx->direct_pixconv(output, input,
            ctx->out_width, ctx->out_height,
            ctx->out_stride, ctx->in_stride);
   }
   else if (ctx->scaler_special)
   {
      /* Take some special, and (hopefully) more optimized path. */
      const void *inp = input;
      int in_stride   = ctx->in_stride;

      if (ctx->in_fmt != SCALER_FMT_ARGB8888)
      {
         ctx->in_pixconv(ctx->input.frame, input,
               ctx->in_width, ctx->in_height,
               ctx->input.stride, ctx->in_stride);

         inp       = ctx->input.frame;
         in_stride = ctx->input.stride;
      }

      bool conv_out  = ctx->out_fmt != SCALER_FMT_ARGB8888;
      void *outp     = output;
      int out_stride = ctx->out_stride;

      if (conv_out)
      {
         outp       = ctx->output.frame;
         out_stride = ctx->output.stride;
      }

      ctx->scaler_special(ctx, outp, inp,
            ctx->out_width, ctx->out_height,
            ctx->in_width, ctx->in_height,
            out_stride, in_stride);

      if (conv_out)
      {
         ctx->out_pixconv(output, ctx->output.frame,
               ctx->out_width, ctx->out_height,
               ctx->out_stride, ctx->output.stride);
      }
   }
   else
   {
      const void *input_frame  = input;
      int stride = ctx->in_stride;
      bool out_fmt_is_not_argb8888 = (ctx->out_fmt != SCALER_FMT_ARGB8888);

      /* Take generic filter path. */
      if (ctx->in_fmt != SCALER_FMT_ARGB8888)
      {
         ctx->in_pixconv(ctx->input.frame, input,
               ctx->in_width, ctx->in_height,
               ctx->input.stride, ctx->in_stride);

         input_frame = ctx->input.frame;
         stride      = ctx->input.stride;
      }
      ctx->scaler_horiz(ctx, input_frame, stride);

      ctx->scaler_vert(ctx,
            out_fmt_is_not_argb8888 ? ctx->output.frame  : output,
            out_fmt_is_not_argb8888 ? ctx->output.stride : ctx->out_stride);

      if (out_fmt_is_not_argb8888)
         ctx->out_pixconv(output, ctx->output.frame,
               ctx->out_width, ctx->out_height,
               ctx->out_stride, ctx->output.stride);
   }
}

