#include "Menu.h"
#include <iostream>

using namespace std;

void Menu()
{
	You you;
	Pk pk;
	int random = 1;
	int vub = 1;
	SetForegroundColor(BLUE);
	cout << "                                                                \\__/" << endl;
	cout << "                                                                        " << endl;
	cout << "|\\    /|    /----\\    |--\\    /--\\    |       | /    |\\   |    |\\   |" << endl;
	cout << "| \\  / |    |    |    |__/    |       |--\\    |/     | \\  |    | \\  | " << endl;
	cout << "|  \\/  |    |    |    |       |       |  |    |\\     |  \\ |    |  \\ |" << endl;
	cout << "|      |    \\____/    |       \\__/    |__/    | \\    |   \\|    |   \\|" << endl;
	cout << "" << endl;
	cout << "                                               \\__/" << endl;
	cout << "" << endl;
	cout << "                                |----    O    |\\   |" << endl;
	cout << "                                |        |    | \\  |" << endl;
	cout << "                                |---\\    |    |  \\ |" << endl;
	cout << "                                |___/    |    |   \\|" << endl << endl << endl;
	SetForegroundColor(YELLOW);
	SetForegroundColor(WHITE);
	cout << "[" << Play << "] Play"  << endl;;
	cout << "[" << Exit << "] Exit" << endl;
	cin >> vub;
	system("cls");
	if (vub == Play)
	{

		FillPk(pk, Size);
		FillYou(you, Size);
		RankingPk(pk, Size);
		RankingYourField(you, random, Size);
		Battle(pk, you, Size);
		if (pk.SumShip == 0)
		{
			cout << "You win" << endl;
		}
		else if (you.SumShip == 0)
		{
			cout << "You lose" << endl;
		}
		else if (pk.SumShip == you.SumShip)
		{
			cout << "Nichia \n";
		}
		else
		{
			cout << "Eror \n";
		}
	}
	else
	{
		cout << "You Exit";
	}
		




}
