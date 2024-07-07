#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Audio");
	//Remember, we need an instance of the asset manager
	AssetManager manager;

	sf::Font font(AssetManager::GetFont("toys.ttf"));
	sf::Text text("Look at my aweasome font", font);
	text.setFillColor(sf::Color::Red);
	// SFML_DEPRECATED
	while (window.isOpen())
	{

		window.clear();
		window.draw(text);
		window.display();

	}

	return 0;
}

