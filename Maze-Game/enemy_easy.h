#pragma once

#include "enemy.h"

class EnemyEasy : public Enemy
{
public:
	EnemyEasy()
	{
		this->group_id = 5;
		this->setColor(sf::Color::Magenta);
	}

	void Update()
	{
	}
};
