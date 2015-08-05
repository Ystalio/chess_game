#include "struct_piece.h"
#include "avail_move.h"
#include <stdio.h>

int check_pieces_position(int i, int j, enum piececolor, Echiquier *chess);

void avail_pawn_move(Position *Pini, Echiquier *E, int *temp){

	int i,j;

	i = Pini->posy;
	j = Pini->posx;

	enum piececolor color = E->t[i][j].c;
	enum piececolor color_adv;
	if(color == white){
		color_adv = black;
	}
	else{
		color_adv = white;
	}

	switch(color){

		case white :
			if(i-1 >= 0){ //verification if inside of array
				if(j-1 >= 0){
					if(check_pieces_position(i-1, j-1, color_adv, E) == 1){
						temp[(i-1)*LARGEUR + j-1]=1;//capture forward on its left
					} 
				}
				if(check_pieces_position(i-1, j, color_adv, E) == 0 && 
						check_pieces_position(i-1, j, color, E) == 0){
					temp[(i-1)*LARGEUR + j]=1;//move forward by one square
				} 
			}
			if(i-1 >=0 && j+1 < LARGEUR){ //verification if inside of array
				if(check_pieces_position(i-1, j+1, color_adv, E) == 1){
					temp[(i-1)*LARGEUR + j+1]=1; //capture forward on its right
				}
			}
			if(E->t[Pini->posy][Pini->posx].m == 0 && 
					check_pieces_position(i-1, j, color_adv, E) == 0 && 
					check_pieces_position(i-2, j, color_adv, E) == 0 && 
					check_pieces_position(i-1, j, color, E) == 0 && 
					check_pieces_position(i-2, j, color, E) == 0){
				temp[(i-2)*LARGEUR + j]=1; //move forward by two square

			}
			if(E->last_move.posx==j+1 && E->last_move.posy==i && E->t[i][j+1].m==1 && E->t[i][j+1].t==pion){
				temp[(i-1)*LARGEUR + j+1]=1;
			}
			if(E->last_move.posx==j-1 && E->last_move.posy==i && E->t[i][j-1].m==1 && E->t[i][j-1].t==pion){
				temp[(i-1)*LARGEUR + j-1]=1;
			}
			break;

		case black :
			if(i+1<LARGEUR){ //verification if inside of array
				if(check_pieces_position(i+1, j, color_adv, E) == 0 && check_pieces_position(i+1, j, color, E) == 0){
					temp[(i+1)*LARGEUR +j]=1;//move forward by one square
				} 
				if(j-1>=0){
					if(check_pieces_position(i+1, j-1, color_adv, E) == 1){
						temp[(i+1)*LARGEUR + j-1]=1;//capture forward on its left
					} 
				}
			}
			if(i+1<LARGEUR && j+1<LARGEUR){ //verification if inside of array
				if(check_pieces_position(i+1, j+1, color_adv, E) == 1){
					temp[(i+1)*LARGEUR + j+1]=1; //capture forward on its right
				}
			}
			if(E->t[Pini->posy][Pini->posx].m==0 && 
					check_pieces_position(i+1, j, color_adv, E) == 0 && 
					check_pieces_position(i+2, j, color_adv, E) == 0 && 
					check_pieces_position(i+1, j, color, E) == 0 && 
					check_pieces_position(i+2, j, color, E) == 0){
				temp[(i+2)*LARGEUR + j]=1; //move forward by two square
			}
			if(E->last_move.posx==j+1 && E->last_move.posy==i && E->t[i][j+1].m==1){
				temp[(i+1)*LARGEUR + j+1]=1;
			}
			if(E->last_move.posx==j-1 && E->last_move.posy==i && E->t[i][j-1].m==1){
				temp[(i+1)*LARGEUR + j-1]=1;
			}
			break;
		case nothing :
			break;
	}
}
