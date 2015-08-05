#include "struct_piece.h"
#include "avail_move.h"

void avail_queen_move(Position *Pini, Echiquier *E, int *temp){
	avail_tower_move(Pini, E, temp);
	avail_bishop_move(Pini, E, temp);
}
