#include <iostream>
using namespace std;


bool fullboard(int gamedata[4][4]) {

	int a = 1; // 1 means full, 0 means having empty block

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (gamedata[i][j] == 0) //having empty block
			{
				 a = 0;
			}
		}
	}
	if (a==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool gameover(int gamedata[4][4])
{
	int fail = 1; //1 means not having 2 near same numbers

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (gamedata[i + 1][j] == gamedata[i][j])
			{
				fail = 0;
			}

		}

	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gamedata[i][j] == gamedata[i][j+1])
			{
				fail = 0;
			}

		}

	}



	if (fullboard(gamedata) && fail == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool have2048(int gamedata[4][4])	// to check if there is 2048 in the board
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (gamedata[i][j] == 2048)
				return true;
		}
	}
	return false;
}
