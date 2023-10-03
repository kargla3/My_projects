#include "funkcje.h"
#include "struktury.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void instrukcja1()
{
	cout << "Plik z ukladem ma nastepujaca postac:" << endl;
	cout << "IN: <wejscie1> <wejscie2> ..." << endl;
	cout << "OUT: <wyjscie ukladu> ..." << endl;
	cout << "<typ bramki> <wezel wejsciowy> <wezel wejsciowy> <wezel wyjsciowy> " << endl;
	cout << "<typ bramki> <wezel wejsciowy> <wezel wejsciowy> <wezel wyjsciowy> " << endl;
	cout << "..." << endl;
	cout << "Dostepne typy bramek: AND, NAND, OR, NOR, XOR, XNOR, NEG" << endl;
	cout << "Np. IN: 1 6" << endl;
	cout << "    OUT: 3" << endl;
	cout << "    NAND 1 6 5" << endl;
	cout << "    NAND 1 5 4" << endl;
	cout << "    NAND 5 6 2" << endl;
	cout << "    NAND 2 4 3" << endl;

}

void instrukcja2()
{
	cout << "Plik z wartosciami logicznymi ma nastepujaca postac" << endl;
	cout << "<wejscie1> : <wartosc logiczna>		<wejscie2> : <wartosc logiczna> ..." << endl;
	cout << "<wejscie1> : <wartosc logiczna>		<wejscie2> : <wartosc logiczna> ..." << endl;
	cout << "..." << endl;
	cout << "Np. 1:0		6:0" << endl;
	cout << "    1:0		6:1" << endl;
	cout << "    1:1		6:0" << endl;
	cout << "    1:1		6:1" << endl;
}

parameter parameters(int argc, char* argv[])
{
	parameter switches;
	if (argc == 7)
	{
		for (int i = 1; i < argc; i++)
		{
			string temp = argv[i];
			if (temp == "-in1") switches.in1 = argv[i + 1];
			else if (temp == "-in2") switches.in2 = argv[i + 1];
			else if (temp == "-out") switches.out = argv[i + 1];
		}
	}
	else
	{
		cout << "Nieprawidlowa ilosc przelacznikow" << endl;
		cout << "Podaj nazwe pliku z ukladem po '-in1', plik z wartosciami logicznymi po '-in2', oraz nazwe pliku wyjsciowego po '-out'" << endl;
		cout << "Jezeli chcesz zobaczyc instrukcje, wybierz 'i', jezeli nie, wybierz dowolny inny znak" << endl;
		char wybor;
		cin >> wybor;
		if (wybor == 'i')
		{
			instrukcja1();
			cout << endl;
			instrukcja2();
		}
		else getchar();
	}
	return switches;
}

vector<string> splitter(string text, char element)
{
	vector<string> words;
	int start = 0;
	int length = 0;
	for (int i = 0; i <= text.length(); i++)
	{
		if (text[i] == element || text[i] == ' ' || text[i] == '\0' || text[i] == ':' || text[i] == '\t')
		{
			length = i - start;
			words.push_back(text.substr(start, length));
			start = i + 1;
		}
	}
	return words;
}

void applier(vector<string> vector, configuration &name, string type)
{
	if (type == "AND" || type == "NAND" || type == "OR" || type == "NOR" || type == "XOR" || type == "XNOR")
	{
		name.type = vector[0];
		name.t_in1 = stoi(vector[1]);
		name.t_in2 = stoi(vector[2]);
		name.t_out = stoi(vector[3]);
	}
	else if (type == "NEG")
	{
		name.type = vector[0];
		name.t_in1 = stoi(vector[1]);
		name.t_out = stoi(vector[2]);
	}
}

void scanner(vector<string>& vector)
{
	for (int i = vector.size()-1; i > 0; i--)
	{
		if (vector[i] == "")
		{
			auto it = vector.begin()+i;
			vector.erase(it);
		}

	}
}

int type(configuration &name)
{
	if (name.type == "NAND")
	{
		if (name.b_in1 == 0 && name.b_in2 == 0) name.b_out = 1;
		else if (name.b_in1 == 0 && name.b_in2 == 1) name.b_out = 1;
		else if (name.b_in1 == 1 && name.b_in2 == 0) name.b_out = 1;
		else if (name.b_in1 == 1 && name.b_in2 == 1) name.b_out = 0;
		return name.b_out;
	}
	else if (name.type == "AND")
	{
		if (name.b_in1 == 0 && name.b_in2 == 0) name.b_out = 0;
		else if (name.b_in1 == 0 && name.b_in2 == 1) name.b_out = 0;
		else if (name.b_in1 == 1 && name.b_in2 == 0) name.b_out = 0;
		else if (name.b_in1 == 1 && name.b_in2 == 1) name.b_out = 1;
		return name.b_out;
	}
	else if (name.type == "NOR")
	{
		if (name.b_in1 == 0 && name.b_in2 == 0) name.b_out = 1;
		else if (name.b_in1 == 0 && name.b_in2 == 1) name.b_out = 0;
		else if (name.b_in1 == 1 && name.b_in2 == 0) name.b_out = 0;
		else if (name.b_in1 == 1 && name.b_in2 == 1) name.b_out = 0;
		return name.b_out;
	}
	else if (name.type == "OR")
	{
		if (name.b_in1 == 0 && name.b_in2 == 0) name.b_out = 0;
		else if (name.b_in1 == 0 && name.b_in2 == 1) name.b_out = 1;
		else if (name.b_in1 == 1 && name.b_in2 == 0) name.b_out = 1;
		else if (name.b_in1 == 1 && name.b_in2 == 1) name.b_out = 1;
		return name.b_out;
	}
	else if (name.type == "XOR")
	{
		if (name.b_in1 == 0 && name.b_in2 == 0) name.b_out = 0;
		else if (name.b_in1 == 0 && name.b_in2 == 1) name.b_out = 1;
		else if (name.b_in1 == 1 && name.b_in2 == 0) name.b_out = 1;
		else if (name.b_in1 == 1 && name.b_in2 == 1) name.b_out = 0;
		return name.b_out;
	}
	else if (name.type == "XNOR")
	{
		if (name.b_in1 == 0 && name.b_in2 == 0) name.b_out = 1;
		else if (name.b_in1 == 0 && name.b_in2 == 1) name.b_out = 0;
		else if (name.b_in1 == 1 && name.b_in2 == 0) name.b_out = 0;
		else if (name.b_in1 == 1 && name.b_in2 == 1) name.b_out = 1;
		return name.b_out;
	}
	else if (name.type == "NEG")
	{
		if (name.b_in1 == 0) name.b_out = 1;
		else if (name.b_in1 == 1) name.b_out = 0;
		return name.b_out;
	}
}

void showgates(vector<configuration> gate, vector<int> in, vector<int> out)
{
	for (int i = 0; i < in.size(); i++)
	{
		cout << "IN: ";
		cout << in[i] << endl;
	}
	for (int i = 0; i < out.size(); i++)
	{
		cout << "OUT: ";
		cout << out[i] << endl;
	}
	for (int i = 0; i < gate.size(); i++)
	{
		cout << gate[i].type << endl;
		cout << gate[i].t_in1 << endl;

		if (gate[i].type != "NEG")
			cout << gate[i].t_in2 << endl;

		cout << gate[i].t_out << endl;
	}
}


void file1reader(string filename, vector<configuration>& gate, vector<int>& in, vector<int>& out, bool& switch1)
{
	fstream file;
	file.open(filename, ios::in);
	if (file.is_open())
	{
		configuration config;
		vector<string> words;
		string line;
		while (getline(file, line))
		{
			words = splitter(line, ' ');
			scanner(words);
		
			if (words[0] == "IN")
			{
				for (int i = 1; i < words.size(); i++)
					in.push_back(stoi(words[i]));
			}
			else if (words[0] == "OUT")
			{
				for (int i = 1; i < words.size(); i++)
					out.push_back(stoi(words[i]));
			}
			else if (words[0] == "AND")
			{
				applier(words, config, "AND");
				gate.push_back(config);
			}
			else if (words[0] == "NAND")
			{
				applier(words, config, "NAND");
				gate.push_back(config);
			}
			else if (words[0] == "OR")
			{
				applier(words, config, "OR");
				gate.push_back(config);
			}
			else if (words[0] == "NOR")
			{
				applier(words, config, "NOR");
				gate.push_back(config);
			}
			else if (words[0] == "XOR")
			{
				applier(words, config, "XOR");
				gate.push_back(config);
			}
			else if (words[0] == "XNOR")
			{
				applier(words, config, "XNOR");
				gate.push_back(config);
			}
			else if (words[0] == "NEG")
			{
				applier(words, config, "NEG");
				gate.push_back(config);
			}
			else
			{
				cout << "Blednie wpisany schemat w pliku 1." << endl;
				instrukcja1();
				switch1 = false;
				break;
			}
		}
		file.close();
	}
}

void file2reader(string filename, vector<logstate>& logdata, vector<int> in, bool& switch2)
{
	fstream file2;
	file2.open(filename, ios::in);
	if (file2.is_open())
	{
		logstate status;
		vector<string> words;
		string line;
		while (getline(file2, line))
		{
			words = splitter(line, ':');
			scanner(words);
		
			for (int i = 0; i < in.size(); i++)
			{
				for (int j = 0; j < words.size();j+=2)
				{
					if (stoi(words[j]) == in[i])
					{
					switch (stoi(words[j + 1]))
						{	
						case 1:
							status.b_in.push_back(1);
							break;
						case 0:
							status.b_in.push_back(0);
							break;
						default:
							cout << "Blednie wpisany schemat w pliku 2. Dostepne wartosci: 0, 1." << endl;
							switch2 = false;
							break;
						}	
					}	
				}
			}
			logdata.push_back(status);
			status.b_in.clear();
		}
		file2.close();
	}
}


void calculator(vector<logstate>& status, vector<configuration>& gate, vector<int> in, vector<int> out, bool switch1, bool switch2)
{
	if (switch1 == true && switch2 == true)
	{
		vector<configuration> temp = gate;
		for (int i = 0; i < status.size(); i++)
		{
			gate = temp;
			cout << "IN: ";
			for (int x = 0; x < in.size(); x++)
				cout << in[x] << ":" << status[i].b_in[x] << "   ";
			cout << endl;

			int counter = 0;
			int j = 0;
			while(gate.size() > counter)
			{	
				for (int k = 0; k < in.size(); k++)
				{
					if (gate[j].t_in1 == in[k]) gate[j].b_in1 = status[i].b_in[k];
					if (gate[j].t_in2 == in[k]) gate[j].b_in2 = status[i].b_in[k];
				}
				if (gate[j].type != "NEG" && (gate[j].b_in1 == 0 || gate[j].b_in1 == 1) && (gate[j].b_in2 == 0 || gate[j].b_in2 == 1) && gate[j].finded == false)
				{
					gate[j].b_out = type(gate[j]);
					counter++;
					gate[j].finded = true;
					for (int x = 0; x < gate.size(); x++)
					{
						if (gate[j].t_out == gate[x].t_in1) gate[x].b_in1 = gate[j].b_out;
						if (gate[j].t_out == gate[x].t_in2) gate[x].b_in2 = gate[j].b_out;
					}
				}
				if (gate[j].type == "NEG" && (gate[j].b_in1 == 0 || gate[j].b_in1 == 1) && gate[j].finded == false)
				{
					gate[j].b_out = type(gate[j]);
					counter++;
					gate[j].finded = true;
					for (int x = 0; x < gate.size(); x++)
					{
						if (gate[j].t_out == gate[x].t_in1) gate[x].b_in1 = gate[j].b_out;
						if (gate[j].t_out == gate[x].t_in2) gate[x].b_in2 = gate[j].b_out;
					}
				}
				j++;
				if (j == gate.size()) j = 0;
			}
			for (int j = 0; j < gate.size(); j++)
			{
				if (gate[j].type != "NEG")
				{
					cout << gate[j].type << "\t" << gate[j].t_in1 << " " << gate[j].t_in2 << " " << gate[j].t_out << endl;
					cout << "\t" << gate[j].b_in1 << " " << gate[j].b_in2 << " " << gate[j].b_out << endl;
				}
				else if (gate[j].type == "NEG")
				{
					cout << gate[j].type << "\t" << gate[j].t_in1 << " " << gate[j].t_out << endl;
					cout << "\t" << gate[j].b_in1 << " " << gate[j].b_out << endl;
				}
			}
			for(int x = 0; x<out.size();x++)
				for (int z = 0; z < gate.size(); z++)
				{
					if (out[x] == gate[z].t_out) status[i].b_out.push_back(gate[z].b_out);
				}

			for (int x = 0; x < status[i].b_out.size(); x++)
				cout <<"OUT: "<< out[x] << ": " << status[i].b_out[x] << endl;
			cout << endl;
		}
	}
}

void file3writer(string filename, vector<logstate> status, vector<int> in, vector<int> out, bool switch1, bool switch2)
{
	if (switch1 == true && switch2 == true)
	{
		fstream file3;
		file3.open(filename, ios::out);
		if (file3.is_open())
		{
			for (int i = 0; i < status.size(); i++)
			{
				file3 << "IN:\t";
				for (int j = 0; j < in.size(); j++)
				{
					file3 << in[j] << ":" << status[i].b_in[j] << "\t";
				}
				file3 << "OUT:\t";
				for (int j = 0; j < out.size(); j++)
				{
					file3 << out[j] << ":" << status[i].b_out[j] << "\t";
				}
				file3 << endl;
			}
			file3.close();
		}
	}
}