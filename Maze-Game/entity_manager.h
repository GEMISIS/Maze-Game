#pragma once

#include <unordered_map>
#include <vector>

#include "entity.h"

typedef void CollisionUpdateEvent(Entity* entityA, Entity* entityB);

class EntityManager
{
public:
	EntityManager()
	{
	}

	void SetCollisionMethod(CollisionUpdateEvent collisionsEvent)
	{
		this->collisionsEvent = collisionsEvent;
	}

	void AddEntity(std::string name, Entity* entity)
	{
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
		while (found != this->entities.end())
		{
			name += "0";
			found = this->entities.find(name);
		}
		this->entities.insert(std::make_pair(name, entity));
	}

	void Update()
	{
		std::vector<std::string> toRemove;

		for (auto& iterator : this->entities)
		{
			if (this->collisionsEvent != NULL)
			{
				for (auto& iterator2 : this->entities)
				{
					if (iterator != iterator2)
					{
						if (iterator.second->Collision(iterator2.second))
						{
							this->collisionsEvent(iterator.second, iterator2.second);
						}
					}
				}
			}
			if (iterator.second->Active())
			{
				iterator.second->Update();
			}
			else
			{
				toRemove.push_back(iterator.first);
			}
		}

		while (toRemove.size() > 0)
		{
			this->entities.erase(toRemove[toRemove.size() - 1]);
			toRemove.pop_back();
		}
	}

	void Render(sf::RenderWindow* window)
	{
		for (auto& iterator : this->entities)
		{
			if (iterator.second->Active())
			{
				window->draw(*iterator.second);
			}
		}
	}
private:
	std::unordered_map<std::string, Entity*> entities;
	CollisionUpdateEvent* collisionsEvent;
};