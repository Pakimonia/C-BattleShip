#pragma once
#include"Ship.h"
#include"Pc.h"


struct You
{
	char youfield[Size][Size];
	char battlefield[Size][Size];
	int x = 0;
	int y = 0;
	int SumShip = (Destroyers * 2) + Torpedo_Boats + (Cruisers * 3) + (Battleship * 4);
};

enum Rand
{
	Rerandomed = 1, Ok = 0
}; 

void Plus(You& you);

void FillYou(You & you, int const size);

void Ranking(You& you, int const size = Size);

void PrintYou(const You& you, int const size = Size);

void RankingYourField(You& you, int random, int const size = Size);


