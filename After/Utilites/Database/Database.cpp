    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.cpp                //
////////////////////////////////////////

#include "Database.h"
#include <stdexcept>

using std::stod;
using std::runtime_error;
using std::out_of_range;
using std::to_string;
using sf::SoundBuffer;
using sf::Sound;

DBS_EntityData* Database::entityData[ENTITY_COUNT] = { NULL };
DBS_MobData* Database::mobData[MOB_COUNT] = { NULL };

int Database::entityLoaded[ENTITY_COUNT] = { 0 };
int Database::mobLoaded[MOB_COUNT] = { 0 };

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
		buffer->loadFromFile(SOUNDS_PATH + ENTITY + textid + "_" + "damage" + "_" + to_string(i) + SOUNDS_EXT);
		entityData[id]->damageSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->deathSoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		buffer->loadFromFile(SOUNDS_PATH + ENTITY + textid + "_" + "death" + "_" + to_string(i) + SOUNDS_EXT);
		entityData[id]->deathSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->entitySoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		buffer->loadFromFile(SOUNDS_PATH + ENTITY + textid + "_" + "entity" + "_" + to_string(i) + SOUNDS_EXT);
		entityData[id]->entitySounds[i].setBuffer(*buffer);
	}
	if (!entityData[id]->texture.loadFromFile(TEXTURES_PATH + ENTITY + textid + TEXTURES_EXT))
	{
		entityData[id]->texture.loadFromFile(TEXTURES_PATH + DEBUG + TEXTURES_EXT);
	}
	entityLoaded[id]++;
}

void Database::loadMob(const int id, const string textid, ifstream& file)
{
	mobData[id] = new DBS_MobData;
	file >> mobData[id]->drops;
	mobData[id]->drop = new S_Drop[mobData[id]->drops];
	for (int i = 0; i < mobData[id]->drops; i++)
	{
		string tmp;
		file >> tmp;
//		Item* item = new Item(tmp);
//		mobData[id]->drop[i].item = item;
		file >> mobData[id]->drop[i].max;
		file >> mobData[id]->drop[i].min;
		file >> mobData[id]->drop[i].chance;
	}
	file >> mobData[id]->experience;
	file >> mobData[id]->canAttackMelee;
	file >> mobData[id]->canAttackLong;
	file >> mobData[id]->meleeAttackRadius;
	file >> mobData[id]->longAttackRadius;
	file >> mobData[id]->meleeAttackDamage;
	file >> mobData[id]->longAttackDamage;

	string tmp;
	file >> tmp;
	mobData[id]->meleeDamageType = stoDamageType(tmp);
	file >> tmp;
	mobData[id]->longDamageType = stoDamageType(tmp);

	file >> mobData[id]->canPoisonAttack;
	file >> mobData[id]->viewRadius;
	file >> mobData[id]->purseRadius;
	entityLoaded[id]++;
}


void Database::removeEntity(const int id)
{
	if (id < 0 || id >= ENTITY_COUNT)
	{
		throw out_of_range("Entity with id " + to_string(id) + " dosn`t exist");
	}
	entityLoaded[id]--;
	if (entityLoaded[id] == 0)
	{
		delete entityData[id]->damageSounds;
		delete entityData[id]->deathSounds;
		delete entityData[id]->entitySounds;
		delete entityData[id];
	}
}

void Database::removeMob(const int id)
{
	if (id < 0 || id >= MOB_COUNT)
	{
		throw out_of_range("Mob with id " + to_string(id) + " dosn`t exist");
	}
	mobLoaded[id]--;
	if (mobLoaded[id] == 0)
	{
		delete mobData[id]->drop;
	}
}


DBS_EntityData* Database::getEntityData(const string textid)
{
	int id;
	ifstream file(DATA_PATH + ENTITY + textid + DATA_EXT);
	if (!file.is_open())
	{
		throw runtime_error("Couldn`t find file \"" + DATA_PATH + ENTITY + textid + DATA_EXT + "\"");
	}
	file >> id;
	if (entityData[id] == NULL)
	{
		loadEntity(id, textid, file);
	}
	file.close();
	return entityData[id];
}

DBS_MobData* Database::getMobData(const string textid)
{
	int id;
	ifstream file(DATA_PATH + ENTITY + MOB + textid + DATA_EXT);
	if (!file.is_open())
	{
		throw runtime_error("Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + textid + DATA_EXT + "\"");
	}
	file >> id;
	if (mobData[id] == NULL)
	{
		loadMob(id, textid, file);
	}
	file.close();
	return mobData[id];
}