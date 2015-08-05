#include "struct_piece.h"
#include "avail_move.h"

int check_pieces_position(int i, int j, enum piececolor, Echiquier *chess);

void avail_knight_move(Position *Pini, Echiquier *E, int *temp){
	//Knight have 8 different movement : (i-1,j-2) (i-1,j+2) (i-2,j-1) (i-2,j+1) (i+1,j-2) (i+1,j+2) (i+2,j-1) (i+2,j+1)

	int i,j;

	i = Pini->posy;
	j = Pini->posx;

	enum piececolor color = E->t[i][j].c;

	if(i-1>=0){
		if(j-2>=0){
			if(check_pieces_position(i-1, j-2, color, E) == 0){
				temp[(i-1)*LARGEUR + j-2]=1;
			}
		}
		if(j+2<8){
			if(check_pieces_position(i-1, j+2, color, E) == 0){
				temp[(i-1)*LARGEUR + j+2]=1;
			}
		}
	}
	if(i-2>=0){
		if(j-1>=0){
			if(check_pieces_position(i-2, j-1, color, E) == 0){
				temp[(i-2)*LARGEUR + j-1]=1;
			}
		}
		if(j+1<8){
			if(check_pieces_position(i-2, j+1, color, E) == 0){
				temp[(i-2)*LARGEUR + j+1]=1;
			}
		}
	}
	if(i+1<8){
		if(j-2>=0){
			if(check_pieces_position(i+1, j-2, color, E) == 0){
				temp[(i+1)*LARGEUR + j-2]=1;
			}
		}
		if(j+2<8){
			if(check_pieces_position(i+1, j+2, color, E) == 0){
				temp[(i+1)*LARGEUR + j+2]=1;
			}
		}
	}
	if(i+2<8){
		if(j-1>=0){
			if(check_pieces_position(i+2, j-1, color, E) == 0){
				temp[(i+2)*LARGEUR + j-1]=1;
			}
		}
		if(j+1<8){
			if(check_pieces_position(i+2, j+1, color, E) == 0){
				temp[(i+2)*LARGEUR + j+1]=1;
			}
		}
	}
}
