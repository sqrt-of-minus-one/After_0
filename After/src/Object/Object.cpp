    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Object.cpp                  //
////////////////////////////////////////

#include "Object.h"
Object::Object(const int id, const std::string textid)
{
	this->id = id;
	this->textid = textid;
	objectData = Database::getObjectData(textid);
	health = objectData->maxHealth;
}

Object::~Object()
{
	Database::removeObject(id);
}

void Object::doBreake(/*const Item* by*/)
{
}

void Object::resetBreake()
{
}

void Object::getDamage(int damage, E_DamageType type)
{
}

void Object::drop()
{
}