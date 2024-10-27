#include "Coin.h"

Coin::Coin(Texture& texture, int x, int y)
{
	this->setTexture(texture);
	this->setTextureRect(IntRect(1, 1, 82, 82));
	this->setPosition(x, y);
	this->setScale(0.4, 0.4);
}

void Coin::updateAnimation(float timer)
{
	int x = timer * 10;
	x = x % 10;
	this->setTextureRect(IntRect(x * 83 + 1, 1, 82, 82));
}

void Coin::createCoin(deque<Coin>& coins, Platform platform, Texture& texture)
{
	if (platform.getPosition().y > 78)
	{
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<> x_position(400, 675);
		uniform_int_distribution<> y_position(-100, -66);
		uniform_int_distribution<> random(0, 99);
		if (random(gen) < 5)
		{
			Coin coin(texture, x_position(gen), y_position(gen));
			coins.emplace_back(coin);
		}
	}
}

void Coin::deleteCoin(deque<Coin>& coins, float timer)
{
	if (!coins.empty() && timer >= 1 && coins.back().getPosition().y > 600)
		coins.pop_front();
}