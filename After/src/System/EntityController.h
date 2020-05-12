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
		Entity* item;
		Cell* next;
	};
	Cell* begin;
	Cell* end;
	int size;
	sf::View view;
public:
	EntityController(RenderWindow& window);
	~EntityController();
	void tick(const float& delta, RenderWindow& window);
	void zoom(const float& factor);
	void add(Entity& entity);
	void remove(const int& num);
};
