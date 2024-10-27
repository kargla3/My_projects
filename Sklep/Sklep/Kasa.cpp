#include <iostream>
#include "Kasa.h"
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include "Produkt.h"
#include "Produkt_na_ilosc.h"
#include "Produkt_na_wage.h"
#include "funkcje.h"

using namespace std;

Kasa::Kasa(double kasa)
{
	this->kasa = kasa;
}

double Kasa::ilePieniedzy()
{
	return kasa;
}

void Kasa::Sprzedaj(vector<Produkt*>& produkty)
{
	vector<Produkt*> lista_zakupowa;
	while (1)
	{
		system("cls");
		wyswietl_kategorie();
		cout << "\nAby wybrac kategorie produktu, ktory chcesz sprzedac, nacisnij odpowiednia cyfre";
		cout << "\nAby sprzedac produkty z listy nacisnij enter";
		cout << "\nAby wyjsc, nacisnij esc\n\n";
		cout << "\n\nLISTA PRODUKTOW Z KOSZYKA" << endl;
		for (int i = 0; i < lista_zakupowa.size(); i++)
		{
			cout << lista_zakupowa[i]->Nazwa() << " " << lista_zakupowa[i]->iloscwaga() << endl;
		}
		int z = _getch();
		if (z > 48 && z < 57) 
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
					if (counter == 0) 	cout << setw(40) << "NAZWA" << setw(15) << "CENA" << setw(15) << "ILOSC/WAGA" << "\n\n";
					counter++;
					if (kategoria == "mieso" || kategoria == "oiw")
						cout << counter << setw(40) << produkty[i]->Nazwa() << setw(15) << produkty[i]->Cena() << "zl/kg" << setw(15) << produkty[i]->iloscwaga() << "kg" << endl;
					else
						cout << counter << setw(40) << produkty[i]->Nazwa() << setw(15) << produkty[i]->Cena() << "zl" << setw(15) << produkty[i]->iloscwaga() << endl;

				}
			}
			cout << "\n\nAby wybrac produkt, nacisnij 1" << endl;
			cout << "Aby wrocic do menu, nacisnij esc" << endl;
			while (1)
			{
				int y = _getch();
				if (y == 49) { wybierz_produkt(kategoria,lista_zakupowa,produkty); break; }
				if (y == 27) { break; }
			}
		}
		if (z == 13) { potwierdz_sprzedaz(produkty, lista_zakupowa); break; }
		if (z == 27) { return; }
	}
}

void Kasa::Remanent(vector<Produkt*> produkty)
{
	cout << setw(15) << "KATEGORIA" << setw(40) << "NAZWA" << setw(15) << "CENA" << setw(15) << "ILOSC/WAGA" << "\n\n";
	for (int i = 0; i < produkty.size(); i++)
	{
		if (produkty[i]->Kategoria() == "mieso" || produkty[i]->Kategoria() == "oiw")
			cout << setw(15) << produkty[i]->Kategoria() << setw(40) << produkty[i]->Nazwa() << setw(15) << produkty[i]->Cena() << "zl/kg" << setw(15) << produkty[i]->iloscwaga() << "kg" << endl;
		else
			cout << setw(15) << produkty[i]->Kategoria() << setw(40) << produkty[i]->Nazwa() << setw(15) << produkty[i]->Cena() << "zl" << setw(18) << produkty[i]->iloscwaga() << endl;
	}
	cout << "Nacisnij esc aby wyjsc" << endl;
	while (1)
	{
		int z = _getch();
		if (z == 27)
			return;
	}
}

void Kasa::wybierz_produkt(string kategoria,vector<Produkt*>& lista_zakupowa, vector<Produkt*> produkty)
{
	string n, il;
	do
	{
		cout << "\nWybierz numer produktu, ktory chcesz dodac do listy: ";
		cin >> n;
	} while (czy_liczba(n) == 0);
	int numer = stoi(n);
	int counter = 0;
	if (kategoria == "mieso" || kategoria == "oiw")
	{
		for (int i = 0; i < produkty.size(); i++)
		{
			if (produkty[i]->Kategoria() == kategoria)
			{
				counter++;
				if (counter == numer)
				{
					string k = produkty[i]->Kategoria();
					string n = produkty[i]->Nazwa();
					double c = produkty[i]->Cena();
					double w = produkty[i]->iloscwaga();
					Produkt_na_wage* nowy = new Produkt_na_wage(k, n, c, w);
					lista_zakupowa.push_back(nowy);
				}
			}
		}
		while (1)
		{
			do
			{
				cout << "\nPodaj wage: ";
				cin >> il;
			} while (czy_liczba(il) == 0);
			if (stod(il) <= lista_zakupowa[lista_zakupowa.size()-1]->iloscwaga())
				break;
		}
		double waga = stoi(il);
		lista_zakupowa[lista_zakupowa.size()-1]->zmien_iw(0, waga);
	}
	else
	{
		for (int i = 0; i < produkty.size(); i++)
		{
			if (produkty[i]->Kategoria() == kategoria)
			{
				counter++;
				if (counter == numer)
				{
					string k = produkty[i]->Kategoria();
					string n = produkty[i]->Nazwa();
					double c = produkty[i]->Cena();
					int il = produkty[i]->iloscwaga();
					Produkt_na_ilosc* nowy = new Produkt_na_ilosc(k, n, c, il);
					lista_zakupowa.push_back(nowy);
				}
			}
		}
		while (1)
		{
			do
			{
				cout << "\nPodaj ilosc: ";
				cin >> il;
			} while (czy_liczba(il) == 0);
			if (stoi(il) <= lista_zakupowa[lista_zakupowa.size() - 1]->iloscwaga())
				break;
		}
		int ilosc = stoi(il);
		lista_zakupowa[lista_zakupowa.size()-1]->zmien_iw(ilosc, 0);
	}
}

void Kasa::potwierdz_sprzedaz(vector<Produkt*>& produkty, vector<Produkt*> lista_zakupowa)
{
	for (int i = 0; i < produkty.size(); i++)
		for (int j = 0; j < lista_zakupowa.size(); j++)
		{
			if (produkty[i]->Nazwa() == lista_zakupowa[j]->Nazwa())
			{
				if (produkty[i]->Kategoria() == "mieso" || produkty[i]->Kategoria() == "oiw")
				{
					double nowa_waga = produkty[i]->iloscwaga() - lista_zakupowa[j]->iloscwaga();
					produkty[i]->zmien_iw(0, nowa_waga);
				}
				else
				{
					int nowa_ilosc = produkty[i]->iloscwaga() - lista_zakupowa[j]->iloscwaga();
					produkty[i]->zmien_iw(nowa_ilosc, 0);
				}
				kasa += lista_zakupowa[j]->Cena() * lista_zakupowa[j]->iloscwaga();
			}

		}
	for (int i = 0; i < lista_zakupowa.size(); i++)
	{
		delete lista_zakupowa[i];
	}
}