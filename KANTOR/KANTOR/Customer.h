#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

class Customer
{
	vector<pair<string, double>> wallet;
	string filename;
public:
	Customer(string);
	vector<pair<string, double>> return_wallet();
	void show_wallet();
	void finalize(string[], double, double, int, int);
	void savewallet();
};

