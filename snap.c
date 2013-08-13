/* SNAP - - Snaps image on color tube to mono tube.                       */
/* Written 9/89 by W. J. Morton                                           */
#define INCL_BASE
#include <stdio.h>
#include <stdlib.h>
#include <os2.h>
#include <ctype.h>

VIOPHYSBUF     viopbBufm;
VIOPHYSBUF     viopbBufc; 
PCH            pchScreenm, pchScreenc;   /* Pointers to mono, color      */

void main(int argc, char **argv)

{
   register int   i;

   viopbBufm.pBuf = (PCH) 0xB0000L;          /* Get a mono screen pointer */
   viopbBufc.cb = 4000;
   VioGetPhysBuf(&viopbBufm, 0);
   pchScreenm = MAKEP(viopbBufm.asel[0],0);

   viopbBufc.pBuf = (PCH) 0xB8000L;         /* Get a color screen pointer */
   viopbBufc.cb = 4000;
   VioGetPhysBuf(&viopbBufc, 0);
   pchScreenc = MAKEP(viopbBufc.asel[0],0);
                                           /* Copy chars from color to mono */
   i = 0;                                  /* and make attributes NORMAL    */  
   for (i = 0; i < 4000; i +=2)
      {
      *(pchScreenm + i) = *(pchScreenc + i);
      *(pchScreenm + i + 1) = 7;
      }      
}
