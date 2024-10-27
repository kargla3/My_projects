#include <iostream>
#include <vector>
#include <conio.h>
#include "funkcje.h"
#include "Produkt.h"
#include "Produkt_na_ilosc.h"
#include "Produkt_na_wage.h"
#include "Uzytkownik.h"
#include "Administrator.h"
#include "Kasjer.h"
#include "Kasa.h"

int main()
{
	vector<Uzytkownik*> uzytkownicy;
	vector<Produkt*> produkty;
	Kasa kasy[4];
	string uzytkownicy_plik = "users.txt", produkty_plik = "products.txt", kasy_plik = "cashregister.txt";
	odczyt_uzytkownikow(uzytkownicy_plik, uzytkownicy);
	odczyt_produktow(produkty_plik, produkty);
	odczyt_kas(kasy_plik, kasy);
	menu(uzytkownicy, produkty, kasy, uzytkownicy_plik, produkty_plik, kasy_plik);
}