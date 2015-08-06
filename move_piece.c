#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct_piece.h"
#include "avail_move.h"
#include "move_piece.h"
#include "platforms.h"

// 4 characters for position and 1 for ending '\0'
#define POSITION_BUFFER_LEN		5

Echiquier simulate_move(Position *Pini, Position *Pfin, Echiquier *E);

struct Piece f(int a,int b,int c,int d,int e){  //fonction affectation de valeurs à une structure
	struct Piece r = {a,b,{c,d},e};
	return r;
}


struct Position g(int a,int b){ //Same, used for record the position of the piece
	struct Position r = {a,b};
	return r;
}

int castle_move(Position *finale,Echiquier *E);
char* strstr(const char* chaine, const char* chaineARechercher);

enum result_mv move_piece(Echiquier *E, Position2 *movement){
	//	int /*r=0,*/end =0; //r necessary to refresh king position if the move is accepted
	Echiquier E_test;
	E_test = *E; //allow to work on the chess without change the game

	Position initiale = g(movement->posx1, movement->posy1) ;
	Position finale = g(movement->posx2, movement->posy2);

	Piece Pini = E->t[initiale.posy][initiale.posx]; //simplify the expression
	int temp[LARGEUR][LARGEUR];
	memset(*temp, 0, sizeof(temp));
	int *ptr_temp;
	ptr_temp = (int *)temp;

	avail_moves[Pini.t](&initiale,E, ptr_temp); //temp become an array with all the available move for the piece given by Pini.t
	if(castle_test(&initiale, &finale)){ 
		if(castle_move(&finale,&E_test)){
			temp[finale.posy][finale.posx]=1;
		}
	}
	if(verification_player(E,&initiale)){
		// if the piece asked to be moved is in the right color, here you go
		if(temp[finale.posy][finale.posx]){//if the move asked by the player is available,you're here

			E_test = simulate_move(&initiale, &finale, E);

			if(!hunt_chess(&E_test)/* && !end*/){//verification if the move do not place the player in chess, skip this if move already impossible
				*E = E_test; 
				if((finale.posy==0 || finale.posy==LARGEUR-1) && E_test.t[finale.posy][finale.posx].t==pion){//Activate the promotion
					int promotion=0;
					do{
						printf("\n\nChoisir votre promotion :\n");
						printf("1. Tour.\n");
						printf("2. Cavalier.\n");
						printf("3. Fou.\n");
						printf("4. Dame.\n");
						printf("\nIndiquer le chiffre correspondant à votre choix :");
						scanf("%d",&promotion);
						fflush(stdin);
						if(promotion != 1 && promotion != 2 && promotion != 3 && promotion != 4){
							printf("\n\nChoisis 1,2,3 ou 4 ! T'es pas une lumière toi n'est-ce pas ?\n");
							promotion=0;
						}
					}while(promotion==0);
					switch(promotion){
						case 1 : E->t[finale.posy][finale.posx]  = f(tour,Pini.c,finale.posx,finale.posy,Pini.m);
							 break;
						case 2 : E->t[finale.posy][finale.posx]  = f(cavalier,Pini.c,finale.posx,finale.posy,Pini.m);
							 break;
						case 3 : E->t[finale.posy][finale.posx]  = f(fou,Pini.c,finale.posx,finale.posy,Pini.m);
							 break;
						case 4 : E->t[finale.posy][finale.posx]  = f(dame,Pini.c,finale.posx,finale.posy,Pini.m);
							 break;
					}
				}
				if(E->joueur == JOUEUR_BLANC){
					E->joueur = JOUEUR_NOIR;
				}
				else{
					E->joueur = JOUEUR_BLANC;
				}
				return valid;
			}
			else /*if(!end)*/{//you pass by there if you're in chess
				return chess;
				/*	E_test = *E;
					printf("\nVous ne pouvez jouer ce coup, votre roi serait en echec par ce deplacement.\n");
					getchar();*/
			}
		}
		else{ //else you're there
			return bad_mv;
			/*printf("\nCette piece ne peut aller la.\n");
			  getchar();*/

			//end=1;
		}
	}
	else{ //else you go there and the programme explain you why you can't (you're trying to move an adverse piece)
		return bad_color;
		/*char *p; 
		  switch (E->joueur){
		  case JOUEUR_BLANC : p = "blanches";
		  break;
		  case JOUEUR_NOIR  : p = "noires";
		  break;
		  case NOTHING :
		  break;
		  }
		  printf("Vous ne pouvez deplacer que les pieces %s\n", p);
		  getchar();*/
	}
}

int castle_test(Position *initiale, Position *finale){
	if(initiale->posx == 4){
		if(initiale->posy == 7 && finale->posy == 7){
			if(finale->posx == 6 || finale->posx == 2){
				return 1;
			}
		}
		else if(initiale->posy == 0 && finale->posy == 0){
			if(finale->posx == 6 || finale->posx == 2){
				return 1;
			}
		}
	}
	return 0;
}
