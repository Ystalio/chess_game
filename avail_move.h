#ifndef AVAIL_MOVE_H
#define AVAIL_MOVE_H

#include "struct_piece.h"

typedef void (*avail_move_func_t)(Position *Pini, Echiquier *E, int *temp);



void avail_pawn_move(Position *Pini, Echiquier *E, int *temp);
void avail_pawn_attacked(Position *Pini, Echiquier *E, int *temp);
void avail_bishop_move(Position *Pini, Echiquier *E, int *temp);
void avail_knight_move(Position *Pini, Echiquier *E, int *temp);
void avail_tower_move(Position *Pini, Echiquier *E, int *temp);
void avail_queen_move(Position *Pini, Echiquier *E, int *temp);
void avail_king_move(Position *Pini, Echiquier *E, int *temp);


const static avail_move_func_t avail_moves[] = {
    &avail_pawn_move,
    &avail_tower_move,
    &avail_knight_move,
    &avail_bishop_move,
    &avail_king_move,
    &avail_queen_move
};
#endif // AVAIL_MOVE_H_INCLUDED
