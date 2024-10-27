#include "Display.h"
#include <iostream>

Display::Display() : window(VideoMode(800, 600), "NeonTower", Style::Titlebar | Style::Close)
{
    font.loadFromFile(".\\Grafika\\czcionka.ttf");
    Image icon;
    icon.loadFromFile(".\\Grafika\\logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Display::begin()
{
    Sprite background(menuTXT);
    Text texts[4];

    Text playText;
    playText.setFont(font);
    playText.setString("Play!");
    playText.setCharacterSize(60);
    playText.setFillColor(Color::White);
    playText.setStyle(Text::Bold);
    playText.setOrigin(playText.getLocalBounds().width / 2, 0);
    playText.setPosition(400, 150);
    texts[0] = playText;

    Text leaderboardText;
    leaderboardText.setFont(font);
    leaderboardText.setString("Leaderboard");
    leaderboardText.setCharacterSize(40);
    leaderboardText.setFillColor(Color::White);
    leaderboardText.setOrigin(leaderboardText.getLocalBounds().width / 2, 0);
    leaderboardText.setPosition(400, 275);
    texts[1] = leaderboardText;

    Text controlText;
    controlText.setFont(font);
    controlText.setString("Controls");
    controlText.setCharacterSize(40);
    controlText.setFillColor(Color::White);
    controlText.setOrigin(controlText.getLocalBounds().width / 2, 0);
    controlText.setPosition(400, 335);
    texts[2] = controlText;

    Text exitText;
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(40);
    exitText.setFillColor(Color::White);
    exitText.setOrigin(exitText.getLocalBounds().width / 2, 0);
    exitText.setPosition(400, 395);
    texts[3] = exitText;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 4; i++) {
                    if (texts[i].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(window)))) {
                        if (texts[i].getString() == "Play!") {
                            if(nickname == "")
                                nickname = enterNickname();
                            if (nickname == "")
                                break;
                            game();
                        }
                        else if (texts[i].getString() == "Leaderboard") {
                            leaderboard();
                        }
                        else if (texts[i].getString() == "Controls") {
                            controls();
                        }
                        else if (texts[i].getString() == "Exit") {
                            Score::saveScores(scoresFile.string(), scores);
                            window.close();
                        }
                    }
                }
            }
        }

        updateText(texts, 4, Color(128,128,128));
        window.clear();
        window.draw(background);
        for (int i = 0; i < 4; i++)
            window.draw(texts[i]);
        window.display();
    }
}

void Display::game()
{
    player = Player(playerTXT, 0.07, 110);

    Sprite background(backgroundTXT);
    background.setPosition(400, 0);

    Sprite scianaL(wallTXT);
    scianaL.setScale(1, 0.6);
    scianaL.setPosition(-600, 0);
    Sprite scianaR(wallTXT);
    scianaR.setScale(-1, 0.6);
    scianaR.setPosition(1720, 0);

    Sprite logo(logoTXT);
    logo.setOrigin(logo.getLocalBounds().width / 2, 0);
    logo.setPosition(200, 50);

    int score = 0;
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + to_string(score));
    scoreText.setCharacterSize(60);
    scoreText.setOrigin(scoreText.getLocalBounds().width / 2, 0);
    scoreText.setPosition(200, 375);

    Text bestscoreText;
    bestscoreText.setFont(font);
    bestscoreText.setString("Best score");
    bestscoreText.setCharacterSize(40);
    bestscoreText.setOrigin(bestscoreText.getLocalBounds().width / 2, 0);
    bestscoreText.setPosition(200, 250);

    Text pbestscoreText;
    pbestscoreText.setFont(font);
    pbestscoreText.setString(nickname + ": " + to_string(Score::checkBestscore(scores, nickname)));
    pbestscoreText.setCharacterSize(40);
    pbestscoreText.setOrigin(pbestscoreText.getLocalBounds().width / 2, 0);
    pbestscoreText.setPosition(200, 300);

    platforms.clear();
    Platform::startingPlatforms(platforms, platformTXT);
    float deltaTime;
    bool run = false;
    Clock clock;
    float timer = 0;
    Event event;

    while (window.isOpen()) {
        window.clear();
        window.draw(background);
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                    gameOver(score);
                }
            }
        }

        deltaTime = clock.restart().asSeconds();

        if (player.getPosition().y < 350)
            run = true;

        if (player.getVelocity().y > 1500)
        {
            gameOver(score);
        }


        if (run)
        {
            timer += deltaTime;
            for (Platform& p : platforms)
            {
                p.updatePosition(deltaTime, player);
                if (p.isMoveable() == true)
                {
                    p.movePlatform(deltaTime);
                }
            }
            for (Coin& c : coins)
            {
                c.updatePosition(deltaTime, player);
                c.updateAnimation(timer);
            }
            Coin::deleteCoin(coins, timer);
            Platform::deletePlatform(platforms, timer);
        }

        player.updatePosition(deltaTime, 400, 675, 550, platforms, coins, score);
        player.updateAnimation();

        for (Coin& c : coins)
            c.draw(window);

        for (Platform& p : platforms)
            p.draw(window);

        Coin::createCoin(coins, platforms.back(), coinTXT);
        Platform::createPlatform(platforms, platformTXT, score);
        changeScore(scoreText, score);

        window.draw(player);
        window.draw(scianaL);
        window.draw(scianaR);
        window.draw(scoreText);
        window.draw(bestscoreText);
        window.draw(pbestscoreText);
        window.draw(logo);

        window.display();
    }
}

void Display::leaderboard()
{
    Text leaderboardText;
    leaderboardText.setFont(font);
    leaderboardText.setString("Leaderboard");
    leaderboardText.setCharacterSize(50);
    leaderboardText.setOrigin(leaderboardText.getLocalBounds().width / 2, 0);
    leaderboardText.setPosition(400, 125);

    Text texts[3];
    Text rightText;
    rightText.setFont(font);
    rightText.setString("Next page");
    rightText.setCharacterSize(20);
    rightText.setOrigin(rightText.getLocalBounds().width / 2, 0);
    rightText.setPosition(600, 450);
    texts[0] = rightText;

    Text leftText;
    leftText.setFont(font);
    leftText.setString("Previous page");
    leftText.setCharacterSize(20);
    leftText.setOrigin(leftText.getLocalBounds().width / 2, 0);
    leftText.setPosition(200, 450);
    texts[1] = leftText;

    Text exitText;
    exitText.setFont(font);
    exitText.setString("Back");
    exitText.setCharacterSize(20);
    exitText.setOrigin(exitText.getLocalBounds().width / 2, 0);
    exitText.setPosition(175, 150);
    texts[2] = exitText;

    Sprite background(menuTXT);
    Sprite board(boardTXT);
    board.setPosition(100, 100);

    vector<Text> scoreTexts;
    int page = 1;
    int results = 6;
    int startIndex = (page - 1) * results;
    int endIndex = min(startIndex + results, static_cast<int>(scores.size()));

    scoreTexts = Score::createTexts(scores, font);

    while (window.isOpen()) {
        Event event;
        startIndex = (page - 1) * results;
        endIndex = min(startIndex + results, static_cast<int>(scores.size()));
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    return;
                }
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 3; i++) {
                    if (texts[i].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(window)))) {
                        if (texts[i].getString() == "Next page" && startIndex < scoreTexts.size() - results) {
                            page++;
                        }
                        else if (texts[i].getString() == "Previous page" && page > 1) {
                            page--;
                        }
                        else if (texts[i].getString() == "Back")
                        {
                            return;
                        }
                    }
                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(board);
        window.draw(leaderboardText);
        updateText(texts, 3, Color(Color::Black));
        if (page > 1)
            window.draw(texts[1]);
        if (page < scores.size() / 6 + 1)
            window.draw(texts[0]);
        window.draw(texts[2]);
        for (int i = startIndex; i < endIndex; i++)
            window.draw(scoreTexts[i]);
        window.display();
    }
}

void Display::controls()
{
    Sprite background(menuTXT);
    Sprite board(controlsTXT);
    board.setPosition(100, 100);

    Text controlsText;
    controlsText.setFont(font);
    controlsText.setString("Controls");
    controlsText.setCharacterSize(50);
    controlsText.setOrigin(controlsText.getLocalBounds().width / 2, 0);
    controlsText.setPosition(400, 125);

    Text texts[1];
    Text exitText;
    exitText.setFont(font);
    exitText.setString("Back");
    exitText.setCharacterSize(20);
    exitText.setOrigin(exitText.getLocalBounds().width / 2, 0);
    exitText.setPosition(175, 150);
    texts[0] = exitText;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    return;
                }
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 3; i++) {
                    if (exitText.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(window)))) {
                        return;
                    }
                }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(board);
        window.draw(controlsText);
        updateText(texts, 1, Color(Color::Black));
        window.draw(texts[0]);
        window.display();
    }
}

void Display::gameOver(int score)
{
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setStyle(Text::Bold);
    gameOverText.setOrigin(gameOverText.getLocalBounds().width / 2, 0);
    gameOverText.setPosition(400, 250);

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Your score is: " + to_string(score));
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(Color::White);
    scoreText.setOrigin(scoreText.getLocalBounds().width / 2, 0);
    scoreText.setPosition(400, 320);

    Text restartText;
    restartText.setFont(font);
    restartText.setString("Press R to Restart,\n   M to go to Menu,\n         Q to Quit");
    restartText.setCharacterSize(20);
    restartText.setFillColor(Color::White);
    restartText.setOrigin(restartText.getLocalBounds().width / 2, 0);
    restartText.setPosition(400, 360);

    Score newScore(nickname, score);
    Score::updateScores(scores, newScore);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::R) {
                    game();
                }
                else if (event.key.code == Keyboard::Q) {
                    Score::saveScores(scoresFile.string(), scores);
                    window.close();
                }
                else if (event.key.code == Keyboard::M) {
                    begin();
                }
            }
        }
        window.clear();
        window.draw(gameOverText);
        window.draw(scoreText);
        window.draw(restartText);
        window.display();
    }
}

string Display::enterNickname()
{
    Sprite background(menuTXT);

    Text text;
    text.setString("Enter your nickname");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setOrigin(text.getLocalBounds().width / 2, 0);
    text.setPosition(400, 250);

    Text playerName;
    playerName.setString("");
    playerName.setFont(font);
    playerName.setCharacterSize(40);
    playerName.setOrigin(playerName.getLocalBounds().width / 2, 0);
    playerName.setPosition(400, 300);

    string input;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                return "";
            }

            if (event.key.code == Keyboard::Escape)
                return "";

            if (event.type == Event::TextEntered)
            {
                if (event.text.unicode == '\b')
                {
                    if (!input.empty())
                        input.pop_back();
                }
                else if (event.text.unicode == '\r')
                {
                    return input;
                }
                else
                {
                    input += static_cast<char>(event.text.unicode);
                }

                playerName.setString(input);
                playerName.setOrigin(playerName.getLocalBounds().width / 2, 0);
                playerName.setPosition(400, 300);
            }
        }

        window.clear();
        window.draw(background);
        window.draw(text);
        window.draw(playerName);
        window.display();
    }
}

void Display::updateText(Text text[], int size, Color color)
{
    for (int i = 0; i < size; i++)
    {
        if (text[i].getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(window))))
        {
            text[i].setFillColor(color);
        }
        else
            text[i].setFillColor(Color::White);
    }
}

void Display::loadLogoTXT(const string& dir)
{
    logoTXT.loadFromFile(dir);
}

void Display::loadMenuTXT(const string& dir)
{
    menuTXT.loadFromFile(dir);
}

void Display::loadPlatformTXT(const string& dir)
{
    platformTXT.loadFromFile(dir);
}

void Display::loadPlayerTXT(const string& dir)
{
    playerTXT.loadFromFile(dir);
}

void Display::loadWallTXT(const string& dir)
{
    wallTXT.loadFromFile(dir);
}

void Display::loadCoinTXT(const string& dir)
{
    coinTXT.loadFromFile(dir);
}

void Display::loadBackgroundTXT(const string& dir)
{
    backgroundTXT.loadFromFile(dir);
}

void Display::loadBoardTXT(const string& dir)
{
    boardTXT.loadFromFile(dir);
}

void Display::loadControlsTXT(const string& dir)
{
    controlsTXT.loadFromFile(dir);
}


void Display::changeScore(Text& text, int score)
{
    text.setString("Score: " + to_string(score));
    text.setOrigin(text.getLocalBounds().width / 2, 0);
}

void Display::loadLeaderboard(const string& dir)
{
    scoresFile = dir;
    scores = Score::loadScores(dir);
}