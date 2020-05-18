    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Object.h                    //
////////////////////////////////////////

#pragma once

#include "../Utilites/Database/Database.h"

class Object
{
protected:
	int id; //ID �������
	std::string textid; //��������� �������������
	DBS_ObjectData objectData; //������ �� �������

	float health; //��������� �������
public:
	Object(const int id, const std::string textid);

	void doBreake(/*const Item* by*/); //����������
	void resetBreake(); //��������� ����������
	void getDamage(int damage, E_DamageType type); //�������� ����
	void drop(); //����
};
