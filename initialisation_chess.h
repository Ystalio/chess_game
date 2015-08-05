#ifndef INITIALISATION_CHESS_H
#define INITIALISATION_CHESS_H



Echiquier E = {
    .t = {
        {{tour,black,.p = {0,0},0},   {cavalier,black,.p = {1,0},0},    {fou,black,.p = {2,0},0},       {dame,black,.p = {3,0},0},   {roi,black,.p = {4,0},0},     {fou,black,.p = {5,0},0},     {cavalier,black,.p = {6,0},0},    {tour,black,.p = {7,0},0}},
        {{pion,black,.p = {0,1},0},   {pion,black,.p = {1,1},0},        {pion,black,.p = {2,1},0},      {pion,black,.p = {3,1},0},   {pion,black,.p = {4,1},0},    {pion,black,.p = {5,1},0},    {pion,black,.p = {6,1},0},        {pion,black,.p = {7,1},0}},
        {{pion,nothing,.p = {0,2},0}, {pion,nothing,.p = {1,2},0},      {pion,nothing,.p = {2,2},0},    {pion,nothing,.p = {3,2},0}, {pion,nothing,.p = {4,2},0},  {pion,nothing,.p = {5,2},0},  {pion,nothing,.p = {6,2},0},      {pion,nothing,.p = {7,2},0}},
        {{pion,nothing,.p = {0,3},0}, {pion,nothing,.p = {1,3},0},      {pion,nothing,.p = {2,3},0},    {pion,nothing,.p = {3,3},0}, {pion,nothing,.p = {4,3},0},  {pion,nothing,.p = {5,3},0},  {pion,nothing,.p = {6,3},0},      {pion,nothing,.p = {7,3},0}},
        {{pion,nothing,.p = {0,4},0}, {pion,nothing,.p = {1,4},0},      {pion,nothing,.p = {2,4},0},    {pion,nothing,.p = {3,4},0}, {pion,nothing,.p = {4,4},0},  {pion,nothing,.p = {5,4},0},  {pion,nothing,.p = {6,4},0},      {pion,nothing,.p = {7,4},0}},
        {{pion,nothing,.p = {0,5},0}, {pion,nothing,.p = {1,5},0},      {pion,nothing,.p = {2,5},0},    {pion,nothing,.p = {3,5},0}, {pion,nothing,.p = {4,5},0},  {pion,nothing,.p = {5,5},0},  {pion,nothing,.p = {6,5},0},      {pion,nothing,.p = {7,5},0}},
        {{pion,white,.p = {0,6},0},   {pion,white,.p = {1,6},0},        {pion,white,.p = {2,6},0},      {pion,white,.p = {3,6},0},   {pion,white,.p = {4,6},0},    {pion,white,.p = {5,6},0},    {pion,white,.p = {6,6},0},        {pion,white,.p = {7,6},0}},
        {{tour,white,.p = {0,7},0},   {cavalier,white,.p = {1,7},0},    {fou,white,.p = {2,7},0},       {dame,white,.p = {3,7},0},   {roi,white,.p = {4,7},0},     {fou,white,.p = {5,7},0},     {cavalier,white,.p = {6,7},0},    {tour,white,.p = {7,7},0}}
    },
    .joueur = JOUEUR_BLANC,
    .last_move ={0,0},

    .black_king =  {{0,0,0,0,1,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}},

    .white_king =  {{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0}},

    .whites_position = {{0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1}},

    .blacks_position = {{1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0}},
  };

struct All_pieces{
/*--------black pieces---------*/
	Position bp1	= {0,1};
	Position bp2	= {1,1};
	Position bp3	= {2,1};
	Position bp4	= {3,1};
	Position bp5	= {4,1};
	Position bp6	= {5,1};
	Position bp7	= {6,1};
	Position bp8	= {7,1};
	Position bt1	= {0,0};
	Position bt2	= {7,0};
	Position bc1	= {1,0};
	Position bc2	= {6,0};
	Position bf1	= {2,0};
	Position bf2	= {5,0};
	Position bd	= {3,0};
	Position br	= {4,0};
/*-------white  pieces---------*/
	Position wp1	= {0,6};
	Position wp2	= {1,6};
	Position wp3	= {2,6};
	Position wp4	= {3,6};
	Position wp5	= {4,6};
	Position wp6	= {5,6};
	Position wp7	= {6,6};
	Position wp8	= {7,6};
	Position wt1	= {0,7};
	Position wt2	= {7,7};
	Position wc1	= {1,7};
	Position wc2	= {6,7};
	Position wf1	= {2,7};
	Position wf2	= {5,7};
	Position wd	= {3,7};
	Position wr	= {4,7};
}All_pieces;
#endif // INITIALISATION_CHESS_H
