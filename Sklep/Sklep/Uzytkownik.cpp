#include "Uzytkownik.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include "funkcje.h"
#include "Uzytkownik.h"
#include "Produkt.h"
#include "Produkt_na_ilosc.h"
#include "Produkt_na_wage.h"
#include "Kasa.h"


using namespace std;

Uzytkownik::Uzytkownik(string stanowisko, string login, string haslo)
{
	this->stanowisko = stanowisko;
	this->login = login;
	this->haslo = haslo;
}

string Uzytkownik::Login()
{
	return login;
}

void Uzytkownik::nowyprodukt(vector<Produkt*>& produkty, string kategoria)
{
	string nazwa, cena, ilosc;
	cout << "\nPodaj nazwe produktu: ";
	cin >> nazwa;
	do
	{
		cout << "\nPodaj cene produktu: ";
		cin >> cena;
	} while (czy_liczba(cena) == 0);

	if (kategoria == "mieso" || kategoria == "oiw")
	{
		do
		{
			cout << "\nPodaj wage produktu: ";
			cin >> ilosc;
		} while (czy_liczba(ilosc) == 0);
		int cenawint = stoi(cena);
		double wagawdouble = stod(ilosc);
		Produkt_na_wage* waga = new Produkt_na_wage(kategoria, nazwa, cenawint, wagawdouble);
		produkty.push_back(waga);
	}
	else
	{
		do
		{
			cout << "\nPodaj ilosc produktu: ";
			cin >> ilosc;
		} while (czy_liczba(ilosc) == 0);
		int cenawint = stoi(cena);
		int iloscwint = stoi(ilosc);
		Produkt_na_ilosc* ilosc = new Produkt_na_ilosc(kategoria, nazwa, cenawint, iloscwint);
		produkty.push_back(ilosc);
	}

	cout << "\nPomyslnie dodano produkt!" << endl;
	Sleep(3000);
}

void Uzytkownik::usunprodukt(vector<Produkt*>& produkty, string kategoria)
{
	string numer;
	int counter = 0;
	do 
	{
		cout << "\nPodaj numer produktu, ktory chcesz usunac: ";
		cin >> numer;
	} while (czy_liczba(numer) == 0);

	int n = stoi(numer);
	for (int i = 0; i < produkty.size(); i++)
	{
		if (produkty[i]->Kategoria() == kategoria)
		{
			counter++;
			if (counter == n)
			{
				delete produkty[i];
				produkty.erase(produkty.begin() + i);
			}
		}
	}
}

void Uzytkownik::zmienilosc(vector<Produkt*>& produkty, string kategoria)
{
	string numer;
	int counter = 0;
	if (kategoria == "mieso" || kategoria == "oiw")
	{
		string waga;
		do 
		{
			cout << "\nPodaj numer produktu, ktorego wage chcesz zmienic: ";
			cin >> numer;
		} while (czy_liczba(numer) == 0);

		do 
		{
			cout << "\nPodaj nowa wage: ";
			cin >> waga;
		} while (czy_liczba(waga) == 0);

		int n = stoi(numer);
		double w = stod(waga);
		for (int i = 0; i < produkty.size(); i++)
		{
			if (produkty[i]->Kategoria() == kategoria)
			{
				counter++;
				if (counter == n)
					produkty[i]->zmien_iw(0,w);
			}
		}
	}
	else
	{
		string ilosc;
		do
		{
			cout << "\nPodaj numer produktu, ktorego ilosc chcesz zmienic: ";
			cin >> numer;
		} while (czy_liczba(numer) == 0);

		do
		{
			cout << "\nPodaj nowa ilosc: ";
			cin >> ilosc;		
		} while (czy_liczba(ilosc) == 0);

		int n = stoi(numer);
		int il = stoi(ilosc);
		for (int i = 0; i < produkty.size(); i++)
		{
			if (produkty[i]->Kategoria() == kategoria)
			{
				counter++;
				if (counter == n)
					produkty[i]->zmien_iw(il,0);
			}
		}
	}
}