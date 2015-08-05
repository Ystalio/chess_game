#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_piece.h"
#include "avail_move.h"
#include "move_piece.h"


void mdfy_pieces_position(int i, int j, enum joueur player, int value, Echiquier *chess);
void mdfy_king_position(int i, int j, enum joueur player, int value, Echiquier *chess);
int check_pieces_position(int i, int j, enum piececolor color, Echiquier *chess);
Echiquier simulate_move(Position *Pini, Position *Pfin, Echiquier *E);

int mat(Echiquier *E){
	int i,j,k,l;
	int r=1;
	int available_move[LARGEUR][LARGEUR];
	memset(*available_move, 0, sizeof(available_move));
	int *ptr_available_move;
	ptr_available_move = (int *)available_move;
	Position Pini, Pfin;
	Echiquier E_mat_test;

	if(!hunt_chess(E)){
		return 0;
	}
	enum joueur player = E->joueur;
	enum piececolor color;
	if(player == JOUEUR_NOIR){
		color = black;
	}
	else{
		color = white;
	}
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			if(check_pieces_position(i, j, color, E)){
				Pini = g(j,i);
				avail_moves[E->t[i][j].t](&Pini,E, ptr_available_move);
				for(k=0;k<LARGEUR;k++){
					for(l=0;l<LARGEUR;l++){
						if(available_move[k][l]){
							Pfin = g(l,k);				
							E_mat_test = simulate_move(&Pini, &Pfin, E);
							if(!hunt_chess(&E_mat_test)){
								return 0;
							}
						}
					}
				}
				memset(*available_move, 0, sizeof(available_move));
			}
		}
	}
	return r;
}

void mdfy_pieces_position(int i, int j, enum joueur player, int value, Echiquier *chess){
	if(player == JOUEUR_BLANC){
		chess->whites_position[i][j] = value;
	}
	else{
		chess->blacks_position[i][j] = value;
	}
}

void mdfy_king_position(int i, int j, enum joueur player, int value, Echiquier *chess){
	if(player == JOUEUR_BLANC){
		chess->white_king[i][j] = value;
	}
	else{
		chess->black_king[i][j] = value;
	}
}
