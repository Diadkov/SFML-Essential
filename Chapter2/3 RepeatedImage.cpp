#include <SFML/Graphics/Image.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// This program loads an image from a file, applies it to a rectangle shape with repeated and smooth textures, and displays it in a window.

int main() {
    // Define video mode with window dimensions 840x720 pixels
    sf::VideoMode vm(840, 720);
    sf::RenderWindow window(vm, "The title"); // Create a window with the title "The title"

    sf::Texture texture;

    // Load an image from a file; if it fails, exit the program
    if (!texture.loadFromFile("C:\\Users\\vd\\Downloads\\picture2.png")) {
        return -1;
    }

    // Print the dimensions of the loaded texture
    std::cout << "Texture dimensions: " << texture.getSize().x << " x " << texture.getSize().y << std::endl;

    texture.setRepeated(true); // Enable texture repeating

    // Create a rectangle shape with size 3 times width and 2 times height of the texture
    sf::RectangleShape rectShape(sf::Vector2f(3 * static_cast<float>(texture.getSize().x), 2 * static_cast<float>(texture.getSize().y)));

    // Set the texture rectangle to cover the entire shape with repeated texture
    rectShape.setTextureRect(sf::IntRect(0, 0, 3 * texture.getSize().x, 2 * texture.getSize().y));

    rectShape.setTexture(&texture); // Apply the texture to the rectangle shape
    texture.setSmooth(true); // Enable texture smoothing

    // Main loop to keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // Check for window close event
                window.close(); // Close the window if the close event is received
            }
        }
        window.clear(sf::Color::Black); // Clear the window with black color

        window.draw(rectShape); // Draw the rectangle shape with the texture

        window.display(); // Display everything on the window
    }

    return 0; // End of program
}
