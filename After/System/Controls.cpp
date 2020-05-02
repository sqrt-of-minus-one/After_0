    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Controls.cpp                //
////////////////////////////////////////

#include "Controls.h"
#include "../Utilites/Constants.h"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::endl;

Keyboard::Key S_Controls::forward = Keyboard::W;
Keyboard::Key S_Controls::back = Keyboard::S;
Keyboard::Key S_Controls::left = Keyboard::A;
Keyboard::Key S_Controls::right = Keyboard::D;
Keyboard::Key S_Controls::run = Keyboard::LShift;
bool S_Controls::invertZoom = false;
bool S_Controls::invertMouseButtons = false;

void S_Controls::load()
{
	ifstream file(OPTIONS_PATH + CONTROLS + DATA_EXT);
	if (!file.is_open())
	{
		defaults();
		save();
	}
	else
	{
		int in;

		file >> in;
		forward = static_cast<Keyboard::Key>(in);

		file >> in;
		back = static_cast<Keyboard::Key>(in);

		file >> in;
		left = static_cast<Keyboard::Key>(in);

		file >> in;
		right = static_cast<Keyboard::Key>(in);

		file >> in;
		run = static_cast<Keyboard::Key>(in);

		file >> invertZoom;

		file >> invertMouseButtons;

		file.close();
	}
}

void S_Controls::defaults()
{
	forward = Keyboard::W;
	back = Keyboard::S;
	left = Keyboard::A;
	right = Keyboard::D;
	run = Keyboard::LShift;
	invertZoom = false;
	invertMouseButtons = false;
}

void S_Controls::save()
{
	ofstream file(OPTIONS_PATH + CONTROLS + DATA_EXT);

	if (!file.is_open())
	{
		
	}

	file <<
		static_cast<int>(forward) << endl <<
		static_cast<int>(back) << endl <<
		static_cast<int>(left) << endl <<
		static_cast<int>(right) << endl <<
		static_cast<int>(run) << endl <<
		invertZoom << endl <<
		invertMouseButtons;

	file.close();
}