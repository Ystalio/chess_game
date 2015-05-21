#ifndef AVAIL_MOVE_H
#define AVAIL_MOVE_H

#include "Struct_Piece.h"

typedef Tab (*avail_move_func_t)(/*int (*adverse)[LARGEUR], int (*mine_piece)[LARGEUR],*/ Position *Pini, Echiquier *E);

/* ********************************Debug******************************************* */
// Bishop OK
// knight OK
// tower OK
// Queen Ok
// king Ok but little and big castle
// pawn OK but en passant move
/* ******************************************************************************** */
/* *****************prototype for avail_pawn_move********************************** */
Tab avail_pawn_move(/*int (*adverse)[LARGEUR], int (*mine_piece)[LARGEUR],*/ Position *Pini, Echiquier *E);
Tab avail_pawn_attacked(Position *Pini, Echiquier *E);
/* ******************************************************************************** */

/* ******************prototype for avail_bishop_move******************************* */
Tab avail_bishop_move(/*int (*adverse)[LARGEUR], int (*mine_piece)[LARGEUR],*/ Position *Pini, Echiquier *E);
/* ******************************************************************************** */

/* ******************prototype for avail_knight_move******************************* */
Tab avail_knight_move(/*int (*adverse)[LARGEUR], int (*mine_piece)[LARGEUR],*/ Position *Pini, Echiquier *E);
/* ******************************************************************************** */

/* ******************protoype for avail_tower_move********************************* */
Tab avail_tower_move(/*int (*adverse)[8], int (*mine_piece)[8],*/ Position *Pini, Echiquier *E);
/* ******************************************************************************** */

/* ******************prototype for avail_queen_move******************************** */
Tab avail_queen_move(/*int (*adverse)[LARGEUR], int (*mine_piece)[LARGEUR],*/ Position *Pini, Echiquier *E);
/* ******************************************************************************** */

/* *****************prototype for avail_king_move********************************** */
Tab avail_king_move(/*int (*adverse)[LARGEUR], int (*mine_piece)[LARGEUR],*/ Position *Pini, Echiquier *E);
/* ******************************************************************************** */

const static avail_move_func_t avail_moves[] = {
    &avail_pawn_move,
    &avail_tower_move,
    &avail_knight_move,
    &avail_bishop_move,
    &avail_king_move,
    &avail_queen_move
};
#endif // AVAIL_MOVE_H_INCLUDED
