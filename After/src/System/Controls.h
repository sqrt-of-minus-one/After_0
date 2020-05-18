    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Controls.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>

struct S_Controls
{
	static sf::Keyboard::Key forward;
	static sf::Keyboard::Key back;
	static sf::Keyboard::Key left;
	static sf::Keyboard::Key right;
	static sf::Keyboard::Key run;
	static bool invertZoom;
	static bool invertMouseButtons;

	static void load();
	static void defaults();
	static void save();
};