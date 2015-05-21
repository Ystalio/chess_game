#include "Struct_Piece.h"
#include "avail_move.h"

Tab avail_pawn_attacked(Position *Pini, Echiquier *E){
    int i,j;
    Tab avail_move = {.t =  {{0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0}
                            }};
    i = Pini->posy;
    j = Pini->posx;
    int (*adverse)[LARGEUR];
    int (*mine_piece)[LARGEUR];
    switch(E->t[i][j].c){
        case white : adverse = E->blacks_position;
                     mine_piece = E->whites_position;
        break;
        case black : adverse = E->whites_position;
                     mine_piece = E->blacks_position;
        break;
        case nothing :
        break;
    }

    switch(E->t[Pini->posy][Pini->posx].c){

        case white :
                        if(i-1 >= 0){ //verification if inside of array
                            if(j-1 >= 0){
                                if(mine_piece[i-1][j-1]==0){avail_move.t[i-1][j-1]=1;} //capture forward on its left
                            }
                        }
                        if(i-1 >=0 && j+1 < LARGEUR){ //verification if inside of array
                            if(mine_piece[i-1][j+1]==0){avail_move.t[i-1][j+1]=1;} //capture forward on its right
                        }
        break;

        case black :
                        if(i+1<LARGEUR){ //verification if inside of array
                            if(j-1>=0){
                                if(mine_piece[i+1][j-1]==0){avail_move.t[i+1][j-1]=1;} //capture forward on its left
                            }
                        }
                        if(i+1<LARGEUR && j+1<LARGEUR){ //verification if inside of array
                            if(mine_piece[i+1][j+1]==0){avail_move.t[i+1][j+1]=1;} //capture forward on its right
                        }
        break;
        case nothing :
        break;
    }
    return avail_move;
}

