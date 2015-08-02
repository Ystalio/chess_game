#include "struct_piece.h"
#include "avail_move.h"

Tab avail_pawn_attacked(Position *Pini, Echiquier *E){

    int i,j,k,l;

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

    switch(E->t[Pini->posy][Pini->posx].c){

        case white :
                        if(i-1 >= 0){ //verification if inside of array
                            if(j-1 >= 0){
                                if(mine_piece[i-1][j-1]==0){
                                    avail_move.t[i-1][j-1]=1; //capture forward on its left
                                }
                            }
                        }
                        if(i-1 >=0 && j+1 < LARGEUR){ //verification if inside of array
                            if(mine_piece[i-1][j+1]==0){
                                avail_move.t[i-1][j+1]=1; //capture forward on its right
                            }
                        }
        break;

        case black :
                        if(i+1<LARGEUR){ //verification if inside of array
                            if(j-1>=0){
                                if(mine_piece[i+1][j-1]==0){
                                    avail_move.t[i+1][j-1]=1; //capture forward on its left
                                }
                            }
                        }
                        if(i+1<LARGEUR && j+1<LARGEUR){ //verification if inside of array
                            if(mine_piece[i+1][j+1]==0){
                                avail_move.t[i+1][j+1]=1; //capture forward on its right
                            }
                        }
        break;
        case nothing :
        break;
    }

    return avail_move;
}

