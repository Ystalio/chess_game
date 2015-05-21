#include <stdio.h>
#include <stdlib.h>

#include "platforms.h"
#include "Struct_Piece.h"
#include "avail_move.h"
#include "move_piece.h"
#include "initialisation_chess.h"

//PETIT COMMENTAIRE : bonne chance pour les tableaux... les x et les y font que de changer... c'est la meeeeerde 8D
void print_binary_chess_table(int (*b)[LARGEUR]);
void print_game(Echiquier* E);
void debug(Position2 *init, Echiquier *E);
int mat(Echiquier *E);

int main(int argc, char *argv[])
{
    Echiquier B = E;
    double end_game;
    do{//loop to start a new game
    do{//loop to change player until mat

		term_clear(); // un peu mieux ;)

        print_game(&B);
        if(hunt_chess(&B)){
        printf("Vous etes en echec !");
        }
        move_piece(&B);

       // print_game(&B);

    }while(!mat(&B));
    char *player;
    switch (B.joueur){
        case JOUEUR_BLANC : player = "blanc";
        break;
        case JOUEUR_NOIR : player = "noir";
    }
	term_clear();

    print_game(&B);
    printf("\nJoueur %s, vous etes echec et mat !\n",player);
    getchar();
    B = E;
    do{
        printf("Souhaitez-vous refaire une partie ?\n1. Oui\n2. Non\n\n");
        scanf("%lf",&end_game);
        if(end_game != 1 && end_game != 2){
            printf("taper 1 ou 2.\n");
        }
    }while(end_game != 1 && end_game != 2);
    }while(end_game==1);
    return 0;
}

