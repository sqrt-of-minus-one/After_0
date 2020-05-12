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

EntityController::~EntityController()
{
	Cell* p = begin;
	Cell* pn = p->next;
	while (pn != nullptr)
	{
		delete p->item;
		delete p;
		p = pn;
		pn = pn->next;
	}
	delete p->item;
	delete p;
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
			
			view.setCenter(static_cast<Last*>(p->item)->getCenter());
			window.setView(view);

			static_cast<Last*>(p->item)->getStats(h, e, w, o, g);
			break;
		}
		}

		Vector2f position = p->item->getCoordinates();
		Vector2f d = p->item->getDxy();
		int dx = (int)(position.x / AREA_WIDTH) - (int)((position.x - d.x) / AREA_WIDTH);
		int dy = (int)(position.y / AREA_HEIGHT) - (int)((position.y - d.y) / AREA_HEIGHT);
		if (dx != 0 || dy != 0)
		{

		}
	}
	cout << "FPS: " << 1000 / delta << endl <<
		"Health: " << h << endl <<
		"Energy: " << e << endl <<
		"Weakness: " << w << endl <<
		"Oxygen: " << o << endl <<
		"Hunger: " << g << endl;
}

void EntityController::zoom(const float& factor)
{
	view.zoom(factor);
}

void EntityController::add(Entity& entity)
{
	end->next = new Cell;
	end = end->next;
	end->item = &entity;
	end->next = nullptr;
	size++;
}

void EntityController::remove(const int& num)
{
	if (num < size && num > 0)
	{
		Cell* p = begin;
		for (int i = 0; i < num - 1; i++)
		{
			p = p->next;
		}
		Cell* pn = p->next;
		p = pn->next;
		delete pn->item;
		delete pn;
	}
}