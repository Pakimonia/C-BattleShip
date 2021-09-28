#include "Battle.h"
#include<iostream>

using namespace std;

void BattelYou(You & you, Pk & computer, int const size)
{
		char perevx;
		char perevy[255];
		cout << "Enter cordinete" << endl;
		cin >> perevx;
		cin >> perevy;
		if (perevx == '@')
		{
			computer.SumShip = 0;
			return;
		}
		if (perevx >= 65 && perevx <= 74)
		{
			you.x = perevx - 64;
		}
		else
		{
			system("cls");
			cout << "These coordinates are not correct" << endl;
			BattelYou(you, computer, size);
		}
		if (atoi(perevy) >= 0 && atoi(perevy) <= Size)
		{
			you.y = atoi(perevy) + 1;
		}
		else
		{
			system("cls");
			cout << "These coordinates are not correct" << endl;
			BattelYou(you, computer, size);
		}
		if (you.x >= Size || you.y >= Size || you.x == 0 || you.y == 0)
		{
			system("cls");
			cout << "These coordinates are not correct" << endl;
			BattelYou(you, computer, size);
		}
		else
		{
			if (computer.youfield[you.y][you.x] == '#' || computer.youfield[you.y][you.x] == 'O')
			{
				system("cls");
				cout << "You not catch" << endl;
				you.battlefield[you.y][you.x] = '0';
				PrintYou(you);
			}
			else if (computer.youfield[you.y][you.x] == '1')
			{
				computer.SumShip--;
				system("cls");
				cout << "You killed" << endl;
				you.battlefield[you.y][you.x] = '¤';
				PrintYou(you);
				BattelYou(you, computer, size);
			}
			else if (computer.youfield[you.y][you.x] == '2')
			{
				computer.SumShip--;
				system("cls");
				cout << "You catch" << endl;
				you.battlefield[you.y][you.x] = '¤';
				PrintYou(you);
				BattelYou(you, computer, size);
			}
			else if (computer.youfield[you.y][you.x] == '3')
			{
				computer.SumShip--;
				system("cls");
				cout << "You catch" << endl;
				you.battlefield[you.y][you.x] = '¤';
				PrintYou(you);
				BattelYou(you, computer, size);
			}
			else if (computer.youfield[you.y][you.x] == '4')
			{
				computer.SumShip--;
				system("cls");
				cout << "You catch" << endl;
				you.battlefield[you.y][you.x] = '¤';
				PrintYou(you);
				BattelYou(you, computer, size);
			}
			else
			{
				system("cls");
				cout << "These coordinates are not correct" << endl;
				BattelYou(you, computer, size);
			}
		}

	

}

void BatelPk(Pk& pk, You& you, const int size = Size)
{
	int way = 1 + rand() % 4;
	pk.x = 1 + rand() % 10;
	pk.y = 1 + rand() % 10;
	for (int i = 0; i < 1; )
	{
		if (you.youfield[pk.x][pk.y] == '#' || you.youfield[pk.x][pk.y] == 'O')
		{
			you.youfield[pk.x][pk.y] = '0';
			i++;
		}
		else if (you.youfield[pk.x][pk.y] == '1')
		{
			you.SumShip--;
			you.youfield[pk.x][pk.y] = '¤';
			BatelPk(pk, you);
		}
		else if (you.youfield[pk.x][pk.y] == '2' || you.youfield[pk.x][pk.y] == '3' || you.youfield[pk.x][pk.y] == '4')
		{
			you.SumShip--;
			you.youfield[pk.x][pk.y] = '¤';
			way = 1 + rand() % 4;
			if (way == Up)
			{
				pk.x--;
			}
			else if (way == Doun)
			{
				pk.x++;
			}
			else if (way == Left)
			{
				pk.y++;
			}
			else if (way == Right)
			{
				pk.y--;
			}
			BatelPk(pk, you);
		}
		else
		{
			break;
		}
	}



}

void Battle(Pk & pk, You & you, const int size)
{
	do
	{
		BatelPk(pk, you);
		PrintPk(pk);
		BattelYou(you, pk, Size);
		if (pk.SumShip <= 0 || you.SumShip <= 0)
		{
			break;
		}
	} while (true);
}
