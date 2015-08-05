#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "avail_move.h"
#include "struct_piece.h"
#include "move_piece.h"
#include "allocation_mem.h"

#define DEPTH		2
#define VAL_PION	1.0
#define VAL_TOUR	5.1
#define VAL_CAVALIER	3.2
#define VAL_FOU		3.33
#define VAL_DAME	8.8

int hunt_chess(Echiquier *E);
int mat(Echiquier *E);
int nb_possib_move(Echiquier *E);
enum joueur convert_piececolor_to_joueur(enum piececolor piece_color);
Position2 get_position(Historic_elements **list, Echiquier *E);
Echiquier simulate_move(Position *Pini, Position *Pfin, Echiquier *E);
int min(enum joueur ia_player, Echiquier *sim_mv, int depth, Historic_elements **list);
int max(enum joueur ia_player, Echiquier *sim_mv, int depth, Historic_elements **list);
int test_three_plan(Historic_elements **list, Echiquier *sim_mv);
int pat(Echiquier *E);
int eval(enum joueur ia_player, int test_three_plan_chess, Echiquier *sim_mv);
unsigned int h_funct(void *chained_list, int size_chaine);
Passant en_passant_test(Echiquier *E);
int get_nb_occurrences(EchiquierSave *actual_plan, Historic_elements *list);
int rand_val(int value, int val_minmax);
void mdfy_pieces_position(int i, int j, enum joueur player, int value, Echiquier *chess);
void mdfy_king_position(int i, int j, enum joueur player, int value, Echiquier *chess);



Position2 ia_player(Historic_elements **list, Echiquier *E){
	return get_position(list, E);	
}

struct Position2 init_pos2(int a, int b, int c, int d){
	Position2 r = {a,b,c,d};
	return r;
}

Position2 get_position(Historic_elements **list, Echiquier *E){
	Position2 position_move;
	Echiquier sim_chess;
	int move_allowed[LARGEUR][LARGEUR];
	int *ptr_move_allowed;
	ptr_move_allowed = (int *)move_allowed;
	Position Pini, Pfin;
	int val_max = INT_MIN, value, depth = DEPTH;	
	int i,j,k,l;
	enum joueur color_player;
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			color_player = convert_piececolor_to_joueur(E->t[i][j].c);
			if(color_player == E->joueur){
				Pini = g(j,i);
				avail_moves[E->t[i][j].t](&Pini,E, ptr_move_allowed);
				for(k=0;k<LARGEUR;k++){
					for(l=0;l<LARGEUR;l++){
						if(move_allowed[k][l]){
							Pfin = g(l,k);
							sim_chess  = simulate_move(&Pini, &Pfin, E);
							value = min(E->joueur, &sim_chess, depth, list);
							if(value == val_max){
								val_max = rand_val(value,val_max);
								position_move = init_pos2(j,i,l,k);
							}
							else if(value > val_max){
								val_max = value;
								position_move = init_pos2(j,i,l,k);
							}
						}
						move_allowed[k][l] = 0;
					}
				}
			}
		}
	}
	return position_move;
}

Echiquier simulate_move(Position *Pini, Position *Pfin, Echiquier *E){

	enum joueur player = E->joueur;
	enum joueur player_adv;
	enum piececolor color;
	if(player == JOUEUR_BLANC){
		player_adv = JOUEUR_NOIR;
		color = white;
	}
	else{
		player_adv = JOUEUR_BLANC;
		color = black;
	}
	Echiquier simulate_move = *E;
	simulate_move.t[Pini->posy][Pini->posx]=f(pion,nothing,Pini->posx,Pini->posy,0);
 	simulate_move.joueur = player;
	if(E->t[Pini->posy][Pini->posx].t == roi){
		mdfy_king_position(Pini->posy, Pini->posx, player, 0, &simulate_move);
		mdfy_king_position(Pfin->posy, Pfin->posx, player, 1, &simulate_move);
	}
	simulate_move.t[Pfin->posy][Pfin->posx] 
		= f(E->t[Pini->posy][Pini->posx].t,color,Pfin->posx,Pfin->posy,E->t[Pini->posy][Pini->posx].m +1);
	mdfy_pieces_position(Pini->posy, Pini->posx, player, 0, &simulate_move);
	mdfy_pieces_position(Pfin->posy, Pfin->posx, player, 1, &simulate_move);
	mdfy_pieces_position(Pfin->posy, Pfin->posx, player_adv, 0, &simulate_move);
	simulate_move.last_move = g(Pfin->posx,Pfin->posy);
	return simulate_move;
}

int min(enum joueur ia_player, Echiquier *sim_mv, int depth, Historic_elements **list){	//evaluation of the adverse move
	int value, min_val = INT_MAX;
	enum joueur color_adv_player;
	Position Pini,Pfin;
	int mv_allowed[LARGEUR][LARGEUR];
	int *ptr_mv_allowed;
	ptr_mv_allowed = (int *)mv_allowed;
	Echiquier sim_adverse_mv = *sim_mv;
	int i,j,k,l;
	int test_three_plan_chess = test_three_plan(list, sim_mv);
	if(depth == 0 || mat(sim_mv) || pat(sim_mv) || test_three_plan_chess){
		return eval(ia_player, test_three_plan_chess, sim_mv);
	}
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			color_adv_player = convert_piececolor_to_joueur(sim_adverse_mv.t[i][j].c);
			if(color_adv_player == sim_mv->joueur){
				Pini = g(j,i);
				avail_moves[sim_mv->t[i][j].t](&Pini, sim_mv, ptr_mv_allowed);
				for(k=0;k<LARGEUR;k++){
					for(l=0;l<LARGEUR;l++){
						if(mv_allowed[k][l]){
							Pfin = g(l,k);
							sim_adverse_mv = simulate_move(&Pini, &Pfin, sim_mv);
							value = max(ia_player, &sim_adverse_mv, depth - 1, list);
							if(value == min_val){
								min_val = rand_val(value, min_val);
							}
							if(value < min_val){
								min_val = value;
							}
						}
						mv_allowed[k][l] = 0;
					}
				}
			}
		}
	}
	return min_val;
}

int max(enum joueur ia_player, Echiquier *sim_mv, int depth, Historic_elements **list){	//evaluation of the ia move
	int value, max_val = INT_MIN;
	enum joueur color_player;
	Position Pini,Pfin;
	int mv_allowed[LARGEUR][LARGEUR];
	int *ptr_mv_allowed;
	ptr_mv_allowed = (int *)mv_allowed;
	Echiquier sim_new_mv = *sim_mv;
	int i,j,k,l;
	int test_three_plan_chess = test_three_plan(list, sim_mv);
	if(depth == 0 || mat(sim_mv) || pat(sim_mv) || test_three_plan_chess){
		return eval(ia_player, test_three_plan_chess, sim_mv);
	}
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			color_player = convert_piececolor_to_joueur(sim_new_mv.t[i][j].c);
			if(color_player == sim_mv->joueur){
				Pini = g(j,i);
				avail_moves[sim_mv->t[i][j].t](&Pini, sim_mv, ptr_mv_allowed);
				for(k=0;k<LARGEUR;k++){
					for(l=0;l<LARGEUR;l++){
						if(mv_allowed[k][l]){
							Pfin = g(l,k);
							sim_new_mv = simulate_move(&Pini, &Pfin, sim_mv);
							value = min(ia_player, &sim_new_mv, depth - 1, list);
							if(value == max_val){
								max_val = rand_val(value, max_val);
							}
							if(value > max_val){
								max_val = value;
							}
						}
						mv_allowed[k][l] = 0;
					}
				}
			}
		}
	}
	return max_val;
}

int eval(enum joueur ia_player, int test_three_plan_chess, Echiquier *sim_mv){
	enum joueur actual_player;
	int i,j;
	int val_ia = 0;
	int val_adv = 0;
	if(mat(sim_mv)){
		if(sim_mv->joueur == ia_player){
			return INT_MIN;
		}
		else{
			return INT_MAX;
		}
	}
	if(hunt_chess(sim_mv)){
		if(sim_mv->joueur == ia_player){
			return INT_MIN + 2;
		}
		return INT_MAX - 2;
	}
	if(pat(sim_mv) || test_three_plan_chess){
		return INT_MIN +1;
	}
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			actual_player = convert_piececolor_to_joueur(sim_mv->t[i][j].c);
			if(sim_mv->t[i][j].c == nothing){
			}
			else if(actual_player == ia_player){
				switch(sim_mv->t[i][j].t){
					case pion :	val_ia = val_ia + VAL_PION;
					break;
					case tour :	val_ia = val_ia + VAL_TOUR;
					break;
					case fou :	val_ia = val_ia + VAL_FOU;
					break;
					case cavalier :	val_ia = val_ia + VAL_CAVALIER;
					break;
					case dame :	val_ia = val_ia + VAL_DAME;
					break;
					case roi :
					break;
				}
			}
			else if(actual_player != ia_player){
				switch(sim_mv->t[i][j].t){
					case pion :	val_adv = val_adv + VAL_PION;
					break;
					case tour :	val_adv = val_adv + VAL_TOUR;
					break;
					case fou :	val_adv = val_adv + VAL_FOU;
					break;
					case cavalier :	val_adv = val_adv + VAL_CAVALIER;
					break;
					case dame :	val_adv = val_adv + VAL_DAME;
					break;
					case roi :
					break;
				}
			}
		}
	}
	return val_ia - val_adv;
}

int test_three_plan(Historic_elements **list, Echiquier *sim_mv){
	EchiquierSave actual_plan;
	int i,j, r = 0, h_value, occurrence;
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){
			actual_plan.t[i][j] = sim_mv->t[i][j].t;
			actual_plan.c[i][j] = sim_mv->t[i][j].c;
			actual_plan.joueur = sim_mv->joueur;
			actual_plan.en_passant = en_passant_test(sim_mv);
		}
	}
	h_value = h_funct(&actual_plan, sizeof(EchiquierSave)) % SIZE_TAB_HASH;
	if(list[h_value] != NULL){
		occurrence = get_nb_occurrences(&actual_plan, list[h_value]);
	}
	if(occurrence == 3){
		r = 1;
	}
	return r;
}

int rand_val(int value, int val_minmax){
	if(rand()%2){
		return value;
	}
	return val_minmax;
}
