#pragma once

#include "entity.h"

class tester2 : public Entity
{
public:
	tester2() : Entity("test.png")
	{
		this->group_id = 2;
		this->setPosition(sf::Vector2f(300, 300));
		this->setColor(sf::Color::Blue);
	}

	void Update()
	{
	}
};
