#include "You.h"
#include<iostream>
#include<windows.h>

using namespace std;

void Plus(You& you )
{
	if (you.youfield[you.x + 1][you.y - 1] == '#')
	{
		you.youfield[you.x + 1][you.y - 1] = 'O';
	}
	if (you.youfield[you.x + 1][you.y + 1] == '#')
	{
		you.youfield[you.x + 1][you.y + 1] = 'O';
	}
	if (you.youfield[you.x - 1][you.y - 1] == '#')
	{
		you.youfield[you.x - 1][you.y - 1] = 'O';
	}
	if (you.youfield[you.x - 1][you.y + 1] == '#')
	{
		you.youfield[you.x - 1][you.y + 1] = 'O';
	}
}

void FillYou(You & you, int const size)
{
		you.youfield[0][0] = ' ';
		you.battlefield[0][0] = ' ';
		for (int i = 1, x = 48, letter = 65; i < size; i++, letter++, x++)
		{
			you.youfield[0][i] = (int)letter;
			you.battlefield[0][i] = (int)letter;
			you.youfield[i][0] = x;
			you.battlefield[i][0] = x;
		}
		for (int i = 1; i < size; i++)
		{
			for (int j = 1; j < size; j++)
			{
				you.youfield[i][j] = '#';
				you.battlefield[i][j] = '#';
			}
		}
}

void Ranking(You & you, int const size)
{
	int num_attempts = 15;
	int way = 1 + rand() % 4;
	int savex = you.x;
	int savey = you.y;
	
	for (int i = 0; i < Torpedo_Boats ; i++)
	{
		you.x = 1 + rand() % 10;
		you.y = 1 + rand() % 10;
		if (you.youfield[you.x][you.y] == '#')
		{
			you.youfield[you.x][you.y] = '1';
			if (you.youfield[you.x - 1][you.y] == '#')
			{
				you.youfield[you.x - 1][you.y] = 'O';
			}
			if (you.youfield[you.x + 1][you.y] == '#')
			{
				you.youfield[you.x + 1][you.y] = 'O';
			}
			if (you.youfield[you.x][you.y - 1] == '#')
			{
				you.youfield[you.x][you.y - 1] = 'O';
			}
			if (you.youfield[you.x][you.y + 1] == '#')
			{
				you.youfield[you.x][you.y + 1] = 'O';
			}
			Plus(you);
		}
		else
		{
			num_attempts--;
			i--;
		}
	}
	for (int i = 0; i < Destroyers ; i++)
	{
		you.x = 1 + rand() % 10;
		you.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		if (you.youfield[you.x][you.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				you.youfield[you.x][you.y] = '2';
				if (way == Up && you.youfield[you.x - 1][you.y] == '#')
				{
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x--;
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
					you.youfield[you.x][you.y] = '2';
				}
				else if (way == Doun && you.youfield[you.x + 1][you.y] == '#')
				{
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x++;
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
					you.youfield[you.x][you.y] = '2';
				}
				else if (way == Left && you.youfield[you.x][you.y + 1] == '#')
				{
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					Plus(you);
					you.y++;
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
					you.youfield[you.x][you.y] = '2';
				}
				else if (way == Right && you.youfield[you.x][you.y - 1] == '#')
				{
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.y--;
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					Plus(you);
					j++;
					you.youfield[you.x][you.y] = '2';
				}
				else
				{
				num_attempts--;
					way = 1 + rand() % 4;
				}
			}
		}
		else
		{
		num_attempts--;
			i--;
		}
	}
	for (int i = 0; i < Cruisers ; i++)
	{
		you.x = 1 + rand() % 10;
		you.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = you.x;
		savey = you.y;
		if (you.youfield[you.x][you.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				you.youfield[you.x][you.y] = '3';
				if (way == Up && you.youfield[you.x - 1][you.y] == '#' && you.youfield[you.x - 2][you.y] == '#')
				{
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x--;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x--;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else if (way == Doun && you.youfield[you.x + 1][you.y] == '#' && you.youfield[you.x + 2][you.y] == '#')
				{
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x++;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x++;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else if (way == Left && you.youfield[you.x][you.y + 1] == '#' && you.youfield[you.x][you.y + 2] == '#')
				{
				if (you.youfield[you.x - 1][you.y] == '#')
				{
					you.youfield[you.x - 1][you.y] = 'O';
				}
				if (you.youfield[you.x + 1][you.y] == '#')
				{
					you.youfield[you.x + 1][you.y] = 'O';
				}
				if (you.youfield[you.x][you.y - 1] == '#')
				{
					you.youfield[you.x][you.y - 1] = 'O';
				}
				Plus(you);
					you.y++;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					Plus(you);
					you.y++;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else if (way == Right && you.youfield[you.x][you.y - 1] == '#' && you.youfield[you.x][you.y - 2] == '#')
				{
				if (you.youfield[you.x - 1][you.y] == '#')
				{
					you.youfield[you.x - 1][you.y] = 'O';
				}
				if (you.youfield[you.x + 1][you.y] == '#')
				{
					you.youfield[you.x + 1][you.y] = 'O';
				}
				if (you.youfield[you.x][you.y + 1] == '#')
				{
					you.youfield[you.x][you.y + 1] = 'O';
				}
				Plus(you);
					you.y--;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					Plus(you);
					you.y--;
					you.youfield[you.x][you.y] = '3';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else
				{
				num_attempts--;
				way = 1 + rand() % 4;
				}
			}
		}
		else
		{
		num_attempts--;
			i--;
		}
	}
	for (int i = 0; i < Battleship ; i++)
	{
		you.x = 1 + rand() % 10;
		you.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = you.x;
		savey = you.y;
		if (you.youfield[you.x][you.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				you.youfield[you.x][you.y] = '4';
				if (way == Up && you.youfield[you.x - 1][you.y] == '#' && you.youfield[you.x - 2][you.y] == '#' && you.youfield[you.x - 3][you.y] == '#')
				{
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x--;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x--;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x--;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else if (way == Doun && you.youfield[you.x + 1][you.y] == '#' && you.youfield[you.x + 2][you.y] == '#' && you.youfield[you.x + 3][you.y] == '#')
				{
				if (you.youfield[you.x - 1][you.y] == '#')
				{
					you.youfield[you.x - 1][you.y] = 'O';
				}
				if (you.youfield[you.x][you.y - 1] == '#')
				{
					you.youfield[you.x][you.y - 1] = 'O';
				}
				if (you.youfield[you.x][you.y + 1] == '#')
				{
					you.youfield[you.x][you.y + 1] = 'O';
				}
				Plus(you);
					you.x++;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x++;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					you.x++;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;


				}
				else if (way == Left && you.youfield[you.x][you.y + 1] == '#' && you.youfield[you.x][you.y + 2] == '#' && you.youfield[you.x][you.y + 3])
				{
				if (you.youfield[you.x - 1][you.y] == '#')
				{
					you.youfield[you.x - 1][you.y] = 'O';
				}
				if (you.youfield[you.x + 1][you.y] == '#')
				{
					you.youfield[you.x + 1][you.y] = 'O';
				}
				if (you.youfield[you.x][you.y - 1] == '#')
				{
					you.youfield[you.x][you.y - 1] = 'O';
				}
				Plus(you);
					you.y++;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					Plus(you);
					you.y++;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					Plus(you);
					you.y++;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y + 1] == '#')
					{
						you.youfield[you.x][you.y + 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else if (way == Right && you.youfield[you.x][you.y - 1] == '#' && you.youfield[you.x][you.y - 2] == '#' && you.youfield[you.x][you.y - 3])
				{
				if (you.youfield[you.x - 1][you.y] == '#')
				{
					you.youfield[you.x - 1][you.y] = 'O';
				}
				if (you.youfield[you.x + 1][you.y] == '#')
				{
					you.youfield[you.x + 1][you.y] = 'O';
				}
				if (you.youfield[you.x][you.y + 1] == '#')
				{
					you.youfield[you.x][you.y + 1] = 'O';
				}
				Plus(you);
					you.y--;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					Plus(you);
					you.y--;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					Plus(you);
					you.y--;
					you.youfield[you.x][you.y] = '4';
					if (you.youfield[you.x - 1][you.y] == '#')
					{
						you.youfield[you.x - 1][you.y] = 'O';
					}
					if (you.youfield[you.x + 1][you.y] == '#')
					{
						you.youfield[you.x + 1][you.y] = 'O';
					}
					if (you.youfield[you.x][you.y - 1] == '#')
					{
						you.youfield[you.x][you.y - 1] = 'O';
					}
					Plus(you);
					j++;
				}
				else
				{
				num_attempts--;
				way = 1 + rand() % 4;
				}
			}
		}
		else
		{
		num_attempts--;
			i--;
		}
	}

}

void PrintYou(const You & you, int const size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0 ; j < size; j++)
		{
			if (j != 0)
			{
				if (you.youfield[i][j] == 'O')
				{
					SetForegroundColor(BLUE);
					cout << "#" << " ";
				}
				else if (you.youfield[i][j] == '#' || you.youfield[i][j] == '0')
				{
					SetForegroundColor(BLUE);
					cout << you.youfield[i][j] << " ";
				}
				else if (you.youfield[i][j] == '1' || you.youfield[i][j] == '2' || you.youfield[i][j] == '3' || you.youfield[i][j] == '4')
				{
					SetForegroundColor(DARKRED);
					cout << you.youfield[i][j] << " ";
				}
				else
				{
					cout << you.youfield[i][j] << " ";
				}
			}
			else
			{
				cout << you.youfield[i][j] << " ";
			}
			SetForegroundColor(WHITE);

		}
		cout << endl;
	}
	cout << "\n\n\n\n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j != 0 && i !=0)
			{
				SetForegroundColor(BLUE);
				cout << you.battlefield[i][j] << " ";
			}
			else
			{
				cout << you.youfield[i][j] << " ";
			}
			SetForegroundColor(WHITE);

		}
		cout << endl;
	}
	cout << "\n\n\n\n";
}

void RankingYourField(You & you, int random, int const size)
{
	Ranking(you, size);
	for (int l = 0; l != Rerandomed;)
	{
		PrintYou(you, size);
		cout << Rerandomed << ") Re randomed" << endl;
		cout << Ok << ") Ok" << endl;
		cin >> random;
		if (random == 1)
		{
			FillYou(you, size);
			system("cls");
			Ranking(you, size);
		}
		else if (random == 0)
		{
			system("cls");
			PrintYou(you, size);
			break;
		}
	}
}



