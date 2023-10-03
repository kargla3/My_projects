#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "funkcje.h"
#include "Uzytkownik.h"
#include "Administrator.h"
#include "Kasjer.h"
#include "Produkt.h"
#include "Produkt_na_ilosc.h"
#include "Produkt_na_wage.h"
#include "Kasa.h"

using namespace std;

void menu(vector<Uzytkownik*> uzytkownicy, vector<Produkt*> produkty,Kasa kasy[], string u, string p, string k);
Uzytkownik* logowanie(vector<Uzytkownik*> uzytkownicy);
void odczyt_uzytkownikow(string nazwa_pliku, vector<Uzytkownik*> &uzytkownicy);
void odczyt_produktow(string nazwa_pliku, vector<Produkt*>& produkty);
void odczyt_kas(string nazwa_pliku, Kasa kasy[]);
void zapis_uzytkownikow(string nazwa_pliku, vector<Uzytkownik*> uzytkownicy);
void zapis_produktow(string nazwa_pliku, vector<Produkt*> produkty);
void zapis_kas(string nazwa_pliku, Kasa kasy[]);
void wyswietl_kategorie();
bool czy_liczba(string s);