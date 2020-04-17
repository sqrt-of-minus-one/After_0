    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: StructsEnums.h              //
////////////////////////////////////////

#pragma once

#include <string>

using std::string;

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
	string item;		//��������� ������������� ����������� ��������
	int min;		//����������� ����������
	int max;		//������������ ����������
	float chance;	//����������� ���������
};

struct S_Message //�������������� ���������
{

};

E_Direction stoDirection(const string in);
E_ClothesType stoClothesType(const string in);
E_DamageType stoDamageType(const string in);