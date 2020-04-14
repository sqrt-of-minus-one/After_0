    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "../StructsEnums.h"

using namespace sf;

struct DBS_EntityData
{
	float maxHealth; //������������ ���������� ��������
	float maxOxygen; //������������ ����� ���������
	float oxygenSpeed; //�������� ������������ ���������
	float oxygenRegenerationSpeed; //�������� �������������� ���������
	S_DamageResist damageResist; //���������������� �����

	float walkSpeed; //�������� ������
	float runSpeed; //�������� ����

	float strength; //��������� ����

//	Audio* damageSound; //����� ��� ��������� �����
//	Audio* deathSound; //����� ��� ������
//	Audio* entitySound; //������ �����
};