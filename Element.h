#pragma once
#include "Common.h"

struct Element
{
	string name; //nazwa elementu
	int wiedza_roll;
    int zrecznosc_roll;
	int sila_roll;
	int dlugosc; //dlugosc elementu

	Element(string n, int w, int s, int z, int d)
	{
		this->name = n;
		this->wiedza_roll = w;
		this->sila_roll = s;
        this->zrecznosc_roll = z;
		this->dlugosc = d;
	}
    ~Element() = default;
};