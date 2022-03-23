#pragma once
#include <iostream>
using namespace std;

#include <conio.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include <string>
#include <cstdio>

//zmienianie pozycji kursora na x, y. Przydatne do rysowania w konsoli
inline void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
