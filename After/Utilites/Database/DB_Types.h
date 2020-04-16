    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../StructsEnums.h"

using sf::Sound;
using sf::Texture;

struct DBS_EntityData
{
	float maxHealth; //Максимальное количество здоровья
	float maxOxygen; //Максимальный запас кислорода
	float oxygenSpeed; //Скорость расходования кислорода
	float oxygenRegenerationSpeed; //Скорость восстановления кислорода
	S_DamageResist damageResist; //Сопротивляемость урону

	float walkSpeed; //Скорость ходьбы
	float runSpeed; //Скорость бега

	float meleeAttackDamage; //Наносимый урон
	int meleeAttackRadius; //Радиус атаки
	E_DamageType meleeDamageType; //Тип наносимого урона

	Sound* damageSounds; //Звуки при получении урона
	Sound* deathSounds; //Звуки при смерти
	Sound* entitySounds; //Просто звуки
	int damageSoundsCount; //Количество звуков при получении урона
	int deathSoundsCount; //Количество звуков при смерти
	int entitySoundsCount; //Количество просто звуков

	Texture texture; //Текстура сущности
};

struct DBS_MobData
{
	int id; //Номер моба
	int drops; //Количество элементов в массиве дропа
	S_Drop* drop; //Массив дропа
	float experience; //Получаемый после убийства опыт
	bool canAttackMelee; //Может ли атаковать вблизи
	bool canAttackLong; //Может ли атаковать издалека
	int longAttackRadius; //Радиус дальнего боя
	float longAttackDamage; //Урон в дальнем бою
	E_DamageType longDamageType; //Тип урона в дальнем бою
	bool canPoisonAttack; //Отравляет ли при атаке
	int viewRadius; //Радиус обзора
	int purseRadius; //Радиус преследования
};

struct DBS_AnimalData
{
	int id; //Номер животного
	string mutantTextid; //Текстовый ID соответствующего мутанта
};