#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <regex>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ranges>


using namespace std;
using namespace sf;

class Score
{
	string nickname;
	int best_score;
public:
	Score(string nickname, int best_score);
	void changeScore(int value);
	string getNickname() const;
	string getScore();
	static vector<Score> loadScores(const string& dir);
	static void updateScores(vector<Score>& scores, Score score);
	static string toLower(const string& str);
	static vector<Text> createTexts(vector<Score> scores,const Font& font);
	static void saveScores(const string& dir, vector<Score> scores);
	static int checkBestscore(vector<Score> scores, string nickname);
};

