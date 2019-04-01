#include "output.hpp"

void OutputHelp() {
    cout << "Programm : chessviz" << endl;
    cout << "Author   : Alexandr Dolbilov" << endl;
    cout << "How to   : ./chessviz [file] [keys]" << endl;
    cout << "Keys : " << endl;
    cout << "--help - to see that help page " << endl;
    cout << "--output=<console|text|html> - select type of output" << endl;
}

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
    fout.close();
}
/// const for HTML output
/// TODO: (may be?) make moar accurate output from prefab file
const string Doctype = "<!DOCTYPE HTML>";
const string Meta = "<meta charset =\"utf-8\">";
const string Title = "<title>chessviz</title>";
const string Style
        = {"<style type=\"text/css\">\n\
    \ttable.chessboard {\n\
    \t border: 5px solid #333;\n\
    \t border-collapse: collapse;\n\
    \t height: 320px;\n\
    \t margin: 20px;\n\
    \t width: 320px;\n\
    }\n\
    \ttable.chessboard caption {\n\
      \t text-align: left;\n\
    \t}\n\
    \ttable.chessboard td {\n\
    \t background-color: #fff;\n\
    \t font-size: 25px;\n\
    \t height: 40px;\n\
    \t text-align: center;\n\
    \t vertical-align: middle;\n\
    \t width: 40px;\n\
    }\n\
    \t table.chessboard tr:nth-child(odd) td:nth-child(even),\n\
    \t table.chessboard tr:nth-child(even) td:nth-child(odd) {\n\
    \t background-color: #999;\n\
    \t}\n\n\
    \ttable.chessboard .white.king:before   { content: \"\\2654\"; }\n\
    \ttable.chessboard .white.queen:before  { content: \"\\2655\"; }\n\
    \ttable.chessboard .white.rook:before   { content: \"\\2656\"; }\n\
    \ttable.chessboard .white.bishop:before { content: \"\\2657\"; }\n\
    \ttable.chessboard .white.knight:before { content: \"\\2658\"; }\n\
    \ttable.chessboard .white.pawn:before   { content: \"\\2659\"; }\n\n\
    \ttable.chessboard .black.king:before   { content: \"\\265A\"; }\n\
    \ttable.chessboard .black.queen:before  { content: \"\\265B\"; }\n\
    \ttable.chessboard .black.rook:before   { content: \"\\265C\"; }\n\
    \ttable.chessboard .black.bishop:before { content: \"\\265D\"; }\n\
    \ttable.chessboard .black.knight:before { content: \"\\265E\"; }\n\
    \ttable.chessboard .black.pawn:before   { content: \"\\265F\"; }\n\
  </style>\n"};

const string a = "0";

void OutputHTML(const board b) {
    ofstream fout("output.html");

    /// initial file text
    fout << Doctype << endl;
    fout << "<head>" << endl;
    fout << Meta << endl;
    fout << Title << endl;
    fout << Style << endl;
    fout << "</head>" << endl;
    fout << endl;
    fout << "<body>" << endl;
    fout << "<table class=\"chessboard\">" << endl;
    /// TODO: list of turns
    fout << "<caption>TODO: list of turns</caption>" << endl;
    /// board output
    for (int i = 0; i < 8; i++) {
        fout << "<tr>" << endl;
        for (int j = 0; j < 8; j++) {
            fout << "<td>";
            /// figure output here
            switch (b.f[i][j]) {
            /// BLACK
            case 'p':
                fout << "<span class=\"black pawn\"></span>";
                break;
            case 'r':
                fout << "<span class=\"black rook\"></span>";
                break;
            case 'n':
                fout << "<span class=\"black knight\"></span>";
                break;
            case 'b':
                fout << "<span class=\"black bishop\"></span>";
                break;
            case 'q':
                fout << "<span class=\"black queen\"></span>";
                break;
            case 'k':
                fout << "<span class=\"black king\"></span>";
                break;
            /// WHITE
            case 'P':
                fout << "<span class=\"white pawn\"></span>";
                break;
            case 'R':
                fout << "<span class=\"white rook\"></span>";
                break;
            case 'N':
                fout << "<span class=\"white knight\"></span>";
                break;
            case 'B':
                fout << "<span class=\"white bishop\"></span>";
                break;
            case 'Q':
                fout << "<span class=\"white queen\"></span>";
                break;
            case 'K':
                fout << "<span class=\"white king\"></span>";
                break;
            }
            fout << "</td>" << endl;
        }
        fout << "</tr>" << endl;
    }
    fout << "</body>" << endl;
    fout.close();
}
