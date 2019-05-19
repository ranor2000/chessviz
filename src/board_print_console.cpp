#include "board_print_console.hpp"

void OutputConsoleBoard(const Board board) {
    cout << endl;
    for (int i = 7; i >= 0; i--) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            if (board[i][j].color == none)
                cout << "  ";
            else
                cout << char((int)board[i][j].figure
                             - LTU * (int)board[i][j].color)
                     << " ";
        }
        cout << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

void OutputConsoleHelp() {
    cout << "Programm : chessviz" << endl;
    cout << "Author   : Alexandr Dolbilov" << endl;
    cout << "How to   : ./chessviz [file] [keys]" << endl;
    cout << "Keys : " << endl;
    cout << "--help - to see that help page " << endl;
    cout << "--output=<console|text|html> - select type of output" << endl;
}