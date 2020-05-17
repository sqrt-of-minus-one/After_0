    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: WorldController.cpp         //
////////////////////////////////////////

#include "WorldController.h"

WorldController::WorldController(sf::RenderWindow& window)
{
	player = new Last;
	view = window.getView();
	entityController = new EntityController(*player);
	entityController->add(new Animal(1, "cow"));
	Vector2f pos = player->getCoordinates();
	world = new World(pos.x, pos.y);
}

WorldController::~WorldController()
{
	delete world;
	delete entityController;
}

void WorldController::tick(const float& delta, sf::RenderWindow& window)
{
	Vector2f move = entityController->tick(delta, window, world->getCenter());
	if (move != Vector2f(0, 0))
	{
		world->moveWorld(move.x, move.y);
	}
	view.setCenter(player->getCenter());
	window.setView(view);
}

void WorldController::zoom(const float& factor)
{
	view.zoom(factor);
}