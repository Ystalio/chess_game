#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

#include "Struct_Piece.h"
#include "avail_move.h"
#include "move_piece.h"

int mat(Echiquier *E){
    int i,j,k,l;
   // int count_piece =0; //count the number of piece who've been tested wether mat // made some mistake, we'll see later
    int r=1;
    Tab available_move;
    Position Pini;
    Echiquier E_mat_test;
    E_mat_test = *E;
    switch (E->joueur){
        case JOUEUR_NOIR :
            for(i=LARGEUR-1;i>=0;i--){
                for(j=LARGEUR-1;j>=0;j--){
                    if(E->blacks_position[i][j]==1){
                        Pini = g(j,i);
                        available_move = avail_moves[E->t[i][j].t](&Pini,E);
                        for(k=0;k<LARGEUR;k++){
                            for(l=0;l<LARGEUR;l++){
                                E_mat_test = *E;
                                if(available_move.t[k][l]==1){
                                    E_mat_test.t[i][j] = f(pion,nothing,j,i,0);
                                    E_mat_test.t[k][l] = f(E->t[i][j].t,black,l,k,E->t[i][j].m+1);
                                    E_mat_test.joueur = JOUEUR_NOIR;
                                    E_mat_test.last_move = g(l,k);
                                    if(E->t[i][j].t==roi){
                                        E_mat_test.black_king[i][j]=0;
                                        E_mat_test.black_king[k][l]=1;
                                    }
                                    E_mat_test.blacks_position[i][j]=0;
                                    E_mat_test.blacks_position[k][l]=1;
                                    E_mat_test.whites_position[k][l]=0;

                                    if(!hunt_chess(&E_mat_test)){
                                        r=0;
                                    }
                                }
                        }
                    }
                }
            }
        }
        break;
        case JOUEUR_BLANC :
            for(i=0;i<LARGEUR;i++){
                for(j=0;j<LARGEUR;j++){
                    if(E->whites_position[i][j]==1){
                        Pini = g(j,i);
                        available_move = avail_moves[E->t[i][j].t](&Pini,E);
                        for(k=0;k<LARGEUR;k++){
                            for(l=0;l<LARGEUR;l++){
                                E_mat_test = *E;
                                if(available_move.t[k][l]==1){
                                    E_mat_test.t[i][j] = f(pion,nothing,j,i,0);
                                    E_mat_test.t[k][l] = f(E->t[i][j].t,white,l,k,E->t[i][j].m+1);
                                    E_mat_test.joueur = JOUEUR_BLANC;
                                    E_mat_test.last_move = g(l,k);
                                    if(E->t[i][j].t==roi){
                                        E_mat_test.white_king[i][j]=0;
                                        E_mat_test.white_king[k][l]=1;
                                    }
                                    E_mat_test.whites_position[i][j]=0;
                                    E_mat_test.whites_position[k][l]=1;
                                    E_mat_test.blacks_position[k][l]=0;
                                   /* printf("\ntest : %d,%d,%d,%d\n",i,j,k,l);
                                    printf("\n-----------E_mat_test-----------\n");
                                    print_game(&E_mat_test);
                                    printf("\n--------------------------------\n");
                                    printf("\njoueur : %d\n",E_mat_test.joueur);
                                    printf("\nlast move : (%d,%d)\n",E_mat_test.last_move.posx,E_mat_test.last_move.posy);
///all this just for debug          printf("------------------whites_position--------------\n");
                                    print_binary_chess_table(E_mat_test.whites_position);
                                    printf("\n------------------Blacks_position--------------\n");
                                    print_binary_chess_table(E_mat_test.blacks_position);
                                    printf("\n---------------black_king----------------\n");
                                    print_binary_chess_table(E_mat_test.black_king);
                                    getchar();*/
                                    if(!hunt_chess(&E_mat_test)){r=0;}
                                }
                            }

                          /*printf("\n-----------E_mat_test==*E-----------\n");
//for debug                 print_game(&E_mat_test);
                            printf("\n--------------------------------\n");*/

                        }
                    }
                }
            }
        break;
    }
    if(!hunt_chess(E)){r=0;}
    return r;
}
