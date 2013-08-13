/* MPRT - - Prints Mono Screen to PRN                                     */
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
   int      row, col;
   FILE     *prn;

   viopbBuf.pBuf = (PCH) 0xB0000L;
   viopbBuf.cb = 4000;
   VioGetPhysBuf(&viopbBuf, 0);
   pchScreen = MAKEP(viopbBuf.asel[0],0);
   i = 0;
   prn = fopen("prn","w");                /* Open printer                 */
   for(row = 1; row <= 25; ++row)
      {
      for (col = 1; col <= 80; ++col)
         {
         fputc(*(pchScreen + i), prn);    /* Put chars to printer         */
         i += 2;
         }
      fputc('\n', prn);                   /* Newline after 80 cols        */
      }
   fputc('\f', prn);                      /* Formfeed at end              */
   return;                                                 
}


