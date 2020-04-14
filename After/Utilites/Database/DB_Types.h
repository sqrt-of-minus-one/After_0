    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	Sound* damageSounds; //Звуки при получении урона
	Sound* deathSounds; //Звуки при смерти
	Sound* entitySounds; //Просто звуки
	int damageSoundsCount; //Количество звуков при получении урона
	int deathSoundsCount; //Количество звуков при смерти
	int entitySoundsCount; //Количество просто звуков
};