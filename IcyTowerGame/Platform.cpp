#include "Platform.h"
#include <iostream>

Platform::Platform(Texture& texture, int x, int y)
{
	this->setTexture(texture);
	this->setTextureRect(IntRect(0, 0, 204, 82));
	this->setPosition(x, y);
	this->setScale(0.5, 1);
}

Platform::Platform(Texture& texture, int x, int y, double scale)
{
	this->setTexture(texture);
	this->setTextureRect(IntRect(0, 0, 204, 82));
	this->setPosition(x, y);
	this->setScale(scale * 0.375, 0.27);
	this->setOrigin(this->getOrigin().x, 15);
}

Vector2f Platform::getSize()
{
	Vector2f size;
	size.x = this->getLocalBounds().width * this->getScale().x;
	size.y = this->getLocalBounds().height * this->getScale().y;
	return size;
}

bool Platform::isVisited()
{
	return visited;
}

void Platform::setVisited()
{
	visited = true;
}

void Platform::setUnvisited() 
{
	visited = false;
}


bool Platform::isMoveable()
{
	return moveable;
}

float Platform::getMovingSpeed()
{
	return actualSpeed;
}

void Platform::startingPlatforms(deque<Platform>& platforms, Texture& platformTexture) 
{
	Platform ground(platformTexture, 332, 550, 6);
	ground.setScale(ground.getScale().x, 1.1);
	ground.setVisited(); 
	platforms.emplace_back(ground);

	for (int i = 450; i > 0; i -= 100)
	{
		random_device rd;
		mt19937 gen(rd()); 

		uniform_int_distribution<> position(400, 624);
		uniform_real_distribution<> scale(0.7, 2);

		Platform platform(platformTexture, position(gen), i, scale(gen));
		platforms.emplace_back(platform);
	}
}

void Platform::createPlatform(deque<Platform>& platforms, Texture& platformTexture, int score)
{
	if (!platforms.empty() && platforms.back().getPosition().y > 78)
	{
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<> position(400, 624);
		uniform_real_distribution<> scale(0.7, 2);
		uniform_int_distribution<> random(0, 100);

		Platform platform(platformTexture, position(gen), -22, scale(gen));

		if (random(gen) < 10 * (int(score / 50) + 1))
			platform.moveable = true;

		platforms.emplace_back(platform);
	}
}

void Platform::deletePlatform(deque<Platform>& platforms, float& timer)
{
	int x = timer * 4;
	x = x % 4 + 1;
	platforms.front().setTextureRect(IntRect(0, x * 84, 204, 82));

	if (!platforms.empty() && timer >= 1 || platforms.size() == 10)
	{
		platforms.pop_front();
		timer = 0;
	}
}

void Platform::movePlatform(float deltaTime)
{
	int rightEdge = this->getPosition().x + this->getSize().x;
	int leftEdge = this->getPosition().x;

	if (rightEdge > 720 || leftEdge < 400)
		movingSpeed *= -1;

	actualSpeed = movingSpeed * deltaTime;
	this->move(deltaTime * movingSpeed, 0);
}

