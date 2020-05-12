    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Area.h                      //
////////////////////////////////////////

#pragma once

#include "../Entity/Entity.h"

class Area
{
protected:
	struct Cell
	{
		Entity* item;
		Cell* next;
	};

//	Object* objects[AREA_WIDTH][AREA_HEIGHT][WORLD_HEIGHT];

	Cell* begin;
	Cell* end;
	int entitySize;

	int x;
	int y;
public:
	Area(const int& x, const int& y);
	~Area();

	void load();
	void unload();
};
