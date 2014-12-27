#include <stdio.h>

#include "main_menu.h"
#include "main_game.h"
#include "game_over.h"
#include "winning_screen.h"

#include "mainCharacter.h"
#include "wall.h"
#include "key.h"
#include "door.h"
#include "enemy_easy.h"
#include "enemy_medium.h"
#include "enemy_hard.h"
#include "enemy_follow.h"
#include "exit_door.h"

int testLevel[] = {
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 11
};

bool won = false;

void UpdateCollisions(Entity* entityA, Entity* entityB)
{
	if (entityA->Group() == 1 && entityB->Group() == 2)
	{
		entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
	}
	if (entityA->Group() == 1 && entityB->Group() == 3)
	{
		entityB->SetActive(0);
		((mainCharacter*)entityA)->AddKey();
	}
	if (entityA->Group() == 1 && entityB->Group() == 4)
	{
		mainCharacter* character = ((mainCharacter*)entityA);
		if (character->KeyCount() > 0)
		{
			entityB->SetActive(0);
			((mainCharacter*)entityA)->RemoveKey();
		}
		else
		{
			entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
		}
	}
	if (entityA->Group() == 1 && (entityB->Group() >= 5 && entityB->Group() <= 10))
	{
		entityB->SetActive(0);
		((mainCharacter*)entityA)->RemoveLife();
		entityA->setPosition(((mainCharacter*)entityA)->GetInitialPosition());
	}
	if ((entityA->Group() >= 5 && entityA->Group() <= 10) && entityB->Group() != 1)
	{
		switch (entityA->Group())
		{
		case 5:
			break;
		case 6:
			entityA->velocity.x = -entityA->velocity.x;
			entityA->velocity.y = -entityA->velocity.y;
			break;
		case 7:
		{
			int option = rand() % 2;
			if (option == 0)
			{
				entityA->velocity.x = -entityA->velocity.x;
			}
			else
			{
				entityA->velocity.x = entityA->velocity.x;
			}
			option = rand() % 2;
			if (option == 0)
			{
				entityA->velocity.y = -entityA->velocity.y;
			}
			else
			{
				entityA->velocity.y = entityA->velocity.y;
			}
		}
			break;
		case 8:
			entityA->velocity.x = -entityA->velocity.x;
			entityA->velocity.y = -entityA->velocity.y;
			break;
		}
	}
	if (entityA->Group() == 1 && entityB->Group() == 11)
	{
		won = true;
	}
}

main_game::main_game()
{
	this->manager = new EntityManager();
}

void main_game::LoadLevel(int levelData[])
{
	std::string mainCharacterName = "mainCharacter";
	this->manager->AddEntity(mainCharacterName, new mainCharacter());

	for (int y = 0; y < 17; y += 1)
	{
		for (int x = 0; x < 25; x += 1)
		{
			std::string name = "";
			switch (levelData[x + y * 25])
			{
			case 1:
				name = mainCharacterName;
				break;
			case 2:
				name = "wall";
				this->manager->AddEntity(name, new Wall());
				break;
			case 3:
				name = "key";
				this->manager->AddEntity(name, new Key());
				break;
			case 4:
				name = "door";
				this->manager->AddEntity(name, new Door());
				break;
			case 5:
				name = "enemy";
				this->manager->AddEntity(name, new EnemyEasy());
				break;
			case 6:
				name = "enemy";
				this->manager->AddEntity(name, new EnemyMedium(false));
				break;
			case 7:
				name = "enemy";
				this->manager->AddEntity(name, new EnemyHard());
				break;
			case 8:
				name = "enemy";
				this->manager->AddEntity(name, new EnemyFollow((mainCharacter*)this->manager->Get(mainCharacterName), 0.25f, 200, 200));
				break;
			case 9:
				name = "enemy";
				this->manager->AddEntity(name, new Door());
				break;
			case 10:
				name = "enemy";
				this->manager->AddEntity(name, new Door());
				break;
			case 11:
				name = "exit_door";
				this->manager->AddEntity(name, new ExitDoor());
				break;
			default:
				continue;
			}
			this->manager->Get(name)->setPosition(x * 32, y * 32 + 56);
		}
	}
}

void main_game::Initialize(sf::RenderWindow* window)
{
	this->manager->SetCollisionMethod(UpdateCollisions);

	this->font.loadFromFile("Montserrat.ttf");

	this->keys = sf::Text("Keys: 0", font, 40U);
	this->keys.setPosition(0, 0);

	this->score = sf::Text("Score: 0", font, 40U);
	this->score.setPosition(250, 0);

	this->lives = sf::Text("Lives: 3", font, 40U);
	this->lives.setPosition(500, 0);

	this->LoadLevel(testLevel);
}
void main_game::Update(sf::RenderWindow* window)
{
	manager->Update();
	if (((mainCharacter*)this->manager->Get("mainCharacter"))->Lives() < 1)
	{
		coreState.SetState(new game_over());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.SetState(new main_menu());
	}
	if (won)
	{
		coreState.SetState(new winning_screen());
		won = false;
	}
}
void main_game::Render(sf::RenderWindow* window)
{
	this->keys.setString("Keys: " + std::to_string(((mainCharacter*)this->manager->Get("mainCharacter"))->KeyCount()));
	this->score.setString("Score: " + std::to_string(((mainCharacter*)this->manager->Get("mainCharacter"))->Score()));
	this->lives.setString("Lives: " + std::to_string(((mainCharacter*)this->manager->Get("mainCharacter"))->Lives()));

	manager->Render(window);
	window->draw(this->keys);
	window->draw(this->score);
	window->draw(this->lives);
}
void main_game::Destroy(sf::RenderWindow* window)
{
	delete manager;
}

