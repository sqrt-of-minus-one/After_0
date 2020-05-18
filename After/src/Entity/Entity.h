    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Entity.h                    //
////////////////////////////////////////

#pragma once

#include "../Utilites/Database/Database.h"
#include <random>
#include <ctime>

//����� ��������
class Entity abstract
{

protected:
	int id; //�������� �������������
	std::string textid; //��������� �������������
	DBS_EntityData* entityData; //���������� �������� ��������

	int z; //���������� �� ��� Z
	float dx; //��������� ���������� X �� ��������� ����
	float dy; //��������� ���������� Y �� ��������� ����

	float poisonTime; //�� ��������� �������� ���
	float stoneTime; //�� ��������� �������� ����������
	float webTime; //�� ������������ �� �������

	float health; //��������
	float oxygen; //��������

	bool isWalking; //��� ��
	bool isRunning; //����� ��
	bool needStairs; //��������� �� �������� ��� ����������� ����� ������

	bool isDead; //̸��� ��

	E_Direction direction; //�����������

	sf::Sprite sprite; //������

	void move(const float& delta); //�����������

	void death(const E_DamageType damageType, const Entity* murderer); //������
	void deathDrop(); //��������� ��������� ����� ������

	void calculateStats(const float& delta); //���������� �����������
public:
	Entity(const int id, const std::string textid);
	~Entity();

	void getDamage(const float damage, const E_DamageType damageType, const Entity* attacker); //��������� �����
	void getPoison(const int duration); //��������� ������� ����������
	void stone(); //����������� � ������
	void web(); //���������������
	void unstone(); //������������ �� �����
	void unweb(); //������������ �� �������

	void draw(sf::RenderWindow& window); //����������� ������� �� ������

	void tick(const float delta); //������ ����

	E_EntityType getType(); //���������� ��� ��������
	sf::Vector2f getDxy(); //���������� ��������� ��������� �� ��������� ����
	sf::Vector2f getCoordinates(); //���������� ����������
	std::string getTextid(); //���������� ��������� �������������
};