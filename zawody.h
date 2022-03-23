#pragma once
#include "Common.h"
#include "Uczestnik.h"
#include "Trasa.h"

//pula imion i nazwisk
string tab[2][5] = { {"Jan","Dzban","Adam","Mariusz", "Dariusz"},{"Pancel","Adamowicz","Pawlak","Geleciak","Globus"} };
const string komentarze[3][2] = {
        /* wiedza */{"pomylil drogi", "zgubil sie"},
        /* zrecznosc */ {"poslizgnal sie i skrecil kostke", "wpadl do wody"},
        /* sila */ {"nie byl w stanie przejsc trasy", "zmeczyl sie i musial odpoczac"}
};

class Zawody
{
	
	vector<Uczestnik*> _uczestnicy; //lista zawodników
	Trasa *_trasa; //obiekt trasy
	static int _iloscKom; //ilosc linijek tekstu komentatora
    friend void dodajKomentarz(string);
    Uczestnik* zwyciezca;
public:

	Zawody(int dlugosc, int ilosc, int trudnosc) {
        srand(time(NULL));
        if (ilosc < 1)
            ilosc = 1;
        for (int i = 0; i < ilosc; i++) {
            string temp = "";
            temp += tab[0][rand() % 5];
            temp += " ";
            temp += tab[1][rand() % 5];
            _uczestnicy.push_back(new Uczestnik(temp, rand() % 20 + 10, rand() % 100, rand() % 100, rand() % 100));
            gotoxy(1, i * 2 + 3);
        }

        gotoxy(2, ilosc + 7);
        _trasa = new Trasa(dlugosc, trudnosc); //generowanie trasy

        //---------------------DEBUG LINE----------------//
        //_uczestnicy[0]->addProgres(36);
        //_uczestnicy[0]->addZal();

    }
    ~Zawody() {
        _iloscKom = 0;
        /*
        delete _trasa;
        for (Uczestnik* u : _uczestnicy) {
            delete u;
        }
        delete zwyciezca;
         */
    }
    Uczestnik* getZwyciezca() { return zwyciezca; }

    bool CzyKtosWygral() {
        bool temp = false;
        for (Uczestnik* uczestnik : _uczestnicy) {
            if (uczestnik->getZal() >= 4) {
                temp = true;
                zwyciezca = uczestnik;
                break;
            }
        }
        return temp;
    }
	//nastepna runda 
	void NastepnaRunda()
	{
        for (Uczestnik*  uczestnik : _uczestnicy) {

            if (uczestnik->getWiedza() + (rand() % 15)  >= _trasa->getEl(uczestnik->getZal()).wiedza_roll) {
                uczestnik->addProgres((rand() % 10), _trasa->getEl(uczestnik->getZal()).dlugosc);
            } else {
                uczestnik->resetProgres();
                dodajKomentarz(uczestnik->getName() + ": " + komentarze[0][rand() % 2]);
            }

            if (uczestnik->getWiedza() + (rand() % 15)  >= _trasa->getEl(uczestnik->getZal()).zrecznosc_roll) {
                uczestnik->addProgres((rand() % 10), _trasa->getEl(uczestnik->getZal()).dlugosc);
            } else {
                uczestnik->resetProgres();
                dodajKomentarz(uczestnik->getName() + ": " + komentarze[1][rand() % 2]);
            }

            if (uczestnik->getSila() + (rand() % 15)  >= _trasa->getEl(uczestnik->getZal()).sila_roll) {
                uczestnik->addProgres((rand() % 10), _trasa->getEl(uczestnik->getZal()).dlugosc);
            } else {
                uczestnik->resetProgres();
                dodajKomentarz(uczestnik->getName() + ": " + komentarze[2][rand() % 2]);
            }
        }
	}

	//wyswietla wszystkich uczestnikow
	void PokazUczestnikow()
	{
		for (int i = 0; i < _uczestnicy.size(); i++)
		{
			gotoxy((i + 1) * 20, 2);
			cout << _uczestnicy[i]->getName();
			gotoxy((i + 1) * 20, 3);
			cout << "Trasa: ";
			for (int j = 0; j < _trasa->getLen(); j++)
			{
				if (j < _uczestnicy[i]->getZal())
					cout << char(178);
				else
					cout << char(176);
			}

			gotoxy((i + 1) * 20, 4);
			cout << "Element: ";
			for (int j = 0; j < 10; j++)
			{
				if (j < _uczestnicy[i]->getProgr() /* /_trasa->getEl(_uczestnicy[i]->getZal()).dlugosc */)
					cout << char(178);
				else
					cout << char(176);
			}

		}

		gotoxy(1, 8);
		cout << "_____________________________________________________________________________________________";
	}
};

int Zawody::_iloscKom = 0;
//dodaje komentarz do komentatora
void dodajKomentarz(string what)
{
    Zawody::_iloscKom += 1;
    gotoxy(1, 9 + Zawody::_iloscKom);
    cout << what;
    if (Zawody::_iloscKom > 25)
        Zawody::_iloscKom = 0;
}
