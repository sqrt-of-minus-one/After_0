    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.h                    //
////////////////////////////////////////

#pragma once

#include "../Utilites/Database/Database.h"

using sf::Sprite;
using sf::RenderWindow;

//Класс сущности
class Entity
{
protected:
	int id; //Числовой идентификатор
	string textid; //Текстовый идентификатор
	DBS_EntityData* entityData; //Постоянные свойства сущности

	float poisonTime; //До окончания действия яда
	float stoneTime; //До окончания действия окаменения
	float webTime; //До распутывания из паутины

	float health; //Здоровье
	float oxygen; //Кислород

	bool isWalking; //Идёт ли
	bool isRunning; //Бежит ли
	bool needStairs; //Требуется ли лестница для перемещения между слоями

	E_Direction direction; //Направление

	Sprite sprite; //Спрайт

	void move(const float& delta); //Перемещение

	void death(const E_DamageType damageType, const Entity* murderer); //Смерть
	void deathDrop(); //Выпадение предметов после смерти

	void calculateStats(const float& delta); //Вычисление показателей
public:
	Entity(const int id, const string textid);

	void getDamage(const float damage, const E_DamageType damageType, const Entity* attacker); //Получение урона
	void getPoison(const int duration); //Получение эффекта отравления
	void stone(); //Превращение в камень
	void web(); //«Запаутинивание»
	void unstone(); //Освобождение от камня
	void unweb(); //Освобождение от паутины

	void draw(RenderWindow& window); //Отображение спрайта на экране

	void tick(const float delta); //Каждый кадр
};