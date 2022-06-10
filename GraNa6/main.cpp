#include <iostream>
#include <vector>
#include <iomanip>
#include "klasy.h"
using namespace std;

vector<Postac> postacie;

void porownanie(Postac p1, Postac p2)
{
	int roznicaDMG, roznicaHP;

	// czyszczenie
	system("cls");

	// wyœwietlenie podstawowych informacji
	cout << setw(10) << left << "Postacie" << setw(15) << "Obrazenia" << setw(10) << "HP" << endl;
	cout << setw(10) << left << p1.pobierzNazwe() << setw(15) << p1.pobierzObrazenia() << setw(10) << p1.pobierzHP() << setw(10) << endl;
	cout << setw(10) << left << p2.pobierzNazwe() << setw(15) << p2.pobierzObrazenia() << setw(10) << p2.pobierzHP() << setw(10) << endl;

	// wyœwietlenie ró¿nicy 
	if (p1.pobierzObrazenia() > p2.pobierzObrazenia())
		roznicaDMG = p1.pobierzObrazenia() - p2.pobierzObrazenia();
	else
		roznicaDMG = p2.pobierzObrazenia() - p1.pobierzObrazenia();

	if (p1.pobierzHP() > p2.pobierzHP())
		roznicaHP = p1.pobierzHP() - p2.pobierzHP();
	else
		roznicaHP = p2.pobierzHP() - p1.pobierzHP();

	cout << endl;
	cout << setw(10) << left << "Roznica" << setw(15) << roznicaDMG << setw(10) << roznicaHP << setw(10) << endl;
}

void wyswietlPostacie(bool czyszczenie)
{
	// czyszczenie
	if (czyszczenie)
	{
		system("cls");
	}

	// wiersz informacyjny
	cout << setw(5) << left << "Lp" << setw(15) << "Nazwa" << endl;

	// wyœwietlenie zawartoœci vectora
	for (int i = 0; i<postacie.size(); i++)
	{
		cout << setw(5) << left << (i+1) << setw(15) << postacie[i].pobierzNazwe() << endl;
	}

	cout << "Press enter... ";
	getchar();
}

void tworzeniePostaci()
{
	string _nazwa = " ";
	int _obrazenia = 0;
	int _hp = 0;

	system("cls");

	cout << "____TWORZENIE POSTACI____\n";

	cout << "Podaj nazwe: ";
	cin >> _nazwa;
	cout << endl;

	cout << "Podaj wartosc obrazen: ";
	cin >> _obrazenia;
	cout << endl;

	cout << "Podaj wartosc zdrowia: ";
	cin >> _hp;
	cout << endl;

	postacie.push_back(Postac(_nazwa, _obrazenia, _hp));
}

void porownanieMenu()
{
	int wybor1, wybor2;

	system("cls");

	wyswietlPostacie(false);

	cout << "Wybierz numer postaci 1: ";
	cin >> wybor1;
	cout << endl;

	cout << "Wybierz numer postaci 2: ";
	cin >> wybor2;
	cout << endl;

	if (wybor1 > postacie.size() || wybor2 > postacie.size())
	{
		cout << "\nZly numer\n";
	}
	else
	{
		porownanie(postacie[wybor1 - 1], postacie[wybor2 - 1]);
	}

	getchar();
}

void menu()
{
	Postac p1("Carl", 5, 40);
	Postac p2("Ben", 10, 20);


	postacie.push_back(p1);
	postacie.push_back(p2);

	do
	{
	int choice;

	system("cls");

	cout << "_____MENU_____" << endl;
	cout << endl << "Liczba postaci: " << postacie.size() << endl;
	cout << "1. Tworzenie postaci\n";
	cout << "2. Wyswietlanie postaci\n";
	cout << "3. Porownanie postaci\n";
	cout << "4. Koniec programu\n";

	cout << endl << "Wybierz: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		tworzeniePostaci();
		break;

	case 2:
		wyswietlPostacie(true);
		break;

	case 3:
		porownanieMenu();
			break;
	case 4:
		exit(0);
		
	default:
		cout << "Nie ma opcji o takim numerze!";
	}

	getchar();
	}while (true);
	
}

int main()
{
	cout << "GAME by Kamil Urbas\n";

	getchar();
	menu();

	return 0;
}

// Gra polega na tworzeniu postaci, porównywaniu ich i testowaniu ich w walce przeciw sobie.
// Menu
//         Licznik postaci, Wyswietlanie postaci, Tworzenie postaci, Porownywanie postaci