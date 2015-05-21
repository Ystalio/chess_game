#include <stdio.h>
#include <stdlib.h>
#include "Struct_Piece.h"

#ifdef __WIN32__
#include <windows.h>

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

#else // Not Windows platform

//FIXME support colors for VT100-like terminals (escape codes)
void color(int t,int f)
{
	(void)t;
	(void)f;
}

#endif

void print_game(Echiquier* E){ //fonction qui affiche l'échiquier en console
    static const char* code = "ptcfrd";
    static int col[3] = {12,15,0};
    int x,y;
    printf("-----------------\n");
    for(x=0;x<LARGEUR;x++)
    {
      for(y=0;y<LARGEUR;y++)
      {
         Piece P = E->t[x][y];
         printf("|");
         color(col[(int)(P.c)],0);
         printf("%c",code[(int)(P.t)]);
         color(15,0);
      }
      printf("|%d\n-----------------\n",8-x);
    }
    printf(" A B C D E F G H\n");
}
