    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: World.cpp                   //
////////////////////////////////////////

#include "World.h"
#include "../Utilites/Log.h"
#include <stdexcept>

AreaLinkedList::AreaLinkedList()
{
	begin = nullptr;
	end = nullptr;
	size = 0;
	iterator = nullptr;
	iteratorIndex = -1;
}

AreaLinkedList::~AreaLinkedList()
{
	for (Cell* p = begin->next; p != nullptr; p = p->next)
	{
		delete p->prev->item;
		delete p->prev;
	}
	delete end->item;
	delete end;
}

void AreaLinkedList::addFirst(Area* item)
{
	if (size <= 0)
	{
		end = new Cell;
		end->next = nullptr;
		begin = end;
	}
	else
	{
		begin->prev = new Cell;
		begin->prev->next = begin;
		begin = begin->prev;
	}
	begin->item = item;
	begin->prev = nullptr;
	size++;
}

void AreaLinkedList::addLast(Area* item)
{
	if (size <= 0)
	{
		begin = new Cell;
		begin->prev = nullptr;
		end = begin;
	}
	else
	{
		end->next = new Cell;
		end->next->prev = end;
		end = end->next;
	}
	end->item = item;
	end->next = nullptr;
	size++;
}

void AreaLinkedList::removeFirst()
{
	if (size > 1)
	{
		begin = begin->next;
		delete begin->prev->item;
		delete begin->prev;
		begin->prev = nullptr;
		size--;
	}
	else if (size == 1)
	{
		delete begin->item;
		delete begin;
		begin = nullptr;
		end = nullptr;
		size--;
	}
}

void AreaLinkedList::removeLast()
{
	if (size > 1)
	{
		end = end->prev;
		delete end->next->item;
		delete end->next;
		end->next = nullptr;
		size--;
	}
	else if (size == 1)
	{
		delete end->item;
		delete end;
		begin = nullptr;
		end = nullptr;
		size--;
	}
}

Area* AreaLinkedList::getFirst()
{
	return begin->item;
}

Area* AreaLinkedList::getLast()
{
	return end->item;
}

Area* AreaLinkedList::get(const int& index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index is out of range");
	}
	else
	{
		Cell* p = begin;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		return p->item;
	}
}

void AreaLinkedList::startIterate()
{
	iterator = begin;
	if (size != 0)
	{
		iteratorIndex = 0;
	}
}

Area* AreaLinkedList::getIterator()
{
	if (iterator != nullptr)
	{
		return iterator->item;
	}
	else
	{
		return nullptr;
	}
}

bool AreaLinkedList::iterateNext()
{
	if (iteratorIndex < size - 1)
	{
		iterator = iterator->next;
		iteratorIndex++;
		return false;
	}
	else
	{
		return false;
	}
}

int AreaLinkedList::getIteratorIndex()
{
	return iteratorIndex;
}


AreasLinkedList::AreasLinkedList()
{
	begin = nullptr;
	end = nullptr;
	size = 0;
	iterator = nullptr;
	iteratorIndex = -1;
}

AreasLinkedList::~AreasLinkedList()
{
	for (Cell* p = begin->next; p != nullptr; p = p->next)
	{
		delete p->prev->item;
		delete p->prev;
	}
	delete end->item;
	delete end;
}

void AreasLinkedList::addFirst(AreaLinkedList* item)
{
	if (size <= 0)
	{
		end = new Cell;
		end->next = nullptr;
		begin = end;
	}
	else
	{
		begin->prev = new Cell;
		begin->prev->next = begin;
		begin = begin->prev;
	}
	begin->item = item;
	begin->prev = nullptr;
	size++;
}

void AreasLinkedList::addLast(AreaLinkedList* item)
{
	if (size <= 0)
	{
		begin = new Cell;
		begin->prev = nullptr;
		end = begin;
	}
	else
	{
		end->next = new Cell;
		end->next->prev = end;
		end = end->next;
	}
	end->item = item;
	end->next = nullptr;
	size++;
}

void AreasLinkedList::removeFirst()
{
	if (size > 1)
	{
		begin = begin->next;
		delete begin->prev->item;
		delete begin->prev;
		begin->prev = nullptr;
		size--;
	}
	else if (size == 1)
	{
		delete begin->item;
		delete begin;
		begin = nullptr;
		end = nullptr;
		size--;
	}
}

void AreasLinkedList::removeLast()
{
	if (size > 1)
	{
		end = end->prev;
		delete end->next->item;
		delete end->next;
		end->next = nullptr;
		size--;
	}
	else if (size == 1)
	{
		delete end->item;
		delete end;
		begin = nullptr;
		end = nullptr;
		size--;
	}
}

AreaLinkedList* AreasLinkedList::getFirst()
{
	return begin->item;
}

AreaLinkedList* AreasLinkedList::getLast()
{
	return end->item;
}

AreaLinkedList* AreasLinkedList::get(const int& index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index is out of range");
	}
	else
	{
		Cell* p = begin;
		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}
		return p->item;
	}
}

void AreasLinkedList::startIterate()
{
	iterator = begin;
	if (size != 0)
	{
		iteratorIndex = 0;
	}
}

AreaLinkedList* AreasLinkedList::getIterator()
{
	if (iterator != nullptr)
	{
		return iterator->item;
	}
	else
	{
		return nullptr;
	}
}

bool AreasLinkedList::iterateNext()
{
	if (iteratorIndex < size - 1)
	{
		iterator = iterator->next;
		iteratorIndex++;
		return false;
	}
	else
	{
		return false;
	}
}

int AreasLinkedList::getIteratorIndex()
{
	return iteratorIndex;
}


World::World(const int& x, const int& y)
{
	centerX = x / WIDTH / AREA_WIDTH;
	centerY = y / HEIGHT / AREA_HEIGHT;
	areas = new AreasLinkedList;
	for (int i = centerX - LOAD_DISTANCE; i <= centerX + LOAD_DISTANCE; i++)
	{
		AreaLinkedList* list = new AreaLinkedList;
		for (int j = centerY - LOAD_DISTANCE; j <= centerY + LOAD_DISTANCE; j++)
		{
			list->addLast(new Area(i, j));
		}
		areas->addLast(list);
	}
	Log::i(I_WORLD_CREATE);
}

World::~World()
{
	delete areas;
}

void World::moveWorld(const float& x, const float& y)
{
	if (y < 0)
	{
		centerY--;
		areas->removeLast();
		AreaLinkedList* list = new AreaLinkedList;
		for (int i = centerX - LOAD_DISTANCE; i <= centerX + LOAD_DISTANCE; i++)
		{
			list->addLast(new Area(i, centerY - LOAD_DISTANCE));
		}
		areas->addFirst(list);
	}
	else if (y > 0)
	{
		centerY++;
		areas->removeFirst();
		AreaLinkedList* list = new AreaLinkedList;
		for (int i = centerX - LOAD_DISTANCE; i <= centerX + LOAD_DISTANCE; i++)
		{
			list->addLast(new Area(i, centerY + LOAD_DISTANCE));
		}
		areas->addLast(list);
	}
	if (x < 0)
	{
		centerX--;
		areas->startIterate();
		do
		{
			areas->getIterator()->removeLast();
			areas->getIterator()->addFirst(new Area(
				centerX - LOAD_DISTANCE,
				centerY - LOAD_DISTANCE + areas->getIteratorIndex()));
		} while (areas->iterateNext());
	}
	else if (x > 0)
	{
		centerX++;
		areas->startIterate();
		do
		{
			areas->getIterator()->removeFirst();
			areas->getIterator()->addLast(new Area(
				centerX + LOAD_DISTANCE,
				centerY - LOAD_DISTANCE + areas->getIteratorIndex()));
		} while (areas->iterateNext());
	}
}

sf::Vector2f World::getCenter()
{
	return sf::Vector2f(centerX, centerY);
}