#include <stdio.h>
#include <stdlib.h>
#include "platforms.h"
#include "struct_piece.h"

void print_game(Echiquier* E){ //fonction qui affiche l'échiquier en console
    static const char* code = "ptcfrd";
    int x,y;
    printf("-----------------\n");
    for(x=0;x<LARGEUR;x++)
    {
      for(y=0;y<LARGEUR;y++)
      {
         Piece P = E->t[x][y];
         printf("|");

		 int fcolor = TCOLOR_BLACK;
		 int bcolor = TCOLOR_WHITE;
		 if(P.c == black) {
			 fcolor = TCOLOR_RED;
			 bcolor = TCOLOR_BLACK;
		 }
		 else if(P.c == white) {
             fcolor = TCOLOR_WHITE;
             bcolor = TCOLOR_BLACK;
		 }
		 else if(P.c == nothing) {
		     fcolor = TCOLOR_BLACK;
			 bcolor = TCOLOR_BLACK;
		 }

		 term_color_set(fcolor, bcolor);

         printf("%c",code[(int)(P.t)]);

		 term_color_set(TCOLOR_WHITE, TCOLOR_BLACK);
      }
      printf("|%d\n-----------------\n",8-x);
    }
    printf(" A B C D E F G H\n");
}
