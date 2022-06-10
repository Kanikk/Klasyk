#include "klasy.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


Postac::Postac(string _nazwa, int _obrazenia, int _hp) : nazwa(_nazwa), obrazenia(_obrazenia), hp(_hp)
{
}

Postac::~Postac()
{
}

string Postac::pobierzNazwe()
{
	return this->nazwa;
}

int Postac::pobierzObrazenia()
{
	return this->obrazenia;
}

int Postac::pobierzHP()
{
	return this->hp;
}

void Postac::modyfikuj()
{
	system("cls");
	cout << "MODIFY CHARACTER";
}

