#include <stdio.h>
#include <stdlib.h>

#include "struct_piece.h"
#include "avail_move.h"
#include "move_piece.h"

void mdfy_pieces_position(int i, int j, enum joueur player, int value, Echiquier *chess);
void mdfy_king_position(int i, int j, enum joueur player, int value, Echiquier *chess);

int mat(Echiquier *E){
	int i,j,k,l;
	int r=1;
	int available_move[LARGEUR][LARGEUR];
	int *ptr_available_move;
	ptr_available_move = (int *)available_move;
	Position Pini;
	Echiquier E_mat_test;
	E_mat_test = *E;

	if(!hunt_chess(&E_mat_test)){
		return 0;
	}
	enum joueur player = E->joueur;
	enum joueur next_player;
	if(player == JOUEUR_NOIR){
		next_player = JOUEUR_BLANC;
	}
	else{
		next_player = JOUEUR_NOIR;
	}
	for(i=LARGEUR-1;i>=0;i--){
		for(j=LARGEUR-1;j>=0;j--){
			if(E->blacks_position[i][j]==1){
				Pini = g(j,i);
				avail_moves[E->t[i][j].t](&Pini,E, ptr_available_move);
				for(k=0;k<LARGEUR;k++){
					for(l=0;l<LARGEUR;l++){
						E_mat_test = *E;
						if(available_move[k][l]){
							E_mat_test.t[i][j] = f(pion,nothing,j,i,0);
							E_mat_test.t[k][l] = f(E->t[i][j].t,player,l,k,E->t[i][j].m+1);
							E_mat_test.joueur = next_player;
							E_mat_test.last_move = g(l,k);
							if(E->t[i][j].t==roi){
								mdfy_king_position(i, j, player, 0, &E_mat_test);
								mdfy_king_position(k, l, player, 1, &E_mat_test);
							}
							mdfy_pieces_position(i, j, player, 0, &E_mat_test);
							mdfy_pieces_position(k, l, player, 1, &E_mat_test);
							mdfy_pieces_position(k, l, next_player, 0, &E_mat_test);

							if(!hunt_chess(&E_mat_test)){
								r=0;
							}
						}
					}
				}
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
