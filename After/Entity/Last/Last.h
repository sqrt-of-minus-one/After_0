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

	void calculateStats(const float delta); //���������� �����������

	void deathDrop(); //��������� ����� ����� ������
public:
	Last();

	void weak(); //��������� ������� ��������

	void tick(const float delta); //������ ����

	void getCenter(float& x, float& y); //�������� ���������� ������
<<<<<<< HEAD
=======
	void getStats(float& health, float& energy, float& weakness, float& oxygene, float& hunger); //�������� ����������
>>>>>>> develop
};
