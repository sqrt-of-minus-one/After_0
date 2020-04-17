    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Wolf.cpp                    //
////////////////////////////////////////

#include "Wolf.h"

Wolf::Wolf(const int id, const string textid) : Animal(id, textid)
{
	wolfData = Database::getWolfData();
}

void Wolf::death(const E_DamageType damageType, const Entity* murderer)
{
}