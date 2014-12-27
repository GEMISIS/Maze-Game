#pragma once

#include "entity.h"

class Wall : public Entity
{
public:
	Wall() : Entity("wall.png")
	{
		this->group_id = 2;
	}

	void Update()
	{
	}
};
