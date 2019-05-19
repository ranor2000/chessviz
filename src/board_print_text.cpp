#include "board_print_text.hpp"

void OutputFileText(const Board board) {
    ofstream fout("output.txt");

    for (int i = 7; i >= 0; i--) {
        fout << i + 1 << " ";
        for (int j = 0; j < 8; j++) {
            if (board[i][j].color == none)
                fout << "  ";
            else
                fout << char((int)board[i][j].figure
                             - LTU * (int)board[i][j].color)
                     << " ";
        }
        fout << endl;
    }
    fout << "  a b c d e f g h" << endl;
    fout.close();
}