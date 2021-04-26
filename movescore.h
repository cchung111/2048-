#include<iostream>
using namespace std;

void move(int gamedata[4][4], int & s) 	// move the tiles and combine the tiles if any according to player's input and update the score, input: board array, score, player input in the function, output: updated array and score 
{
	char i;
	cout<<"Please enter w/a/s/d to move the tiles: ";
	//read in a char  "a"left "s"down "d"right "w"up
	cin >> i;

	if (i == 'w')//move up
	{

		//i for row, j for column
		for (int j = 0; j < 4; j++)
		{
			int run = 4;
			for (int i = 0; i < 4; i++)//move all zero numbers to the bottom
			{
				if (gamedata[i][j] == 0)
				{
					run--;

					for (int k = i + 1; k < 4; k++)
					{
						gamedata[k - 1][j] = gamedata[k][j];

						gamedata[k][j] = 0;
					}
					i--;
					if (run == 0)
					{
						break;
					}
				}

			}
		}



		for (int j = 0; j < 4; j++)
		{

			for (int i = 0; i < 3; i++)
			{
				if (gamedata[i][j] == 0)//first number is a zero, break and run next colunm
				{
					break;
				}
				else//if not a zero, check whether it is equals to next number,
				{
					if (gamedata[i][j] == gamedata[i + 1][j])
					{
						gamedata[i][j] = (gamedata[i + 1][j] * 2);
						s += gamedata[i][j];
						if (i==2)
						{
							gamedata[3][j] = 0;
						}
						else
						{
							for (int k = i + 1; k < 3; k++)
							{
								gamedata[k][j] = gamedata[k + 1][j];

								gamedata[k + 1][j] = 0;
							}
						}

					}
				}
			}

		}
	}
	else if (i == 's')//move down
	{

		//i for row, j for column
		for (int j = 0; j < 4; j++)
		{
			int run = 4;
			for (int i = 3; i >= 0; i--)//move all zero numbers to the top
			{
				if (gamedata[i][j] == 0)
				{
					run--;

					for (int k = i - 1; k >= 0; k--)
					{
						gamedata[k + 1][j] = gamedata[k][j];

						gamedata[k][j] = 0;
					}
					i++;
					if (run == 0)
					{
						break;
					}
				}

			}
		}



		for (int j = 0; j < 4; j++)
		{

			for (int i = 3; i > 0; i--)
			{
				if (gamedata[i][j] == 0)
				{
					break;
				}
				else
				{
					if (gamedata[i][j] == gamedata[i - 1][j])
					{
						gamedata[i][j] = (gamedata[i - 1][j] * 2);
						s += gamedata[i][j];
						if (i==1)
						{
							gamedata[0][j] = 0;
						}
						else
						{
							for (int k = i - 1; k > 0; k--)
							{
								gamedata[k][j] = gamedata[k - 1][j];

								gamedata[k - 1][j] = 0;
							}
						}

					}
				}
			}

		}
	}
	else if (i == 'a')
	{

		//i for row, j for column
		for (int i = 0; i < 4; i++)
		{
			int run = 4;
			for (int j = 0; j < 4; j++)//move all zero numbers to the bottom
			{
				if (gamedata[i][j] == 0)
				{
					run--;

					for (int k = j + 1; k < 4; k++)
					{
						gamedata[i][k-1] = gamedata[i][k];

						gamedata[i][k] = 0;
					}
					j--;
					if (run == 0)
					{
						break;
					}
				}

			}
		}



		for (int i = 0; i < 4; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				if (gamedata[i][j] == 0)//first number is a zero, break and run next colunm
				{
					break;
				}
				else//if not a zero, check whether it is equals to next number,
				{
					if (gamedata[i][j] == gamedata[i][j+1])
					{
						gamedata[i][j] = (gamedata[i][j+1] * 2);
						s += gamedata[i][j];
						if (j==2)
						{
							gamedata[i][3] = 0;
						}
						else
						{
							for (int k = j + 1; k < 3; k++)
							{
								gamedata[i][k] = gamedata[i][k + 1];

								gamedata[i][k + 1] = 0;
							}
						}

					}
				}
			}

		}
	}
	else if (i == 'd')//move down
	{

	//i for row, j for column
	for (int i = 0; i < 4; i++)
	{
		int run = 4;
		for (int j = 3; j >= 0; j--)
		{
			if (gamedata[i][j] == 0)
			{
				run--;

				for (int k = j - 1; k >= 0; k--)
				{
					gamedata[i][k+1] = gamedata[i][k];

					gamedata[i][k] = 0;
				}
				j++;
				if (run == 0)
				{
					break;
				}
			}

		}
	}


	for (int i = 0; i < 4; i++)
	{

		for (int j = 3; j > 0; j--)
		{
			if (gamedata[i][j] == 0)
			{
				break;
			}
			else
			{
				if (gamedata[i][j] == gamedata[i][j-1])
				{
					gamedata[i][j] = (gamedata[i][j-1] * 2);
					s += gamedata[i][j];
					if (j==1)
					{
						gamedata[i][0] = 0;
					}
					else
					{
						for (int k = j - 1; k > 0; k--)
						{
							gamedata[i][k] = gamedata[i][k - 1];

							gamedata[i][k - 1] = 0;
						}
					}

				}
			}
		}

	}
	}

}

bool boardchange(int gamedata[4][4], int temp[4][4]) {

	int a = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			if (temp[i][j]!=gamedata[i][j])
			{

				 a = 1;

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
