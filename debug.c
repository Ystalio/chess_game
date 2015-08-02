#include <stdio.h>
#include <stdlib.h>

#include "struct_piece.h"
#include "avail_move.h"
#include "move_piece.h"

//Voir aussi hunt_mat.c, move_piece.c

void debug(Position2 *R, Echiquier *E){
    Position init ={R->posx1,R->posy1};
    Position end ={R->posx2,R->posy2};
    int i,j,k,l;
    Piece p = E->t[init.posy][init.posx];
    Piece q = E->t[end.posy][end.posx];

    static const char* code = "PTCFRD";
    static const char* color = "NBR";

            printf("\n\nInit_square   End_square\n");

            printf("%c             %c\n",code[(int)(p.t)],code[(int)(q.t)]);
            printf("%c             %c\n",color[(int)(p.c)],color[(int)(q.c)]);
            printf("(%d,%d)        (%d,%d)\n",p.p.posx,p.p.posy,q.p.posx,q.p.posy);
            printf("%d             %d\n",p.m,q.m);
            printf("last_move = (%d,%d)\n\n",E->last_move.posx,E->last_move.posy);

    printf("avail_move        whites_position        blacks_position\n");

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d",R->avail.t[i][j]);
        }
        printf("          ");
        for(k=0;k<8;k++){
            printf("%d",E->whites_position[i][k]);
        }
        printf("               ");
        for(l=0;l<8;l++){
            printf("%d",E->blacks_position[i][l]);
        }
            printf("\n");
    }
}
