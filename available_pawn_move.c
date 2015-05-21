#include "Struct_Piece.h"
#include "avail_move.h"

Tab avail_pawn_move(Position *Pini, Echiquier *E){
    int i,j;
    Tab avail_move = {.t =  {{0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0}
                            }};
    i = Pini->posy;
    j = Pini->posx;
    int (*adverse)[LARGEUR]; // array who receive the pieces' position of the adverse
    int (*mine_piece)[LARGEUR]; // array who reveive the pieces' position of the player
    switch(E->t[i][j].c){
        case white : adverse = E->blacks_position;
                     mine_piece = E->whites_position;
        break;
        case black : adverse = E->whites_position;
                     mine_piece = E->blacks_position;
        break;
        case nothing :
        break;
    }

    switch(E->t[Pini->posy][Pini->posx].c){

        case white :
                        if(i-1 >= 0){ //verification if inside of array
                            if(j-1 >= 0){
                                if(adverse[i-1][j-1]==1){avail_move.t[i-1][j-1]=1;} //capture forward on its left
                            }
                            if(adverse[i-1][j]==0 && mine_piece[i-1][j]== 0){avail_move.t[i-1][j]=1;} //move forward by one square
                        }
                        if(i-1 >=0 && j+1 < LARGEUR){ //verification if inside of array
                            if(adverse[i-1][j+1]==1){avail_move.t[i-1][j+1]=1;} //capture forward on its right
                        }
                        if(E->t[Pini->posy][Pini->posx].m == 0 && adverse[i-1][j]==0 && adverse[i-2][j]==0 && mine_piece[i-1][j]== 0 && mine_piece[i-2][j]== 0){
                            avail_move.t[i-2][j]=1; //move forward by two square

                        }
                        if(E->last_move.posx==j+1 && E->last_move.posy==i && E->t[i][j+1].m==1 && E->t[i][j+1].t==black){
                            avail_move.t[i-1][j+1]=1;
                        }
                        if(E->last_move.posx==j-1 && E->last_move.posy==i && E->t[i][j-1].m==1 && E->t[i][j-1].t==black){
                            avail_move.t[i-1][j-1]=1;
                        }
        break;

        case black :
                        if(i+1<LARGEUR){ //verification if inside of array
                            if(adverse[i+1][j]==0 && mine_piece[i+1][j]==0){avail_move.t[i+1][j]=1;} //move forward by one square
                            if(j-1>=0){
                                if(adverse[i+1][j-1]==1){avail_move.t[i+1][j-1]=1;} //capture forward on its left
                            }
                        }
                        if(i+1<LARGEUR && j+1<LARGEUR){ //verification if inside of array
                            if(adverse[i+1][j+1]==1){avail_move.t[i+1][j+1]=1;} //capture forward on its right
                        }
                        if(E->t[Pini->posy][Pini->posx].m==0 && adverse[i+1][j]==0 && adverse[i+2][j]==0 && mine_piece[i+1][j]==0 && mine_piece[i+2][j]==0){
                            avail_move.t[i+2][j]=1; //move forward by two square
                        }
                        if(E->last_move.posx==j+1 && E->last_move.posy==i && E->t[i][j+1].m==1 /*&& E->t[i][j+1].t== white*/){//if black instead of black it works...
                            avail_move.t[i+1][j+1]=1;
                        }
                        if(E->last_move.posx==j-1 && E->last_move.posy==i && E->t[i][j-1].m==1 /*&& E->t[i][j-1].t== white*/){//if black instead of black it works...
                            avail_move.t[i+1][j-1]=1;
                        }
        break;
        case nothing :
        break;
    }
    return avail_move;
}

