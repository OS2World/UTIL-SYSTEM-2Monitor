/* CSAVE - - 'Prints' Color Screen to a file                              */
#define INCL_BASE
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
   FILE     *filehandle;

   if(argc < 2)
      {
      printf("Usage is:  CSAVE filename\n");
      return;
      }
   filehandle = fopen(argv[1],"w");       /* Open output file             */
   viopbBuf.pBuf = (PCH) 0xB8000L;
   viopbBuf.cb = 4000;
   VioGetPhysBuf(&viopbBuf, 0);
   pchScreen = MAKEP(viopbBuf.asel[0],0);
   i = 0;
   for(row = 1; row <= 25; ++row)
      {
      for (col = 1; col <= 80; ++col)
         {
         fputc(*(pchScreen + i), filehandle); /* Put chars to file            */
         i += 2;
         }
      fputc('\n', filehandle);            /* Newline after 80 cols        */
      }
   return;                                                 
}


