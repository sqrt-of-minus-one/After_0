    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: After.cpp                   //
////////////////////////////////////////

#include "System/Controls.h"
#include "Entity/Last/Last.h"
#include "Entity/Mob/Animal/Animal.h"
#include "Utilites/Log.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using std::cout;
using std::endl;
using std::srand;
using std::time;
using std::runtime_error;

void check_debug()
{
	ifstream file(TEXTURES_PATH + ENTITY + DEBUG + "_1x1" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x1" + TEXTURES_EXT);
		throw runtime_error(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x1" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + ENTITY + DEBUG + "_1x2" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x2" + TEXTURES_EXT);
		throw runtime_error(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x2" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + ENTITY + DEBUG + "_2x2" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x2" + TEXTURES_EXT);
		throw runtime_error(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x2" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + ENTITY + DEBUG + "_2x1" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x1" + TEXTURES_EXT);
		throw runtime_error(NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x1" + TEXTURES_EXT);
	}
	file.close();
}

int main()
{
	srand(time(NULL));
	Log::clear();
	Log::i(START);
	check_debug();

	RenderWindow window(VideoMode(800, 450), "After");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	View view = window.getView();
	int zoom = 1;

	Last* last = new Last;
	Entity* entity = new Animal(1, "cow");
	Clock clock;
	try
	{
		while (window.isOpen())
		{
			float delta = clock.getElapsedTime().asMilliseconds();
			clock.restart();

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					Log::i(CLOSE);
				}
				if (event.type == Event::MouseWheelMoved)
				{
					int wheelDelta = event.mouseWheel.delta < 0 ^ S_Controls::invertZoom ? 1 : -1;
					if (!(zoom == MAX_ZOOM && wheelDelta > 0 || zoom == MIN_ZOOM && wheelDelta < 0))
					{
						zoom += wheelDelta;
						view.zoom(wheelDelta > 0 ? ZOOM_STEP : 1 / ZOOM_STEP);
						window.setView(view);
					}
				}
			}

			std::system("cls");

			float h, e, w, o, g;
			last->getStats(h, e, w, o, g);
			cout << "FPS: " << 1000 / delta << endl <<
				"Health: " << h << endl <<
				"Energy: " << e << endl <<
				"Weakness: " << w << endl <<
				"Oxygen: " << o << endl <<
				"Hunger: " << g;
			window.clear();

			float x, y;
			last->getCenter(x, y);
			view.setCenter(x, y);
			window.setView(view);

			last->tick(delta);
			last->draw(window);

			static_cast<Animal*>(entity)->tick(delta);
			entity->draw(window);

			//Tmp
			CircleShape c[5][5];
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					c[i][j].setPosition(i * 500, j * 500);
					c[i][j].setRadius(5);
					window.draw(c[i][j]);
				}
			}
			//End tmp

			window.display();
			
		}
	}
	catch (std::exception e)
	{
		std::system("log.txt");
	}
}