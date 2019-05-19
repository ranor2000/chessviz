#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include <iostream>

using namespace std;

// lower to upper const
constexpr int LTU = 'a' - 'A';

// none is spec color for empty cell
enum COLOR {
    none = -1,
    black = 0,
    white = 1,
};

enum FIGURE {
    king = 'k',
    queen = 'q',
    rook = 'r',
    knight = 'n',
    bishop = 'b',
    pawn = 'p'
};

// 0,0 - is empty sqare (initialized)
struct Square {
    COLOR color = none;
    FIGURE figure = king;
};

typedef Square Board[8][8];

// chess board is 8x8 sqaures
// format of data is [x][y]
//[x]|
// 7 |8 r n b q k b n r
// 6 |7 p p p p p p p p
// 5 |6
// 4 |5
// 3 |4
// 2 |3
// 1 |2 P P P P P P P P
// 0 |1 R N B Q K B N R
//   |  A B C D E F G H
//   +------------------
//      0 1 2 3 4 5 6 7 [y]

void ResetBoard(Board& board);

#endif // BOARD_H