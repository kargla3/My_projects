#pragma once
#include "Uzytkownik.h"
#include <vector>
#include <iostream>
#include <string>
#include <conio.h>
#include "funkcje.h"
#include <Windows.h>
#include <iomanip>
#include "Kasjer.h"

using namespace std;

class Administrator : public Uzytkownik
{
public:
	Administrator(string stanowisko, string login, string haslo);
	void menu(vector<Uzytkownik*>& uzytkownicy, vector<Produkt*>& produkty, Kasa kasy[]);
	void dodaj_uzytkownika(vector<Uzytkownik*>& uzytkownicy);
	void przejdz_do_kategorii(int z, vector<Produkt*>& produkty);
	void zmiencene(vector<Produkt*>& produkty, string kategoria);
};