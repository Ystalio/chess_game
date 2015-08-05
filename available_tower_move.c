#include "struct_piece.h"
#include "avail_move.h"

int check_pieces_position(int i, int j, enum piececolor color, Echiquier *chess);

void avail_tower_move(Position *Pini, Echiquier *E, int *temp){

	int i,j,k,a=0,b=0,c=0,d=0;
	i = Pini->posy;
	j = Pini->posx;
	enum piececolor color = E->t[i][j].c;
	enum piececolor color_adv;
	if(color ==white){
		color_adv = black;
	}
	else{
		color_adv = white;
	}

	for(k=1;k<=LARGEUR;k++){
		if(j-k >= 0){
			if(a==1){
			}
			else if(check_pieces_position(i, j-k, color, E) == 1){ 		//
				a=1;                          				//
			}                                 				//
			else if(check_pieces_position(i, j-k, color_adv, E) == 1){      //
				temp[i*LARGEUR + j-k]=1;       					//        000000
				a=1;                          				//        000000
			}                                 				//        111000
			else if(a!=1){                    				//        000000
				temp[i*LARGEUR + j-k]=1;       					//        000000
			}                                 				//
		}
		if(j+k < LARGEUR){
			if(b==1){
			}
			else if(check_pieces_position(i, j+k, color, E) == 1){          //
				b=1;                            			//
			}                                   				//        000000
			else if(check_pieces_position(i, j+k, color_adv, E) == 1){      //        000000
				temp[i*LARGEUR + j+k]=1;         				//        001111
				b=1;                            			//        000000
			}                                   				//        000000
			else if(b!=1){                      				//
				temp[i*LARGEUR + j+k]=1;         				//
			}
		}


		if(i+k < LARGEUR){
			if(c==1){
			}
			else if(check_pieces_position(i+k, j, color, E) == 1){          //
				c=1;                            			//
			}                                   				//      000000
			else if(check_pieces_position(i+k, j, color_adv, E) == 1){      //      000000
				temp[(i+k)*LARGEUR + j]=1;         				//      001000
				c=1;                            			//      001000
			}                                   				//      001000
			else if(c!=1){                      				//
				temp[(i+k)*LARGEUR + j]=1;         				//
			}
		}

		if(i-k>=0){
			if(d==1){
			}
			else if(check_pieces_position(i-k, j, color, E) == 1){          //
				d=1;                            			//
			}                                   				//      001000
			else if(check_pieces_position(i-k, j, color_adv, E) == 1){      //      001000
				temp[(i-k)*LARGEUR + j]=1;         				//      001000
				d=1;                            			//      000000
			}                                   				//      000000
			else if(d!=1){                      				//
				temp[(i-k)*LARGEUR + j]=1;         				//
			}
		}

		if(a && b && c && d){break;}
	}
}
