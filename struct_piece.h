#ifndef STRUCT_PIECE_H
#define STRUCT_PIECE_H

#define SIZE_TAB_HASH 1000
#define LARGEUR     8
#define FALSE       0
#define TRUE        1

enum piecetype {pion = 0,tour,cavalier,fou,roi,dame};
enum piececolor{black = 0,white,nothing};
enum joueur{JOUEUR_NOIR = 0,JOUEUR_BLANC, NOTHING};


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

typedef struct All_pieces{
/*--------black pieces---------*/
	Position bp1;
	Position bp2;	
	Position bp3;
	Position bp4;
	Position bp5;
	Position bp6;
	Position bp7;
	Position bp8;
	Position bt1;
	Position bt2;
	Position bc1;
	Position bc2;
	Position bf1;
	Position bf2;
	Position bd;
	Position br;
/*-------white  pieces---------*/
	Position wp1;
	Position wp2;
	Position wp3;
	Position wp4;
	Position wp5;
	Position wp6;
	Position wp7;
	Position wp8;
	Position wt1;
	Position wt2;
	Position wc1;
	Position wc2;
	Position wf1;
	Position wf2;
	Position wd;
	Position wr;
}All_pieces;

void modification_tab(Position Pini, Position Pend, Tab *r);//save piece movement

void print_binary_chess_table(int *b);
#endif // STRUCT_PIECE_H
