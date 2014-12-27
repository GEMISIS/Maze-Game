#include "main_menu.h"
#include "test_state.h"

main_menu::main_menu()
{
}

void main_menu::Initialize(sf::RenderWindow* window)
{
	this->font.loadFromFile("OuterspaceMilitia.ttf");

	this->logo = sf::Text("Maze\nGame", font, 100U);
	this->logo.setOrigin(this->logo.getGlobalBounds().width / 2, 0);
	this->logo.setPosition(window->getSize().x / 2, 0);

	this->play = sf::Text("Play", font, 64U);
	this->play.setOrigin(this->play.getGlobalBounds().width / 2, 0);
	this->play.setPosition(window->getSize().x / 2, this->logo.getGlobalBounds().height * 1.5f);

	this->quit = sf::Text("Quit", font, 64U);
	this->quit.setOrigin(this->quit.getGlobalBounds().width / 2, 0);
	this->quit.setPosition(window->getSize().x / 2, this->logo.getGlobalBounds().height * 1.5f + this->play.getGlobalBounds().height * 1.5f);

	this->selected = 0;
}
void main_menu::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !down)
	{
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !up)
	{
		this->selected -= 1;
	}
	if (this->selected < 0)
	{
		this->selected = 1;
	}
	if (this->selected > 1)
	{
		this->selected = 0;
	}

	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			coreState.SetState(new test_state());
			break;
		case 1:
			quitGame = true;
			break;
		}
	}
}
void main_menu::Render(sf::RenderWindow* window)
{
	this->play.setColor(sf::Color::White);
	this->quit.setColor(sf::Color::White);

	this->play.setString("Play");
	this->quit.setString("Quit");

	switch (this->selected)
	{
	case 0:
		this->play.setString("-Play");
		this->play.setColor(sf::Color(128, 0, 0));
		break;
	case 1:
		this->quit.setString("-Quit");
		this->quit.setColor(sf::Color(128, 0, 0));
		break;
	}
	window->draw(this->logo);
	window->draw(this->play);
	window->draw(this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
}

