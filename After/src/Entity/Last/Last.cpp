    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Last.cpp                    //
////////////////////////////////////////

#include "Last.h"
#include "../../System/Controls.h"

Last::Last() : Entity(0, "last")
{
	maxHunger = 40;
	hunger = maxHunger;
	hungeringSpeed = 0;

	maxEnergy = 40;
	energy = maxEnergy;
	energySpeed = 0.0045;
	energyRegenerationSpeed = 0.003;

	weakness = maxEnergy;
	weaknessSpeed = 0.00005;

	weakTime = 0;
}

void Last::calculateStats(const float delta)
{
	if (weakness > 0)
	{
		weakness -= weaknessSpeed * delta;
	}

	if (energy > weakness)
	{
		energy = weakness;
	}
	if (isRunning)
	{
		energy -= energySpeed * delta;
	}
	else if (energy < weakness)
	{
		energy += energyRegenerationSpeed * delta;
	}
}

void Last::deathDrop()
{
}

void Last::weak()
{
}

void Last::tick(const float delta)
{
	isRunning = false;
	isWalking = true;
	if (sf::Keyboard::isKeyPressed(S_Controls::forward))
	{
		if (sf::Keyboard::isKeyPressed(S_Controls::right))
		{
			if (direction != FR)
			{
				direction = FR;
				sf::IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_fr);
				sprite.setTextureRect(rect);
			}
		}
		else if (sf::Keyboard::isKeyPressed(S_Controls::left))
		{
			if (direction != FL)
			{
				direction = FL;
				sf::IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_fl);
				sprite.setTextureRect(rect);
			}
		}
		else if (direction != F)
		{
			direction = F;
			sf::IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_f);
			sprite.setTextureRect(rect);
		}
	}
	else if (sf::Keyboard::isKeyPressed(S_Controls::back))
	{
		if (sf::Keyboard::isKeyPressed(S_Controls::right))
		{
			if (direction != BR)
			{
				direction = BR;
				sf::IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_br);
				sprite.setTextureRect(rect);
			}
		}
		else if (sf::Keyboard::isKeyPressed(S_Controls::left))
		{
			if (direction != BL)
			{
				direction = BL;
				sf::IntRect rect = sprite.getTextureRect();
				sprite.setTexture(entityData->texture_bl);
				sprite.setTextureRect(rect);
			}
		}
		else if (direction != B)
		{
			direction = B;
			sf::IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_b);
			sprite.setTextureRect(rect);
		}
	}
	else if (sf::Keyboard::isKeyPressed(S_Controls::right))
	{
		if (direction != R)
		{
			direction = R;
			sf::IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_r);
			sprite.setTextureRect(rect);
		}
	}
	else if (sf::Keyboard::isKeyPressed(S_Controls::left))
	{
		if (direction != L)
		{
			direction = L;
			sf::IntRect rect = sprite.getTextureRect();
			sprite.setTexture(entityData->texture_l);
			sprite.setTextureRect(rect);
		}
	}
	else
	{
		isWalking = false;
	}

	static bool run_control = true;

	if (energy <= 0)
	{
		run_control = false;
	}
	else if (!run_control && energy > maxEnergy / 10)
	{
		run_control = true;
	}

	if (isWalking && sf::Keyboard::isKeyPressed(S_Controls::run) && run_control)
	{
		isRunning = true;
	}

	calculateStats(delta);
	Entity::tick(delta);
}

sf::Vector2f Last::getCenter()
{
	return sf::Vector2f(sprite.getPosition().x + entityData->width * WIDTH / 2,
		sprite.getPosition().y + entityData->height * HEIGHT / 2);
}

void Last::getStats(float& health, float& energy, float& weakness, float& oxygen, float& hunger)
{
	health = this->health;
	energy = this->energy;
	weakness = this->weakness;
	oxygen = this->oxygen;
	hunger = this->hunger;
}