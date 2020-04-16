    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mob.h                       //
////////////////////////////////////////

#pragma once

#include "../Entity.h"
#include "../../Utilites/Database/Database.h"
#include <string>

using std::string;

class Mob : public Entity
{
protected:
	DBS_MobData* mobData; //���������� �������� ����

	bool isAngry; //�������� �� ����-�� ���������
	Entity* targer; //���� ��� �����

	void attackMelee(Entity* attacked); //������� �����
	void attackLong(Entity* attacked); //������� �����
public:
	Mob(const int id, const string textid);
};
