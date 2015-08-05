#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_piece.h"
#include "avail_move.h"

enum joueur convert_piececolor_to_joueur(enum piececolor piececolor);

int hunt_chess(Echiquier *E){//if the position on the E chess is a chess position for the actual player, then hunt_chess return 1
	int i,j,r=0;
	int adverse_position[LARGEUR][LARGEUR];
	memset(*adverse_position, 0, sizeof(adverse_position));
	Position initiale;
	int *ptr_adverse_position;
	ptr_adverse_position = (int *)adverse_position;
	enum joueur adverse_color_player;
	enum joueur color_piece;
	if(E->joueur == JOUEUR_BLANC){
		adverse_color_player = JOUEUR_NOIR;
	}
	else{
		adverse_color_player = JOUEUR_BLANC;
	}
	for(i=0;i<LARGEUR;i++){//all these loops are necessary to put at 1 all the adverse_position squares where the king would be in chess
		for(j=0;j<LARGEUR;j++){
			color_piece = convert_piececolor_to_joueur(E->t[i][j].c);
			if(color_piece == adverse_color_player){
				initiale.posx=j;
				initiale.posy=i;
				if(E->t[i][j].t != pion){
					avail_moves[E->t[i][j].t](&initiale,E, ptr_adverse_position);
				}
				else{
					avail_pawn_attacked(&initiale,E, ptr_adverse_position);
				}
			}
		}
	}
	for(i=0;i<LARGEUR;i++){
		for(j=0;j<LARGEUR;j++){

			switch(E->joueur){
				case JOUEUR_BLANC : if(adverse_position[i][j] && E->white_king[i][j]){
							    r=1;
						    }
						    break;
				case JOUEUR_NOIR :  if(adverse_position[i][j] && E->black_king[i][j]){
							    r=1;
						    }
						    break;
				case NOTHING :
						    break;
			}

			if(r==1){break;}
		}
	}
	return r;
}
