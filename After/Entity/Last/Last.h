    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Last.h                      //
////////////////////////////////////////

#pragma once

#include "../Entity.h"

//����� ������
class Last : public Entity
{
protected:
	float hunger; //����� ������
	float maxHunger; //������������ �����
	float hungeringSpeed; //�������� ���������
	float energy; //�������
	float maxEnergy; //������������ �������
	float energySpeed; //�������� ����� �������
	float energyRegenerationSpeed; //�������� �������������� �������
	float weakness; //���������
	float weaknessSpeed; //�������� ���������� ���������

	float weakTime; //����� �� ����������� �������� ������� ��������
	
//	PlayerInventory* inventory; //���������
//	Skills* skills; //������

	void calculateStats(); //���������� �����������

	void deathDrop(); //��������� ����� ����� ������
public:
	void weak(); //��������� ������� ��������
};
