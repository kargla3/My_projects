#pragma once
#include "Currency.h"
#include "Customer.h"
#include <conio.h>
#include <cmath>

class Cash_register
{
	vector<Currency> currencies;

public:
	Cash_register(vector<Currency>);
	void menu(Customer);
	void show_currencies();
	string arrow(int, string, string);
	static string arrow(int, string, int);
	void choose_currency(Customer&);
	void buy_sell(Currency, Customer&);
	void calculate(string, string&, Currency, int, int);
	void exchange(Customer&, string[] , double, double, int);
};

