    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: StructsEnums.cpp            //
////////////////////////////////////////

#include "StructsEnums.h"

E_Direction stoDirection(const std::string& in)
{
	if		(in == "FR")	return FR;
	else if (in == "R")		return R;
	else if (in == "BR")	return BR;
	else if (in == "B")		return B;
	else if (in == "BL")	return BL;
	else if (in == "L")		return L;
	else if (in == "FL")	return FL;
	else					return F;
}

E_ClothesType stoClothesType(const std::string& in)
{
	if		(in == "Jacket")	return JACKET;
	else if (in == "Shirt")		return SHIRT;
	else if (in == "Pants")		return PANTS;
	else if (in == "Shoes")		return SHOES;
	else if (in == "Backpack")	return BACKPACK;
	else						return HAT;
}

E_DamageType stoDamageType(const std::string& in)
{
	if		(in == "Cut")			return CUT;
	else if (in == "Pierce")		return PIERCE;
	else if (in == "Poison")		return POISON;
	else if (in == "Radiation")		return RADIATION;
	else if (in == "Suffocation")	return SUFFOCATION;
	else if (in == "Burn")			return BURN;
	else							return STRIKE;
}

E_EntityType stoEntityType(const std::string& str)
{
	if (str == "Alien")			return ENTITY_ALIEN;

	else if (str == "Animal")	return ENTITY_ANIMAL;
	else if (str == "Wolf")		return ENTITY_WOLF;

	else if (str == "Mutant")	return ENTITY_MUTANT;

	else if (str == "Robot")	return ENTITY_ROBOT;

	else						return ENTITY_LAST;
}

E_ObjectType stoObjectType(const std::string& str)
{
	if (str == "Stone")			return STONE_OBJ;
	else if (str == "Wood")		return WOOD_OBJ;
	else if (str == "Dirt")		return DIRT_OBJ;
	else if (str == "Glass")	return GLASS_OBJ;
	else if (str == "Air")		return AIR_OBJ;
	else						return OTHER_OBJ;
}