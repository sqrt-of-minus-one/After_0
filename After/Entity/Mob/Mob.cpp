    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mob.cpp                     //
////////////////////////////////////////

#include "Mob.h"

Mob::Mob(const int id, const string textid) : Entity(id, textid)
{
	mobData = Database::getMobData(textid);
}

void Mob::attackMelee(Entity* attacked)
{
}

void Mob::attackLong(Entity* attacked)
{
}
