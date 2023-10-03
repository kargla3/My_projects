#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

struct komorka {
	string znak;
	bool zaklepane;
};

void start();
void wyswietl();
void sprawdz();
void koniecgry();
void wygrana(string znak);
void reset();

string strzalka1();
string strzalka2();
string strzalka3();
string strzalka4();
string strzalka5();
string strzalka6();
string strzalka7();
string strzalka8();
string strzalka9();


int width = 26;
int height = 20;
int x = 1, y = 1, z;
int counter = 0;

komorka tab[3][3]{ {"      ",false, "      ",false, "      ", false},
				   {"      ",false, "      ",false, "      ", false},
				   {"      ",false, "      ",false, "      ", false} };

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	start();
	wyswietl();
}

void start()
{
	cout << "\n   WITAJ W GRZE KOLKO I KRZYZYK!\n\n";
	cout << "   STEROWANIE ZA POMOCA STRZALEK\n";
	cout << "   ZATWIERDZENIE ZA POMOCA ENTER\n\n";
	cout << "ABY ROZPOCZAC WYBIERZ DOWOLNY KLAWISZ";
	_getch();
}

void wyswietl()
{
	while (1)
	{
		system("cls");
		for (int i = 0; i < width; i++)
			cout << '#';
		cout << "\n#                        #";
		if (counter % 2 == 0)
			cout << "\n#  RUCH:    Kolko        #\n";
		else cout << "\n#  RUCH:    Krzyzyk      #\n";
		cout << "#                        #\n";
			cout << "#        |      |        #\n";
			cout << "#  "<< tab[0][0].znak << '|' << tab[0][1].znak << '|' << tab[0][2].znak <<"  #" << '\n';
			cout << "#  "<<strzalka1() << '|' << strzalka2() << '|' << strzalka3() <<"  #" << '\n';
			cout << "#  ------ ------ ------  #\n";
			cout << "#        |      |        #\n";
			cout << "#  "<<tab[1][0].znak << '|' << tab[1][1].znak << '|' << tab[1][2].znak<<"  #" << '\n';
			cout << "#  "<<strzalka4() << '|' << strzalka5() << '|' << strzalka6() <<"  #" << '\n';
			cout << "#  ------ ------ ------  #\n";
			cout << "#        |      |        #\n";
			cout << "#  "<<tab[2][0].znak << '|' << tab[2][1].znak << '|' << tab[2][2].znak<<"  #" << '\n';
			cout << "#  "<<strzalka7() << '|' << strzalka8() << '|' << strzalka9() <<"  #" << '\n';
			cout << "#                        #\n";

		for (int i = 0; i < width; i++)
			cout << "#";
		cout << "\n\nNACISNIJ ESC ABY WYJSC Z GRY\n";

		z = _getch();

		if (z == 72) y--;
		if (y == 0) y = 3;
		if (z == 80) y++;
		if (y > 3) y = 1;
		if (z == 75) x--;
		if (x == 0) x = 3;
		if (z == 77) x++;
		if (x > 3) x = 1;


		if (z == 13)
		{
			if (tab[y - 1][x - 1].zaklepane == false)
			{
				if (counter % 2 == 0)
				{
					tab[y - 1][x - 1].znak = "  <>  ";
					tab[y - 1][x - 1].zaklepane = true;
				}
				else if (counter % 2 != 0)
				{
					tab[y - 1][x - 1].znak = "  ><  ";
					tab[y - 1][x - 1].zaklepane = true;
				}
				counter++;
				sprawdz();
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n  Pole zajete!\n";
				SetConsoleTextAttribute(hConsole, 7);
				Sleep(2000);
			}
		}

		if (z == 27) koniecgry();
		if (counter == 9) koniecgry();
	}
}

string strzalka1() { if (x == 1 && y == 1) return "  ^^  "; else return "      "; }
string strzalka2() { if (x == 2 && y == 1) return "  ^^  "; else return "      "; }
string strzalka3() { if (x == 3 && y == 1) return "  ^^  "; else return "      "; }
string strzalka4() { if (x == 1 && y == 2) return "  ^^  "; else return "      "; }
string strzalka5() { if (x == 2 && y == 2) return "  ^^  "; else return "      "; }
string strzalka6() { if (x == 3 && y == 2) return "  ^^  "; else return "      "; }
string strzalka7() { if (x == 1 && y == 3) return "  ^^  "; else return "      "; }
string strzalka8() { if (x == 2 && y == 3) return "  ^^  "; else return "      "; }
string strzalka9() { if (x == 3 && y == 3) return "  ^^  "; else return "      "; }


void sprawdz()
{
	for (int i = 0; i < 3; i++)
	{
		if ((tab[i][0].znak == "  <>  " || tab[i][0].znak == "  ><  ") && ((tab[i][0].znak == tab[i][1].znak) && (tab[i][0].znak == tab[i][2].znak))) wygrana(tab[i][0].znak);
		else if ((tab[0][i].znak == "  <>  " || tab[0][i].znak == "  ><  ") && ((tab[0][i].znak == tab[1][i].znak) && (tab[0][i].znak == tab[2][i].znak))) wygrana(tab[0][i].znak);
	}
	if ((tab[0][0].znak == "  <>  " || tab[0][0].znak == "  ><  ") && ((tab[0][0].znak == tab[1][1].znak) && (tab[0][0].znak == tab[2][2].znak))) wygrana(tab[0][0].znak);
	else if ((tab[0][2].znak == "  <>  " || tab[0][2].znak == "  ><  ") && ((tab[0][2].znak == tab[1][1].znak) && (tab[0][2].znak == tab[2][0].znak))) wygrana(tab[0][2].znak);
}

void koniecgry()
{
	int n = 1;
	reset();
	while (1)
	{
		system("cls");
		cout << "\n\n\t   KONIEC GRY!\n";
		if (n == 1)
		{
			SetConsoleTextAttribute(hConsole, 13);
			cout << "\t*Zagraj ponownie*\n";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "\t      Wyjdz";
		}
		else if (n == 2)
		{
			cout << "\t Zagraj ponownie\n";
			SetConsoleTextAttribute(hConsole, 13);
			cout << "\t     *Wyjdz*";
			SetConsoleTextAttribute(hConsole, 7);

		}
		z = _getch();
		if (z == 72)n--;
		if (n == 0) n = 2;
		if (z == 80)n++;
		if (n > 2) n = 1;

		if ((z == 13) && (n == 1)) wyswietl();
		if ((z == 13) && (n == 2)) exit(0);
	}
}

void wygrana(string znak)
{
	int n = 1;
	reset();
	system("cls");
	string temp;
	if (znak == "  <>  ") temp = "Kolko";
	else temp = "Krzyzyk";

	while (1)
	{
		system("cls");
		cout << "\n\n    Gratulacje! "<<temp<<" wygrywa!\n";
		if (n == 1)
		{
			SetConsoleTextAttribute(hConsole, 13);
			cout << "\t*Zagraj ponownie*\n";
			SetConsoleTextAttribute(hConsole, 7);
			cout << "\t      Wyjdz";
		}
		else if (n == 2)
		{
			cout << "\t Zagraj ponownie\n";
			SetConsoleTextAttribute(hConsole, 13);
			cout << "\t     *Wyjdz*";
			SetConsoleTextAttribute(hConsole, 7);
		}
		z = _getch();
		if (z == 72)n--;
		if (n == 0) n = 2;
		if (z == 80)n++;
		if (n > 2) n = 1;

		if ((z == 13) && (n == 1)) wyswietl();
		if ((z == 13) && (n == 2)) exit(0);
	}


}

void reset()
{
	for(int i = 0; i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			tab[i][j].znak = "      ";
			tab[i][j].zaklepane = false;
		}
	counter = 0;
}