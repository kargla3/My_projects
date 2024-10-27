#pragma once
#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "Produkt.h"
#include "Kasa.h"

using namespace std;

class Uzytkownik
{
	string stanowisko;
	string login;
	string haslo;
public:
	Uzytkownik(string stanowisko, string login, string haslo);
	string Login();
	virtual void menu(vector<Uzytkownik*> &uzytkownicy,vector<Produkt*> &produkty,Kasa kasy[]) = 0;
	friend Uzytkownik* logowanie(vector<Uzytkownik*> uzytkownicy);
	friend void zapis_uzytkownikow(string nazwa_pliku, vector<Uzytkownik*> uzytkownicy);
	virtual void przejdz_do_kategorii(int z, vector<Produkt*>& produkty) = 0;
	void nowyprodukt(vector<Produkt*>& produkty, string kategoria);
	void usunprodukt(vector<Produkt*>& produkty, string kategoria);
	void zmienilosc(vector<Produkt*>& produkty, string kategoria);

};