#pragma once

#include "entity.h"

class ExitDoor : public Entity
{
public:
	ExitDoor() : Entity("exit_door.png")
	{
		this->group_id = 11;
	}

	void Update()
	{
	}
};
