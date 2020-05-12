    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../StructsEnums.h"

using sf::Sound;
using sf::Texture;

struct DBS_EntityData
{
	E_EntityType type; //��� ��������

	bool isUnloaded; //����������� �� �� ������, ����� ����� ������ ������

	float maxHealth; //������������ ���������� ��������
	float maxOxygen; //������������ ����� ���������
	float oxygenSpeed; //�������� ������������ ���������
	float oxygenRegenerationSpeed; //�������� �������������� ���������
	S_DamageResist damageResist; //���������������� �����

	float walkSpeed; //�������� ������
	float runSpeed; //�������� ����

	float meleeAttackDamage; //��������� ����
	int meleeAttackRadius; //������ �����
	E_DamageType meleeDamageType; //��� ���������� �����

	Sound* damageSounds; //����� ��� ��������� �����
	Sound* deathSounds; //����� ��� ������
	Sound* entitySounds; //������ �����
	int damageSoundsCount; //���������� ������ ��� ��������� �����
	int deathSoundsCount; //���������� ������ ��� ������
	int entitySoundsCount; //���������� ������ ������

	Texture texture_f; //�������� ��������, �����
	Texture texture_fr; //����� � ������
	Texture texture_r; //������
	Texture texture_br; //� �. �.
	Texture texture_b;
	Texture texture_bl;
	Texture texture_l;
	Texture texture_fl;
	int height; //������ �������
	int width; //������ �������
};

struct DBS_MobData
{
	int id; //����� ����
	int drops; //���������� ��������� � ������� �����
	S_Drop* drop; //������ �����
	float experience; //���������� ����� �������� ����
	bool canAttackMelee; //����� �� ��������� ������
	bool canAttackLong; //����� �� ��������� ��������
	int longAttackRadius; //������ �������� ���
	float longAttackDamage; //���� � ������� ���
	E_DamageType longDamageType; //��� ����� � ������� ���
	bool canPoisonAttack; //��������� �� ��� �����
	int viewRadius; //������ ������
	int purseRadius; //������ �������������
};

struct DBS_AnimalData
{
	int id; //����� ���������
	string mutantTextid; //��������� ID ���������������� �������
};

struct DBS_WolfData
{
	float maxHunger;
	float hungerSpeed;
};