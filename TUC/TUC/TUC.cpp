#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "funkcje.h"
#include "struktury.h"

using namespace std;

int main(int argc, char* argv[])
{	
	parameter switches = parameters(argc, argv);
	string filename1 = switches.in1;
	string filename2 = switches.in2;
	string filename3 = switches.out;

	vector<int> in;
	vector<int> out;
	vector<configuration> gate;
	vector<logstate> logdata;
	bool switch1 = true, switch2 = true;

	file1reader(filename1, gate, in, out, switch1);					// zczytywanie ukladu bramek logicznych
	file2reader(filename2, logdata, in, switch2);					// zczytywanie stanow logicznych wejsc 
	calculator(logdata, gate, in, out, switch1, switch2);			// wyliczanie stanow wyjsc dla poszczegolnych stanow wejsc
	file3writer(filename3, logdata, in, out, switch1, switch2);		// zapis danych do pliku
}
