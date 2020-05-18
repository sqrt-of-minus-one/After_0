    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.h                  //
////////////////////////////////////////

#pragma once

#include "DB_Types.h"
#include "../Constants.h"
#include <fstream>

class Database
{
private:
	static DBS_EntityData* entityData[ENTITY_COUNT];
	static DBS_MobData* mobData[MOB_COUNT];
	static DBS_AnimalData* animalData[ANIMAL_COUNT];
	static DBS_WolfData* wolfData;
	static DBS_ObjectData* objectData[OBJECT_COUNT];

	static int entityLoaded[ENTITY_COUNT];
	static int mobLoaded[MOB_COUNT];
	static int animalLoaded[ANIMAL_COUNT];
	static int wolfLoaded;
	static int objectLoaded[OBJECT_COUNT];

	static void loadEntity(const int id, const std::string textid, std::ifstream& file);
	static void loadMob(const int id, const std::string textid, std::ifstream& file);
	static void loadAnimal(const int id, const std::string textid, std::ifstream& file);
	static void loadWolf(std::ifstream& file);
	static void loadObject(const int id, const std::string textid, std::ifstream& file);
public:
	static void removeEntity(const int id);
	static void removeMob(const int id);
	static void removeAnimal(const int id);
	static void removeWolf();
	static void removeObject(const int id);

	static DBS_EntityData* getEntityData(const std::string textid);
	static DBS_MobData* getMobData(const std::string textid);
	static DBS_AnimalData* getAnimalData(const std::string textid);
	static DBS_WolfData* getWolfData();
	static DBS_ObjectData* getObjectData(const std::string textid);
};