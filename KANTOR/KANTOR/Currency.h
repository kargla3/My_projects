#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

class Currency
{
	string exchange_pair;
	double buy_price;
	double sell_price;

public:
	Currency(string,double,double);
	string Exchange_pair();
	double Buy_price();
	double Sell_price();
	static vector<Currency> load_currencies(string);
	void show_pair();
};

