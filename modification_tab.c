#include "Struct_Piece.h"
#include "avail_move.h"
/*
This function allow to refresh the bitboards, when the movement is done.
*/
void modification_tab(Position Pini, Position Pend, Tab *r){
    r->t[Pini.posx][Pini.posy]=0;
    r->t[Pend.posx][Pend.posy]=1;

}
