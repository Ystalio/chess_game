#include <stdio.h>
#include "struct_piece.h"
#include "avail_move.h"


struct Castle c(int a,int b,int c){//fonction affectation de valeurs à une structure Castle
    struct Castle r = {a,b,c};
    return r;
}

int no_chess_castle(Position *Pini,Echiquier *E);
int hunt_chess(Echiquier *E);

Castle avail_castle_move(Position *Pini, Echiquier *E){

    int i = Pini->posy;
    int j = Pini->posx;
    int k;
    Castle castle = {0,1,1};
    if(E->t[j][i].m==0){
            if(E->t[0][i].m==0){
                for(k=1;k<j;k++){
                    printf("\n%d\n",k);//debug
                    if(E->t[i][k].c != nothing){
                        printf("\nok1\n");//debug
                        printf("%d,%d",i,k);//debug

                        castle.big_castle = 0;
                    }
                }
                if(castle.big_castle){
                    if(no_chess_castle(Pini,E)){
                        printf("\nok2\n");
                        castle.no_castle=1;
                    }
                }
            }
            if(E->t[7][i].m==0){
                for(k=LARGEUR-1;k>j;k--){
                    printf("\n%d\n",k);//debug
                    if(E->t[i][k].c != nothing){
                        printf("\nok3\n");//debug
                        printf("%d,%d",i,k);//debug
                        castle.castle = 0;
                    }
                }
                if(castle.castle){
                    if(no_chess_castle(Pini,E)){
                        printf("\nok4\n");
                        castle.no_castle = 1;
                    }
                }
            }
        }
return castle;
}

int no_chess_castle(Position *Pini,Echiquier *E){
    Echiquier E_test = *E;
    int i,j,r = 0;
    i = Pini->posy;
    j = Pini->posx;
    if(E_test.joueur== JOUEUR_BLANC){
        E_test.white_king[i][j-3]=1;
        E_test.white_king[i][j-2]=1;
        E_test.white_king[i][j-1]=1;
    }
    else {
        E_test.black_king[i][j-3]=1;
        E_test.black_king[i][j-2]=1;
        E_test.black_king[i][j-1]=1;
    }
    if(hunt_chess(&E_test)){r = 1;}

    return r;
}
