#pragma once
#ifndef _OUTPUT_H

#include <iostream>

using std::cout;
using std::endl;

struct board {
    char f[8][8];
};

void OutputConsole(board b);

// TODO: Text file output
// TODO: HTML file output

#endif