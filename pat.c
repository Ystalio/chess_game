#include <stdlib.h>
#include <stdio.h>
#include "avail_move.h"
#include "struct_piece.h"
#include "move_piece.h"

int hunt_chess(Echiquier *E);
int mat(Echiquier *E);
void get_chess_after_move(int i, int j, int k, int l, Echiquier* E, Echiquier *E_test);
int test_echec(int *available_move,Echiquier *E,int i, int j);
void mdfy_pieces_position(int i, int j, enum joueur player, int value, Echiquier *chess);
void mdfy_king_position(int i, int j, enum joueur player, int value, Echiquier *chess);


enum joueur convert_piececolor_to_joueur(enum piececolor piece_color){
	switch(piece_color){
		case black : return JOUEUR_NOIR;
		case white : return JOUEUR_BLANC;
		default : return NOTHING;
	}
}

int pat(Echiquier *E){
	int non_pat=1;
	int i,j;
	Position Pini;
	int available_move[LARGEUR][LARGEUR];
	int *ptr_available_move;
	ptr_available_move = (int *)available_move;
	if(!hunt_chess(E)){
		non_pat=0;
		for(i=0;i<LARGEUR;i++){
			for(j=0;j<LARGEUR;j++){
				enum joueur piece_color = convert_piececolor_to_joueur(E->t[i][j].c);
				if(piece_color==E->joueur){
					Pini = g(j,i);
					avail_moves[E->t[i][j].t](&Pini,E, ptr_available_move);
					if(!test_echec(ptr_available_move,E,i,j)){
						non_pat=1;
					}
				}
			}
		}
	}

	return !non_pat;
}

int test_echec(int *available_move,Echiquier *E,int i,int j){
	int k,l;
	int counter_nb_chess=1;
	Echiquier E_test = *E;
	int all_move_make_chess;
	for(k=0;k<LARGEUR;k++){
		for(l=0;l<LARGEUR;l++){
			if(available_move[k*LARGEUR + l]){
				get_chess_after_move(i,j,k,l,E,&E_test);
				if(hunt_chess(&E_test)){
					counter_nb_chess=counter_nb_chess && 1;		
				}
				else{
					counter_nb_chess=0;
				}
			}
		}
	}
	all_move_make_chess=counter_nb_chess;
	return all_move_make_chess;
}

void get_chess_after_move(int i, int j, int k, int l, Echiquier* E, Echiquier *E_test){
	enum piececolor color = E->t[i][j].c;
	enum joueur player = E->joueur;
	enum joueur player_adv;
	if(player == JOUEUR_BLANC){
		player_adv = JOUEUR_NOIR;
	}
	else{
		player_adv = JOUEUR_BLANC;
	}

	E_test->t[i][j]=f(pion,nothing,j,i,0);
	E_test->t[k][l]=f(E->t[i][j].t,color,l,k,E->t[i][j].m +1);
	E_test->last_move=g(l,k);

	mdfy_pieces_position(i, j, player, 0, E_test);
	mdfy_pieces_position(k, l, player, 1, E_test);
	mdfy_pieces_position(k, l, player_adv, 0, E_test);
	if(E->t[i][j].t==roi){
		mdfy_king_position(i, j, player, 0, E_test);
		mdfy_king_position(k, l, player, 1, E_test);
	}
}	
