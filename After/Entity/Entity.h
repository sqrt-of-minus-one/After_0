    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.h                    //
////////////////////////////////////////

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../Utilites/StructsEnums.h"
#include "../Utilites/Database/Database.h"

using sf::Sprite;
using std::string;

class Entity
{
protected:
	int id; //Числовой идентификатор
	string textid; //Текстовый идентификатор
	DBS_EntityData* entityData; //Постоянные свойства сущности

	float poison; //До окончания действия яда

	float health; //Здоровье
	float oxygen; //Кислород

	float walkSpeed; //Скорость ходьбы
	float runSpeed; //Скорость бега

	bool isWalking; //Идёт ли
	bool isRunning; //Бежит ли
	bool needStairs; //Требуется ли лестница для перемещения между слоями

	E_Direction direction; //Направление

	Sprite sprite; //Спрайт

	void move(); //Перемещение

	void death(const E_DamageType damageType, const Entity* murderer);
	void deathDrop();

	void calculateStatis();
public:
	Entity(const int id, const string textid);

	void getDamage(const float damage, const E_DamageType damageType, const Entity* attacker);
	void getPoison(const int duration);
	void stone();
	void web();
	void unstone();
	void unweb();

};