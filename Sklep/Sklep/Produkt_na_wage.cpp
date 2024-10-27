#include "Produkt_na_wage.h"

Produkt_na_wage::Produkt_na_wage(string kategoria, string nazwa, double cena, double waga) : Produkt(kategoria, nazwa, cena)
{
	this->waga = waga;
}

void Produkt_na_wage::zmien_iw(int i, double d)
{
	waga = d;
}

double Produkt_na_wage::iloscwaga()
{
	return waga;
}