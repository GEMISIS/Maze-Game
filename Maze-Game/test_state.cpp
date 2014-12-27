#include <stdio.h>
#include "main_menu.h"
#include "test_state.h"
#include "tester.h"
#include "tester2.h"

void UpdateCollisions(Entity* entityA, Entity* entityB)
{
	if (entityA->Group() == 1 && entityB->Group() == 2)
	{
		entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
		entityB->SetActive(0);
	}
}

test_state::test_state()
{
	this->manager = new EntityManager();
}

void test_state::Initialize(sf::RenderWindow* window)
{
	this->manager->SetCollisionMethod(UpdateCollisions);
	this->manager->AddEntity("tester", new tester());
	this->manager->AddEntity("tester2", new tester2());
}
void test_state::Update(sf::RenderWindow* window)
{
	manager->Update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.SetState(new main_menu());
	}
}
void test_state::Render(sf::RenderWindow* window)
{
	manager->Render(window);
}
void test_state::Destroy(sf::RenderWindow* window)
{
	delete manager;
}

