#include "Currency.h"

Currency::Currency(string currency, double buy, double sell)
{
	this->exchange_pair = currency;
	this->buy_price = buy;
	this->sell_price = sell;
}

string Currency::Exchange_pair()
{
	return exchange_pair;
}

double Currency::Buy_price()
{
	return buy_price;
}

double Currency::Sell_price()
{
	return sell_price;
}

vector<Currency> Currency::load_currencies(string filename)
{
	vector<Currency> v;
	ifstream file(filename);
	for (istream_iterator<string> it(file), end; it != end; it++)
	{
		string line = *it;
		string pair, buy, sell;
		pair.resize(line.size());
		buy.resize(line.size());
		sell.resize(line.size());
		string::iterator itb = line.begin();
		string::iterator ite = line.end();
		
		copy(itb, find(itb, ite, '|'), pair.begin());
		itb = find(itb, ite, '|') + 1;
		copy(itb, find(itb, ite, '|'), buy.begin());
		itb = find(itb, ite, '|') + 1;
		copy(itb, find(itb, ite, '\n'), sell.begin());
		Currency c(pair, stod(buy), stod(sell));
		v.push_back(c);
	}

	return v;
}

void Currency::show_pair()
{
	cout <<exchange_pair << "   " << buy_price << "   " << sell_price << endl << endl;
}
