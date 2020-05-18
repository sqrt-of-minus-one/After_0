    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Wolf.h                      //
////////////////////////////////////////

#pragma once

#include "../Animal.h"

//Класс волка
class Wolf : public Animal
{
protected:
	float hunger; //Шкала голода
	DBS_WolfData* wolfData; //Данные о волке

	void death(const E_DamageType damageType, const Entity* murderer);
public:
	Wolf(const int id, const std::string textid);
};

