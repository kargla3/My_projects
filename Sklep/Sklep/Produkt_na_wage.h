#pragma once
#include <iostream>
#include "Produkt.h"

class Produkt_na_wage : public Produkt
{
	double waga;
public:
	Produkt_na_wage(string kategoria, string nazwa, double cena, double waga);
	void zmien_iw(int i = 0, double d = 0);
	double iloscwaga();
};