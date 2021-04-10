#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void randomtile(int board[4][4]) {
    int empty[16][2];
    int a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) {
                empty[a][0] = i;
                empty[a][1] = j;
                ++a;
            }
        }
    }
    int tile = rand() % a;
    b = rand() % 2;
    if (b == 1)
        board[empty[tile][0]][empty[tile][1]] = 2;
    else
        board[empty[tile][0]][empty[tile][1]] = 4;
}

void printboard(int board[4][4]) {
    for (int i = 0; i < 4; ++i) {
        cout<<"---------"<<endl;
        cout<<'|';
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] != 0)
                cout<<board[i][j]<<'|';
            else
                cout<<' '<<'|';
        }
        cout<<endl;
        cout<<"---------"<<endl;
    }
}
