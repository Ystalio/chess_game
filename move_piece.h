#ifndef MOVE_PIECE_H_INCLUDED
#define MOVE_PIECE_H_INCLUDED

typedef struct Position2{
    int posx1;
    int posy1;
    int posx2;
    int posy2;
    Tab avail;
}Position2;

struct Position g(int a,int b);
struct Piece f(int a,int b,int c,int d,int e);
int verification_player(Echiquier *E, Position *init);
void move_piece(Echiquier *E);
int hunt_chess(Echiquier *E);
void print_game(Echiquier* E);

#endif // MOVE_PIECE_H_INCLUDED
