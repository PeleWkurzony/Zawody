#pragma once

#include "Common.h"


void dodajKomentarz(string);
class Uczestnik
{
	string imie_nazwisko;
	int wiek;

	//0 - 100
	int wiedza;
	int zrecznosc;
	int sila;

	int zaliczone = 0;
	int progres = 0;
public:

	Uczestnik(string name, int wiek, int w, int z, int s)
	{
		cout << "Witamy uczestnika " << name << ", ktory ma " << wiek << " lat i pochodzi z Gdanska!\n";
		cout << "Wiedza: " << w << ", Zrecznosc: " << z << ", Sila: " << s << endl;
		this->imie_nazwisko = name;
		this->wiek = wiek;
		this->wiedza = w;
		this->zrecznosc = z;
		this->sila = s;
	}
    ~Uczestnik() = default;

	string getName() { return imie_nazwisko; }
	int getWiek() { return wiek; }
	int getWiedza() { return wiedza; }
	int getSila() { return sila; }
	int getZrecznosc() { return zrecznosc; }
	int getZal() { return zaliczone; }
	int getProgr() { return progres; }

	//zwieksza zaliczone elementy trasy o 1
	void addZal()
	{
		zaliczone++;
	}

	//zwieksza progres danego elementu trasy o a, majac na uwadze dlugosc elementu (dlugosc)
	void addProgres(int a, int dlugosc)
	{
		if (progres + a < dlugosc)
			progres += a;
		else // Zakonczyl etap
        {
            resetProgres();
            addZal();
            dodajKomentarz(imie_nazwisko + ": zakonczyl etap nr " + to_string(zaliczone));
        }
	}

	//resetuje progres elementu
	void resetProgres()
	{
		progres = 0;
	}
	
};