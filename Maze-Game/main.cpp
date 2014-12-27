#include "game_state.h"
#include "test_state.h"

#include <Windows.h>

game_state coreState;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Maze Game");

	coreState.SetWindow(&window);
	coreState.SetState(new test_state());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		coreState.Update();

		window.display();

		Sleep(5);
	}

	return 0;
}

