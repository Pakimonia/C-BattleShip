#include "Pc.h"
#include<iostream>

using namespace std;

void PlusPk (Pk& pk)
{
	if (pk.youfield[pk.x + 1][pk.y - 1] == '#')
	{
		pk.youfield[pk.x + 1][pk.y - 1] = 'O';
	}
	if (pk.youfield[pk.x + 1][pk.y + 1] == '#')
	{
		pk.youfield[pk.x + 1][pk.y + 1] = 'O';
	}
	if (pk.youfield[pk.x - 1][pk.y - 1] == '#')
	{
		pk.youfield[pk.x - 1][pk.y - 1] = 'O';
	}
	if (pk.youfield[pk.x - 1][pk.y + 1] == '#')
	{
		pk.youfield[pk.x - 1][pk.y + 1] = 'O';
	}
}

void FillPk(Pk & pk, int const size)
{
		pk.youfield[0][0] = ' ';
		for (int i = 1, x = 48, letter = 65; i < size; i++, letter++, x++)
		{
			pk.youfield[0][i] = (int)letter;
			pk.youfield[i][0] = x;

		}
		for (int i = 1; i < size; i++)
		{
			for (int j = 1; j < size; j++)
			{
				pk.youfield[i][j] = '#';

			}
		}
}

void RankingPk(Pk & pk, int const size)
{
	int num_attempts = 15;
	int way = 1 + rand() % 4;
	int savex = pk.x;
	int savey = pk.y;

	for (int i = 0; i < Torpedo_Boats; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			pk.youfield[pk.x][pk.y] = '1';
			if (pk.youfield[pk.x - 1][pk.y] == '#')
			{
				pk.youfield[pk.x - 1][pk.y] = 'O';
			}
			if (pk.youfield[pk.x + 1][pk.y] == '#')
			{
				pk.youfield[pk.x + 1][pk.y] = 'O';
			}
			if (pk.youfield[pk.x][pk.y - 1] == '#')
			{
				pk.youfield[pk.x][pk.y - 1] = 'O';
			}
			if (pk.youfield[pk.x][pk.y + 1] == '#')
			{
				pk.youfield[pk.x][pk.y + 1] = 'O';
			}
			PlusPk(pk);
		}
		else
		{
			num_attempts--;
			i--;
		}
	}
	for (int i = 0; i < Destroyers; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				pk.youfield[pk.x][pk.y] = '2';
				if (way == Up && pk.youfield[pk.x - 1][pk.y] == '#')
				{
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x--;
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
					pk.youfield[pk.x][pk.y] = '2';
				}
				else if (way == Doun && pk.youfield[pk.x + 1][pk.y] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x++;
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
					pk.youfield[pk.x][pk.y] = '2';
				}
				else if (way == Left && pk.youfield[pk.x][pk.y + 1] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					PlusPk(pk);
					pk.y++;
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
					pk.youfield[pk.x][pk.y] = '2';
				}
				else if (way == Right && pk.youfield[pk.x][pk.y - 1] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.y--;
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					PlusPk(pk);
					j++;
					pk.youfield[pk.x][pk.y] = '2';
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
	for (int i = 0; i < Cruisers; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = pk.x;
		savey = pk.y;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				pk.youfield[pk.x][pk.y] = '3';
				if (way == Up && pk.youfield[pk.x - 1][pk.y] == '#' && pk.youfield[pk.x - 2][pk.y] == '#')
				{
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x--;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x--;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
				}
				else if (way == Doun && pk.youfield[pk.x + 1][pk.y] == '#' && pk.youfield[pk.x + 2][pk.y] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x++;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x++;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
				}
				else if (way == Left && pk.youfield[pk.x][pk.y + 1] == '#' && pk.youfield[pk.x][pk.y + 2] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					PlusPk(pk);
					pk.y++;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					PlusPk(pk);
					pk.y++;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
				}
				else if (way == Right && pk.youfield[pk.x][pk.y - 1] == '#' && pk.youfield[pk.x][pk.y - 2] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.y--;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					PlusPk(pk);
					pk.y--;
					pk.youfield[pk.x][pk.y] = '3';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					PlusPk(pk);
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
	for (int i = 0; i < Battleship; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = pk.x;
		savey = pk.y;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				pk.youfield[pk.x][pk.y] = '4';
				if (way == Up && pk.youfield[pk.x - 1][pk.y] == '#' && pk.youfield[pk.x - 2][pk.y] == '#' && pk.youfield[pk.x - 3][pk.y] == '#')
				{
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x--;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x--;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x--;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
				}
				else if (way == Doun && pk.youfield[pk.x + 1][pk.y] == '#' && pk.youfield[pk.x + 2][pk.y] == '#' && pk.youfield[pk.x + 3][pk.y] == '#')
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x++;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x++;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.x++;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;


				}
				else if (way == Left && pk.youfield[pk.x][pk.y + 1] == '#' && pk.youfield[pk.x][pk.y + 2] == '#' && pk.youfield[pk.x][pk.y + 3])
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					PlusPk(pk);
					pk.y++;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					PlusPk(pk);
					pk.y++;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					PlusPk(pk);
					pk.y++;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					j++;
				}
				else if (way == Right && pk.youfield[pk.x][pk.y - 1] == '#' && pk.youfield[pk.x][pk.y - 2] == '#' && pk.youfield[pk.x][pk.y - 3])
				{
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y + 1] = 'O';
					}
					PlusPk(pk);
					pk.y--;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					PlusPk(pk);
					pk.y--;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					PlusPk(pk);
					pk.y--;
					pk.youfield[pk.x][pk.y] = '4';
					if (pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x - 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x + 1][pk.y] = 'O';
					}
					if (pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y - 1] = 'O';
					}
					PlusPk(pk);
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






	/*for (int i = 0; i < Torpedo_Boats; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			pk.youfield[pk.x][pk.y] = '1';
		}
		else
		{
			i--;
		}

	}
	for (int i = 0; i < Destroyers; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = pk.x;
		savey = pk.y;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				pk.youfield[pk.x][pk.y] = '2';
				if (way == Left)
				{
					pk.x--;

				}
				else if (way == Right)
				{
					pk.x++;
				}
				else if (way == Up)
				{
					pk.y++;
				}
				else if (way == Doun)
				{
					pk.y--;
				}
				if (pk.youfield[pk.x][pk.y] == '#')
				{
					pk.youfield[pk.x][pk.y] = '2';
					j++;
				}
				else
				{
					pk.x = savex;
					pk.y = savey;
					way = 1 + rand() % 4;
				}
			}
		}
		else
		{
			i--;
		}
	}
	for (int i = 0; i < Cruisers; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = pk.x;
		savey = pk.y;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				pk.youfield[pk.x][pk.y] = '3';
				if (way == Left)
				{
					pk.x--;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x - 1][pk.y] == '#')
					{
						pk.youfield[pk.x][pk.y] = '3';
						pk.x--;
						pk.youfield[pk.x][pk.y] = '3';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}

				}
				else if (way == Right)
				{
					pk.x++;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x + 1][pk.y] == '#')
					{
						pk.youfield[pk.x][pk.y] = '3';
						pk.x++;
						pk.youfield[pk.x][pk.y] = '3';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}
				}
				else if (way == Up)
				{
					pk.y++;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y] = '3';
						pk.y++;
						pk.youfield[pk.x][pk.y] = '3';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}
				}
				else if (way == Doun)
				{
					pk.y--;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y] = '3';
						pk.y--;
						pk.youfield[pk.x][pk.y] = '3';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}
				}
			}
		}
		else
		{
			i--;
		}
	}
	for (int i = 0; i < Battleship; i++)
	{
		pk.x = 1 + rand() % 10;
		pk.y = 1 + rand() % 10;
		way = 1 + rand() % 4;
		savex = pk.x;
		savey = pk.y;
		if (pk.youfield[pk.x][pk.y] == '#')
		{
			for (int j = 0; j < 1; )
			{
				pk.youfield[pk.x][pk.y] = '4';
				if (way == Left)
				{
					pk.x--;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x - 1][pk.y] == '#' && pk.youfield[pk.x - 2][pk.y] == '#')
					{
						pk.youfield[pk.x][pk.y] = '4';
						pk.x--;
						pk.youfield[pk.x][pk.y] = '4';
						pk.x--;
						pk.youfield[pk.x][pk.y] = '4';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}

				}
				else if (way == Right)
				{
					pk.x++;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x + 1][pk.y] == '#' && pk.youfield[pk.x + 2][pk.y] == '#')
					{
						pk.youfield[pk.x][pk.y] = '4';
						pk.x++;
						pk.youfield[pk.x][pk.y] = '4';
						pk.x++;
						pk.youfield[pk.x][pk.y] = '4';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}
				}
				else if (way == Up)
				{
					pk.y++;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x][pk.y + 1] == '#' && pk.youfield[pk.x][pk.y + 1] == '#')
					{
						pk.youfield[pk.x][pk.y] = '4';
						pk.y++;
						pk.youfield[pk.x][pk.y] = '4';
						pk.y++;
						pk.youfield[pk.x][pk.y] = '4';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}
				}
				else if (way == Doun)
				{
					pk.y--;
					if (pk.youfield[pk.x][pk.y] == '#' && pk.youfield[pk.x][pk.y - 1] == '#' && pk.youfield[pk.x][pk.y - 1] == '#')
					{
						pk.youfield[pk.x][pk.y] = '4';
						pk.y--;
						pk.youfield[pk.x][pk.y] = '4';
						pk.y--;
						pk.youfield[pk.x][pk.y] = '4';
						j++;
					}
					else
					{
						pk.x = savex;
						pk.y = savey;
						way = 1 + rand() % 4;
					}
				}

			}
		}
		else
		{
			i--;
		}
	}*/

}

void PrintPk(const Pk & pk, int const size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << pk.youfield[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n\n\n";
}

