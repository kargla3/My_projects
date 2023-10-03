#include <iostream>
#include "Produkt_na_ilosc.h"

Produkt_na_ilosc::Produkt_na_ilosc(string kategoria, string nazwa, double cena, int ilosc) : Produkt(kategoria, nazwa, cena)
{
	this->ilosc = ilosc;
};

void Produkt_na_ilosc::zmien_iw(int i, double d)
{
	ilosc = i;
}

double Produkt_na_ilosc::iloscwaga()
{
	return ilosc;
}