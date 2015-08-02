#include <stdio.h>
#include <stdlib.h>

#include "struct_piece.h"
#include "avail_move.h"

int hunt_chess(Echiquier *E){//if the position on the E chess is a chess position, then hunt_chess return 1
    int i,j,k,l,r=0;
    Tab adverse_position = {.t =   {{0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0},
                                    {0,0,0,0,0,0,0,0}
                                    }};
    Tab temp;
    Position initiale;
    int adverse_color_player = !E->joueur;
        for(i=0;i<LARGEUR;i++){//all these loops are necessary to put at 1 all the adverse_position squares where the king would be in chess
            for(j=0;j<LARGEUR;j++){
                if(E->t[i][j].c==(adverse_color_player)){
                    initiale.posx=j;
                    initiale.posy=i;
                    if(E->t[i][j].t != pion){
                        temp = avail_moves[E->t[i][j].t](&initiale,E);
                       // printf("\n---------%d_adverse_position----------\n",E->t[i][j].t);
                       // print_binary_chess_table(temp.t);//for debug
                       // printf("\n------------------------------------------\n");
                    }
                    else{
                        temp = avail_pawn_attacked(&initiale,E);
                    }

                    for(k=0;k<LARGEUR;k++){
                        for(l=0;l<LARGEUR;l++){
                            adverse_position.t[k][l]= adverse_position.t[k][l] || temp.t[k][l];

                            temp.t[k][l]=0;
                        }
                    }
                }
            }
        }

       /* printf("\n---------adverse_position_attack----------\n");   //
        print_binary_chess_table(adverse_position.t);               //for debug
        printf("\n------------------------------------------\n");   //
        printf("\n------------adverse_position--------------\n");
        print_binary_chess_table(E->blacks_position);
        printf("\n------------------------------------------\n");   //debug*/
        for(i=0;i<LARGEUR;i++){
            for(j=0;j<LARGEUR;j++){

                switch(E->joueur){
                    case JOUEUR_BLANC : if(adverse_position.t[i][j] && E->white_king[i][j]){
                                        r=1;
                                        }
                    break;
                    case JOUEUR_NOIR :  if(adverse_position.t[i][j] && E->black_king[i][j]){
                                        r=1;
                                        }
                    break;
		    case NOTHING :
		    break;
                }

                if(r==1){break;}
            }
        }
    return r;
}
