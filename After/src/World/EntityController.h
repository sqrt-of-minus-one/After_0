    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: EntityController.h          //
////////////////////////////////////////

#include "../Entity/Last/Last.h"
#include "../Entity/Mob/Alien/Alien.h"
#include "../Entity/Mob/Animal/Wolf/Wolf.h"
#include "../Entity/Mob/Mutant/Mutant.h"
#include "../Entity/Mob/Robot/Robot.h"

#pragma once
class EntityController
{
protected:
	struct Cell
	{
		Cell* prev;
		Entity* item;
		Cell* next;
	};
	Cell* begin;
	Cell* end;
	int entityCount;
public:
	EntityController(Last& last);
	~EntityController();
	sf::Vector2f tick(const float& delta, sf::RenderWindow& window, const sf::Vector2f& center);
	void add(Entity* entity);
	bool remove(const Entity& entity);
};
