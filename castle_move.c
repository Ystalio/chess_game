#include <stdio.h>
#include <stdlib.h>

#include "Struct_Piece.h"
#include "avail_move.h"
#include "move_piece.h"


int castle_move(Position *finale,Echiquier *E){
    int r=1;
    Echiquier E_test_castle = *E;
   // printf("castle_move");//debug
   // getchar();//debug
    switch (E->joueur){
        case JOUEUR_BLANC :
          //  printf("Joueur blanc");//debug
          //  getchar();
            if(finale->posy!=7){r=0;printf("good y position\n");/*debug*/}//if the movement asked is on the top of the chess, castle is impossible

            else if(finale->posx==2){
               // printf("good x=2 position");//debug
               // getchar();
                if(E_test_castle.t[7][1].c==nothing &&
                   E_test_castle.t[7][2].c==nothing &&
                   E_test_castle.t[7][3].c==nothing){
                   //   printf("no piece between");//debug
                   //   getchar();//debug
                    if(E_test_castle.t[7][0].m==0 && E_test_castle.t[7][4].m==0){//if tower and king have never move both
                        E_test_castle.white_king[7][1]=1;
                        E_test_castle.white_king[7][2]=1;
                        E_test_castle.white_king[7][3]=1;
                   //     printf("never moved\n");//debug
                   //     print_binary_chess_table(E_test_castle.white_king);//debug
                   //     getchar();//debug
                        if(hunt_chess(&E_test_castle)){r=0;}//if only one square between tower and king (including the king's square) then castle is not possible
                        else{
                   //   printf("move tower\n");//debug
                            E->t[7][0]= f(pion,nothing,7,7,0);
                            E->t[7][3]=f(tour,white,5,7,1);
                            E->whites_position[7][7]=0;
                            E->whites_position[7][5]=1;
                        }
                    }
                    else{r=0;}
                }
                else{r=0;
                }
            }
            else if(finale->posx==6){
               // printf("good x=6 position\n");//debug
                if(E_test_castle.t[7][5].c==nothing &&
                   E_test_castle.t[7][6].c==nothing){
                    //    printf("No piece between\n");//debug
                    if(E_test_castle.t[7][7].m==0 && E_test_castle.t[7][4].m==0){//if tower and king have never move both
                    //    printf("never moved\n");//debug
                        E_test_castle.white_king[7][5]=1;
                        E_test_castle.white_king[7][6]=1;
                        if(hunt_chess(&E_test_castle)){r=0;}//if only one square between tower and king (including the king's square) then castle is not possible
                        else{
                        E->t[7][7]= f(pion,nothing,7,7,0);
                        E->t[7][5]=f(tour,white,5,7,1);
                        E->whites_position[7][7]=0;
                        E->whites_position[7][5]=1;
                        }
                    }
                    else{r=0;}
                }
                else{r=0;}
            }
        break;
        case JOUEUR_NOIR :
            if(finale->posy!=0){r=0;}//the same but for the black player
            else if(finale->posx==2){
                if(E_test_castle.t[0][1].c==nothing &&
                   E_test_castle.t[0][2].c==nothing &&
                   E_test_castle.t[0][3].c==nothing){
                    if(E_test_castle.t[0][0].m==0 && E_test_castle.t[0][4].m==0){//if tower and king have never move both
                        E_test_castle.black_king[0][1]=1;
                        E_test_castle.black_king[0][2]=1;
                        E_test_castle.black_king[0][3]=1;
                        if(hunt_chess(&E_test_castle)){r=0;}//if only one square between tower and king (including the king's square) then castle is not possible
                        else{
                            E->t[0][0]= f(pion,nothing,0,0,0);
                            E->t[0][3]=f(tour,black,3,0,1);
                            E->blacks_position[0][0]=0;
                            E->blacks_position[0][3]=1;
                        }
                    }
                    else{r=0;}
                }
                else{r=0;}
            }
            else if(finale->posx==6){
                if(E_test_castle.t[0][5].c==nothing &&
                   E_test_castle.t[0][6].c==nothing){
                    if(E_test_castle.t[0][7].m==0 && E_test_castle.t[0][4].m==0){//if tower and king have never move both
                        E_test_castle.black_king[0][5]=1;
                        E_test_castle.black_king[0][6]=1;
                        if(hunt_chess(&E_test_castle)){r=0;}//if only one square between tower and king (including the king's square) then castle is not possible
                        else{
                            E->t[0][7]= f(pion,nothing,7,0,0);
                            E->t[0][5]=f(tour,black,5,0,1);
                            E->blacks_position[0][7]=0;
                            E->blacks_position[0][5]=1;
                        }
                    }
                    else{r=0;}
                }
                else{r=0;}
            }
        break;
    }
    return r;
}
