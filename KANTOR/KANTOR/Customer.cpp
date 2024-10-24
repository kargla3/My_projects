#include "Customer.h"

Customer::Customer(string filename)
{
	this->filename = filename;
	vector<pair<string, double>> v;
	ifstream file(filename);
	for (istream_iterator<string> it(file), end; it != end; it++)
	{
		string line = *it;
		string currency, amount;
		currency.resize(line.size());
		amount.resize(line.size());
		string::iterator itb = line.begin();
		string::iterator ite = line.end();
		
		copy(itb, find(itb, ite, '|'), currency.begin());
		itb = find(itb, ite, '|') + 1;
		copy(itb, find(itb, ite, '|'), amount.begin());

		currency = currency.substr(0, 3);
		pair<string, double> pair;
		pair.first = currency;
		pair.second = stod(amount);
		v.push_back(pair);
	}
	this->wallet = v;
}
vector<pair<string, double>> Customer::return_wallet()
{
	return wallet;
}

void Customer::show_wallet()
{
	cout << "\nYOUR WALLET" << endl;
	for (int i = 0; i < wallet.size(); i++)
	{
		cout << wallet[i].first << " " << wallet[i].second << endl;
	}
}

void Customer::finalize(string p[], double first_amount, double second_amount, int index, int z)
{
	int n;
	int secondindex = -1;
	cout << "\nDO YOU WANT TO FINALIZE TRANSACTION?" << endl;
	cout << "Y \t\t - YES" << endl;
	cout << "N \t\t - NO" << endl;
	while (1)
	{
		n = _getch();
		if (n == 121)
		{
			if (z == 1)
			{
				wallet[index].second -= second_amount;
				for (int i = 0; i < wallet.size(); i++)
					if (wallet[i].first.substr(0,3) == p[0])
						secondindex = i;
				if (secondindex == -1)
				{
					pair<string, double> newpair;
					newpair.first = p[0];
					newpair.second = first_amount;
					wallet.push_back(newpair);
				}
				else
				{
					wallet[secondindex].second += first_amount;
				}
			}
			else
			{
				wallet[index].second -= first_amount;
				for (int i = 0; i < wallet.size(); i++)
					if (wallet[i].first.substr(0, 3) == p[1])
						secondindex = i;
				if (secondindex == -1)
				{
					pair<string, double> newpair;
					newpair.first = p[1];
					newpair.second = second_amount;
					wallet.push_back(newpair);
				}
				else
				{
					wallet[secondindex].second += second_amount;
				}
			}
			cout << "TRANSACTION ACCEPTED!" << endl;
			cout << "PRESS ANY KEY TO CONTINUE" << endl;
			break;
		}
		else if (n == 110)
		{
			cout << "TRANSACTION DENIED!" << endl;
			cout << "PRESS ANY KEY TO CONTINUE" << endl;
			break;
		}
	}
}

void Customer::savewallet()
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < wallet.size(); i++)
		{
			file << wallet[i].first << '|' << wallet[i].second << endl;
		}
		file.close();
	}
}