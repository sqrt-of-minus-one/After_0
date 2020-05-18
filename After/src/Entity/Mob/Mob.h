    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mob.h                       //
////////////////////////////////////////

#pragma once

#include "../Entity.h"

class Mob abstract : public Entity
{
protected:
	DBS_MobData* mobData; //Постоянные свойства моба

	bool isAngry; //Пытается ли кого-то атаковать
	Entity* targer; //Цель для атаки

	void attackMelee(Entity* attacked); //Ближняя атака
	void attackLong(Entity* attacked); //Дальняя атака
	
	void control(); //Управление действиями моба
public:
	Mob(const int id, const std::string textid);
	~Mob();

	void tick(const float delta);
};
