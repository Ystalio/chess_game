#include "struct_piece.h"
#include "avail_move.h"

int check_pieces_position(int i, int j, enum piececolor color, Echiquier *chess);

void avail_bishop_move(Position *Pini, Echiquier *E, int *temp){

    int k;
    int a=0,b=0,c=0,d=0; /* a,b,c and d are used to determined
    when to stop the research of an eventual available move */

    int i = Pini->posy;
    int j = Pini->posx;
    enum piececolor color = E->t[i][j].c;
    enum piececolor color_adv;
    if(color == black){
	    color_adv = white;
    }
    else{color_adv = black;}

    for(k=1;k<=LARGEUR;k++){
	    if(i-k >= 0){
		    if(j-k >= 0){
			    if(a==1){
			    }
			    else if(check_pieces_position(i-k,j-k,color,E)){
				    a=1;                            		//
			    }                                   		//
			    else if(check_pieces_position(i-k,j-k,color_adv,E)){// exemple of move tested here :
				    temp[(i-k)*LARGEUR + j-k]=1;       			//        100000
				    a=1;                            		//        010000
			    }                                   		//        001000
			    else if(a!=1){                      		//        000000
				    temp[(i-k)*LARGEUR + j-k]=1;       			//        000000
			    }                                   		//
		    }
		    if(j+k < LARGEUR){
			    if(b==1){
			    }
			    else if(check_pieces_position(i-k,j+k,color,E)){   	//
				    b=1;                            		// exemple of move tested here :
			    }                                   		//        000000
			    else if(check_pieces_position(i-k,j+k,color_adv,E)){//        000000
				    temp[(i-k)*LARGEUR + j+k]=1;       			//        001000
				    b=1;                            		//        010000
			    }                                   		//        100000
			    else if(b!=1){                      		//
				    temp[(i-k)*LARGEUR + j+k]=1;       			//
			    }
		    }
	    }

	    if(i+k < LARGEUR){
		    if(j+k < LARGEUR){
			    if(c==1){
			    }
			    else if(check_pieces_position(i+k,j+k,color,E)){   	//
				    c=1;                            		// exemple of move tested here :
			    }                                   		//      000000
			    else if(check_pieces_position(i+k,j+k,color_adv,E)){//      000000
				    temp[(i+k)*LARGEUR + j+k]=1;       			//      001000
				    c=1;                            		//      000100
			    }                                   		//      000010
			    else if(c!=1){                      		//
				    temp[(i+k)*LARGEUR + j+k]=1;       			//
			    }
		    }
		    if(j-k >= 0){
			    if(d==1){
			    }
			    else if(check_pieces_position(i+k,j-k,color,E)){   	//
				    d=1;                            		// exemple of move tested here :
			    }                                   		//      000010
			    else if(check_pieces_position(i+k,j-k,color_adv,E)){//      000100
				    temp[(i+k)*LARGEUR + j-k]=1;       			//      001000
				    d=1;                            		//      000000
			    }                                   		//      000000
			    else if(d!=1){                      		//
				    temp[(i+k)*LARGEUR + j-k]=1;       			//
			    }
		    }
	    }
	    if(a && b && c && d){break;}
    }
}

int check_pieces_position(int i, int j, enum piececolor color, Echiquier *chess){
	if(color == black){
		return chess->blacks_position[i][j];
	}
	else{
		return chess->whites_position[i][j];
	}
}
