#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "platforms.h"
#include "struct_piece.h"
#include "move_piece.h"
#include "allocation_mem.h"

#define POSITION_BUFFER_LEN	5

Position2 get_joueur_mvt(Historic_elements **list, Echiquier *E){
	char movement[POSITION_BUFFER_LEN];
	int correct_move=0;
	static int example_move=1;
	char *joueur_color;
	Position initiale, finale;
	switch(E->joueur){
		case JOUEUR_BLANC : joueur_color = "[Blanc]"; 
				    break;
		case JOUEUR_NOIR : joueur_color = "[Noir]";
				   break;
		case NOTHING :
				   break;
	}
	while(!correct_move){
		printf("\n%s Indiquer le deplacement %s : ",joueur_color, example_move ? "(sous la forme 'a2a4' par exemple) " : "");
		if(fgets(movement, POSITION_BUFFER_LEN, stdin) == NULL){
			exit(1);
		}
		flush_stdin();
		if(isalpha(movement[0]) && isdigit(movement[1]) && isalpha(movement[2]) && isdigit(movement[3])){
			initiale.posx = movement[0] - ( islower(movement[0]) ? 'a' : 'A');
			initiale.posy = 8 - (movement[1] - '0');
			finale.posx = movement[2] - ( islower(movement[2]) ? 'a' : 'A');
			finale.posy = 8 - (movement[3] - '0');
			correct_move = 1;
			example_move = 0;
		}
		else {
			printf("Mouvement invalide (ordre origine puis distination, forme attendue : 'a2a4' ou 'C2C3')\n");
		}
	}
	Position2 mvt_ini_fin = {initiale.posx,initiale.posy,finale.posx,finale.posy};
	return mvt_ini_fin;
}
