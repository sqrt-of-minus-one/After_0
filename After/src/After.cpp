    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: After.cpp                   //
////////////////////////////////////////

#include "System/Controls.h"
#include "Utilites/Log.h"
#include "World/WorldController.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <mutex>

void check_debug()
{
	std::ifstream file(TEXTURES_PATH + ENTITY + DEBUG + "_1x1" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x1" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x1" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + ENTITY + DEBUG + "_1x2" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x2" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_1x2" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + ENTITY + DEBUG + "_2x2" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x2" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x2" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + ENTITY + DEBUG + "_2x1" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x1" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + ENTITY + DEBUG + "_2x1" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + OBJECT + DEBUG + "_1x1" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_1x1" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_1x1" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + OBJECT + DEBUG + "_1x2" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_1x2" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_1x2" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + OBJECT + DEBUG + "_2x2" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_2x2" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_2x2" + TEXTURES_EXT);
	}
	file.close();

	file.open(TEXTURES_PATH + OBJECT + DEBUG + "_2x1" + TEXTURES_EXT);
	if (!file.is_open())
	{
		Log::e(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_2x1" + TEXTURES_EXT);
		throw std::runtime_error(W_NO_FILE + TEXTURES_PATH + OBJECT + DEBUG + "_2x1" + TEXTURES_EXT);
	}
	file.close();
}

int main()
{
	srand(time(NULL));
	Log::clear();
	Log::i(I_START);
	check_debug();

	sf::RenderWindow window(sf::VideoMode(800, 450), "After");
	//window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);
	int zoom = 1;

	std::mutex windowMtx;
	int loading = 0;

	WorldController* controller;

	std::thread loadTR([&controller, &window, &loading, &windowMtx]()
	{
		controller = new WorldController(window, windowMtx, loading);
		loading = -1;
	});
	sf::Text text;
	sf::Font font;
	font.loadFromFile("Times New Roman.ttf");
	text.setFont(font);

	while (window.isOpen() && loading > -1)
	{
		sf::Event event;

		windowMtx.lock();
		while (window.pollEvent(event))
		{
			windowMtx.unlock();
			if (event.type == sf::Event::Closed)
			{
				text.setString("Closing, please wait...");
				windowMtx.lock();
				window.clear();
				window.draw(text);
				window.display();
				windowMtx.unlock();
				loadTR.join();
				window.close();
				Log::i(I_CLOSE);
			}
			text.setString("Loading... (" + std::to_string(100 * loading / ((2 * LOAD_DISTANCE + 1) * (2 * LOAD_DISTANCE + 1))) + "%)");
			windowMtx.lock();
			window.clear();
			window.draw(text);
			window.display();
		}
		windowMtx.unlock();
	}

	if (loadTR.joinable())
	{
		loadTR.join();
	}
	
	sf::Clock clock;
	try
	{
		while (window.isOpen())
		{
			float delta = clock.getElapsedTime().asMilliseconds();
			clock.restart();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					Log::i(I_CLOSE);
				}
				if (event.type == sf::Event::MouseWheelMoved)
				{
					int wheelDelta = event.mouseWheel.delta < 0 ^ S_Controls::invertZoom ? 1 : -1;
					if (!(zoom == MAX_ZOOM && wheelDelta > 0 || zoom == MIN_ZOOM && wheelDelta < 0))
					{
						zoom += wheelDelta;
						controller->zoom(wheelDelta > 0 ? ZOOM_STEP : 1 / ZOOM_STEP);
					}
				}
			}

			std::system("cls");
			window.clear();

			controller->tick(delta, window);

			//Tmp
			sf::CircleShape c[5][5];
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
	if (controller != nullptr)
	{
		delete controller;
	}
	return 0;
}