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
//	for (int i = 0; i < AREA_WIDTH; i++)
//	{
//		for (int j = 0; j < AREA_HEIGHT; j++)
//		{
//			for (int k = 0; k < WORLD_HEIGHT; k++)
//			{
//				delete objects[i][j][k];
//			}
//		}
//	}
	
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