    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Mob.cpp                     //
////////////////////////////////////////

#include "Mob.h"
#include <random>
#include <ctime>
using std::time;
using std::rand;
using std::srand;

Mob::Mob(const int id, const string textid) : Entity(id, textid)
{
	mobData = Database::getMobData(textid);
}

void Mob::attackMelee(Entity* attacked)
{
}

void Mob::attackLong(Entity* attacked)
{
}

void Mob::control()
{
	srand(time(NULL));
	switch (rand() % 12)
	{
	case 0:
	case 9:
	case 10:
	case 11:
	{
		isWalking = false;
		break;
	}
	case 1:
	{
		isWalking = true;
		direction = FR;
		break;
	}
	case 2:
	{
		isWalking = true;
		direction = R;
		break;
	}
	case 3:
	{
		isWalking = true;
		direction = BR;
		break;
	}
	case 4:
	{
		isWalking = true;
		direction = B;
		break;
	}
	case 5:
	{
		isWalking = true;
		direction = BL;
		break;
	}
	case 6:
	{
		isWalking = true;
		direction = L;
		break;
	}
	case 7:
	{
		isWalking = true;
		direction = FL;
		break;
	}
	case 8:
	{
		isWalking = true;
		direction = F;
		break;
	}
	}
}

void Mob::tick(const float delta)
{
	srand(time(NULL));
	static float t = 0;
	static float rt = (rand() % 8 + 3) * 1000;

	t += delta;
	if (t >= rt)
	{
		t -= rt;
		rt = (rand() % 8 + 3) * 1000;
		control();
	}

	Entity::tick(delta);
}