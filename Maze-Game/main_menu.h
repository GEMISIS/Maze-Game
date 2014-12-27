#pragma once

#include "game_state.h"
#include "entity_manager.h"

class main_menu : public tiny_state
{
public:
	main_menu();
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
};