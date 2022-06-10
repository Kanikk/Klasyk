#pragma once
#include <iostream>
using namespace std;

class Postac
{
public:
	Postac(string = "", int = 0, int = 0);
	~Postac();


	string pobierzNazwe();
	int pobierzObrazenia();
	int pobierzHP();
	void modyfikuj();
	
private:
	string nazwa;
	int obrazenia;
	int hp;
};

