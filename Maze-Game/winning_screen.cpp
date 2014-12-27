#include "winning_screen.h"
#include "main_menu.h"

winning_screen::winning_screen()
{
}

void winning_screen::Initialize(sf::RenderWindow* window)
{
	this->font.loadFromFile("OuterspaceMilitia.ttf");

	this->winner = sf::Text("You\nWin", font, 100U);
	this->winner.setOrigin(this->winner.getGlobalBounds().width / 2, this->winner.getGlobalBounds().height / 2);
	this->winner.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	this->winner.setColor(sf::Color(0, 128, 0));
}
void winning_screen::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		coreState.SetState(new main_menu());
	}
}
void winning_screen::Render(sf::RenderWindow* window)
{
	window->draw(this->winner);
}
void winning_screen::Destroy(sf::RenderWindow* window)
{
}

