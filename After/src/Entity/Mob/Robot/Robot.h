    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Robot.h                     //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//����� ������
class Robot : public Mob
{
protected:
	void send(const S_Message& message); //��������� ��������� �� ����
public:
	Robot(const int id, const std::string textid);

	void recieve(const S_Message& message); //������� ��������� � ����
};
