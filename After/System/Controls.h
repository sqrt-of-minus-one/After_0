    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Controls.h                  //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>

using sf::Keyboard;

struct S_Controls
{
	static Keyboard::Key forward;
	static Keyboard::Key back;
	static Keyboard::Key left;
	static Keyboard::Key right;
	static bool invertZoom;
	static bool invertMouseButtons;

	static void load();
	static void defaults();
	static void save();
};