    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: EntityController.cpp        //
////////////////////////////////////////

#include "EntityController.h"
#include <iostream>
using std::cout;
using std::endl;

EntityController::EntityController(Last& last)
{
	begin = new Cell;
	begin->item = &last;
	begin->prev = nullptr;
	begin->next = nullptr;
	end = begin;
	entityCount = 1;
}

EntityController::~EntityController()
{
	for (Cell* p = begin->prev; p != nullptr; p = p->next)
	{
		delete p->prev->item;
		delete p->prev;
	}
	delete end->item;
	delete end;
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

			static_cast<Last*>(p->item)->getStats(h, e, w, o, g);
			break;
		}
		}
	}
	cout << "FPS: " << 1000 / delta  << endl <<
		"Health: " << h << endl <<
		"Energy: " << e << endl <<
		"Weakness: " << w << endl <<
		"Oxygen: " << o << endl <<
		"Hunger: " << g << endl;
}

void EntityController::add(Entity* entity)
{
	end->next = new Cell;
	end->next->prev = end;
	end = end->next;
	end->item = entity;
	end->next = nullptr;
	entityCount++;
}

/*void EntityController::remove(const int& num)
{
	if (num < entityCount && num > 0)
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
}*/