#include "struct_piece.h"
#include "avail_move.h"

int check_pieces_position(int i, int j, enum piececolor, Echiquier *chess);

void avail_king_move(Position *Pini, Echiquier *E, int *temp){
	int i,j;
	i = Pini->posy;
	j = Pini->posx;

	enum piececolor color = E->t[i][j].c;

	if(i-1>=0){
		if(j-1>=0){
			if(check_pieces_position(i-1,j-1, color, E) == 0){
				temp[(i-1)*LARGEUR + j-1]=1;
			}
		}
		if(check_pieces_position(i-1,j,color,E)==0){
			temp[(i-1)*LARGEUR + j]=1;
		}
		if(j+1<8){
			if(check_pieces_position(i-1, j+1, color, E) == 0){
				temp[(i-1)*LARGEUR + j+1]=1;
			}
		}
	}
	if(j-1>=0){
		if(check_pieces_position(i, j-1, color, E) == 0){
			temp[i*LARGEUR + j-1]=1;
		}
	}
	if(j+1<8){
		if(check_pieces_position(i, j+1, color, E) == 0){
			temp[i*LARGEUR + j+1]=1;
		}
	}

	if(i+1<8){
		if(j-1>=0){
			if(check_pieces_position(i+1, j-1, color, E) == 0){
				temp[(i+1)*LARGEUR + j-1]=1;
			}
		}
		if(check_pieces_position(i+1, j, color, E) == 0){
			temp[(i+1)*LARGEUR + j]=1;
		}
		if(j+1<8){
			if(check_pieces_position(i+1, j+1, color, E) == 0){
				temp[(i+1)*LARGEUR + j+1]=1;
			}
		}
	}
}
