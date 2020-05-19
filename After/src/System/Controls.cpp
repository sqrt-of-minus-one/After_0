    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Controls.cpp                //
////////////////////////////////////////

#include "Controls.h"
#include "../Utilites/Constants.h"
#include <fstream>

sf::Keyboard::Key S_Controls::forward = sf::Keyboard::W;
sf::Keyboard::Key S_Controls::back = sf::Keyboard::S;
sf::Keyboard::Key S_Controls::left = sf::Keyboard::A;
sf::Keyboard::Key S_Controls::right = sf::Keyboard::D;
sf::Keyboard::Key S_Controls::run = sf::Keyboard::LShift;
bool S_Controls::invertZoom = false;
bool S_Controls::invertMouseButtons = false;

void S_Controls::load()
{
	std::ifstream file(OPTIONS_PATH + CONTROLS_FILE + DATA_EXT);
	if (!file.is_open())
	{
		defaults();
		save();
	}
	else
	{
		int in;

		file >> in;
		forward = static_cast<sf::Keyboard::Key>(in);

		file >> in;
		back = static_cast<sf::Keyboard::Key>(in);

		file >> in;
		left = static_cast<sf::Keyboard::Key>(in);

		file >> in;
		right = static_cast<sf::Keyboard::Key>(in);

		file >> in;
		run = static_cast<sf::Keyboard::Key>(in);

		file >> invertZoom;

		file >> invertMouseButtons;

		file.close();
	}
}

void S_Controls::defaults()
{
	forward = sf::Keyboard::W;
	back = sf::Keyboard::S;
	left = sf::Keyboard::A;
	right = sf::Keyboard::D;
	run = sf::Keyboard::LShift;
	invertZoom = false;
	invertMouseButtons = false;
}

void S_Controls::save()
{
	std::ofstream file(OPTIONS_PATH + CONTROLS_FILE + DATA_EXT);

	if (!file.is_open())
	{
		
	}

	file <<
		static_cast<int>(forward) << std::endl <<
		static_cast<int>(back) << std::endl <<
		static_cast<int>(left) << std::endl <<
		static_cast<int>(right) << std::endl <<
		static_cast<int>(run) << std::endl <<
		invertZoom << std::endl <<
		invertMouseButtons;

	file.close();
}