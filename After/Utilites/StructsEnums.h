    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: StructsEnums.h              //
////////////////////////////////////////

#pragma once

#include <string>

using std::string;

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
	string item;		//Текстовый идентификатор выпадающего предмета
	int min;		//Минимальное количество
	int max;		//Максимальное количество
	float chance;	//Вероятность выпадения
};

struct S_Message //Телепатическое сообщение
{

};

E_Direction stoDirection(const string& in);
E_ClothesType stoClothesType(const string& in);
E_DamageType stoDamageType(const string& in);
E_EntityType stoEntityType(const string& str);