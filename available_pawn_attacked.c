#include "struct_piece.h"
#include "avail_move.h"

int check_pieces_position(int i, int  j, enum piececolor, Echiquier *chess);

void avail_pawn_attacked(Position *Pini, Echiquier *E, int *temp){

	int i,j;

	i = Pini->posy;
	j = Pini->posx;

	enum piececolor color = E->t[i][j].c;

	switch(color){

		case white :
			if(i-1 >= 0){ //verification if inside of array
				if(j-1 >= 0){
					if(check_pieces_position(i-1, j-1, color, E) == 0){
						temp[(i-1)*LARGEUR + j-1]=1; //capture forward on its left
					}
				}
			}
			if(i-1 >=0 && j+1 < LARGEUR){ //verification if inside of array
				if(check_pieces_position(i-1, j+1, color, E) == 0){
					temp[(i-1)*LARGEUR + j+1]=1; //capture forward on its right
				}
			}
			break;

		case black :
			if(i+1<LARGEUR){ //verification if inside of array
				if(j-1>=0){
					if(check_pieces_position(i+1, j-1, color, E) == 0){
						temp[(i+1)*LARGEUR + j-1]=1; //capture forward on its left
					}
				}
			}
			if(i+1<LARGEUR && j+1<LARGEUR){ //verification if inside of array
				if(check_pieces_position(i+1, j+1, color, E) == 0){
					temp[(i+1)*LARGEUR + j+1]=1; //capture forward on its right
				}
			}
			break;
		case nothing :
			break;
	}
}
