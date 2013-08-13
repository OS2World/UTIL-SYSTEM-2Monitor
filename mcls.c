/* MCLS - - Clears Mono Screen                                            */
/* Written 9/89 by W. J. Morton                                           */

#define INCL_BASE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <os2.h>
#include <ctype.h>

VIOPHYSBUF     viopbBuf;                  /* Structure for physical buf   */
PCH            pchScreen;

void main(int argc, char **argv)

{
   register int   i;

   viopbBuf.pBuf = (PCH) 0xB0000L;
   viopbBuf.cb = 4000;
   VioGetPhysBuf(&viopbBuf, 0);
   pchScreen = MAKEP(viopbBuf.asel[0],0);
   for(i = 0; i < 4000; i += 2)          /* Set Mono Buff to spaces      */
      {
      *(pchScreen + i) = ' ';
      *(pchScreen + i + 1) = 7;
      }
   return;                                                 
}



