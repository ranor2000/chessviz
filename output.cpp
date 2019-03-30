#include "output.hpp"

void OutputConsole(const board b) {
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            cout << b.f[i][j] << " ";
        }
        cout << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

void OutputText(const board b) {
    ofstream fout("output.txt");

    for (int i = 0; i < 8; i++) {
        fout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            fout << b.f[i][j] << " ";
        }
        fout << endl;
    }
    fout << "  a b c d e f g h" << endl;
}