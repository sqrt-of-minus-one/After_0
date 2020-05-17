    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: WorldController.h           //
////////////////////////////////////////

#pragma once

#include "World.h"
#include "EntityController.h"

class WorldController
{
protected:
	World* world;
	EntityController* entityController;
	sf::View view;
	Last* player;
public:
	WorldController(sf::RenderWindow& window);
	~WorldController();

	void tick(const float& delta, sf::RenderWindow& window);
	void zoom(const float& factor);
};
