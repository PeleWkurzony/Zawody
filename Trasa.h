#pragma once
#include "Common.h"
#include "Element.h"

Element sciezka = Element("Sciezka", 8, 0, 12, 40);
Element krzaki = Element("Krzaki", 4, 12, 5,60);
Element kamienie = Element("Kamienie", 8, 8, 12, 50);

Element tab_elementy[3] = { sciezka,krzaki,kamienie };



class Trasa
{
	int _len;
	float _diff;
	vector <Element*> _elementy;

public:
	//zwraca ilosc elementow trasy
	int getLen() { return _len; }

	//pobiera dany element o indeksie i
	Element getEl(int i)
	{
		return *_elementy[i];
	}
    ~Trasa() {
        for (Element* e : _elementy) {
            delete e;
        }
    }

	Trasa(int len, int diff)
	{
		this->_diff = diff;
		this->_len = len;

		cout << "Trasa sklada sie z:\n";
		for (int i = 0; i < _len; i++)
		{
			_elementy.push_back(&tab_elementy[rand() % 3]);
			_elementy[i]->sila_roll *= _diff;
			_elementy[i]->wiedza_roll *= _diff;
			_elementy[i]->dlugosc *= _diff;
			cout << i+1 << ". " << _elementy[i]->name << endl;
		}


	}

};