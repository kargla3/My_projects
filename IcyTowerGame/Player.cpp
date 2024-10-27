#include "Player.h"

Player::Player() {};

Player::Player(Texture& texture, double speed, double jumpHeight) : Sprite(texture)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->setPosition(525, 550);
	this->setScale(1.6, 1.6);
	this->setOrigin(0, 32);
	this->setTextureRect(IntRect(0, 0, 32, 32));
	this->previousPosition = this->getPosition();
	jumpBuffer.loadFromFile(".\\Grafika\\jump.wav");
	jumpSound.setBuffer(jumpBuffer);
};

void Player::draw(RenderWindow& window)
{
	window.draw(*this);
}

void Player::updatePosition(float deltaTime, int minX, int maxX, int maxY, deque<Platform>& platforms, deque<Coin>& coins, int& score)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (velocity.x < 300)
			velocity.x += speed;
		if (velocity.x < 0)
			velocity.x += speed * 2;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (velocity.x > -300)
			velocity.x += -speed;
		if (velocity.x > 0)
			velocity.x += -speed * 2;
	}
	else if (canJump && velocity.y <= 0)
		velocity.x *= 0.999;
	else if (!canJump)
		velocity.x *= 0.9999;

	if (Keyboard::isKeyPressed(Keyboard::Up) && canJump && velocity.y <= 0)
	{
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
		jumpSound.play(); 
	}

	velocity.y += 981.0f * deltaTime;

	checkPlatform(platforms, score);
	checkCoin(coins, score);

	if (this->getPosition().x > maxX)
	{
		this->setPosition(maxX, this->getPosition().y);
		if (!canJump && velocity.x > 150 && velocity.y < 0)
			velocity.y = -sqrt(3 * 981 * jumpHeight);
		velocity.x *= -0.5;
	}
	else if (this->getPosition().x < minX)
	{
		this->setPosition(minX, this->getPosition().y);
		if (!canJump && velocity.x < -150 && velocity.y < 0)
			velocity.y = -sqrt(3 * 981 * jumpHeight);
		velocity.x *= -0.5;
	}

	previousPosition = this->getPosition();
	this->move(velocity * deltaTime);
}

void Player::updateAnimation()
{
	if (std::abs(velocity.x) > 25)
	{
		int x = 0;
		x = (int)this->getPosition().x / 15 % 6;
		x *= 32;

		if (velocity.x > 0)
		{
			this->setTextureRect(IntRect(x, 65, 32, 32));
			if (velocity.y < 0)
			{
				int y = 0;
				y = int(this->getPosition().y) / 56 % 8;
				y *= 32;

				this->setTextureRect(IntRect(y, 129, 32, 32));
			}
			else if (velocity.y > 10)
			{
				int y = 0;
				y = int(this->getPosition().y) / 60 % 2;
				y *= 32;

				this->setTextureRect(IntRect(y + 160, 129, 32, 32));
			}
		}
		else
		{
			this->setTextureRect(IntRect(x, 97, 32, 32));
		}
	}
	else
	{
		this->setTextureRect(IntRect(0, 0, 32, 32));
	}

}

void Player::checkPlatform(deque<Platform>& platforms, int& score)
{
	for (Platform& p : platforms)
	{
		if (this->getGlobalBounds().intersects(p.getGlobalBounds()))
		{
			Vector2f playerPos = this->getPosition();
			Vector2f playerSize = this->getLocalBounds().getSize();
			Vector2f platformPos = p.getPosition();
			Vector2f platformSize = p.getSize();

			if (this->previousPosition.y >= platformPos.y - 10 && velocity.y > 0 && playerPos.y - 10 <= platformPos.y 
				&& playerPos.x + playerSize.x > platformPos.x && playerPos.x + 15 < platformPos.x + platformSize.x) {
				if (!p.isVisited())
				{
					score++;
					p.setVisited();
				}
				canJump = true;
				this->setPosition(playerPos.x, platformPos.y );
				velocity.y = 0;
				if (p.isMoveable())
				{
					this->move(p.getMovingSpeed(), 0);
				}
			}
		}
		if (this->getPosition().y <= p.getPosition().y && velocity.y < 0 && !p.isVisited())
		{
			score++;
			p.setVisited();
		}
		else if (this->getPosition().y >= p.getPosition().y && velocity.y > 0 && p.isVisited())
		{
			score--;
			p.setUnvisited();
		}
			
	}
}

void Player::checkCoin(deque<Coin>& coins, int& score)
{
	int leftside = this->getPosition().x;
	int rightside = this->getPosition().x + this->getLocalBounds().width;
	int top = this->getPosition().y - this->getLocalBounds().height;
	int bottom = this->getPosition().y;

	for (Coin& c : coins)
	{
		if (this->getGlobalBounds().intersects(c.getGlobalBounds()))
		{
			coins.pop_front();
			score += 5;
		}
	}
}

Vector2f Player::getVelocity()
{
	return velocity;
}

void Player::changeJumpHeight(float amount)
{
	jumpHeight = amount;
}

bool Player::can_Jump()
{
	return canJump;
}