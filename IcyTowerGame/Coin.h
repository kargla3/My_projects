#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Object.h"
#include "Platform.h"
#include <iostream>

using namespace std;
using namespace sf;

class Coin : public Object
{
public:
	Coin(Texture& texture, int x, int y);
	void updateAnimation(float timer);
	static void createCoin(deque<Coin>& coins, Platform platform, Texture& texture);
	static void deleteCoin(deque<Coin>& coins, float timer);
};

