#include "board_print_text.hpp"

void OutputFileText(const board b) {
    ofstream fout("output.txt");

    for (int i = 0; i < 8; i++) {
        fout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            fout << b.f[i][j] << " ";
        }
        fout << endl;
    }
    fout << "  a b c d e f g h" << endl;
    fout.close();
}