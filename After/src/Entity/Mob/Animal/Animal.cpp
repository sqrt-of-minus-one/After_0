    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Animal.cpp                  //
////////////////////////////////////////

#include "Animal.h"

Animal::Animal(const int id, const std::string textid) : Mob(id, textid)
{
	animalData = Database::getAnimalData(textid);
}

void Animal::mutate()
{
}

void Animal::death(const E_DamageType damageType, const Entity* murderer)
{
}