#pragma once
#include <iostream>
#include "Uzytkownik.h"
#include "Kasa.h"

using namespace std;

class Kasjer : public Uzytkownik
{
public:
	Kasjer(string stanowisko, string login, string haslo);
	void menu(vector<Uzytkownik*>& uzytkownicy, vector<Produkt*>& produkty, Kasa kasy[]);
	void przejdz_do_kategorii(int z, vector<Produkt*>& produkty);
	void przejdz_do_kas(Kasa kasy[], vector<Produkt*>& produkty);
	void kasa(int z, Kasa kasy[], vector<Produkt*>& produkty);
};