    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.h                    //
////////////////////////////////////////

#pragma once

#include "../Utilites/Database/Database.h"
#include <random>
#include <ctime>

//Класс сущности
class Entity abstract
{

protected:
	int id; //Числовой идентификатор
	std::string textid; //Текстовый идентификатор
	DBS_EntityData* entityData; //Постоянные свойства сущности

	int z; //Координата по оси Z
	float dx; //Изменение координаты X за последний кадр
	float dy; //Изменение координаты Y за последний кадр

	float poisonTime; //До окончания действия яда
	float stoneTime; //До окончания действия окаменения
	float webTime; //До распутывания из паутины

	float health; //Здоровье
	float oxygen; //Кислород

	bool isWalking; //Идёт ли
	bool isRunning; //Бежит ли
	bool needStairs; //Требуется ли лестница для перемещения между слоями

	bool isDead; //Мёртв ли

	E_Direction direction; //Направление

	sf::Sprite sprite; //Спрайт

	void move(const float& delta); //Перемещение

	void death(const E_DamageType damageType, const Entity* murderer); //Смерть
	void deathDrop(); //Выпадение предметов после смерти

	void calculateStats(const float& delta); //Вычисление показателей
public:
	Entity(const int id, const std::string textid);
	~Entity();

	void getDamage(const float damage, const E_DamageType damageType, const Entity* attacker); //Получение урона
	void getPoison(const int duration); //Получение эффекта отравления
	void stone(); //Превращение в камень
	void web(); //«Запаутинивание»
	void unstone(); //Освобождение от камня
	void unweb(); //Освобождение от паутины

	void draw(sf::RenderWindow& window); //Отображение спрайта на экране

	void tick(const float delta); //Каждый кадр

	E_EntityType getType(); //Возвращает тип сущности
	sf::Vector2f getDxy(); //Возвращает изменение координат за последний кадр
	sf::Vector2f getCoordinates(); //Возвращает координаты
	std::string getTextid(); //Возвращает текстовый идентификатор
};