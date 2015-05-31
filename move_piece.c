#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Struct_Piece.h"
#include "avail_move.h"
#include "move_piece.h"
#include "platforms.h"

// 4 characters for position and 1 for ending '\0'
#define POSITION_BUFFER_LEN		5


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

void move_piece(Echiquier *E){
    int r=0,end =0; //r necessary to refresh king position if the move is accepted
    char movement[POSITION_BUFFER_LEN];
    Echiquier E_test;
	int correct_move = 0;

	// used to display an example until a valid move is given
	static int example_move = 1;

    E_test = *E; //allow to work on the chess without change the game

	Position initiale;
	Position finale;

    char *joueur_color;
    switch(E->joueur){
        case JOUEUR_BLANC : joueur_color = "[Blanc]";
        break;
        case JOUEUR_NOIR : joueur_color = "[Noir]";
        break;
    }

	while(!correct_move) {

		printf("\n%s Indiquer le deplacement %s: ",joueur_color, example_move ? "(sous la forme 'a2a4' par exemple) " : "");

		if(fgets(movement, POSITION_BUFFER_LEN, stdin) == NULL) {
			// error on stdin or end of input, exit as soon as possible
			//XXX not very clean
			exit(1);
		}
		flush_stdin();

		// check if movement is well formated!
		if(isalpha(movement[0]) && isdigit(movement[1])
				&& isalpha(movement[2]) && isdigit(movement[3]))
		{
			initiale.posx = movement[0] - ( islower(movement[0]) ?  'a' : 'A');
			initiale.posy = 8 - (movement[1] - '0');

			finale.posx = movement[2] - ( islower(movement[2]) ?  'a' : 'A');
			finale.posy = 8 - (movement[3] - '0');

			correct_move = 1;
			example_move = 0;
		}
		else {
			printf("Mouvement invalide (ordre origine puis destination, forme attendue : 'a2a4' ou 'C2C3')\n");
		}
	}


    Piece Pini = E->t[initiale.posy][initiale.posx]; //simplify the expression
    Tab temp;

    switch (E->joueur){
        case JOUEUR_BLANC : E_test.blacks_position[finale.posy][finale.posx]=0;
        break;
        case JOUEUR_NOIR :  E_test.whites_position[finale.posy][finale.posx]=0;
        break;
    }
    temp = avail_moves[Pini.t](&initiale,E); //temp become a Tab with all the available move for the piece given by Pini.t
    //Let's see avail_move.h to understand best
   if(strstr(movement,"e1g1")!= NULL || //this function is necessary to elaborate the castle move
       strstr(movement,"e1c1")!= NULL ||
       strstr(movement,"e8g8")!= NULL ||
       strstr(movement,"e8c8")!= NULL){
       // printf("No bug for now");//debug
       // getchar();//debug
        if(castle_move(&finale,&E_test)){
            temp.t[finale.posy][finale.posx]=1;
        }
    }
   // printf("\n");
    //print_binary_chess_table(temp.t);


    if(verification_player(E,&initiale)){//let's see verification_player.c
        // if the piece asked to be moved is in the right color, here you go
        Piece Pini = E->t[initiale.posy][initiale.posx]; //simplify the expression
        if(temp.t[finale.posy][finale.posx]){//if the move asked by the player is available,you're here

            if(Pini.t==roi){//This condition refresh the king array of the E_test (will be usefull to seek for an eventual chess)
                switch(E->joueur){
                    case JOUEUR_BLANC : E_test.white_king[finale.posy][finale.posx]=1;
                                        E_test.white_king[initiale.posy][initiale.posx]=0;
                                       // printf("Test_king_move\n");//debug
                                        r=1;
                    break;
                    case JOUEUR_NOIR :  E_test.black_king[finale.posy][finale.posx]=1;
                                        E_test.black_king[initiale.posy][initiale.posx]=0;
                                        r=1;
                    break;
                }
            }

            if(Pini.t==pion && E->last_move.posy==initiale.posy){//Necessary to clean the adverse pawn's square when "en passant" occurs
                if(E->t[initiale.posy][initiale.posx+1].t == pion && E->t[initiale.posy][initiale.posx+1].m == 1 && finale.posx == initiale.posx+1){
                    switch (E->joueur){
                    case JOUEUR_BLANC : E_test.t[finale.posy+1][finale.posx]=f(pion,nothing,initiale.posx,initiale.posy+1,0);
                                        E_test.blacks_position[finale.posy+1][finale.posx]=0;
                    break;
                    case JOUEUR_NOIR :  E_test.t[finale.posy-1][finale.posx]=f(pion,nothing,initiale.posx,initiale.posy-1,0);
                                        E_test.whites_position[finale.posy-1][finale.posx]=0;
                    break;
                    }
                }
                else if(E->t[initiale.posy][initiale.posx-1].t == pion && E->t[initiale.posy][initiale.posx-1].m == 1 && finale.posx == initiale.posx-1){
                    switch (E->joueur){
                    case JOUEUR_BLANC : E_test.t[finale.posy+1][finale.posx]=f(pion,nothing,initiale.posx,initiale.posy+1,0);
                                        E_test.blacks_position[finale.posy+1][finale.posx]=0;
                    break;
                    case JOUEUR_NOIR :  E_test.t[finale.posy-1][finale.posx]=f(pion,nothing,initiale.posx,initiale.posy-1,0);
                                        E_test.whites_position[finale.posy-1][finale.posx]=0;
                    break;
                    }
                }

            }

            E_test.t[finale.posy][finale.posx]  = f(Pini.t,Pini.c,finale.posx,finale.posy,Pini.m+1);//refresh E_test piece position
            E_test.t[initiale.posy][initiale.posx]  = f(pion,nothing,initiale.posx,initiale.posy,0);//clean the initial square E_test piece position
            switch (E->joueur){//refresh whites et blacks positions
                case JOUEUR_BLANC :  E_test.whites_position[finale.posy][finale.posx]=1;
                                     E_test.whites_position[initiale.posy][initiale.posx]=0;
                break;
                case JOUEUR_NOIR :   E_test.blacks_position[finale.posy][finale.posx]=1;
                                     E_test.blacks_position[initiale.posy][initiale.posx]=0;
                break;
            }

            if(!hunt_chess(&E_test) && !end){//verification if the move do not place the player in chess, skip this if move already impossible
               // printf("You're not in chess\n");//debug
               // printf("joueur actuel E_test : %d\n",E_test.joueur);//debug
                *E = E_test; //include E_test in E : the piece's movement is accepted
                E->last_move = g(finale.posx,finale.posy);//refresh the last move position
                if((finale.posy==0 || finale.posy==LARGEUR-1) && E_test.t[finale.posy][finale.posx].t==pion){//Activate the promotion
                    int promotion=0;
                    do{
                        printf("\n\nChoisir votre promotion :\n1. Tour.\n2. Cavalier.\n3. Fou.\n4. Dame.\n\nIndiquer le chiffre correspondant à votre choix :");
                        scanf("%d",&promotion);
                        fflush(stdin);
                        if(promotion != 1 && promotion & 2 && promotion != 3 && promotion != 4){
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

                switch (E->joueur){//this switch refresh the whites and blacks' position and switch the player
                    case JOUEUR_BLANC : E->whites_position[initiale.posy][initiale.posx] = 0;
                                        E->whites_position[finale.posy][finale.posx] = 1;
                                        E->blacks_position[finale.posy][finale.posx] = 0;
                                        if(r){
                                            E->white_king[finale.posy][finale.posx]=1;
                                            E->white_king[initiale.posy][initiale.posx]=0;
                                        }
                                        E->joueur=JOUEUR_NOIR;
                    break;
                    case JOUEUR_NOIR  : E->blacks_position[initiale.posy][initiale.posx] = 0;
                                        E->blacks_position[finale.posy][finale.posx] = 1;
                                        E->whites_position[finale.posy][finale.posx] = 0;
                                        if(r){
                                            E->black_king[finale.posy][finale.posx]=1;
                                            E->black_king[initiale.posy][initiale.posx]=0;
                                        }
                                        E->joueur=JOUEUR_BLANC;
                    break;
                }
            }
            else if(!end){//you pass by there if you're in chess
                E_test = *E;
                printf("\nVous ne pouvez jouer ce coup, votre roi serait en echec par ce deplacement.\n");
                getchar();
            }
        }
        else{ //else you're there
            printf("\nCette piece ne peut aller la.\n");
            getchar();

            end=1;
        }

//-----------------------------------------Validation move----------------------------------------------------------------------


//---------------------end validation move------------------------------------------------------------------------

    }
    else{ //else you go there and the programme explain you why you can't (you're trying to move a adverse piece)
        char *p; //Pourquoi ça marche que si c'est un pointeur ?. . .
        switch (E->joueur){
            case JOUEUR_BLANC : p = "blanches";
            break;
            case JOUEUR_NOIR  : p = "noires";
            break;
        }
        printf("Vous ne pouvez deplacer que les pieces %s\n", p);
        getchar();
    }
    //Position2 R = {initiale.posx,initiale.posy,finale.posx,finale.posy,temp}; //instruction for the debug
   // return R;
}
