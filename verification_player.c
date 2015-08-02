#include "struct_piece.h"

int verification_player(Echiquier *E, Position *init){
    int r;
    int color_player = E->joueur;
    int color_piece  = E->t[init->posy][init->posx].c;

    if(color_player == color_piece){
        r = 1;
    }
    else{r = 0;}
    return r;
}
