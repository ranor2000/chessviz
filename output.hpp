#pragma once
#ifndef _OUTPUT_H

#include <fstream>
#include <iostream>

using namespace std;

struct board {
    char f[8][8];
};

void OutputConsole(const board b);

void OutputText(const board b);

// TODO: HTML file output

#endif