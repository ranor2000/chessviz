
#include "board_print_console.hpp"
#include "board_print_html.hpp"
#include "board_print_text.hpp"

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
                OutputConsoleHelp();
            else if (!strcmp(argv[i], "--output=console"))
                OutputConsoleBoard(b);
            else if (!strcmp(argv[i], "--output=text"))
                OutputFileText(b);
            else if (!strcmp(argv[i], "--output=html"))
                OutputFileHTML(b);
            else
                cout << "Wrong arguments!" << endl;
        }
    else
        OutputConsoleHelp(); // Help output by default

    return 0;
}