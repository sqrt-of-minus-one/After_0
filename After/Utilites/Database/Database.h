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
	static void loadEntity(const int id, const string textid, ifstream& file);
public:
	static DBS_EntityData* getEntityData(const string textid);
};