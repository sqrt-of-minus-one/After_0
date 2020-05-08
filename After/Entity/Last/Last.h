    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Last.h                      //
////////////////////////////////////////

#pragma once

#include "../Entity.h"

//Класс игрока
class Last : public Entity
{
protected:
	float hunger; //Шкала голода
	float maxHunger; //Максимальный голод
	float hungeringSpeed; //Скорость голодания
	float energy; //Энергия
	float maxEnergy; //Максимальная энергия
	float energySpeed; //Скорость траты энергии
	float energyRegenerationSpeed; //Скорость восстановления энергии
	float weakness; //Усталость
	float weaknessSpeed; //Скорость накопления усталости

	float weakTime; //Время до прекращения действия эффекта слабости
	
//	PlayerInventory* inventory; //Инвентарь
//	Skills* skills; //Навыки

	void calculateStats(const float delta); //Вычисление показателей

	void deathDrop(); //Выпадение вещей после смерти
public:
	Last();

	void weak(); //Наложение эффекта слабости

	void tick(const float delta); //Каждый кадр

	void getCenter(float& x, float& y); //Получить координаты центра
<<<<<<< HEAD
=======
	void getStats(float& health, float& energy, float& weakness, float& oxygene, float& hunger); //Получить показатели
>>>>>>> develop
};
