#pragma once

#include "enemy.h"
#include "mainCharacter.h"

class EnemyFollow : public Enemy
{
public:
	EnemyFollow(mainCharacter* mainCharacter, float speed, float viewWidth, float viewHeight)
	{
		this->group_id = 8;
		this->setColor(sf::Color::Green);

		this->SetMainCharacter(mainCharacter);
		viewingBoundaries = sf::FloatRect(this->getGlobalBounds().left, this->getGlobalBounds().top, viewWidth, viewHeight);

		this->speed = speed;
	}

	void SetMainCharacter(mainCharacter* mainCharacter)
	{
		this->mainCharacter = mainCharacter;
	}

	void Update()
	{
		viewingBoundaries = sf::FloatRect(
			this->getGlobalBounds().left - this->viewingBoundaries.width / 2, 
			this->getGlobalBounds().top - this->viewingBoundaries.height / 2,
			this->viewingBoundaries.width, 
			this->viewingBoundaries.height);
		if (this->mainCharacter != NULL)
		{
			if (this->viewingBoundaries.intersects(this->mainCharacter->getGlobalBounds()))
			{
				target = this->mainCharacter->getPosition();
			}
		}

		if (this->viewingBoundaries.intersects(this->mainCharacter->getGlobalBounds()))
		{
			if (this->getPosition().x < target.x)
			{
				this->velocity.x = this->speed;
			}
			if (this->getPosition().x > target.x)
			{
				this->velocity.x = -this->speed;
			}

			if (this->getPosition().y < target.y)
			{
				this->velocity.y = this->speed;
			}
			if (this->getPosition().y > target.y)
			{
				this->velocity.y = -this->speed;
			}
		}
		else
		{
			this->velocity.x = 0;
			this->velocity.y = 0;
		}

		Entity::Update();
	}
private:
	mainCharacter* mainCharacter;
	sf::FloatRect viewingBoundaries;
	sf::Vector2f target;
	float speed;
};
