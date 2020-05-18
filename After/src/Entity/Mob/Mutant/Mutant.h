    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mutant.h                    //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//Класс мутанта
class Mutant : public Mob
{
	float danceTime; //Время до окончания танца
public:
	Mutant(const int id, const std::string textid);

	void underControl(const S_Message& message); //Нахождение под влиянием инопланетянина
	void dance(); //Начать танцевать
};
