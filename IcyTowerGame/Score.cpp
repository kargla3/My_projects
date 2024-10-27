#include "Score.h"

Score::Score(string nickname, int score)
{
	this->nickname = nickname;
	this->best_score = score;
}

void Score::changeScore(int value)
{
	this->best_score = value;
}

string Score::getNickname() const
{
	return nickname;
}

string Score::getScore()
{
	return to_string(best_score);
}

vector<Score> Score::loadScores(const string& dir)
{
    vector<Score> scores;
    try {
        filesystem::path filePath = dir;
        if (!filesystem::exists(filePath))
            throw runtime_error("File does not exist");

        ifstream file(filePath);
        if (!file.is_open())
            throw runtime_error("Unable to open file");

        string line;
        regex pattern(R"((\w+)\s+(\d+))");
        smatch match;
        while (getline(file, line))
        {
            if (regex_match(line, match, pattern))
            {
                if (match.size() == 3)
                {
                    Score score(match[1].str(), stoi(match[2].str()));
                    scores.push_back(score);
                }
            }
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return scores;
}


void Score::updateScores(vector<Score>& scores, Score newScore)
{
    string playerName = toLower(newScore.getNickname());
    int playerScore = stoi(newScore.getScore());

    auto it = find_if(scores.begin(), scores.end(), [&playerName](Score& score) {
        return toLower(score.getNickname()) == playerName;
        });

    if (it != scores.end()) {
        if (stoi(it->getScore()) < playerScore)
            it->changeScore(playerScore);
    }
    else {
        scores.push_back(Score(newScore.getNickname(), playerScore));
    }
}

string Score::toLower(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

vector<Text> Score::createTexts(vector<Score> scores,const Font& font)
{
    auto view = scores | views::all;
    ranges::sort(view, [](Score& a, Score& b) {
        return stoi(a.getScore()) > stoi(b.getScore()); 
        });

    vector<Text> scoreTexts;
    for (int i = 0; i < view.size(); i++)
    {
        Text score;
        score.setFont(font);
        score.setString(to_string(i + 1) + ". " + view[i].getNickname() + " " + view[i].getScore());
        if (i == 0) score.setFillColor(Color(255, 215, 0));
        else if (i == 1) score.setFillColor(Color(192, 192, 192));
        else if (i == 2) score.setFillColor(Color(110, 64, 48));
        score.setCharacterSize(30);
        score.setOrigin(score.getLocalBounds().width / 2, 0);
        score.setPosition(400, 185 + i % 6 * 45);
        scoreTexts.push_back(score);
    }
    return scoreTexts;
}

void Score::saveScores(const string& dir, vector<Score> scores)
{
    try {
        filesystem::path filePath = dir;
        ofstream file(filePath, ios::trunc);
        if (!file.is_open())
            throw runtime_error("Unable to open file");

        for (Score s : scores)
            file << s.getNickname() << " " << s.getScore() << endl;

        file.close();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

int Score::checkBestscore(vector<Score> scores, string nickname)
{
    string playername = toLower(nickname);
    auto it = find_if(scores.begin(), scores.end(), [&playername](Score& score) {
        return toLower(score.getNickname()) == playername;
        });
    if (it != scores.end()) {
        return stoi(it->getScore());
    }
    else
        return 0;
}
