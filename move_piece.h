#ifndef MOVE_PIECE_H_INCLUDED
#define MOVE_PIECE_H_INCLUDED

enum result_mv {valid, chess, bad_mv, bad_color};

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
enum result_mv move_piece(Echiquier *E, Position2 *movement);
int hunt_chess(Echiquier *E);
void print_game(Echiquier* E);
int castle_test(Position *initiale, Position *finale);
#endif // MOVE_PIECE_H_INCLUDED
