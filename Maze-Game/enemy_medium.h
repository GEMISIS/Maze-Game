#pragma once

#include "enemy.h"

class EnemyMedium : public Enemy
{
public:
	EnemyMedium(bool righty)
	{
		this->group_id = 6;
		this->setColor(sf::Color::Yellow);
		if (righty)
		{
			this->velocity.x = 1;
		}
		else
		{
			this->velocity.y = 1;
		}
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
			this->velocity.y = -this->velocity.y;
		}
		if (this->getPosition().y + this->getGlobalBounds().height >= 600)
		{
			this->velocity.y = -this->velocity.y;
		}

		Entity::Update();
	}
};
