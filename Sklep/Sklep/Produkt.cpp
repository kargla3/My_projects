#include <iostream>
#include "Produkt.h"
#include "Produkt_na_ilosc.h"

using namespace std;

Produkt::Produkt(string kategoria, string nazwa, double cena)
{
	this->kategoria = kategoria;
	this->nazwa = nazwa;
	this->cena = cena;
}

double Produkt::Cena()
{
	return cena;
}

string Produkt::Kategoria()
{
	return kategoria;
}
string Produkt::Nazwa()
{
	return nazwa;
}

void Produkt::zmien_cene(double cena)
{
	this->cena = cena;
}