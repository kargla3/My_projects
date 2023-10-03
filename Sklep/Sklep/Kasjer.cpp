#include "Kasjer.h"
#include "Uzytkownik.h"
#include <iostream>
#include "funkcje.h"
#include <iomanip>
#include <conio.h>
#include <string>
#include <vector>

Kasjer::Kasjer(string stanowisko, string login, string haslo) : Uzytkownik(stanowisko, login, haslo) {}

void Kasjer::menu(vector<Uzytkownik*>& uzytkownicy, vector<Produkt*>& produkty, Kasa kasy[])
{
	while (1)
	{
		system("cls");
		cout << "\nMenu kasjera" << endl;
		wyswietl_kategorie();
		cout << "\nAby wybrac kategorie, nacisnij odpowiednia cyfre";
		cout << "\nAby otworzyc kase, nacisnij 9";
		cout << "\nAby wylogowac, nacisnij esc" << endl;
		while (1)
		{
			int z = _getch();
			if (z > 48 && z < 57) { przejdz_do_kategorii(z, produkty); break; }
			if (z == 57) { przejdz_do_kas(kasy, produkty); break; }
			if (z == 27) { return; }
		}
	}
}

void Kasjer::przejdz_do_kategorii(int z, vector<Produkt*>& produkty)
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
	cout << "Aby wrocic do menu, nacisnij esc" << endl;
	while (1)
	{
		int z = _getch();
		if (z == 49) { nowyprodukt(produkty, kategoria); break; }
		if (z == 50) { usunprodukt(produkty, kategoria); break; }
		if (z == 51) { zmienilosc(produkty, kategoria); break; }
		if (z == 27) { return; }
	}
}

void Kasjer::przejdz_do_kas(Kasa kasy[], vector<Produkt*>& produkty)
{
	system("cls");
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "\t" << "Kasa" << endl;
	}
	cout << "Aby wybrac kase, nacisnij odpowiednia cyfre" << endl;
	cout << "Aby wyjsc, nacisnij esc" << endl;
	while (1)
	{
		int z = _getch();
		if (z > 48 && z < 53) { kasa(z, kasy, produkty); break; }
		if (z == 27) { return; }

	}
}

void Kasjer::kasa(int z, Kasa kasy[], vector<Produkt*>& produkty)
{
	system("cls");
	z -= 48;
	cout << "Kasa " << z << endl;
	cout << "Saldo: " << kasy[z - 1].ilePieniedzy() << endl;
	cout << "\nAby zrobic remanent, nacisnij 1" << endl;
	cout << "Aby sprzedac produkty, nacisnij 2" << endl;
	cout << "Aby wyjsc, nacisnij esc" << endl << endl;
	while (1)
	{
		int x = _getch();
		if (x == 49) { kasy[z - 1].Remanent(produkty); break; }
		if (x == 50) { kasy[z - 1].Sprzedaj(produkty); break; }
		if (x == 27) { return; }
	}
}