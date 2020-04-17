    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Animal.h                    //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//Класс животного
class Animal : public Mob
{
protected:
	DBS_AnimalData* animalData; //Информация о животном

	void mutate(); //Мутация

	void death(const E_DamageType damageType, const Entity* murderer); //Смерть
public:
	Animal(const int id, const string textid);
};
