#include "zawody.h"

int main()
{
    start:
    system("CLS");
    Zawody* game = new Zawody(5,3,1.0);
	gotoxy(32, 25);
	cout << "Kliknij cokolwiek, aby przejsc dalej . . . ";
	_getch();
	system("CLS");
	gotoxy(1, 1);

    while (true)
	{
        game->NastepnaRunda();
        game->PokazUczestnikow();
        if (game->CzyKtosWygral()) {
            system("CLS");
            game->PokazUczestnikow();
            break;
        }
		_getch();
	}
    int count = game->getZwyciezca()->getName().length() + 12;
    gotoxy(25 + (61 - count) / 2, 15);
    cout << game->getZwyciezca()->getName() << ": wygral gre";
    gotoxy(25, 20);
    cout << "Rozgrywka zakonczyla sie. Czy chesz zagrac jeszcze raz? (y/n)";
    char c;
    while (true) {
       c = (char) _getch();
        if (c == 'y') {
            delete game;
            goto start;
        }
        if (c == 'n') {
            break;
        }
    }

    return 0;
}