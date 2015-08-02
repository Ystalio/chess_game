#include "struct_piece.h"
#include "avail_move.h"

Tab avail_queen_move(/*int (*adverse)[8], int (*mine_piece)[8],*/ Position *Pini, Echiquier *E){
    int i,j;
    Tab temp_bishop = avail_bishop_move(/*adverse,mine_piece,*/Pini,E);
    Tab temp_tower  = avail_tower_move(/*adverse,mine_piece,*/Pini,E);

    Tab avail_move = {.t = {{0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0}
                            }};

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            avail_move.t[i][j]= temp_bishop.t[i][j] || temp_tower.t[i][j];
        }
    }
    return avail_move;
}
