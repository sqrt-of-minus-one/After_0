    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mutant.h                    //
////////////////////////////////////////

#pragma once

#include "../Mob.h"

//����� �������
class Mutant : public Mob
{
	float danceTime; //����� �� ��������� �����
public:
	Mutant(const int id, const string textid);

	void underControl(const S_Message& message); //���������� ��� �������� ��������������
	void dance(); //������ ���������
};
