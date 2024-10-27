#include "funkcje.h"
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

void menu(vector<Uzytkownik*> uzytkownicy, vector<Produkt*> produkty, Kasa kasy[], string u, string p, string k)
{
	while(1)
	{
		system("cls");
		cout << "_____ELEKTRONICZNY SYSTEM ZARZADANIA SKLEPEM_____" << endl;
		cout << "\n	   NACISNIJ 1 ABY ZALOGOWAC" << endl;
		cout << "	    NACISNIJ ESC ABY WYJSC" << endl;
		while (1)
		{
			int z = _getch();
			if (z == 49) { logowanie(uzytkownicy)->menu(uzytkownicy, produkty, kasy); break; }
			if (z == 27) { zapis_uzytkownikow(u, uzytkownicy); zapis_produktow(p, produkty); zapis_kas(k, kasy); exit(0); }
		}
	}
}
Uzytkownik* logowanie(vector<Uzytkownik*> uzytkownicy)
{
	string login, haslo;
	bool founded = false;
	while (founded == false)
	{
		system("cls");
		cout << "\nPodaj login: ";
		cin >> login;
		cout << "\nPodaj haslo: ";
		cin >> haslo;

		for (int i = 0; i < uzytkownicy.size(); i++)
		{
			if (uzytkownicy[i]->login == login)
			{
				if (uzytkownicy[i]->haslo == haslo)
				{
					cout << "\nZalogowano pomyslnie, nacisnij enter aby wejsc do systemu";
					founded = true;
					while (1)
					{
						if (_getch() == 13) {
							return uzytkownicy[i];
						}
					}
				}
			}
		}
		cout << "\nBledny login lub haslo" << endl;
		Sleep(2000);
	}
}

void odczyt_uzytkownikow(string nazwa_pliku, vector<Uzytkownik*> &uzytkownicy)
{
	fstream file;
	file.open(nazwa_pliku, ios::in);
	if (file.is_open())
	{
		string wiersz;
		while (getline(file, wiersz))
		{
			vector<string> slowa;
			stringstream s(wiersz);
			string slowo, stanowisko, login, haslo;
			while (s >> slowo) slowa.push_back(slowo);

			if (slowa.size() == 3)
			{
				stanowisko = slowa[0];
				login = slowa[1];
				haslo = slowa[2];

				if (stanowisko == "administrator")
				{
					Administrator* wa = new Administrator(stanowisko, login, haslo);
					uzytkownicy.push_back(wa);
				}
				else if (stanowisko == "kasjer") 
				{
					Kasjer* wk = new Kasjer(stanowisko, login, haslo);
					uzytkownicy.push_back(wk);
				}
			}
			else 
			{
				cout << "Za malo danych" << endl;
				break;
			}
		}
		return;
		file.close();
	}
}

void odczyt_produktow(string nazwa_pliku, vector<Produkt*>& produkty)
{
	fstream file;
	file.open(nazwa_pliku, ios::in);
	if(file.is_open())
	{
		string wiersz;
		while (getline(file, wiersz))
		{
			vector<string> slowa;
			stringstream s(wiersz);
			string slowo, kategoria, nazwa, cena, ilosc;
			while (s >> slowo) slowa.push_back(slowo);

			if (slowa.size() == 4)
			{
				kategoria = slowa[0];
				nazwa = slowa[1];
				cena = slowa[2];
				ilosc = slowa[3];

				if (czy_liczba(cena) && czy_liczba(ilosc))
				{
					if (kategoria == "mieso" || kategoria == "oiw")
					{
						int cenawint = stoi(cena);
						double wagawdouble = stod(ilosc);
						Produkt_na_wage* waga = new Produkt_na_wage(kategoria, nazwa, cenawint, wagawdouble);
						produkty.push_back(waga);
					}
					else
					{
						int cenawint = stoi(cena);
						int iloscwint = stoi(ilosc);
						Produkt_na_ilosc* ilosc = new Produkt_na_ilosc(kategoria, nazwa, cenawint, iloscwint);
						produkty.push_back(ilosc);
					}
				}
			}
			else
			{
				cout << "Za malo danych!" << endl;
				break;
			}
		}
		file.close();
	}
}

void odczyt_kas(string nazwa_pliku, Kasa kasy[])
{
	fstream file;
	file.open(nazwa_pliku, ios::in);
	if (file.is_open())
	{
		int i = 0;
		string line;
		while (getline(file, line))
		{
			if (i > (sizeof(kasy) / sizeof(int))+1) break;
			if (czy_liczba(line))
			{
				Kasa nowa(stod(line));
				kasy[i] = nowa;
				i++;
			}
		}
		file.close();
	}
}

void wyswietl_kategorie()
{
	cout << "1.____PIECZYWO_____" << endl;
	cout << "2.______NABIAL_____" << endl;
	cout << "3.______MIESO______" << endl;
	cout << "4.______SUCHE______" << endl;
	cout << "5._OWOCE I WARZYWA_" << endl;
	cout << "6.____PRZEKASKI____" << endl;
	cout << "7.______NAPOJE_____" << endl;
	cout << "8.__KAWY/HERBATY___" << endl;
}

void zapis_uzytkownikow(string nazwa_pliku, vector<Uzytkownik*> uzytkownicy)
{
	fstream file;
	file.open(nazwa_pliku, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < uzytkownicy.size(); i++)
		{
			file << uzytkownicy[i]->stanowisko << " " << uzytkownicy[i]->login << " " << uzytkownicy[i]->haslo << endl;
			delete uzytkownicy[i];
		}
		return;
		file.close();
	}
}

void zapis_produktow(string nazwa_pliku, vector<Produkt*> produkty)
{
	fstream file;
	file.open(nazwa_pliku, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < produkty.size(); i++)
		{
			file << produkty[i]->kategoria << " " << produkty[i]->nazwa << " " << produkty[i]->cena << " " << produkty[i]->iloscwaga() << endl;
			delete produkty[i];
		}
		file.close();
	}
}
void zapis_kas(string nazwa_pliku, Kasa kasy[])
{
	fstream file;
	file.open(nazwa_pliku, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			file << kasy[i].ilePieniedzy() << endl;
		}
		file.close();
	}
}

bool czy_liczba(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) == 0 && s[i] != ',' && s[i] != '.')
			return false;
	}
	return true;
}