    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Alien.h                     //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//Класс инопланетянина
class Alien : public Mob
{
protected:
	void send(Alien* reciever, const S_Message& message); //Отправить сообщение
public:
	Alien(const int id, const string textid);
	
	void recieve(const S_Message& message); //Принять сообщение
};
