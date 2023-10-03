#pragma once
#include <string>
#include <vector>
#include "Produkt.h"

using namespace std;

class Kasa
{
	double kasa;
public:
	Kasa(double kasa = 0);
	double ilePieniedzy();
	void Sprzedaj(vector<Produkt*> &produkty);
	void Remanent(vector<Produkt*> produkty);
	void wybierz_produkt(string kategoria,vector<Produkt*>& lista_zakupowa, vector<Produkt*> produkty);
	void potwierdz_sprzedaz(vector<Produkt*>& produkty, vector<Produkt*> lista_zakupowa);
	friend void odczyt_kas(string nazwa_pliku, Kasa kasy[]);
};