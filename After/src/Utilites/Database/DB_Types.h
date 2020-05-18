    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: DB_Types.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../StructsEnums.h"

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

	sf::Sound* damageSounds; //����� ��� ��������� �����
	sf::Sound* deathSounds; //����� ��� ������
	sf::Sound* entitySounds; //������ �����
	int damageSoundsCount; //���������� ������ ��� ��������� �����
	int deathSoundsCount; //���������� ������ ��� ������
	int entitySoundsCount; //���������� ������ ������

	sf::Texture texture_f; //�������� ��������, �����
	sf::Texture texture_fr; //����� � ������
	sf::Texture texture_r; //������
	sf::Texture texture_br; //� �. �.
	sf::Texture texture_b;
	sf::Texture texture_bl;
	sf::Texture texture_l;
	sf::Texture texture_fl;
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
	std::string mutantTextid; //��������� ID ���������������� �������
};

struct DBS_WolfData
{
	float maxHunger;
	float hungerSpeed;
};


struct DBS_ObjectData
{
	int id; //ID �������

	E_ObjectType type; //��� �������

	bool canBeBrokenByHand; //����� �� ���� �������� �����
	float brokeByHandSpeed; //���������� ������, ����������� �� ���������� �����
	//Todo: �������� ���������� �������������

	float damage; //��������� ��� �������� ����
	E_DamageType damageType; //��� ���������� �����

	int drops; //���������� ��������� � ������� �����
	S_Drop* drop; //����

	float maxHealth; //���������
	S_DamageResist damageResist; //���������������� �����

	sf::Texture texture; //��������
	int height; //������
	int width; //������
	float opacity; //������������
};