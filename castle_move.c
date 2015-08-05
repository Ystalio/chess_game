#include <stdio.h>
#include <stdlib.h>

#include "struct_piece.h"
#include "avail_move.h"
#include "move_piece.h"

void mdfy_pieces_position(int i, int j, enum piececolor color, int value, Echiquier *chess);
void mdfy_king_position(int i, int j, enum joueur player, int value, Echiquier *chess);

int castle_move(Position *finale,Echiquier *E){
	int r=1, posy;
	Echiquier E_test_castle = *E;

	enum joueur player = E->joueur;
	enum piececolor color;
	if(player == JOUEUR_BLANC){
		color = white;
		posy = 7;
	}
	else{
		color = black;
		posy = 0;
	}
	if(finale->posy!=posy){r=0;}//if the movement asked is on the top of the chess, castle is impossible
	else if(finale->posx==2){
		if(E_test_castle.t[posy][1].c==nothing &&
				E_test_castle.t[posy][2].c==nothing &&
				E_test_castle.t[posy][3].c==nothing){
			if(E_test_castle.t[posy][0].m==0 && E_test_castle.t[posy][4].m==0){//if tower and king have never move both
				mdfy_king_position(posy, 1, player, 1, &E_test_castle);
				mdfy_king_position(posy, 2, player, 1, &E_test_castle);
				mdfy_king_position(posy, 3, player, 1, &E_test_castle);
				if(hunt_chess(&E_test_castle)){r=0;}
				//if only one square between tower and king (including the king's square) then castle is not possible
				else{
					E->t[posy][0]= f(pion,nothing,0,posy,0);
					E->t[posy][3]=f(tour,color,3,posy,1);
					mdfy_pieces_position(posy, 0, color, 0, E);
					mdfy_pieces_position(posy, 3, color, 1, E);
				}
			}
			else{
				r=0;
			}
		}
		else{
			r=0;
		}
	}
	else if(finale->posx==6){
		if(E_test_castle.t[posy][5].c==nothing &&
				E_test_castle.t[posy][6].c==nothing){
			if(E_test_castle.t[posy][7].m==0 && E_test_castle.t[posy][4].m==0){//if tower and king have never move both
				mdfy_king_position(posy, 5, player, 1, &E_test_castle);
				mdfy_king_position(posy, 6, player, 1, &E_test_castle);
				if(hunt_chess(&E_test_castle)){
					r=0;
				}//if only one square between tower and king (including the king's square) then castle is not possible
				else{
					E->t[posy][7]= f(pion,nothing,7,posy,0);
					E->t[posy][5]=f(tour,color,5,posy,1);
					mdfy_pieces_position(posy, 7, color, 0, E);
					mdfy_pieces_position(posy, 5, color, 1, E);
				}
			}
			else{
				r=0;
			}
		}
		else{
			r=0;
		}
	}
	return r;
}
