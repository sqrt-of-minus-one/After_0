    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: World.h                     //
////////////////////////////////////////

#pragma once

#include "Area.h"

class World
{
protected:
	Area* areas[2 * LOAD_DISTANCE + 1][2 * LOAD_DISTANCE + 1];
	int centerX;
	int centerY;
public:
	World(const int& x, const int& y);
	void moveEntity(Entity* entity);
};
