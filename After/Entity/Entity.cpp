    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.cpp                  //
////////////////////////////////////////

#include "Entity.h"

Entity::Entity(const int id, const string textid)
{
	this->id = id;
	this->textid = textid;
	entityData = Database::getEntityData(textid);
}