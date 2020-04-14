    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.cpp                //
////////////////////////////////////////

#include "Database.h"
#include <stdexcept>

using std::stod;
using std::runtime_error;
using std::to_string;
using sf::SoundBuffer;
using sf::Sound;

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
	file >> entityData[id]->damageSoundsCount;
	file >> entityData[id]->deathSoundsCount;
	file >> entityData[id]->entitySoundsCount;
	entityData[id]->damageSounds = new Sound[entityData[id]->damageSoundsCount];
	entityData[id]->deathSounds = new Sound[entityData[id]->deathSoundsCount];
	entityData[id]->entitySounds = new Sound[entityData[id]->entitySoundsCount];
	for (int i = 0; i < entityData[id]->damageSoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		buffer->loadFromFile(SOUNDS_PATH + ENTITY + textid + "_" + "damage" + "_" + to_string(i) + ".wav");
		entityData[id]->damageSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->deathSoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		buffer->loadFromFile(SOUNDS_PATH + ENTITY + textid + "_" + "death" + "_" + to_string(i) + ".wav");
		entityData[id]->deathSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->entitySoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		buffer->loadFromFile(SOUNDS_PATH + ENTITY + textid + "_" + "entity" + "_" + to_string(i) + ".wav");
		entityData[id]->entitySounds[i].setBuffer(*buffer);
	}
}

DBS_EntityData* Database::getEntityData(const string textid)
{
	int id;
	ifstream file(DATA_PATH + ENTITY + textid + ".dat");
	if (!file.is_open())
	{
		throw runtime_error("Couldn`t find file \"" + DATA_PATH + ENTITY + textid + ".dat\"");
	}
	file >> id;
	if (entityData == NULL)
	{
		loadEntity(id, textid, file);
	}
	file.close();
	return entityData[id];
}