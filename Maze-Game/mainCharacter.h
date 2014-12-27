#pragma once

#include "entity.h"

class mainCharacter : public Entity
{
public:
	mainCharacter() : Entity("test.png")
	{
		this->group_id = 1;
		this->keyCount = 0;
		this->score = 0;
		this->lives = 3;
	}

	void Update()
	{
		this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);

		while (this->getPosition().x <= 0)
		{
			this->move(sf::Vector2f(1, 0));
		}
		while (this->getPosition().x + this->getGlobalBounds().width >= 800)
		{
			this->move(sf::Vector2f(-1, 0));
		}
		while (this->getPosition().y <= 56)
		{
			this->move(sf::Vector2f(0, 1));
		}
		while (this->getPosition().y + this->getGlobalBounds().height >= 600)
		{
			this->move(sf::Vector2f(0, -1));
		}

		Entity::Update();
	}

	void AddKey()
	{
		this->keyCount += 1;
	}

	void RemoveKey()
	{
		this->keyCount -= 1;
	}

	void RemoveLife()
	{
		this->lives -= 1;
	}

	void AddPoint(int pointValue)
	{
		this->score += pointValue;
	}

	int KeyCount()
	{
		return this->keyCount;
	}

	int Score()
	{
		return this->score;
	}

	int Lives()
	{
		return this->lives;
	}

	void SetInitialPosition(float x, float y)
	{
		this->initialPosition = sf::Vector2f(x, y);
	}

	sf::Vector2f GetInitialPosition()
	{
		return this->initialPosition;
	}
private:
	sf::Vector2f initialPosition;
	int keyCount, score, lives;
};
