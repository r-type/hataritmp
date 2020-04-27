#include "libretro-hatari.h"

#include "vkbd_def2.h"
#include "graph.h"

extern int NPAGE;
extern int KCOL;
extern int BKGCOLOR;
extern int SHIFTON;

int kbd_alpha=1;

void virtual_kdb(unsigned short int *pixels,int vx,int vy)
{
   int x, y, posx,posy,page;
   short unsigned *pix, coul;

   int scale;
   int XSIDE2;
   int YSIDE2;
   int xoff;
   int XBASE;
   int YBASE;

   scale = (retrow < 640) ? 1 : 2;
   xoff = (scale == 1) ? 1 : 2;

   XSIDE2 = (5*scale*3)+xoff;
   YSIDE2 = (8*scale)+2;

   XBASE = (retrow-NPLGN*XSIDE2)/2;  
   YBASE = retroh/2 + (retroh/2 -NLIGN*YSIDE2)/2;  

   page = (NPAGE == -1) ? 0 : NPLGN*NLIGN;
   pix= (short unsigned *)&pixels[0];

   coul = RGB565(28, 28, 31);

   if(kbd_alpha){
	DrawFBoxBmpRGBA(pix,XBASE,YBASE,XSIDE2*NPLGN,YSIDE2*NLIGN,0x8080,128);
	BKGCOLOR = 0;
   }
   else   BKGCOLOR = (KCOL>0?0x8080:0);

   for(x=0;x<NPLGN;x++)
   {
      for(y=0;y<NLIGN;y++)
      {

	posx=XBASE+x*XSIDE2 ;
	posy=YBASE+YSIDE2*y ;

	Gui_Text(pix,posx, posy,SHIFTON==-1?MVk[(y*NPLGN)+x+page].norml:MVk[(y*NPLGN)+x+page].shift,coul,BKGCOLOR,scale);
	
      }
   }

   posx=XBASE+vx*XSIDE2 ;
   posy=YBASE+YSIDE2*vy ;

   coul = RGB565(2,31,1);

   Gui_Text(pix,posx, posy,SHIFTON==-1?MVk[(vy*NPLGN)+vx+page].norml:MVk[(vy*NPLGN)+vx+page].shift,coul,BKGCOLOR,scale);

}

int check_vkey2(int x,int y)
{
   int page;
   //check which key is press
   page= (NPAGE==-1) ? 0 : NPLGN*NLIGN;
   return MVk[y*NPLGN+x+page].val;
}

