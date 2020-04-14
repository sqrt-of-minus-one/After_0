    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.cpp                //
////////////////////////////////////////

#include "Database.h"
#include <stdexcept>

using std::stod;
using std::runtime_error;

DBS_EntityData* Database::entityData[ENTITY_COUNT] = { NULL };

void Database::loadEntity(const int id, const string textid, ifstream& file)
{
	entityData[id] = new DBS_EntityData;
	file >> entityData[id]->maxHealth;
	file >> entityData[id]->maxOxygen;
	file >> entityData[id]->oxygenSpeed;
	file >> entityData[id]->oxygenRegenerationSpeed;
	file >> entityData[id]->damageResist.strike;
	file >> entityData[id]->damageResist.cut;
	file >> entityData[id]->damageResist.pierce;
	file >> entityData[id]->damageResist.poison;
	file >> entityData[id]->damageResist.radiation;
	file >> entityData[id]->damageResist.suffocation;
	file >> entityData[id]->damageResist.burn;
	file >> entityData[id]->walkSpeed;
	file >> entityData[id]->runSpeed;
	file >> entityData[id]->strength;
}

DBS_EntityData* Database::getEntityData(const string textid)
{
	int id;
	ifstream file(ENTITY_PATH + textid + ".dat");
	if (!file.is_open())
	{
		throw runtime_error("Couldn`t find file \"" + ENTITY_PATH + textid + ".dat\"");
	}
	file >> id;
	if (entityData == NULL)
	{
		loadEntity(id, textid, file);
	}
	file.close();
	return entityData[id];
}