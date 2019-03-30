#include "output.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

// const list of params
// "--help" for description of program
const std::string sParam[]{"--help", "--output=console", "--output=text"};

int main(int argc, char const* argv[]) {
    // == EXECUTE HANDLER

    // list of enabled params,
    bool* bParam = new bool[sizeof(sParam)]{false};

    // if program exeuted with params
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            for (unsigned int j = 0; j < sizeof(sParam); j++) {
                if (argv[i] == sParam[j])
                    bParam[j] = true;
            }
        }
    }

    // if user need help
    if (bParam[0]) {
        cout << "CHESSVIZ_9000 RC" << endl;
        cout << "program for check permissibility of chess match" << endl;
        cout << "chessviz [--help] [--output=<console|text>]" << endl;
    }

    board b = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p', 'p', 'p', 'p', 'p',
            'p', 'p', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'P', 'P', 'P',
            'P', 'P', 'P', 'P', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
    };

    // output = text
    if (bParam[1])
        OutputConsole(b);

    if (bParam[2])
        OutputText(b);

    return 0;
}