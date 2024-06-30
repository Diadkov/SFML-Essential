#include <SFML/Graphics/Image.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// This program loads an image from a file, applies it as a texture to shapes, and displays them in a window.

int main() {
    // Define video mode with window dimensions 840x720 pixels
    sf::VideoMode vm(840, 720);
    sf::RenderWindow window(vm, "The title"); // Create a window with the title "The title"

    sf::Image img;

    // Load an image from a file; if it fails, exit the program
    if (!img.loadFromFile("C:\\Users\\vd\\Downloads\\picture1.png")) {
        return -1;
    }

    sf::Texture texture;
    texture.loadFromImage(img); // Load the image into a texture

    // Get the size of the texture and print the dimensions
    sf::Vector2u textureSize = texture.getSize();
    float rectWidth = static_cast<float>(textureSize.x);
    float rectHeight = static_cast<float>(textureSize.y);
    std::cout << rectHeight << " " << rectWidth;

    // Create a rectangle shape with dimensions based on the texture size
    sf::RectangleShape rectShape(sf::Vector2f(rectHeight, rectWidth));

    // Create a convex shape with 5 points
    sf::ConvexShape shape(5);
    shape.setPoint(0, sf::Vector2f(0, 0));
    shape.setPoint(1, sf::Vector2f(200, 0));
    shape.setPoint(2, sf::Vector2f(180, 120));
    shape.setPoint(3, sf::Vector2f(100, 200));
    shape.setPoint(4, sf::Vector2f(20, 120));
    shape.setTexture(&texture); // Apply the texture to the convex shape
    shape.setOutlineThickness(2); // Set outline thickness
    shape.setOutlineColor(sf::Color::Red); // Set outline color to red
    shape.move(20, 20); // Move the shape to position (20, 20)

    rectShape.setTexture(&texture); // Apply the texture to the rectangle shape

    // Main loop to keep the window open
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // Check for window close event
                window.close(); // Close the window if the close event is received
            }
        }
        window.clear(sf::Color::Black); // Clear the window with black color

        window.draw(shape); // Draw the convex shape

        window.display(); // Display everything on the window
    }

    return 0; // End of program
}
