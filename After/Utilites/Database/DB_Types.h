    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "../StructsEnums.h"

using namespace sf;

struct DBS_EntityData
{
	float maxHealth; //Максимальное количество здоровья
	float maxOxygen; //Максимальный запас кислорода
	float oxygenSpeed; //Скорость расходования кислорода
	float oxygenRegenerationSpeed; //Скорость восстановления кислорода
	S_DamageResist damageResist; //Сопротивляемость урону

	float walkSpeed; //Скорость ходьбы
	float runSpeed; //Скорость бега

	float strength; //Наносимый урон

//	Audio* damageSound; //Звуки при получении урона
//	Audio* deathSound; //Звуки при смерти
//	Audio* entitySound; //Просто звуки
};