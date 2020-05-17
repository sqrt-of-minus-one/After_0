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
	void tick(const float& delta, RenderWindow& window);
	void add(Entity* entity);
};
