    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.cpp                //
////////////////////////////////////////

#include "Database.h"
#include "../Log.h"
#include <stdexcept>

using std::stod;
using std::runtime_error;
using std::out_of_range;
using std::to_string;
using sf::SoundBuffer;

DBS_EntityData* Database::entityData[ENTITY_COUNT] = { NULL };
DBS_MobData* Database::mobData[MOB_COUNT] = { NULL };
DBS_AnimalData* Database::animalData[MOB_COUNT] = { NULL };
DBS_WolfData* Database::wolfData = NULL;

int Database::entityLoaded[ENTITY_COUNT] = { 0 };
int Database::mobLoaded[MOB_COUNT] = { 0 };
int Database::animalLoaded[MOB_COUNT] = { 0 };
int Database::wolfLoaded = 0;

void Database::loadEntity(const int id, const string textid, ifstream& file)
{
	string useless, tmp;
	entityData[id] = new DBS_EntityData;

	file >> useless >> tmp;
	entityData[id]->type = stoEntityType(tmp);

	file >> useless >> entityData[id]->isUnloaded;
	file >> useless >> entityData[id]->maxHealth;
	file >> useless >> entityData[id]->maxOxygen;
	file >> useless >> entityData[id]->oxygenSpeed;
	file >> useless >> entityData[id]->oxygenRegenerationSpeed;
	file >> useless >> entityData[id]->damageResist.strike;
	file >> useless >> entityData[id]->damageResist.cut;
	file >> useless >> entityData[id]->damageResist.pierce;
	file >> useless >> entityData[id]->damageResist.poison;
	file >> useless >> entityData[id]->damageResist.radiation;
	file >> useless >> entityData[id]->damageResist.suffocation;
	file >> useless >> entityData[id]->damageResist.burn;
	file >> useless >> entityData[id]->walkSpeed;
	file >> useless >> entityData[id]->runSpeed;
	file >> useless >> entityData[id]->meleeAttackDamage;
	file >> useless >> entityData[id]->meleeAttackRadius;

	file >> useless >> tmp;
	entityData[id]->meleeDamageType = stoDamageType(tmp);

	file >> useless >> entityData[id]->damageSoundsCount;
	file >> useless >> entityData[id]->deathSoundsCount;
	file >> useless >> entityData[id]->entitySoundsCount;
	entityData[id]->damageSounds = new Sound[entityData[id]->damageSoundsCount];
	entityData[id]->deathSounds = new Sound[entityData[id]->deathSoundsCount];
	entityData[id]->entitySounds = new Sound[entityData[id]->entitySoundsCount];
	for (int i = 0; i < entityData[id]->damageSoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		string path = SOUNDS_PATH + ENTITY + textid + "_" + "damage" + "_" + to_string(i) + SOUNDS_EXT;
		if (!buffer->loadFromFile(path))
		{
			Log::w(W_NO_FILE + path);
		}
		entityData[id]->damageSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->deathSoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		string path = SOUNDS_PATH + ENTITY + textid + "_" + "death" + "_" + to_string(i) + SOUNDS_EXT;
		if (!buffer->loadFromFile(path))
		{
			Log::w(W_NO_FILE + path);
		}
		entityData[id]->deathSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->entitySoundsCount; i++)
	{
		SoundBuffer* buffer = new SoundBuffer;
		string path = SOUNDS_PATH + ENTITY + textid + "_" + "entity" + "_" + to_string(i) + SOUNDS_EXT;
		if (!buffer->loadFromFile(path))
		{
			Log::w(W_NO_FILE + path);
		}
		entityData[id]->entitySounds[i].setBuffer(*buffer);
	}

	file >> useless >> entityData[id]->height;
	file >> useless >> entityData[id]->width;

	if (!entityData[id]->texture_f.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_f" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_f" + TEXTURES_EXT);
		entityData[id]->texture_f.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_fr.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_fr" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_fr" + TEXTURES_EXT);
		entityData[id]->texture_fr.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_r.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_r" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_r" + TEXTURES_EXT);
		entityData[id]->texture_r.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_br.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_br" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_br" + TEXTURES_EXT);
		entityData[id]->texture_br.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_b.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_b" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_b" + TEXTURES_EXT);
		entityData[id]->texture_b.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_bl.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_bl" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_bl" + TEXTURES_EXT);
		entityData[id]->texture_bl.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_l.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_l" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_l" + TEXTURES_EXT);
		entityData[id]->texture_l.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_fl.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_fl" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_fl" + TEXTURES_EXT);
		entityData[id]->texture_fl.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + to_string(entityData[id]->height) + "x" + to_string(entityData[id]->width) + TEXTURES_EXT);
	}

	entityLoaded[id]++;
}

void Database::loadMob(const int id, const string textid, ifstream& file)
{
	string useless;
	mobData[id] = new DBS_MobData;
	mobData[id]->id = id;
	file >> useless >> mobData[id]->drops;
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
	file >> useless >> mobData[id]->experience;
	file >> useless >> mobData[id]->canAttackMelee;
	file >> useless >> mobData[id]->canAttackLong;
	file >> useless >> mobData[id]->longAttackRadius;
	file >> useless >> mobData[id]->longAttackDamage;

	string tmp;
	file >> useless >> tmp;
	mobData[id]->longDamageType = stoDamageType(tmp);

	file >> useless >> mobData[id]->canPoisonAttack;
	file >> useless >> mobData[id]->viewRadius;
	file >> useless >> mobData[id]->purseRadius;
	mobLoaded[id]++;
}

void Database::loadAnimal(const int id, const string textid, ifstream& file)
{
	string useless;
	animalData[id] = new DBS_AnimalData;
	animalData[id]->id = id;
	file >> useless >> animalData[id]->mutantTextid;
	animalLoaded[id]++;
}

void Database::loadWolf(ifstream& file)
{
	string useless;
	wolfData = new DBS_WolfData;
	file >> useless >> wolfData->maxHunger;
	file >> useless >> wolfData->hungerSpeed;
	wolfLoaded++;
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
		entityData[id] = NULL;
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
		delete mobData[id];
		mobData[id] = NULL;
	}
}

void Database::removeAnimal(const int id)
{
	if (id < 0 || id >= ANIMAL_COUNT)
	{
		throw out_of_range("Animal with id " + to_string(id) + " dosn`t exist");
	}
	animalLoaded[id]--;
	if (animalLoaded[id] == 0)
	{
		delete animalData[id];
		animalData[id] = NULL;
	}
}

void Database::removeWolf()
{
	wolfLoaded--;
	if (wolfLoaded == 0)
	{
		delete wolfData;
		wolfData = NULL;
	}
}


DBS_EntityData* Database::getEntityData(const string textid)
{
	string useless;
	int id;
	ifstream file(DATA_PATH + ENTITY + textid + DATA_EXT);
	if (!file.is_open())
	{
		string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + textid + DATA_EXT + "\"";
		Log::e(error);
		throw runtime_error(error);
	}
	file >> useless >> id;
	if (entityData[id] == NULL)
	{
		loadEntity(id, textid, file);
	}
	file.close();
	return entityData[id];
}

DBS_MobData* Database::getMobData(const string textid)
{
	string useless;
	int id;
	ifstream file(DATA_PATH + ENTITY + MOB + textid + DATA_EXT);
	if (!file.is_open())
	{
		string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + textid + DATA_EXT + "\"";
		Log::e(error);
		throw runtime_error(error);
	}
	file >> useless >> id;
	if (mobData[id] == NULL)
	{
		loadMob(id, textid, file);
	}
	file.close();
	return mobData[id];
}

DBS_AnimalData* Database::getAnimalData(const string textid)
{
	string useless;
	int id;
	ifstream file(DATA_PATH + ENTITY + MOB + ANIMAL + textid + DATA_EXT);
	if (!file.is_open())
	{
		string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + ANIMAL + textid + DATA_EXT + "\"";
		Log::e(error);
		throw runtime_error(error);
	}
	file >> useless >> id;
	if (animalData[id] == NULL)
	{
		loadAnimal(id, textid, file);
	}
	file.close();
	return animalData[id];
}

DBS_WolfData* Database::getWolfData()
{
	if (wolfData == NULL)
	{
		ifstream file(DATA_PATH + ENTITY + MOB + ANIMAL + EXTRA + "wolf" + DATA_EXT);
		if (!file.is_open())
		{
			string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + ANIMAL + EXTRA + "wolf" + DATA_EXT + "\"";
			Log::e(error);
			throw runtime_error(error);
		}
		loadWolf(file);
		file.close();
	}
	return wolfData;
}