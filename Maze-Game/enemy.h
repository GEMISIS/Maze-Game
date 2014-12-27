#pragma once

#include "entity.h"

class Enemy : public Entity
{
public:
	Enemy() : Entity("enemy.png")
	{
		this->group_id = 5;
	}

	void Update()
	{
	}
};
