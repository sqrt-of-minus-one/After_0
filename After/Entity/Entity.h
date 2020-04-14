    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.h                    //
////////////////////////////////////////

#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../Utilites/StructsEnums.h"
#include "../Utilites/Database/Database.h"

using sf::Sprite;
using std::string;

class Entity
{
protected:
	int id; //�������� �������������
	string textid; //��������� �������������
	DBS_EntityData* entityData; //���������� �������� ��������

	float poison; //�� ��������� �������� ���

	float health; //��������
	float oxygen; //��������

	float walkSpeed; //�������� ������
	float runSpeed; //�������� ����

	bool isWalking; //��� ��
	bool isRunning; //����� ��
	bool needStairs; //��������� �� �������� ��� ����������� ����� ������

	E_Direction direction; //�����������

	Sprite sprite; //������

	void move(); //�����������

	void death(const E_DamageType damageType, const Entity* murderer);
	void deathDrop();

	void calculateStatis();
public:
	Entity(const int id, const string textid);

	void getDamage(const float damage, const E_DamageType damageType, const Entity* attacker);
	void getPoison(const int duration);
	void stone();
	void web();
	void unstone();
	void unweb();

};