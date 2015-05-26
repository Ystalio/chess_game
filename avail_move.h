#ifndef AVAIL_MOVE_H
#define AVAIL_MOVE_H

#include "Struct_Piece.h"

typedef Tab (*avail_move_func_t)( Position *Pini, Echiquier *E);



Tab avail_pawn_move(Position *Pini, Echiquier *E);
Tab avail_pawn_attacked(Position *Pini, Echiquier *E);
Tab avail_bishop_move(Position *Pini, Echiquier *E);
Tab avail_knight_move(Position *Pini, Echiquier *E);
Tab avail_tower_move(Position *Pini, Echiquier *E);
Tab avail_queen_move(Position *Pini, Echiquier *E);
Tab avail_king_move(Position *Pini, Echiquier *E);


const static avail_move_func_t avail_moves[] = {
    &avail_pawn_move,
    &avail_tower_move,
    &avail_knight_move,
    &avail_bishop_move,
    &avail_king_move,
    &avail_queen_move
};
#endif // AVAIL_MOVE_H_INCLUDED
