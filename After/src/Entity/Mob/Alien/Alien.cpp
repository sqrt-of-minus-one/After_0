    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Alien.cpp                   //
////////////////////////////////////////

#include "Alien.h"

Alien::Alien(const int id, const std::string textid) : Mob(id, textid)
{
}

void Alien::send(Alien* reciever, const S_Message& message)
{
}

void Alien::recieve(const S_Message& message)
{
}