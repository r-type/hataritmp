#ifndef LIBRETRO_HATARI_H
#define LIBRETRO_HATARI_H 1

#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "SDL.h"

#include <stdbool.h>
#include "ikbd.h"
#include "configuration.h"

extern const char SDLKeyToSTScanCode[512] ;

#include <libco.h>

extern cothread_t mainThread;
extern cothread_t emuThread;

extern char Key_Sate[512];
extern char Key_Sate2[512];

extern int pauseg; 

#include "SDL_video.h"

#define LOGI printf

#define NPLGN 20
#define NLIGN 5
#define NLETT 5

#define RGB565(r, g, b)  (((r) << (5+6)) | ((g) << 6) | (b))

#endif
