#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Produkt
{
	string kategoria;
	string nazwa;
	double cena;
public:
	Produkt(string kategoria, string nazwa, double cena);
	double Cena();
	string Kategoria();
	string Nazwa();
	void zmien_cene(double cena);
	friend void zapis_produktow(string nazwa_pliku, vector<Produkt*> produkty);
	virtual double iloscwaga() = 0;
	virtual void zmien_iw(int i = 0, double d = 0) = 0;
};
