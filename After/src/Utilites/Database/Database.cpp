    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.cpp                //
////////////////////////////////////////

#include "Database.h"
#include "../Log.h"
#include <stdexcept>

DBS_EntityData* Database::entityData[ENTITY_COUNT] = { nullptr };
DBS_MobData* Database::mobData[MOB_COUNT] = { nullptr };
DBS_AnimalData* Database::animalData[MOB_COUNT] = { nullptr };
DBS_WolfData* Database::wolfData = nullptr;
DBS_ObjectData* Database::objectData[OBJECT_COUNT] = { nullptr };

int Database::entityLoaded[ENTITY_COUNT] = { 0 };
int Database::mobLoaded[MOB_COUNT] = { 0 };
int Database::animalLoaded[MOB_COUNT] = { 0 };
int Database::wolfLoaded = 0;
int Database::objectLoaded[OBJECT_COUNT] = { 0 };

void Database::loadEntity(const int id, const std::string textid, std::ifstream& file)
{
	std::string useless, tmp;
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
	entityData[id]->damageSounds = new sf::Sound[entityData[id]->damageSoundsCount];
	entityData[id]->deathSounds = new sf::Sound[entityData[id]->deathSoundsCount];
	entityData[id]->entitySounds = new sf::Sound[entityData[id]->entitySoundsCount];
	for (int i = 0; i < entityData[id]->damageSoundsCount; i++)
	{
		sf::SoundBuffer* buffer = new sf::SoundBuffer;
		std::string path = SOUNDS_PATH + ENTITY + textid + "_" + "damage" + "_" + std::to_string(i) + SOUNDS_EXT;
		if (!buffer->loadFromFile(path))
		{
			Log::w(W_NO_FILE + path);
		}
		entityData[id]->damageSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->deathSoundsCount; i++)
	{
		sf::SoundBuffer* buffer = new sf::SoundBuffer;
		std::string path = SOUNDS_PATH + ENTITY + textid + "_" + "death" + "_" + std::to_string(i) + SOUNDS_EXT;
		if (!buffer->loadFromFile(path))
		{
			Log::w(W_NO_FILE + path);
		}
		entityData[id]->deathSounds[i].setBuffer(*buffer);
	}
	for (int i = 0; i < entityData[id]->entitySoundsCount; i++)
	{
		sf::SoundBuffer* buffer = new sf::SoundBuffer;
		std::string path = SOUNDS_PATH + ENTITY + textid + "_" + "entity" + "_" + std::to_string(i) + SOUNDS_EXT;
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
		entityData[id]->texture_f.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_fr.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_fr" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_fr" + TEXTURES_EXT);
		entityData[id]->texture_fr.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_r.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_r" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_r" + TEXTURES_EXT);
		entityData[id]->texture_r.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_br.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_br" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_br" + TEXTURES_EXT);
		entityData[id]->texture_br.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_b.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_b" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_b" + TEXTURES_EXT);
		entityData[id]->texture_b.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_bl.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_bl" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_bl" + TEXTURES_EXT);
		entityData[id]->texture_bl.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_l.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_l" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_l" + TEXTURES_EXT);
		entityData[id]->texture_l.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}
	if (!entityData[id]->texture_fl.loadFromFile(TEXTURES_PATH + ENTITY + textid + "_fl" + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + ENTITY + textid + "_fl" + TEXTURES_EXT);
		entityData[id]->texture_fl.loadFromFile(TEXTURES_PATH + ENTITY + DEBUG + "_" + std::to_string(entityData[id]->height) + "x" + std::to_string(entityData[id]->width) + TEXTURES_EXT);
	}

	entityLoaded[id]++;
}

void Database::loadMob(const int id, const std::string textid, std::ifstream& file)
{
	std::string useless;
	mobData[id] = new DBS_MobData;
	mobData[id]->id = id;
	file >> useless >> mobData[id]->drops;
	mobData[id]->drop = new S_Drop[mobData[id]->drops];
	for (int i = 0; i < mobData[id]->drops; i++)
	{
		std::string tmp;
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

	std::string tmp;
	file >> useless >> tmp;
	mobData[id]->longDamageType = stoDamageType(tmp);

	file >> useless >> mobData[id]->canPoisonAttack;
	file >> useless >> mobData[id]->viewRadius;
	file >> useless >> mobData[id]->purseRadius;
	mobLoaded[id]++;
}

void Database::loadAnimal(const int id, const std::string textid, std::ifstream& file)
{
	std::string useless;
	animalData[id] = new DBS_AnimalData;
	animalData[id]->id = id;
	file >> useless >> animalData[id]->mutantTextid;
	animalLoaded[id]++;
}

void Database::loadWolf(std::ifstream& file)
{
	std::string useless;
	wolfData = new DBS_WolfData;
	file >> useless >> wolfData->maxHunger;
	file >> useless >> wolfData->hungerSpeed;
	wolfLoaded++;
}

void Database::loadObject(const int id, const std::string textid, std::ifstream& file)
{
	std::string useless, tmp;
	objectData[id] = new DBS_ObjectData;

	file >> useless >> tmp;
	objectData[id]->type = stoObjectType(tmp);

	file >> useless >> objectData[id]->canBeBrokenByHand;
	file >> useless >> objectData[id]->brokeByHandSpeed;
	file >> useless >> objectData[id]->damage;

	file >> useless >> tmp;
	objectData[id]->damageType = stoDamageType(tmp);

	file >> useless >> objectData[id]->drops;
	objectData[id]->drop = new S_Drop[objectData[id]->drops];
	for (int i = 0; i < objectData[id]->drops; i++)
	{
		std::string tmp;
		file >> tmp;
		//		Item* item = new Item(tmp);
		//		objectData[id]->drop[i].item = item;
		file >> objectData[id]->drop[i].max;
		file >> objectData[id]->drop[i].min;
		file >> objectData[id]->drop[i].chance;
	}
	file >> useless >> objectData[id]->maxHealth;
	file >> useless >> objectData[id]->damageResist.cut;
	file >> useless >> objectData[id]->damageResist.pierce;
	file >> useless >> objectData[id]->damageResist.poison;
	file >> useless >> objectData[id]->damageResist.radiation;
	file >> useless >> objectData[id]->damageResist.suffocation;
	file >> useless >> objectData[id]->damageResist.burn;
	file >> useless >> objectData[id]->height;
	file >> useless >> objectData[id]->width;
	file >> useless >> objectData[id]->opacity;

	if (!objectData[id]->texture.loadFromFile(TEXTURES_PATH + OBJECT + textid + TEXTURES_EXT))
	{
		Log::w(W_NO_FILE + TEXTURES_PATH + OBJECT + textid + TEXTURES_EXT);
		objectData[id]->texture.loadFromFile(TEXTURES_PATH + OBJECT + DEBUG + "_" + std::to_string(objectData[id]->height) + "x" + std::to_string(objectData[id]->width) + TEXTURES_EXT);
	}

	objectLoaded[id]++;
}


void Database::removeEntity(const int id)
{
	if (id < 0 || id >= ENTITY_COUNT)
	{
		throw std::out_of_range("Entity with id " + std::to_string(id) + " dosn`t exist");
	}
	entityLoaded[id]--;
	if (entityLoaded[id] == 0)
	{
		if (entityData[id]->damageSoundsCount > 0)
		{
			delete[] entityData[id]->damageSounds;
		}
		if (entityData[id]->deathSoundsCount > 0)
		{
			delete[] entityData[id]->deathSounds;
		}
		if (entityData[id]->entitySoundsCount > 0)
		{
			delete[] entityData[id]->entitySounds;
		}
		delete entityData[id];
		entityData[id] = nullptr;
	}
}

void Database::removeMob(const int id)
{
	if (id < 0 || id >= MOB_COUNT)
	{
		throw std::out_of_range("Mob with id " + std::to_string(id) + " dosn`t exist");
	}
	mobLoaded[id]--;
	if (mobLoaded[id] == 0)
	{
		delete mobData[id]->drop;
		delete mobData[id];
		mobData[id] = nullptr;
	}
}

void Database::removeAnimal(const int id)
{
	if (id < 0 || id >= ANIMAL_COUNT)
	{
		throw std::out_of_range("Animal with id " + std::to_string(id) + " dosn`t exist");
	}
	animalLoaded[id]--;
	if (animalLoaded[id] == 0)
	{
		delete animalData[id];
		animalData[id] = nullptr;
	}
}

void Database::removeWolf()
{
	wolfLoaded--;
	if (wolfLoaded == 0)
	{
		delete wolfData;
		wolfData = nullptr;
	}
}

void Database::removeObject(const int id)
{
	if (id < 0 || id >= OBJECT_COUNT)
	{
		throw std::out_of_range("Object with id " + std::to_string(id) + " dosn`t exist");
	}
	objectLoaded[id]--;
	if (objectLoaded[id] == 0)
	{
		delete objectData[id]->drop;
		delete objectData[id];
		objectData[id] = nullptr;
	}
}


DBS_EntityData* Database::getEntityData(const std::string textid)
{
	std::string useless;
	int id;
	std::ifstream file(DATA_PATH + ENTITY + textid + DATA_EXT);
	if (!file.is_open())
	{
		std::string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + textid + DATA_EXT + "\"";
		Log::e(error);
		throw std::runtime_error(error);
	}
	file >> useless >> id;
	if (entityData[id] == nullptr)
	{
		loadEntity(id, textid, file);
	}
	file.close();
	return entityData[id];
}

DBS_MobData* Database::getMobData(const std::string textid)
{
	std::string useless;
	int id;
	std::ifstream file(DATA_PATH + ENTITY + MOB + textid + DATA_EXT);
	if (!file.is_open())
	{
		std::string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + textid + DATA_EXT + "\"";
		Log::e(error);
		throw std::runtime_error(error);
	}
	file >> useless >> id;
	if (mobData[id] == nullptr)
	{
		loadMob(id, textid, file);
	}
	file.close();
	return mobData[id];
}

DBS_AnimalData* Database::getAnimalData(const std::string textid)
{
	std::string useless;
	int id;
	std::ifstream file(DATA_PATH + ENTITY + MOB + ANIMAL + textid + DATA_EXT);
	if (!file.is_open())
	{
		std::string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + ANIMAL + textid + DATA_EXT + "\"";
		Log::e(error);
		throw std::runtime_error(error);
	}
	file >> useless >> id;
	if (animalData[id] == nullptr)
	{
		loadAnimal(id, textid, file);
	}
	file.close();
	return animalData[id];
}

DBS_WolfData* Database::getWolfData()
{
	if (wolfData == nullptr)
	{
		std::ifstream file(DATA_PATH + ENTITY + MOB + ANIMAL + EXTRA + "wolf" + DATA_EXT);
		if (!file.is_open())
		{
			std::string error = "Couldn`t find file \"" + DATA_PATH + ENTITY + MOB + ANIMAL + EXTRA + "wolf" + DATA_EXT + "\"";
			Log::e(error);
			throw std::runtime_error(error);
		}
		loadWolf(file);
		file.close();
	}
	return wolfData;
}

DBS_ObjectData* Database::getObjectData(const std::string textid)
{
	std::string useless;
	int id;
	std::ifstream file(DATA_PATH + OBJECT + textid + DATA_EXT);
	if (!file.is_open())
	{
		std::string error = "Couldn`t find file \"" + DATA_PATH + OBJECT + textid + DATA_EXT + "\"";
		Log::e(error);
		throw std::runtime_error(error);
	}
	file >> useless >> id;
	if (objectData[id] == nullptr)
	{
		loadObject(id, textid, file);
	}
	file.close();
	return objectData[id];
}