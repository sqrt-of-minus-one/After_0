    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.cpp                  //
////////////////////////////////////////

#include "Entity.h"

Entity::Entity(const int id, const std::string textid)
{
	this->id = id;
	this->textid = textid;
	entityData = Database::getEntityData(textid);

	z = 0;

	poisonTime = 0.0;
	stoneTime = 0.0;
	webTime = 0.0;

	health = entityData->maxHealth;
	oxygen = entityData->maxOxygen;

	isWalking = false;
	isRunning = false;
	needStairs = false;

	direction = F;

	sprite.setTexture(entityData->texture_f);
	sprite.setTextureRect(sf::IntRect(0, 0, entityData->width * WIDTH, entityData->height * HEIGHT));
}

Entity::~Entity()
{
	Database::removeEntity(id);
}

void Entity::move(const float& delta)
{
	dx = 0;
	dy = 0;
	if (isWalking)
	{
		float x, y;
		x = y = delta * (isRunning ? entityData->runSpeed : entityData->walkSpeed);
		switch (direction)
		{
		case F:
		{
			x *= 0;
			y *= -1;
			break;
		}
		case FR:
		{
			x *= SQRT2;
			y *= -SQRT2;
			break;
		}
		case R:
		{
			x *= 1;
			y *= 0;
			break;
		}
		case BR:
		{
			x *= SQRT2;
			y *= SQRT2;
			break;
		}
		case B:
		{
			x *= 0;
			y *= 1;
			break;
		}
		case BL:
		{
			x *= -SQRT2;
			y *= SQRT2;
			break;
		}
		case L:
		{
			x *= -1;
			y *= 0;
			break;
		}
		case FL:
		{
			x *= -SQRT2;
			y *= -SQRT2;
			break;
		}
		}
		sprite.move(x, y);
		dx = x;
		dy = y;
	}
}

void Entity::death(const E_DamageType damageType, const Entity* murderer)
{
}

void Entity::deathDrop()
{
}

void Entity::calculateStats(const float& delta)
{
}

void Entity::getDamage(const float damage, const E_DamageType damageType, const Entity* attacker)
{
}

void Entity::getPoison(const int duration)
{
}

void Entity::stone()
{
}

void Entity::web()
{
}

void Entity::unstone()
{
}

void Entity::unweb()
{
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Entity::tick(const float delta)
{
	move(delta);
	calculateStats(delta);

	sf::IntRect rect = sprite.getTextureRect();
	
	static float current_frame = 0;
	current_frame += delta;
	if (current_frame >= CHANGE_FRAME)
	{
		current_frame -= CHANGE_FRAME;
		if (rect.left == WIDTH * entityData->width * (FRAMES_COUNT - 1))
		{
			rect.left = 0;
		}
		else
		{
			rect.left += WIDTH * entityData->width;
		}
		sprite.setTextureRect(rect);
	}

	if (!isWalking && rect.top != STAY_ANIM * HEIGHT * entityData->height)
	{
		rect.top = STAY_ANIM * HEIGHT * entityData->height;
		sprite.setTextureRect(rect);
	}
	else if (isWalking)
	{
		if (!isRunning && rect.top != WALK_ANIM * HEIGHT * entityData->height)
		{
			rect.top = WALK_ANIM * HEIGHT * entityData->height;
			sprite.setTextureRect(rect);
		}
		else if (isRunning && rect.top != RUN_AMIN * HEIGHT * entityData->height)
		{
			rect.top = RUN_AMIN * HEIGHT * entityData->height;
			sprite.setTextureRect(rect);
		}
	}

	if (entityData->entitySoundsCount > 0)
	{
		static float audio_time = 0;
		static float audio_mtime = (rand() % 40 + 20) * 1000;
		audio_time += delta;
		if (audio_time >= audio_mtime)
		{
			audio_time = 0;
			audio_mtime = (rand() % 40 + 20) * 1000;
			entityData->entitySounds[rand() % entityData->entitySoundsCount].play();
		}
	}
}

E_EntityType Entity::getType()
{
	return entityData->type;
}

sf::Vector2f Entity::getDxy()
{
	return sf::Vector2f(dx, dy);
}

sf::Vector2f Entity::getCoordinates()
{
	return sprite.getPosition();
}

std::string Entity::getTextid()
{
	return textid;
}