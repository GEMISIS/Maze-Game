#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	Entity()
	{
		this->active = 1;
		this->texture = new sf::Texture();
	}
	Entity(std::string filename)
	{
		this->active = 1;
		this->texture = new sf::Texture();
		this->Load(filename, sf::IntRect());
	}
	Entity(std::string filename, sf::IntRect rect)
	{
		this->active = 1;
		this->texture = new sf::Texture();
		this->Load(filename);
	}

	void Load(std::string filename)
	{
		this->Load(filename, sf::IntRect());
	}
	void Load(std::string filename, sf::IntRect rect)
	{
		this->texture->loadFromFile(filename, rect);
		this->setTexture(*this->texture);
	}

	bool Collision(Entity* entity)
	{
		if (entity != NULL)
		{
			return this->getGlobalBounds().intersects(entity->getGlobalBounds());
		}
		return false;
	}

	void SetActive(int active)
	{
		this->active = active;
	}

	int Active()
	{
		return this->active;
	}

	int Group()
	{
		return this->group_id;
	}

	virtual void Update()
	{
		this->move(this->velocity);
	}

	~Entity()
	{
		delete this->texture;
	}

	sf::Vector2f velocity;
protected:
	int active, group_id;
private:
	sf::Texture* texture;
};