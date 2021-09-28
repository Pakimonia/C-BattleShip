#include<iostream>
#include<time.h>
#include"Menu.h"

using namespace std;
int main()
{ 
	setlocale(LC_ALL, "ru");
	srand(time(0));
	Menu();
	cout << "\n\n";
	system("pause");
	return 0;
}