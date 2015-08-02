#include <stdlib.h>
#include <stdio.h>
#include "platforms.h"
#include "struct_piece.h"
#include "allocation_mem.h"
#include "initialisation_chess.h"
#include "avail_move.h"
#include "move_piece.h"
#include "choice_player.h"

#define JOUEUR_BUFFER_LEN 		2
#define SIZE_TAB_HASH			1000

void print_game(Echiquier* E);
int mat(Echiquier *E);
int pat(Echiquier *E);
int three_plan_chess(Historic_elements **list,Echiquier *E);


int main(int argc, char *argv[])
{
	Position2 mvt_j1, mvt_j2;
	Echiquier B = E;
	double end_game;
	enum joueur_type joueur1, joueur2;
	do{//loop to start a new game
		int test_three_plan_chess;
		int i = 0;
		Historic_elements *list[SIZE_TAB_HASH]={NULL};
		do{
			char joueur1_temp[JOUEUR_BUFFER_LEN], joueur2_temp[JOUEUR_BUFFER_LEN];
			printf("\nChoisissez qui est le joueur blanc parmi ces choix :\n");
			printf("1. joueur\n2. ia\n");
			if(fgets(joueur1_temp,sizeof(joueur1_temp),stdin)==NULL){
				fprintf(stderr,"error fgets");
				exit(1);
			}
			flush_stdin();
			printf("\nChoisissez qui est le joueur noir parmi ces choix :\n");
			printf("1. joueur\n2. ia\n");
			if(fgets(joueur2_temp,sizeof(joueur2_temp),stdin)==NULL){
				fprintf(stderr,"error fgets");
				exit(1);
			}
			flush_stdin();

			joueur1 = strtol(joueur1_temp,NULL,10);
			joueur2 = strtol(joueur2_temp,NULL,10);

			if((joueur1 != 1 && joueur1 != 2) || (joueur2 != 1 && joueur2 != 2)){
				printf("Veuillez repondre exclusivement par '1' ou '2'.\n");
			}
		}while((joueur1 != 1 && joueur1 != 2) || (joueur2 != 1 && joueur2 != 2));

		do{//loop to change player each round until mat
			int right_move = 0;
			term_clear(); // un peu mieux ;)

			print_game(&B);
			if(hunt_chess(&B)){
				printf("Vous etes en echec !\n");
			}
			switch(B.joueur){
				case JOUEUR_BLANC : mvt_j1 = get_mvt[joueur1](list, &B); 
						    right_move =  move_piece(&B,&mvt_j1);
						    break;
				case JOUEUR_NOIR : mvt_j2 = get_mvt[joueur2](list, &B); 
						   right_move = move_piece(&B,&mvt_j2);
						   break;
				case NOTHING :
						   break;
			}
			if(right_move){
				test_three_plan_chess = three_plan_chess(list, &B);
			}
			else{
				test_three_plan_chess = 0;
			}
		}while(!mat(&B) && !pat(&B) && !test_three_plan_chess);

		char *player;
		switch (B.joueur){
			case JOUEUR_BLANC : player = "blanc";
					    break;
			case JOUEUR_NOIR : player = "noir";
					   break;
			case NOTHING :
					   break;
		}
		term_clear();

		print_game(&B);
		if(mat(&B)){
			printf("\nJoueur %s, vous etes echec et mat !\n",player);
		}
		else if(pat(&B)){
			printf("\nEchec et pat ! La partie est nulle.\n");
		}
		else if(test_three_plan_chess){
			printf("\nIl y a eu trois etats de jeu identique. La partie est donc nulle.\n");
		}
		B = E;
		do{
			printf("Souhaitez-vous refaire une partie ?\n1. Oui\n2. Non\n\n");
			scanf("%lf",&end_game);
			flush_stdin();
			if(end_game != 1 && end_game != 2){
				printf("taper 1 ou 2.\n");
			}
		}while(end_game != 1 && end_game != 2);
		for(i=0;i<SIZE_TAB_HASH;i++){
			Historic temp = list[i];
			while(temp != NULL){
				Historic swap = temp->next;
				free(temp);	
				temp = swap;
			}
		}
	}while(end_game==1);
	return 0;
}
