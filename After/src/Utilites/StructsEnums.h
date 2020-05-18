    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: StructsEnums.h              //
////////////////////////////////////////

#pragma once

#include <string>

enum E_EntityType //Тип сущности
{
	ENTITY_LAST,	//Игрок

	ENTITY_ALIEN,	//Инопланетянин

	ENTITY_ANIMAL,	//Животное
	ENTITY_WOLF,	//Животное: волк

	ENTITY_MUTANT,	//Мутант

	ENTITY_ROBOT	//Робот
};

enum E_Direction
{
	F,	//Вперёд
	FR,	//Вперёд и вправо
	R,	//И так далее...
	BR,
	B,
	BL,
	L,
	FL
};

enum E_ClothesType //Типы одежды
{
	HAT,		//Шапка
	JACKET,		//Куртка
	SHIRT,		//Футболка/рубашка
	PANTS,		//Брюки
	SHOES,		//Обувь
	BACKPACK	//Рюкзак
};

enum E_DamageType //Виды урона
{
	STRIKE,			//Удар
	CUT,			//Порез
	PIERCE,			//Колющий удар
	POISON,			//Отравление
	RADIATION,		//Радиация
	SUFFOCATION,	//Удушье
	BURN			//Ожог
};

enum E_ObjectType //Тип объекта
{
	STONE_OBJ, //Камень
	WOOD_OBJ, //Древесина
	DIRT_OBJ, //Земля
	GLASS_OBJ, //Стекло
	AIR_OBJ, //Воздух (или газ)
	OTHER_OBJ //Прочее
};

struct S_DamageResist //Сопротивляемость различным видам урона
{
	float strike;		//Удар
	float cut;			//Порез
	float pierce;		//Колющий удар
	float poison;		//Отравление
	float radiation;	//Радиация
	float suffocation;	//Удушье
	float burn;			//Ожог

};

struct S_Drop //Дроп
{
	std::string item;		//Текстовый идентификатор выпадающего предмета
	int min;		//Минимальное количество
	int max;		//Максимальное количество
	float chance;	//Вероятность выпадения
};

struct S_Message //Телепатическое сообщение
{

};

E_Direction stoDirection(const std::string& in);
E_ClothesType stoClothesType(const std::string& in);
E_DamageType stoDamageType(const std::string& in);
E_EntityType stoEntityType(const std::string& str);
E_ObjectType stoObjectType(const std::string& str);