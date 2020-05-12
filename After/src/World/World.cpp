    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: World.cpp                   //
////////////////////////////////////////

#include "World.h"

World::World(const int& x, const int& y)
{
	centerX = x / AREA_WIDTH;
	centerY = y / AREA_HEIGHT;
	for (int i = x / AREA_WIDTH - LOAD_DISTANCE; i <= x / AREA_WIDTH + LOAD_DISTANCE; i++)
	{
		for (int j = y / AREA_HEIGHT - LOAD_DISTANCE; j <= y / AREA_HEIGHT + LOAD_DISTANCE; j++)
		{
			areas[i][j] = new Area(i, j);
		}
	}
}

void World::moveEntity(Entity* entity)
{

}