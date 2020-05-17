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
//	Object* objects[AREA_WIDTH][AREA_HEIGHT][WORLD_HEIGHT];

	int x;
	int y;
public:
	Area(const int& x, const int& y);
	~Area();

	void load();
	void unload();
};
