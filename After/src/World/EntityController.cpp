    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: EntityController.cpp        //
////////////////////////////////////////

#include "EntityController.h"
#include <iostream>

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
	if (entityCount == 1)
	{
		delete begin->item;
		delete begin;
	}
	else
	{
		for (Cell* p = begin->prev; p != nullptr; p = p->next)
		{
			delete p->prev->item;
			delete p->prev;
		}
		delete end->item;
		delete end;
	}
}

sf::Vector2f EntityController::tick(const float& delta, sf::RenderWindow& window, const sf::Vector2f& center)
{
	sf::Vector2f res(0, 0);
	float h, e, w, o, g;
	static_cast<Last*>(begin->item)->getStats(h, e, w, o, g);
	std::cout << "FPS: " << 1000 / delta << std::endl <<
		center.x << " " << center.y << std::endl <<
		"Health: " << h << std::endl <<
		"Energy: " << e << std::endl <<
		"Weakness: " << w << std::endl <<
		"Oxygen: " << o << std::endl <<
		"Hunger: " << g << std::endl << std::endl;
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

			sf::Vector2f pos = p->item->getCoordinates();
			res.x = (int)pos.x / WIDTH / AREA_WIDTH - center.x;
			res.y = (int)pos.y / HEIGHT / AREA_HEIGHT - center.y;

			continue;
		}
		}
		sf::Vector2f position = p->item->getCoordinates();
		std::cout << p->item->getTextid() << " " << (int)p->item->getCoordinates().x / WIDTH << " " << (int)p->item->getCoordinates().y / HEIGHT << std::endl;
		if (position.x / WIDTH / AREA_WIDTH < center.x - LOAD_DISTANCE ||
			position.x / WIDTH / AREA_WIDTH > center.x + LOAD_DISTANCE ||
			position.y / HEIGHT / AREA_HEIGHT < center.y - LOAD_DISTANCE ||
			position.y / HEIGHT / AREA_HEIGHT > center.y + LOAD_DISTANCE)
		{
			p->prev->next = p->next;
			if (p->next != nullptr)
			{
				p->next->prev = p->prev;
			}
			Cell* tmp = p->prev;
			delete p->item;
			delete p;
			p = tmp;
			entityCount--;
		}
	}
	return res;
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

bool EntityController::remove(const Entity& entity)
{
	for (Cell* p = begin; p != nullptr; p = p->next)
	{
		if (p->item == &entity)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p->item;
			delete p;
			entityCount--;
			return true;
		}
	}
	return false;
}