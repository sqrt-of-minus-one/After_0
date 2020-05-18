    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: StructsEnums.h              //
////////////////////////////////////////

#pragma once

#include <string>

enum E_EntityType //��� ��������
{
	ENTITY_LAST,	//�����

	ENTITY_ALIEN,	//�������������

	ENTITY_ANIMAL,	//��������
	ENTITY_WOLF,	//��������: ����

	ENTITY_MUTANT,	//������

	ENTITY_ROBOT	//�����
};

enum E_Direction
{
	F,	//�����
	FR,	//����� � ������
	R,	//� ��� �����...
	BR,
	B,
	BL,
	L,
	FL
};

enum E_ClothesType //���� ������
{
	HAT,		//�����
	JACKET,		//������
	SHIRT,		//��������/�������
	PANTS,		//�����
	SHOES,		//�����
	BACKPACK	//������
};

enum E_DamageType //���� �����
{
	STRIKE,			//����
	CUT,			//�����
	PIERCE,			//������� ����
	POISON,			//����������
	RADIATION,		//��������
	SUFFOCATION,	//������
	BURN			//����
};

enum E_ObjectType //��� �������
{
	STONE_OBJ, //������
	WOOD_OBJ, //���������
	DIRT_OBJ, //�����
	GLASS_OBJ, //������
	AIR_OBJ, //������ (��� ���)
	OTHER_OBJ //������
};

struct S_DamageResist //���������������� ��������� ����� �����
{
	float strike;		//����
	float cut;			//�����
	float pierce;		//������� ����
	float poison;		//����������
	float radiation;	//��������
	float suffocation;	//������
	float burn;			//����

};

struct S_Drop //����
{
	std::string item;		//��������� ������������� ����������� ��������
	int min;		//����������� ����������
	int max;		//������������ ����������
	float chance;	//����������� ���������
};

struct S_Message //�������������� ���������
{

};

E_Direction stoDirection(const std::string& in);
E_ClothesType stoClothesType(const std::string& in);
E_DamageType stoDamageType(const std::string& in);
E_EntityType stoEntityType(const std::string& str);
E_ObjectType stoObjectType(const std::string& str);