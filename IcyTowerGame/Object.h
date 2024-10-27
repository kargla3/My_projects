#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <cmath>
#include <deque>

using namespace std;
using namespace sf;

class Player;

class Object : public Sprite
{
	Vector2f velocity;

public:
	Object();
	void draw(RenderWindow& window);
	void updatePosition(float deltaTime, Player& player);

};

