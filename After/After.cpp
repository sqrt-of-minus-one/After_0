    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: After.cpp                   //
////////////////////////////////////////

#include "System/Controls.h"
#include "Entity/Last/Last.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 450), "After");
	Last* last = new Last;
	Clock clock;

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
			}
		}

		std::system("cls");
		std::cout << "FPS: " << 1000 / delta << std::endl;
		window.clear();

		last->tick(delta);
		last->draw(window);

		window.display();
	}
}