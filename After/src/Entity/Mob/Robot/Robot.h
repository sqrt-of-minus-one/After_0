    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Robot.h                     //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//Класс робота
class Robot : public Mob
{
protected:
	void send(const S_Message& message); //Отправить сообщение на базу
public:
	Robot(const int id, const string textid);

	void recieve(const S_Message& message); //Принять сообщение с базы
};
