#ifndef INITIALISATION_CHESS_H
#define INITIALISATION_CHESS_H



Echiquier E = {
    .t = {
        {{pion,nothing,.p = {0,0},0},   {pion,nothing,.p = {1,0},0},    {tour,white,.p = {2,0},0},       {pion,nothing,.p = {3,0},0},   {pion,nothing,.p = {4,0},0},     {pion,nothing,.p = {5,0},0},     {pion,nothing,.p = {6,0},0},    {roi,white,.p = {7,0},0}},
        {{pion,nothing,.p = {0,1},0},   {pion,nothing,.p = {1,1},0},        {pion,nothing,.p = {2,1},0},      {pion,nothing,.p = {3,1},0},   {pion,nothing,.p = {4,1},0},    {pion,nothing,.p = {5,1},0},    {pion,nothing,.p = {6,1},0},        {pion,nothing,.p = {7,1},0}},
        {{pion,nothing,.p = {0,2},0}, {pion,nothing,.p = {1,2},0},      {pion,nothing,.p = {2,2},0},    {pion,nothing,.p = {3,2},0}, {pion,nothing,.p = {4,2},0},  {pion,nothing,.p = {5,2},0},  {pion,nothing,.p = {6,2},0},      {pion,nothing,.p = {7,2},0}},
        {{pion,nothing,.p = {0,3},0}, {pion,nothing,.p = {1,3},0},      {pion,nothing,.p = {2,3},0},    {pion,nothing,.p = {3,3},0}, {pion,nothing,.p = {4,3},0},  {pion,nothing,.p = {5,3},0},  {pion,nothing,.p = {6,3},0},      {pion,nothing,.p = {7,3},0}},
        {{pion,nothing,.p = {0,4},0}, {pion,nothing,.p = {1,4},0},      {pion,nothing,.p = {2,4},0},    {pion,nothing,.p = {3,4},0}, {pion,nothing,.p = {4,4},0},  {pion,nothing,.p = {5,4},0},  {pion,nothing,.p = {6,4},0},      {pion,nothing,.p = {7,4},0}},
        {{pion,nothing,.p = {0,5},0}, {pion,nothing,.p = {1,5},0},      {pion,nothing,.p = {2,5},0},    {pion,nothing,.p = {3,5},0}, {pion,nothing,.p = {4,5},0},  {pion,nothing,.p = {5,5},0},  {pion,nothing,.p = {6,5},0},      {pion,nothing,.p = {7,5},0}},
        {{pion,nothing,.p = {0,6},0},   {pion,nothing,.p = {1,6},0},        {pion,nothing,.p = {2,6},0},      {pion,nothing,.p = {3,6},0},   {pion,nothing,.p = {4,6},0},    {pion,nothing,.p = {5,6},0},    {pion,nothing,.p = {6,6},0},        {tour,white,.p = {7,6},0}},
        {{roi,black,.p = {0,7},0},   {pion,nothing,.p = {1,7},0},    {pion,nothing,.p = {2,7},0},       {pion,nothing,.p = {3,7},0},   {pion,nothing,.p = {4,7},0},     {pion,nothing,.p = {5,7},0},     {pion,nothing,.p = {6,7},0},    {pion,nothing,.p = {7,7},0}}
    },
    .joueur = JOUEUR_BLANC,
    .last_move ={0,0},

    .black_king =  {{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {1,0,0,0,0,0,0,0}},

    .white_king =  {{0,0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}},

    .whites_position = {{0,0,1,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0}},

    .blacks_position = {{0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0}},
  };

#endif // INITIALISATION_CHESS_H
