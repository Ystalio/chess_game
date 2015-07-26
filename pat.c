#include <stdlib.h>
#include <stdio.h>
#include "avail_move.h"
#include "Struct_Piece.h"
#include "move_piece.h"

int hunt_chess(Echiquier *E);
int mat(Echiquier *E);
Echiquier get_chess_after_move(int i, int j, int k, int l, Echiquier* E);
int test_echec(Tab available_move,Echiquier *E,int i, int j);


enum joueur convert_piececolor_to_joueur(enum piececolor piece_color){
	switch(piece_color){
		case black : return JOUEUR_NOIR;
	 	break;
		case white : return JOUEUR_BLANC;
		break;
		default: return JOUEUR_BLANC;fprintf(stderr,"converting enum piececolor to joueur : in Struct_Piece.h");
		break;
	}
}

int pat(Echiquier *E){
	int non_pat=1;
	int i,j;
	Position Pini;
	Tab available_move;
	if(!hunt_chess(E)){
		non_pat=0;
		for(i=0;i<LARGEUR;i++){
			for(j=0;j<LARGEUR;j++){
				enum joueur piece_color = convert_piececolor_to_joueur(E->t[i][j].c);
				if(piece_color==E->joueur){
					Pini = g(j,i);
					available_move = avail_moves[E->t[i][j].t](&Pini,E);
					if(!test_echec(available_move,E,i,j)){
						non_pat=1;
					}
				}
			}
		}
	}

	return !non_pat;
}

int test_echec(Tab available_move,Echiquier *E,int i,int j){
	int k,l;
	int counter_nb_chess=1;
	Echiquier E_test;
	int all_move_make_chess;
	for(k=0;k<LARGEUR;k++){
		for(l=0;l<LARGEUR;l++){
			if(available_move.t[k][l]){
				E_test=get_chess_after_move(i,j,k,l,E);
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

Echiquier get_chess_after_move(int i, int j, int k, int l, Echiquier* E){
	Echiquier E_test;
	E_test=*E;
	E_test.t[i][j]=f(pion,nothing,j,i,0);
	E_test.t[k][l]=f(E->t[i][j].t,E->t[i][j].c,l,k,E->t[i][j].m +1);
/*	switch(E_test.joueur){
		case JOUEUR_BLANC : E_test.joueur=JOUEUR_NOIR;
		break;
		case JOUEUR_NOIR : E_test.joueur=JOUEUR_BLANC;
	}*/
	E_test.last_move=g(l,k);
	switch(E->t[i][j].c){
	case white :	E_test.whites_position[i][j]=0;
			E_test.whites_position[k][l]=1;
			E_test.blacks_position[k][l]=0;
			if(E->t[i][j].t==4){
			E_test.white_king[i][j]=0;
			E_test.white_king[k][l]=1;
			}
	break;
	case black :	E_test.blacks_position[i][j]=0;
			E_test.whites_position[k][l]=1;
			E_test.whites_position[k][l]=0;
			if(E->t[i][j].t==4){
			E_test.black_king[i][j]=0;
			E_test.black_king[k][l]=1;
			}
	break;
	default :
	break;
	}
	return E_test;
}	
