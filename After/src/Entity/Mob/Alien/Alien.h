    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Alien.h                     //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//����� ��������������
class Alien : public Mob
{
protected:
	void send(Alien* reciever, const S_Message& message); //��������� ���������
public:
	Alien(const int id, const string textid);
	
	void recieve(const S_Message& message); //������� ���������
};
