#pragma once

#include "game_state.h"
#include "entity_manager.h"

class test_state : public tiny_state
{
public:
	test_state();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	EntityManager* manager;
};