#include "struct_piece.h"
#include "avail_move.h"

Tab avail_knight_move(/*int (*adverse)[8], int (*mine_piece)[8],*/ Position *Pini, Echiquier *E){

    int i,j,k,l;

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

    int mine_piece[LARGEUR][LARGEUR];
    switch(E->t[i][j].c){
	    case white : for(k=0;k<LARGEUR;k++){
				 for(l=0;l<LARGEUR;l++){
				     mine_piece[k][l] = E->whites_position[k][l];
			     }
			 }
			 break;
	    case black : for(k=0;k<LARGEUR;k++){
			     for(l=0;l<LARGEUR;l++){
				     mine_piece[k][l] = E->blacks_position[k][l];
			     }
		     }
		     break;
	case nothing :
		     break;
    }

    if(i-1>=0){
        if(j-2>=0){
            if(mine_piece[i-1][j-2]==0){
                avail_move.t[i-1][j-2]=1;
            }
        }
        if(j+2<8){
            if(mine_piece[i-1][j+2]==0){
                avail_move.t[i-1][j+2]=1;
            }
        }
    }
    if(i-2>=0){
        if(j-1>=0){
            if(mine_piece[i-2][j-1]==0){
                avail_move.t[i-2][j-1]=1;
            }
        }
        if(j+1<8){
                if(mine_piece[i-2][j+1]==0){
                    avail_move.t[i-2][j+1]=1;
                }
        }
    }
    if(i+1<8){
        if(j-2>=0){
            if(mine_piece[i+1][j-2]==0){
                avail_move.t[i+1][j-2]=1;
            }
        }
        if(j+2<8){
            if(mine_piece[i+1][j+2]==0){
                avail_move.t[i+1][j+2]=1;
            }
        }
    }
    if(i+2<8){
        if(j-1>=0){
            if(mine_piece[i+2][j-1]==0){
                avail_move.t[i+2][j-1]=1;
            }
        }
        if(j+1<8){
            if(mine_piece[i+2][j+1]==0){
                avail_move.t[i+2][j+1]=1;
            }
        }
    }

    return avail_move;
}
