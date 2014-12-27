#pragma once

#include "entity.h"

class tester : public Entity
{
public:
	tester() : Entity("test.png")
	{
		this->group_id = 1;
	}

	void Update()
	{
		this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);

		Entity::Update();
	}
};
