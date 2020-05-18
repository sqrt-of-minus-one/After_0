    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: WorldController.cpp         //
////////////////////////////////////////

#include "WorldController.h"

WorldController::WorldController(sf::RenderWindow& window, std::mutex& windowMtx, int& loading)
{
	player = new Last;
	
	windowMtx.lock();
	view = window.getView();
	windowMtx.unlock();

	entityController = new EntityController(*player);
	entityController->add(new Animal(1, "cow"));
	sf::Vector2f pos = player->getCoordinates();
	world = new World(pos.x, pos.y, loading);
}

WorldController::~WorldController()
{
	delete world;
	delete entityController;
}

void WorldController::tick(const float& delta, sf::RenderWindow& window)
{
	sf::Vector2f move = entityController->tick(delta, window, world->getCenter());
	if (move != sf::Vector2f(0, 0))
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