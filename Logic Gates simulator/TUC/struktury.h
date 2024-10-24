#ifndef STRUKTURY_H
#define STRUKTURY_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Struktura nazw plikow wejsciowych i pliku wyjsciowego 
struct parameter {
/// @param in1 nazwa pliku z ukladem bramek logicznych
	string in1;
/// @param in2 nazwa pliku z wartosciami logicznymi
	string in2;
/// @param out nazwa pliku wyjsciowego
	string out;
};

/// Struktura danych bramki logicznej
struct configuration {
/// @param type typ bramki
	string type;
/// @param t_in1 numer wezla wejsciowego nr1
	int t_in1;
/// @param b_in1 stan logiczny wezla wejsciowego nr1
	int b_in1;

/// @param t_in2 numer wezla wejsciowego nr2
	int t_in2;
/// @param b_in2 stan logiczny wezla wejsciowego nr2
	int b_in2;

/// @param t_out numer wezla wyjsciowego
	int t_out;
/// @param b_out stan logiczny wezla wyjsciowego
	int b_out;

	bool finded = false;
};

/// Struktura stanow logicznych posczegolnych wejsc i wyjsc
struct logstate {
	/// @param b_in wektor stanow logicznych wejsc ukladu
	vector<int> b_in;
	/// @param b_out wektor stanow logicznych wyjsc ukladu
	vector<int> b_out;
};


#endif 