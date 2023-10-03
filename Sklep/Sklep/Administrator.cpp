#include "Administrator.h"
#include "Uzytkownik.h"
#include <vector>
#include <iostream>
#include <string>
#include <conio.h>
#include "funkcje.h"
#include <Windows.h>
#include <iomanip>
#include "Kasjer.h"

Administrator::Administrator(string stanowisko, string login, string haslo) : Uzytkownik(stanowisko, login, haslo) {}

void Administrator::menu(vector<Uzytkownik*>& uzytkownicy, vector<Produkt*>& produkty, Kasa kasy[])
{
	while (1)
	{
		system("cls");
		cout << "\nMenu administratora" << endl;
		wyswietl_kategorie();
		cout << "\nAby wybrac kategorie, nacisnij odpowiednia cyfre";
		cout << "\nAby dodac uzytkownika, nacisnij 9";
		cout << "\nAby wylogowac, nacisnij esc";
		while (1)
		{
			int z = _getch();
			if (z > 48 && z < 57) { przejdz_do_kategorii(z, produkty); break; }
			if (z == 57) { dodaj_uzytkownika(uzytkownicy); break; }
			if (z == 27) { return; }
		}
	}
}

void Administrator::dodaj_uzytkownika(vector<Uzytkownik*>& uzytkownicy)
{
	string stanowisko, login, haslo;
	cout << "\n\nDodawanie nowego uzytkownika";
	while (stanowisko != "administrator" && stanowisko != "kasjer")
	{
		cout << "\n\nPodaj stanowisko (do wyboru administrator/kasjer): ";
		cin >> stanowisko;
	}
	cout << "Podaj nowy login: ";
	cin >> login;
	cout << "Podaj nowe haslo: ";
	cin >> haslo;
	for (int i = 0; i < uzytkownicy.size(); i++)
	{
		if (uzytkownicy[i]->Login() == login)
		{
			cout << "Nie udalo sie dodac uzytkownika! Login juz istnieje";
			Sleep(3000);
			return;
		}
	}
	if (stanowisko == "administrator")
	{
		Administrator* nowy = new Administrator(stanowisko, login, haslo);
		uzytkownicy.push_back(nowy);
	}
	else if (stanowisko == "kasjer")
	{
		Kasjer* nowy = new Kasjer(stanowisko, login, haslo);
		uzytkownicy.push_back(nowy);
	}
	cout << "Pomyslnie dodano nowego uzytkownika!";
	Sleep(3000);
}

void Administrator::przejdz_do_kategorii(int z, vector<Produkt*>& produkty)
{
	system("cls");
	string kategoria;
	z -= 48;

	switch (z)
	{
	case 1:
		kategoria = "pieczywo";
		cout << "PIECZYWO" << endl;
		break;
	case 2:
		kategoria = "nabial";
		cout << "NABIAL" << endl;
		break;
	case 3:
		kategoria = "mieso";
		cout << "MIESO" << endl;
		break;
	case 4:
		kategoria = "suche";
		cout << "SUCHE" << endl;
		break;
	case 5:
		kategoria = "oiw";
		cout << "OWOCE I WARZYWA" << endl;
		break;
	case 6:
		kategoria = "przekaski";
		cout << "PRZEKASKI" << endl;
		break;
	case 7:
		kategoria = "napoje";
		cout << "NAPOJE" << endl;
		break;
	case 8:
		kategoria = "kh";
		cout << "KAWY I HERBATY" << endl;
		break;
	}
	int counter = 0;
	for (int i = 0; i < produkty.size(); i++)
	{
		if (produkty[i]->Kategoria() == kategoria)
		{
			counter++;
			if (kategoria == "mieso" || kategoria == "oiw")
			{
				if (counter == 1) 	cout << setw(40) << "NAZWA" << setw(15) << "CENA" << setw(15) << "WAGA" << "\n\n";
				cout << counter << setw(40) << produkty[i]->Nazwa() << setw(15) << produkty[i]->Cena() << "zl/kg" << setw(15) << produkty[i]->iloscwaga() << "kg" << endl;
			}
			else
			{
				if (counter == 1) 	cout << setw(40) << "NAZWA" << setw(15) << "CENA" << setw(15) << "ILOSC" << "\n\n";
				cout << counter << setw(40) << produkty[i]->Nazwa() << setw(15) << produkty[i]->Cena() << "zl" << setw(15) << produkty[i]->iloscwaga() << endl;
			}

		}
	}
	cout << "\n\nAby dodac nowy produkt, nacisnij 1" << endl;
	cout << "Aby usunac istniejacy produkt, nacisnij 2" << endl;
	cout << "Aby zmienic ilosc danego produktu, nacisnij 3" << endl;
	cout << "Aby zmienic cene danego produktu, nacisnij 4" << endl;
	cout << "Aby wrocic do menu, nacisnij esc" << endl;
	while (1)
	{
		int z = _getch();
		if (z == 49) { nowyprodukt(produkty, kategoria); break; }
		if (z == 50) { usunprodukt(produkty, kategoria); break; }
		if (z == 51) { zmienilosc(produkty, kategoria); break; }
		if (z == 52) { zmiencene(produkty, kategoria); break; }
		if (z == 27) { return; }
	}
}

void Administrator::zmiencene(vector<Produkt*>& produkty, string kategoria)
{
	string numer;
	int counter = 0;
	string cena;
	do
	{
		cout << "\nPodaj numer produktu, ktorego cene chcesz zmienic: ";
		cin >> numer;
	} while (czy_liczba(numer) == 0);

	do
	{
		cout << "\nPodaj nowa cene: ";
		cin >> cena;
	} while (czy_liczba(cena) == 0);

	int n = stoi(numer);
	double c = stod(cena);
	for (int i = 0; i < produkty.size(); i++)
	{
		if (produkty[i]->Kategoria() == kategoria)
		{
			counter++;
			if (counter == n)
			{
				produkty[i]->zmien_cene(c);
			}
		}
	}
}