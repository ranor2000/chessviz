#include "output.hpp"
#include <iostream>
#include <string.h>

int main(int argc, char const* argv[]) {
    // TODO: normal board initialize
    board b = {
            'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 'p', 'p', 'p', 'p', 'p',
            'p', 'p', 'p', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'P', 'P', 'P',
            'P', 'P', 'P', 'P', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
    };

    // basic execute handler

    if (argc > 1)
        for (int i = 1; i < argc; i++) {
            // check for "--help"

            if (!strcmp(argv[i], "--help"))
                OutputHelp();
            if (!strcmp(argv[i], "--output=console"))
                OutputConsole(b);
            if (!strcmp(argv[i], "--output=text"))
                OutputText(b);
            if (!strcmp(argv[i], "--output=html"))
                OutputHTML(b);
        }

    return 0;
}