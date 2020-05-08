    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: EntityController.cpp        //
////////////////////////////////////////

#include "EntityController.h"
#include <iostream>
using std::cout;
using std::endl;

EntityController::EntityController(RenderWindow& window)
{
	begin = new Cell;
	begin->item = new Last;
	begin->next = nullptr;
	end = begin;
	view = window.getView();
}

void EntityController::tick(const float& delta, RenderWindow& window)
{
	float h, e, w, o, g;
	for (Cell* p = begin; p != nullptr; p = p->next)
	{
		switch (p->item->getType())
		{
		case ENTITY_ALIEN:
		{
			static_cast<Alien*>(p->item)->tick(delta);
			static_cast<Alien*>(p->item)->draw(window);
			break;
		}

		case ENTITY_ANIMAL:
		{
			static_cast<Animal*>(p->item)->tick(delta);
			static_cast<Animal*>(p->item)->draw(window);
			break;
		}
		case ENTITY_WOLF:
		{
			static_cast<Wolf*>(p->item)->tick(delta);
			static_cast<Wolf*>(p->item)->draw(window);
			break;
		}

		case ENTITY_MUTANT:
		{
			static_cast<Mutant*>(p->item)->tick(delta);
			static_cast<Mutant*>(p->item)->draw(window);
			break;
		}

		case ENTITY_ROBOT:
		{
			static_cast<Robot*>(p->item)->tick(delta);
			static_cast<Robot*>(p->item)->draw(window);
			break;
		}

		case ENTITY_LAST:
		{
			static_cast<Last*>(p->item)->tick(delta);
			static_cast<Last*>(p->item)->draw(window);
			
			float x, y;
			static_cast<Last*>(p->item)->getCenter(x, y);
			static_cast<Last*>(p->item)->getStats(h, e, w, o, g);
			view.setCenter(x, y);
			window.setView(view);

			break;
		}
		}
	}
	cout << "FPS: " << 1000 / delta << endl <<
		"Health: " << h << endl <<
		"Energy: " << e << endl <<
		"Weakness: " << w << endl <<
		"Oxygen: " << o << endl <<
		"Hunger: " << g << endl;
}

void EntityController::add(Entity& entity)
{
	end->next = new Cell;
	end = end->next;
	end->item = &entity;
	end->next = nullptr;
	size++;
}

void EntityController::zoom(const float& factor)
{
	view.zoom(factor);
}