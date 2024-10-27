#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Platform.h"
#include "Coin.h"
#include "Score.h"
#include <iostream>
#include <deque>
#include <filesystem>
#include <regex>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
using namespace sf;


class Display
{
	Player player;
	string nickname;
	RenderWindow window;
	deque<Platform> platforms;
	deque<Coin> coins;
	vector<Score> scores;
	Font font;
	Texture logoTXT;
	Texture menuTXT;
	Texture platformTXT;
	Texture playerTXT;
	Texture backgroundTXT;
	Texture wallTXT;
	Texture coinTXT;
	Texture boardTXT;
	Texture controlsTXT;
	filesystem::path scoresFile;

public:
	Display();

	void begin();
	void game();
	void leaderboard();
	void controls();
	void gameOver(int score);
	string enterNickname();
	void updateText(Text text[], int size, Color color);
	void loadLogoTXT(const string& dir);
	void loadMenuTXT(const string& dir);
	void loadPlatformTXT(const string& dir);
	void loadPlayerTXT(const string& dir);
	void loadWallTXT(const string& dir);
	void loadCoinTXT(const string& dir);
	void loadBackgroundTXT(const string& dir);
	void loadBoardTXT(const string& dir);
	void loadControlsTXT(const string& dir);
	void changeScore(Text& text, int score);
	void loadLeaderboard(const string& dir);
};

