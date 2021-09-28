#pragma once
#include"Ship.h"
#include"You.h"

struct Pk
{
	char youfield[Size][Size];
	int x = 0;
	int y = 0;
	int SumShip = (Destroyers * 2) + Torpedo_Boats + (Cruisers * 3) + (Battleship * 4);
};

void FillPk(Pk & pk, int const size = Size);

void RankingPk(Pk& pk, int const size = Size);

void PrintPk(const Pk& pk, int const size = Size);

