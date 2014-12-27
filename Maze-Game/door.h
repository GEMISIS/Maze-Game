#pragma once

#include "entity.h"

class Door : public Entity
{
public:
	Door() : Entity("door.png")
	{
		this->group_id = 4;
	}

	void Update()
	{
	}
};
