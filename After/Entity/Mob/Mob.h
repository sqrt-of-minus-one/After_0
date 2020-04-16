    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mob.h                       //
////////////////////////////////////////

#pragma once

#include "../Entity.h"
#include "../../Utilites/Database/Database.h"
#include <string>

using std::string;

class Mob : public Entity
{
protected:
	DBS_MobData* mobData; //Постоянные свойства моба

	bool isAngry; //Пытается ли кого-то атаковать
	Entity* targer; //Цель для атаки

	void attackMelee(Entity* attacked); //Ближняя атака
	void attackLong(Entity* attacked); //Дальняя атака
public:
	Mob(const int id, const string textid);
};
