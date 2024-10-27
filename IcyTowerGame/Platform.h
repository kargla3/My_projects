#pragma once
#include "Object.h"

class Platform : public Object
{
	bool visited = false;
	bool moveable = false;
	int movingSpeed = 50;
	float actualSpeed = 0;

public:
	Platform(Texture& texture, int x, int y);
	Platform(Texture& texture, int x, int y, double scale);
	Vector2f getSize();
	bool isVisited();
	void setVisited();
	void setUnvisited();
	bool isMoveable();
	float getMovingSpeed();
	static void startingPlatforms(deque<Platform>& platforms, Texture& platformTexture);
	static void createPlatform(deque<Platform>& platforms, Texture& platformTexture, int score);
	static void deletePlatform(deque<Platform>& platforms, float& timer);
	void movePlatform(float deltaTime);
};

