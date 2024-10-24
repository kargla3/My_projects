#include "Cash_register.h"

Cash_register::Cash_register(vector<Currency> vector)
{
	currencies = vector;
}

void Cash_register::menu(Customer customer)
{
	int z = 1;
	while (1)
	{
		system("cls");
		cout << "ONLINE CURRENCY EXCHANGE" << endl;
		show_currencies();
		cout << "        " << arrow(z, ">", 1) << "EXCHANGE" << arrow(z, "<", 1) << endl;
		cout << "          " << arrow(z, ">", 2) << "EXIT" << arrow(z, "<", 2) << endl; 

		cout << "\n/\\ or \\/ \t - SELECT" << endl;
		cout << "ENTER \t\t - CONFIRM" << endl;

		int n = _getch();
		if (n == 72) z--;
		else if (n == 80) z++;
		else if (z == 1 && n == 13) { choose_currency(customer); }
		else if (z == 2 && n == 13) { customer.savewallet(); exit(0); }
		if (z == 3) z = 1;
		else if (z == 0) z = 2;
	}

}

void Cash_register::show_currencies()
{
	cout << "          SELL     BUY" << endl;
	for (int i = 0; i < currencies.size(); i++)
		currencies[i].show_pair();
}


string Cash_register::arrow(int n, string direction, string opt)
{
	if (n == 1 && opt == "exchange") return direction;
	else if (n == 2 && opt == "exit") return direction;
	else return " ";
}
string Cash_register::arrow(int n, string direction, int opt)
{
	if (n == opt) return direction;
	else return " ";
}

void Cash_register::choose_currency(Customer &customer)
{
	int z = 1;
	int pairs = currencies.size();
	while (1)
	{
		system("cls");
		cout << "\tSELECT CURRENCY" << endl;
		cout << "           SELL     BUY" << endl;
		for (int i = 0; i < pairs; i++)
			cout << arrow(z, "> ", i + 1) << currencies[i].Exchange_pair() << "   " << currencies[i].Buy_price() << "   " << currencies[i].Sell_price() << arrow(z, " <", i + 1) << endl << endl;
		cout << "/\\ or \\/ \t - SELECT" << endl;
		cout << "ENTER \t\t - CONFIRM" << endl;
		cout << "ESC \t\t - BACK" << endl;
		int n = _getch();
		if (n == 72) z--;
		else if (n == 80) z++;
		else if (n == 13) { buy_sell(currencies[z - 1], customer); }
		else if (n == 27) { break; };
		if (z > pairs) z = 1;
		else if (z == 0) z = pairs;
	}
}

void Cash_register::buy_sell(Currency currency, Customer &customer)
{
	int z = 1;
	int x = 1;
	int changed_characters = 0;
	string pair, first, second, first_amount, second_amount;
	string p[2];
	bool wallet = false;
	pair = currency.Exchange_pair();
	first_amount = " 0                ";
	second_amount = " 0                ";
	first.resize(pair.size());
	second.resize(pair.size());
	string::iterator itb = pair.begin();
	string::iterator ite = pair.end();
	copy(itb, find(itb, ite, '/'), first.begin());
	itb = find(itb, ite, '/') + 1;
	copy(itb, find(itb, ite, '/'), second.begin());
	while (1)
	{
		system("cls");
		if (z == 1 && x == 1)
			cout << "  BUY " << first << endl;
		else if (z == 2 && x == 1)
			cout << "  SELL " << first << endl;
		else if (z == 1 && x == 2)
			cout << "  BUY " << second << endl;
		else if (z == 2 && x == 2)
			cout << "  SELL " << second << endl;
 
		if (x == 1)
		{
			p[0] = first;
			p[1] = second;
		}
		else
		{
			p[0] = second;
			p[1] = first;
		}

		cout << "\n         " << p[0] << endl;
 
		for (int i = 0; i < 20; i++)
			cout << "#";
		cout << "\n#" << first_amount << '#';
		if (changed_characters == 9) cout << " 9 CHARACTERS LIMIT!" << endl;
		else cout << endl;

		for (int i = 0; i < 20; i++)
			cout << '#';
		cout << endl;

		cout << "\n         " << p[1] << endl;

		for (int i = 0; i < 20; i++)
			cout << "#";

		cout << "\n#" << second_amount << '#' << endl;
		for (int i = 0; i < 20; i++)
			cout << '#';

		cout << "\n\n/\\ or \\/ \t - SELL/BUY" << endl;
		cout << "<= or => \t - " << first << '/' << second << endl;
		cout << "ENTER \t\t - EXCHANGE" << endl;
		cout << "W \t\t - CHECK WALLET" << endl;
		cout << "ESC \t\t - BACK" << endl;

		if (wallet)
			customer.show_wallet();

		int n = _getch();
		if (n == 72)
		{
			z--;
			if (z == 0) z = 2;
			calculate(first_amount, second_amount, currency, z, x);
		}
		else if (n == 80)
		{
			z++;
			if (z == 3) z = 1;
			calculate(first_amount, second_amount, currency, z, x);
		}
		else if (n == 75)
		{
			x--;
			first_amount = " 0                ";
			changed_characters = 0;
			if (x == 0) x = 2;
			calculate(first_amount, second_amount, currency, z, x);
		}
		else if (n == 77)
		{
			x++;
			first_amount = " 0                ";
			changed_characters = 0;
			if (x == 3) x = 1;
			calculate(first_amount, second_amount, currency, z, x);
		}
		else if (n == 13)
		{
			if (changed_characters > 0)
			{
				exchange(customer, p, stod(first_amount), stod(second_amount), z);
				wallet = false;
			}
			else
			{
				cout << "\nENTER AMOUNT" << endl;
				_getch();
			}
		}
		else if (n == 119) { wallet = true; }
		else if (n == 27) { break; }
		else if (n > 45 && n < 58 && n != 47)
		{	
			if (changed_characters < 9)
			{ 
				first_amount[changed_characters + 1] = n; changed_characters++; calculate(first_amount, second_amount, currency, z, x); 
			}
		}
		else if (n == 8) 
		{
			if (changed_characters > 1) 
			{
				changed_characters--;  first_amount[changed_characters + 1] = ' '; calculate(first_amount, second_amount, currency, z, x); 
			} 
			else if (changed_characters == 1)
			{
				changed_characters--; first_amount[changed_characters + 1] = '0'; calculate(first_amount, second_amount, currency, z, x);
			}
		}
	}
}

void Cash_register::calculate(string first, string& second, Currency currency, int z, int x)
{
	double fa = stod(first);
	double multiplier = 0;
	if (x == 1)
		if (z == 1) { multiplier = currency.Sell_price(); }
		else { multiplier = currency.Buy_price(); }
	else 
		if (z == 1) { multiplier = 1 / currency.Buy_price(); }
		else { multiplier = 1 / currency.Sell_price(); }

	double sa = round(fa * multiplier * 1000) / 1000;
	second = ' ' + to_string(sa);
	second = second.substr(0, second.find_last_not_of('0') + 1);
	second = second.substr(0, second.find_last_not_of('.') + 1);
	string freespace = "";
	if (second.size() < first.size())
	{
		for (int i = 0; i < first.size() - second.size(); i++)
			freespace += " ";
	}
	second += freespace;
}

void Cash_register::exchange(Customer &customer, string pair[], double first_amount, double second_amount, int z)
{
	int index = -1;
	
	pair[0] = pair[0].substr(0, 3);
	pair[1] = pair[1].substr(0, 3);

	switch (z)
	{
		case 1:
			for (int i = 0; i < customer.return_wallet().size(); i++)
				if (customer.return_wallet()[i].first.substr(0, 3) == pair[1])
					index = i;

			if (index == -1)
				cout << "\nYOU DONT HAVE ENOUGH MONEY!" << endl;
			else
			{
				if (customer.return_wallet()[index].second >= second_amount)
					customer.finalize(pair, first_amount, second_amount, index, z);
				else
					cout << "\nYOU DONT HAVE ENOUGH MONEY" << endl;
			}
			break;
		case 2:
			for (int i = 0; i < customer.return_wallet().size(); i++)
				if (customer.return_wallet()[i].first.substr(0, 3) == pair[0])
					index = i;

			if (index == -1)
				cout << "\nYOU DONT HAVE ENOUGH MONEY!" << endl;
			else
			{
				if (customer.return_wallet()[index].second >= first_amount)
					customer.finalize(pair, first_amount, second_amount, index, z);
				else
					cout << "\nYOU DONT HAVE ENOUGH MONEY" << endl;
			}
			break;
	}
	_getch();
}
