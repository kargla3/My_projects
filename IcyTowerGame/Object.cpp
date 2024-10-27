#include "Object.h"
#include "Player.h"

Object::Object() {};

void Object::draw(RenderWindow& window)
{
	window.draw(*this);
}

void Object::updatePosition(float deltaTime, Player& player)
{
	float speed = 0;
	if (player.getVelocity().y < 0)
	{
		player.changeJumpHeight(45);
		speed = abs(2 * player.getVelocity().y);
	}
	else if (player.getVelocity().y > 320)
	{
		speed = -abs(1.5 * player.getVelocity().y);
	}
	else if (player.can_Jump() && player.getPosition().y < 200)
	{
		speed = 75;
	}
	
	if (int(player.getPosition().y) == 500 || int(player.getPosition().y) - 500 > 3)
	{
		player.setPosition(player.getPosition().x, 500);
		speed = -abs(2* player.getVelocity().y);
	}
	move(0,speed * deltaTime);
}

