#pragma once

#include "entity.h"

class Key : public Entity
{
public:
	Key() : Entity("key.png")
	{
		this->group_id = 3;
	}

	void Update()
	{
	}
};
