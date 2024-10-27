#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Platform.h"
#include "Coin.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

class Player : public Sprite
{
	Vector2f velocity;
	Vector2f previousPosition;
	double speed;
	double jumpHeight;
	bool canJump = true;

	SoundBuffer jumpBuffer;
	Sound jumpSound;

public:
	Player();
	Player(Texture& texture, double speed, double jumpHeight);

	void draw(RenderWindow& window);
	void updatePosition(float deltaTime, int minX, int maxX, int maxY, deque<Platform>& platforms, deque<Coin>& coins, int& score);
	void updateAnimation();
	void checkPlatform(deque<Platform>& platforms, int& score);
	void checkCoin(deque<Coin>& coins, int& score);
	Vector2f getVelocity();
	void changeJumpHeight(float amount);
	bool can_Jump();
};

