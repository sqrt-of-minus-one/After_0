    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../StructsEnums.h"

struct DBS_EntityData
{
	E_EntityType type; //Тип сущности

	bool isUnloaded; //Выгружается ли из памяти, когда игрок уходит далеко

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

	sf::Sound* damageSounds; //Звуки при получении урона
	sf::Sound* deathSounds; //Звуки при смерти
	sf::Sound* entitySounds; //Просто звуки
	int damageSoundsCount; //Количество звуков при получении урона
	int deathSoundsCount; //Количество звуков при смерти
	int entitySoundsCount; //Количество просто звуков

	sf::Texture texture_f; //Текстура сущности, вперёд
	sf::Texture texture_fr; //Вперёд и вправо
	sf::Texture texture_r; //Вправо
	sf::Texture texture_br; //И т. д.
	sf::Texture texture_b;
	sf::Texture texture_bl;
	sf::Texture texture_l;
	sf::Texture texture_fl;
	int height; //Высота спрайта
	int width; //Ширина спрайта
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
	std::string mutantTextid; //Текстовый ID соответствующего мутанта
};

struct DBS_WolfData
{
	float maxHunger;
	float hungerSpeed;
};


struct DBS_ObjectData
{
	int id; //ID объекта

	E_ObjectType type; //Тип объекта

	bool canBeBrokenByHand; //Может ли быть разрушен рукой
	float brokeByHandSpeed; //Количество секунд, необходимых на разрушение рукой
	//Todo: Скорость разрушения инструментами

	float damage; //Наносимый при контакте урон
	E_DamageType damageType; //Тип наносимого урона

	int drops; //Количество элементов в массиве дропа
	S_Drop* drop; //Дроп

	float maxHealth; //Прочность
	S_DamageResist damageResist; //Сопротивляемость урону

	sf::Texture texture; //Текстура
	int height; //Высота
	int width; //Ширина
	float opacity; //Прозрачность
};