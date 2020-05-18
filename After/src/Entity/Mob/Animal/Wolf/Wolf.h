    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Wolf.h                      //
////////////////////////////////////////

#pragma once

#include "../Animal.h"

//����� �����
class Wolf : public Animal
{
protected:
	float hunger; //����� ������
	DBS_WolfData* wolfData; //������ � �����

	void death(const E_DamageType damageType, const Entity* murderer);
public:
	Wolf(const int id, const std::string textid);
};

