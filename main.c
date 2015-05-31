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
void ia_player(Echiquier *E);

int mat(Echiquier *E);


int main(int argc, char *argv[])
{
    Echiquier B = E;
    double end_game;
    char ia;
    do{//loop to start a new game
        do{

            printf("Voulez-vous jouer contre l'I.A ?\n1. Oui\n2. Non\n");
            scanf("%c",&ia);
            flush_stdin();
            if(ia!='1' && ia!='2'){
                printf("Veuillez repondre exclusivement par '1' ou '2'.\n");
            }
        }while(ia!='1' && ia!='2');

    char color_player;
    if(ia=='1'){
        do{
            color_player=0;
            printf("Choisissez votre couleur : 1.Blanc 2.Noir :\n");
            scanf("%c",&color_player);
            flush_stdin();
            if(color_player!='1' && color_player!='2'){
                printf("Veuillez repondre exclusivement par '1' ou '2'.\n");
            }
        }while(color_player!='1' && color_player!='2');
    }
    do{//loop to change player each round until mat

		term_clear(); // un peu mieux ;)

        print_game(&B);
        if(hunt_chess(&B)){
        printf("Vous etes en echec !\n");
        }
        if(ia=='1'){
            switch (B.joueur){
                case JOUEUR_BLANC : if(color_player=='2'){
                                        ia_player(&B);
                                    }

                break;
                case JOUEUR_NOIR : if(color_player=='1'){
                                        ia_player(&B);
                                   }
            }
        }
        else{
            move_piece(&B);
        }
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
        flush_stdin();
        if(end_game != 1 && end_game != 2){
            printf("taper 1 ou 2.\n");
        }
    }while(end_game != 1 && end_game != 2);
    }while(end_game==1);
    return 0;
}

