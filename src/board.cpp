#include "board.hpp"

void ResetBoard(Board& board) {
    // White figures initialize
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 2; j++)
            board[j][i].color = white;
    // pawns
    for (int i = 0; i < 8; i++)
        board[1][i].figure = pawn;
    // king
    board[0][4].figure = king;
    // queen
    board[0][3].figure = queen;
    // bishops
    board[0][2].figure = bishop;
    board[0][5].figure = bishop;
    // knights
    board[0][1].figure = knight;
    board[0][6].figure = knight;
    // rookies
    board[0][0].figure = rook;
    board[0][7].figure = rook;

    // Black figures initialize
    for (int i = 0; i < 8; i++)
        for (int j = 6; j < 8; j++)
            board[j][i].color = black;
    // pawns
    for (int i = 0; i < 8; i++)
        board[6][i].figure = pawn;
    // king
    board[7][4].figure = king;
    // queen
    board[7][3].figure = queen;
    // bishops
    board[7][2].figure = bishop;
    board[7][5].figure = bishop;
    // knights
    board[7][1].figure = knight;
    board[7][6].figure = knight;
    // rookies
    board[7][0].figure = rook;
    board[7][7].figure = rook;
}