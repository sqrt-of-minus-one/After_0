    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	Sound* damageSounds; //����� ��� ��������� �����
	Sound* deathSounds; //����� ��� ������
	Sound* entitySounds; //������ �����
	int damageSoundsCount; //���������� ������ ��� ��������� �����
	int deathSoundsCount; //���������� ������ ��� ������
	int entitySoundsCount; //���������� ������ ������

	Texture texture; //�������� ��������
};

struct DBS_MobData
{
	int drops; //���������� ��������� � ������� �����
	S_Drop* drop; //������ �����
	float experience; //���������� ����� �������� ����
	bool canAttackMelee; //����� �� ��������� ������
	bool canAttackLong; //����� �� ��������� ��������
	int meleeAttackRadius; //������ �������� ���
	int longAttackRadius; //������ �������� ���
	float meleeAttackDamage; //���� � ������� ���
	float longAttackDamage; //���� � ������� ���
	E_DamageType meleeDamageType; //��� ����� � ������� ���
	E_DamageType longDamageType; //��� ����� � ������� ���
	bool canPoisonAttack; //��������� �� ��� �����
	int viewRadius; //������ ������
	int purseRadius; //������ �������������
};