    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Area.cpp                    //
////////////////////////////////////////

#include "Area.h"

Area::Area(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
	for (int i = 0; i < AREA_WIDTH; i++)
	{
		for (int j = 0; j < AREA_HEIGHT; j++)
		{
			for (int k = 0; k < WORLD_HEIGHT; k++)
			{
				objects[i][j][k] = new Object(0, "air");
			}
		}
	}
	load();
}

Area::~Area()
{
	unload();
}

void Area::load()
{
}

void Area::unload()
{
	for (int i = 0; i < AREA_WIDTH; i++)
	{
		for (int j = 0; j < AREA_HEIGHT; j++)
		{
			for (int k = 0; k < WORLD_HEIGHT; k++)
			{
				delete objects[i][j][k];
			}
		}
	}
}