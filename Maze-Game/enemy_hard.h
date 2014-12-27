#pragma once

#include "enemy.h"

class EnemyHard : public Enemy
{
public:
	EnemyHard()
	{
		this->group_id = 7;
		this->setColor(sf::Color::Red);
		this->velocity.y = 1;
	}

	void Update()
	{
		if (this->getPosition().x <= 0)
		{
			this->velocity.x = -this->velocity.x;
		}
		if (this->getPosition().x + this->getGlobalBounds().width >= 800)
		{
			this->velocity.x = -this->velocity.x;
		}
		if (this->getPosition().y <= 56)
		{
			this->velocity.x = 1;
			this->velocity.y = -this->velocity.y;
		}
		if (this->getPosition().y + this->getGlobalBounds().height >= 600)
		{
			this->velocity.x = -1;
			this->velocity.y = -this->velocity.y;
		}

		Entity::Update();
	}
};
