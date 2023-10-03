#pragma once
#include "Produkt.h"
#include <string>

class Produkt_na_ilosc : public Produkt
{
	int ilosc;
public:
	Produkt_na_ilosc(string kategoria, string nazwa, double cena, int ilosc);
	void zmien_iw(int i = 0, double d = 0);
	double iloscwaga();
};