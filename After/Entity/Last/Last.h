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

	void calculateStats(); //Вычисление показателей

	void deathDrop(); //Выпадение вещей после смерти
public:
	void weak(); //Наложение эффекта слабости
};
