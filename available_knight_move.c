#include "Struct_Piece.h"
#include "avail_move.h"

Tab avail_knight_move(/*int (*adverse)[8], int (*mine_piece)[8],*/ Position *Pini, Echiquier *E){
    int i,j;
    Tab avail_move = {.t = {{0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0}
                            }};
//Knight have 8 different movement : (i-1,j-2) (i-1,j+2) (i-2,j-1) (i-2,j+1) (i+1,j-2) (i+1,j+2) (i+2,j-1) (i+2,j+1)
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

        if(i-1>=0){
            if(j-2>=0){
                if(mine_piece[i-1][j-2]==0){avail_move.t[i-1][j-2]=1;}
            }
            if(j+2<8){
                if(mine_piece[i-1][j+2]==0){avail_move.t[i-1][j+2]=1;}
            }
        }
        if(i-2>=0){
            if(j-1>=0){
                if(mine_piece[i-2][j-1]==0){avail_move.t[i-2][j-1]=1;}
            }
            if(j+1<8){
                if(mine_piece[i-2][j+1]==0){avail_move.t[i-2][j+1]=1;}
            }
        }
        if(i+1<8){
            if(j-2>=0){
                if(mine_piece[i+1][j-2]==0){avail_move.t[i+1][j-2]=1;}
            }
            if(j+2<8){
                if(mine_piece[i+1][j+2]==0){avail_move.t[i+1][j+2]=1;}
            }
        }
        if(i+2<8){
            if(j-1>=0){
                if(mine_piece[i+2][j-1]==0){avail_move.t[i+2][j-1]=1;}
            }
            if(j+1<8){
                if(mine_piece[i+2][j+1]==0){avail_move.t[i+2][j+1]=1;}
            }
        }

    return avail_move;
}
