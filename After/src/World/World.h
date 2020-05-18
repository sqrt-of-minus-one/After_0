    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: World.h                     //
////////////////////////////////////////

#pragma once

#include "Area.h"
#include <thread>
#include <mutex>

//Next two classes are very bad! But they`re working! I hope...
class AreaLinkedList
{
protected:
	struct Cell
	{
		Cell* prev;
		Area* item;
		Cell* next;
	};

	Cell* begin;
	Cell* end;
	int size;

	Cell* iterator;
	int iteratorIndex;
public:
	AreaLinkedList();
	~AreaLinkedList();
	void addFirst(Area* item);
	void addLast(Area* item);
	void removeFirst();
	void removeLast();
	Area* getFirst();
	Area* getLast();
	Area* get(const int& index);
	void startIterate();
	Area* getIterator();
	bool iterateNext();
	int getIteratorIndex();
};

class AreasLinkedList
{
protected:
	struct Cell
	{
		Cell* prev;
		AreaLinkedList* item;
		Cell* next;
	};

	Cell* begin;
	Cell* end;
	int size;

	Cell* iterator;
	int iteratorIndex;
public:
	AreasLinkedList();
	~AreasLinkedList();
	void addFirst(AreaLinkedList* item);
	void addLast(AreaLinkedList* item);
	void removeFirst();
	void removeLast();
	AreaLinkedList* getFirst();
	AreaLinkedList* getLast();
	AreaLinkedList* get(const int& index);
	void startIterate();
	AreaLinkedList* getIterator();
	bool iterateNext();
	int getIteratorIndex();
};

class World
{
protected:
	AreasLinkedList* areas;
	int centerX;
	int centerY;
public:
	World(const int& x, const int& y, int& loading);
	~World();

	void moveWorld(const float& x, const float& y);

	sf::Vector2f getCenter();
};
