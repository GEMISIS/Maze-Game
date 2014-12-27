#include "game_over.h"
#include "main_menu.h"

game_over::game_over()
{
}

void game_over::Initialize(sf::RenderWindow* window)
{
	this->font.loadFromFile("OuterspaceMilitia.ttf");

	this->gameOver = sf::Text("Game\nOver", font, 100U);
	this->gameOver.setOrigin(this->gameOver.getGlobalBounds().width / 2, this->gameOver.getGlobalBounds().height / 2);
	this->gameOver.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	this->gameOver.setColor(sf::Color(128, 0, 0));
}
void game_over::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		coreState.SetState(new main_menu());
	}
}
void game_over::Render(sf::RenderWindow* window)
{
	window->draw(this->gameOver);
}
void game_over::Destroy(sf::RenderWindow* window)
{
}

