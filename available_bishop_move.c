#include "Struct_Piece.h"
#include "avail_move.h"

Tab avail_bishop_move(Position *Pini, Echiquier *E){

    int k;
    int a=0,b=0,c=0,d=0; /* a,b,c and d are used to determined
    when to stop the research of an eventual available move */

    Tab avail_move = {.t = {{0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0}
                            }};

    int i = Pini->posy;
    int j = Pini->posx;
    int (*adverse)[LARGEUR];
    int (*mine_piece)[LARGEUR];
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


        for(k=1;k<=LARGEUR;k++){
            if(i-k >= 0){
                if(j-k >= 0){
                    if(a==1){
                    }
                    else if(mine_piece[i-k][j-k]==1){
                        a=1;                            //
                    }                                   //
                    else if(adverse[i-k][j-k]==1){      // exemple of move tested here :
                        avail_move.t[i-k][j-k]=1;       //        100000
                        a=1;                            //        010000
                    }                                   //        001000
                    else if(a!=1){                      //        000000
                        avail_move.t[i-k][j-k]=1;       //        000000
                    }                                   //
                }
                if(j+k < LARGEUR){
                    if(b==1){
                    }
                    else if(mine_piece[i-k][j+k]==1){   //
                        b=1;                            // exemple of move tested here :
                    }                                   //        000000
                    else if(adverse[i-k][j+k]==1){      //        000000
                        avail_move.t[i-k][j+k]=1;       //        001000
                        b=1;                            //        010000
                    }                                   //        100000
                    else if(b!=1){                      //
                        avail_move.t[i-k][j+k]=1;       //
                    }
                }
            }

            if(i+k < LARGEUR){
                if(j+k < LARGEUR){
                    if(c==1){
                    }
                    else if(mine_piece[i+k][j+k]==1){   //
                        c=1;                            // exemple of move tested here :
                    }                                   //      000000
                    else if(adverse[i+k][j+k]==1){      //      000000
                        avail_move.t[i+k][j+k]=1;       //      001000
                        c=1;                            //      000100
                    }                                   //      000010
                    else if(c!=1){                      //
                        avail_move.t[i+k][j+k]=1;       //
                    }
                }
                if(j-k >= 0){
                    if(d==1){
                    }
                    else if(mine_piece[i+k][j-k]==1){   //
                        d=1;                            // exemple of move tested here :
                    }                                   //      000010
                    else if(adverse[i+k][j-k]==1){      //      000100
                        avail_move.t[i+k][j-k]=1;       //      001000
                        d=1;                            //      000000
                    }                                   //      000000
                    else if(d!=1){                      //
                        avail_move.t[i+k][j-k]=1;       //
                    }
                }
            }
            if(a && b && c && d){break;}
        }

return avail_move;
}
