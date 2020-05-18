    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mob.h                       //
////////////////////////////////////////

#pragma once

#include "../Entity.h"

class Mob abstract : public Entity
{
protected:
	DBS_MobData* mobData; //���������� �������� ����

	bool isAngry; //�������� �� ����-�� ���������
	Entity* targer; //���� ��� �����

	void attackMelee(Entity* attacked); //������� �����
	void attackLong(Entity* attacked); //������� �����
	
	void control(); //���������� ���������� ����
public:
	Mob(const int id, const std::string textid);
	~Mob();

	void tick(const float delta);
};
