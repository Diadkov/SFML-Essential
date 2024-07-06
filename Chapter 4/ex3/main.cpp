#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 3;
	settings.minorVersion = 0;
	settings.antialiasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode(640, 480), "OpenGL", sf::Style::Default, settings);

	settings = window.getSettings();
	std::cout << "depthBits: " << settings.depthBits << std::endl;
	std::cout << "stencilBits: " << settings.stencilBits << std::endl;
	std::cout << "antialiasingLevel: " << settings.antialiasingLevel << std::endl;
	std::cout << "version: " << settings.majorVersion << "." << settings.minorVersion << std::endl;

	//Window is ready to receive OpenGL calls here

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
		}
			
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// drawing shape
		window.pushGLStates();

		// draw shape using sfml
		window.popGLStates();

		// swap buffer 
		window.display();
	}

	return 0;
}

