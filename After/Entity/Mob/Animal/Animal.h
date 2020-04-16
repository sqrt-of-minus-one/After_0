    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Animal.h                    //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

class Animal : public Mob
{
protected:
	DBS_AnimalData* animalData;

	void mutate();

	void death(const E_DamageType damageType, const Entity* murderer);
public:
	Animal(const int id, const string textid);
};
