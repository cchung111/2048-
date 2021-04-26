#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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
    int tile = rand() % a;  //get a random empty tile
    b = rand() % 2;
    if (b == 1)
        board[empty[tile][0]][empty[tile][1]] = 2;  //make tile become 2 or 4
    else
        board[empty[tile][0]][empty[tile][1]] = 4;
}

void printboard(int board[4][4])    //print out the board
{
    cout<<"--------------------"<<endl;
    for (int i = 0; i < 4; ++i) {
        cout<<'|';
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] != 0)
                cout<<setw(4)<<board[i][j]<<'|';
            else
                cout<<"    "<<'|';
        }
        cout<<endl;
        cout<<"--------------------"<<endl;
    }
}

void initialboard(int gamedata[4][4])   //initialize the board
{
	for (int i; i < 4; i++)
	{
		for (int j; j < 4; j++)
			gamedata[i][j] = 0;
	}
}
