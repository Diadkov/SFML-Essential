#include <SFML/Graphics/Image.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "AssetManager.h" // Include your AssetManager header
#include <iostream>

int main() {
    AssetManager manager; // Create an instance of AssetManager to manage textures

    // Define video mode with window dimensions 840x720 pixels
    sf::VideoMode vm(840, 720);
    sf::RenderWindow window(vm, "The title"); // Create a window with the title "The title"

    // Load textures using AssetManager's GetTexture function and create sprites
    sf::Sprite sprite1 = sf::Sprite(manager.GetTexture("C:\\Users\\vd\\Downloads\\Sprout Lands - Sprites - Basic pack (1)\\Sprout Lands - Sprites - Basic pack\\Characters\\Basic Charakter Actions.png"));
    sf::Sprite sprite2 = sf::Sprite(manager.GetTexture("C:\\Users\\vd\\Downloads\\Sprout Lands - Sprites - Basic pack (1)\\Sprout Lands - Sprites - Basic pack\\Objects\\Basic_Furniture.png"));
    sf::Sprite sprite3 = sf::Sprite(manager.GetTexture("C:\\Users\\vd\\Downloads\\Sprout Lands - Sprites - Basic pack (1)\\Sprout Lands - Sprites - Basic pack\\Objects\\Basic_Furniture.png"));
    sf::Sprite sprite4 = sf::Sprite(manager.GetTexture("C:\\Users\\vd\\Downloads\\Sprout Lands - Sprites - Basic pack (1)\\Sprout Lands - Sprites - Basic pack\\Characters\\Egg_And_Nest.png"));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window if the close event is received
            }
        }

        window.clear(); // Clear the window with default background color

        // Draw all sprites on the window
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);

        window.display(); // Display everything drawn on the window
    }

    return 0; // End of program
}