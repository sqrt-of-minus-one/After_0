    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.cpp                  //
////////////////////////////////////////

#include "Entity.h"

Entity::Entity(const int id, const string textid)
{
	this->id = id;
	this->textid = textid;
	entityData = Database::getEntityData(textid);
}

void Entity::move(const float& delta)
{
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

void Entity::tick(const float delta)
{
	move(delta);
	calculateStats(delta);
}