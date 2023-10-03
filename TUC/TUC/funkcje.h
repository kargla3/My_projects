#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "struktury.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Funkcja wyswietlajaca instrukcje do pliku 1
void instrukcja1();

/// Funkcja wyswietlajaca instrukcje do pliku 2
void instrukcja2();

/// Przypisanie zmiennych w zaleznosci od przelacznikow
/// @param argc ilosc polecen
/// @param argv[] polecenia
/// @returns struktura z nazwami plikow
parameter parameters(int agrc, char* argv[]);

/// Rozdzielanie linijki na wektor slow
/// @param text linijka w pliku
/// @param element element rozdzielajacy
vector<string> splitter(string text, char element);

/// Przyporzadkowanie danych(wezly wejsc i wyjsc) pod odpowiednie bramki
/// @param vector wektor slow zawierajacych dane z danej linijki
/// @param name struktura danych jednej osobnej bramki
/// @param type typ bramki
void applier(vector<string> vector, configuration& name, string type);

/// Usuwanie pustych linijek w pliku
void scanner(vector<string> &vector);

/// Wyliczanie stanow wyjsc dla poszczegolnych typow bramek i stanow wejsc
/// @param name uklad danej bramki
int type(configuration &name);

/// Funkcja wyswietlajaca w konsoli wezly wejsciowe, wyjsciowe i caly uklad bramek
/// @param gate wektor bramek logicznych
/// @param in wektor wezlow wejsciowych
/// @param out wektor wezlow wyjsciowych
void showgates(vector<configuration> gate, vector<int> in, vector<int> out);

/// Funkcja zczytujaca dane z pliku pierwszego, oraz implemetujaca do poszczegolnych wektorow
/// @param filename nazwa pliku
/// @param gate wektor bramek logicznych
/// @param in wektor wezlow wejsciowych
/// @param out wektor wezlow wyjsciowych
void file1reader(string filename, vector<configuration>& gate, vector<int> &in, vector<int> &out, bool& switch1);

/// Funkcja zczytujaca stany logiczne z pliku drugiego 
/// @param filename nazwa pliku
/// @param logdata wektor stanow logicznych dla odpowiednich wezlow wejsciowych
/// @param in wektor wezlow wejsciowych
void file2reader(string filename, vector<logstate>& logdata, vector<int> in, bool& switch2);

/// Funkcja wyliczajaca wszystkie stany logiczne na podstawie typow bramek oraz wezlow
/// @param status wektor stanow logicznych dla odpowiednich wezlow wejsciowych
/// @param gate wektor bramek logicznych
/// @param in wektor wezlow wejsciowych
/// @param out wektor wezlow wyjsciowych
void calculator(vector<logstate>& status, vector<configuration>& gate, vector<int> in, vector<int> out, bool switch1, bool switch2);

/// Funkcja zapisujaca odpowiednie dane do pliku wyjsciowego
/// @param filename nazwa pliku
/// @param status wektor stanow logicznych dla odpowiednich wezlow wejsciowych
/// @param in wektor wezlow wejsciowcyh
/// @param out wektor wezlow wyjsciowych
void file3writer(string filename, vector<logstate> status, vector<int> in, vector<int> out, bool switch1, bool switch2);

#endif