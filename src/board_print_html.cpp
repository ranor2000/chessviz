#include "board_print_html.hpp"

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

void OutputFileHTML(const Board board) {
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
    for (int i = 7; i >= 0; i--) {
        fout << "<tr>" << endl;
        for (int j = 0; j < 8; j++) {
            fout << "<td>";

            // empty
            if (board[i][j].color == none) {
                fout << "</td>";
                continue;
            }

            // color detecting
            fout << "<span class=\"";
            if (board[i][j].color == black)
                fout << "black ";
            else
                fout << "white ";

            // figure detect
            switch (board[i][j].figure) {
            case king:
                fout << "king";
                break;
            case queen:
                fout << "queen";
                break;
            case bishop:
                fout << "bishop";
                break;
            case pawn:
                fout << "pawn";
                break;
            case knight:
                fout << "knight";
                break;
            case rook:
                fout << "rook";
                break;
            default:
                break;
            }
            fout << "\"></span>";
            fout << "</td>";
        }
        fout << "</tr>";
    }
    fout << "</body>" << endl;
    fout.close();
}