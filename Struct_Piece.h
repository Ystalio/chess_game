#ifndef STRUCT_PIECE_H
#define STRUCT_PIECE_H

#define LARGEUR     8
#define FALSE       0
#define TRUE        1

enum piecetype {pion = 0,tour,cavalier,fou,roi,dame};
enum piececolor{black = 0,white,nothing};
enum joueur{JOUEUR_NOIR = 0,JOUEUR_BLANC};


typedef struct Castle{
    int no_castle;
    int castle;
    int big_castle;
}Castle;

typedef struct Position{
    int posx;
    int posy;
}Position;

typedef struct Piece
{
    enum piecetype t;
    enum piececolor c;
    Position p;
    int m; //count the number of movement for the piece, usefull for pawn's move at the beggening, en passant,
    //and for the little and big castle
}Piece;



typedef struct Tab //usefull to return an array
{
    int t[LARGEUR][LARGEUR];
}Tab;

typedef struct Echiquier
{
    Piece t[LARGEUR][LARGEUR];
    enum joueur joueur;  // a qui de jouer.
    Position last_move;//save the last move (the square at 1 is the last move) usefull for the "en passant" move
    int black_king[LARGEUR][LARGEUR];
    int white_king[LARGEUR][LARGEUR];
    int whites_position[LARGEUR][LARGEUR];
    int blacks_position[LARGEUR][LARGEUR];
}Echiquier;


void modification_tab(Position Pini, Position Pend, Tab *r);//save piece movement

void print_binary_chess_table(int (*b)[LARGEUR]);
#endif // STRUCT_PIECE_H
