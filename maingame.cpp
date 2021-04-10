#include <iostream>
#include <cstdlib>
#include "board.h"

using namespace std;

int main() {
    srand(time(NULL));
    int gameboard[4][4] ={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    randomtile(gameboard);
    randomtile(gameboard);
    printboard(gameboard);
    return 0;
}
