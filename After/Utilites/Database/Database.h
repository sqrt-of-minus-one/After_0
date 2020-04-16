    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Database.h                  //
////////////////////////////////////////

#pragma once

#include "DB_Types.h"
#include "../Constants.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

class Database
{
protected:
	static DBS_EntityData* entityData[ENTITY_COUNT];
	static DBS_MobData* mobData[MOB_COUNT];

	static int entityLoaded[ENTITY_COUNT];
	static int mobLoaded[MOB_COUNT];

	static void loadEntity(const int id, const string textid, ifstream& file);
	static void loadMob(const int id, const string textid, ifstream& file);
public:
	static void removeEntity(const int id);
	static void removeMob(const int id);

	static DBS_EntityData* getEntityData(const string textid);
	static DBS_MobData* getMobData(const string textid);
};