    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Object.h                    //
////////////////////////////////////////

#pragma once

#include "../Utilites/Database/Database.h"

class Object
{
protected:
	int id; //ID объекта
	std::string textid; //Текстовый идентификатор
	DBS_ObjectData objectData; //Данные об объекте

	float health; //Прочность объекта
public:
	Object(const int id, const std::string textid);

	void doBreake(/*const Item* by*/); //Разрушение
	void resetBreake(); //Окончание разрушения
	void getDamage(int damage, E_DamageType type); //Получить урон
	void drop(); //Дроп
};
