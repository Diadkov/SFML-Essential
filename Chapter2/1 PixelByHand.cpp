#include <SFML/Graphics/Image.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// This program creates an image from a pixel array and displays it on a rectangle shape in a window.

int main() {
    // Define video mode with window dimensions 840x720 pixels
    sf::VideoMode vm(840, 720);
    sf::RenderWindow window(vm, "Pixel Array"); // Create a window with the title "Pixel Array"

    const unsigned int kWidth = 5, kHeight = 5; // Dimensions of the pixel array

    // Array of pixels in RGBA format (red, green, blue, alpha)
    sf::Uint8 pixels[kWidth * kHeight * 4] = {
        255, 255, 255, 255, // white pixel
        0, 0, 0, 255,       // black pixel
        255, 0, 0, 255,     // red pixel
        128, 128, 128, 255  // grey pixel
    };

    sf::Image img;
    img.create(kWidth, kHeight, pixels); // Create an image from the pixel array

    sf::Texture texture;
    texture.loadFromImage(img); // Load the image into a texture

    // Create a rectangle shape with size scaled up for visibility
    sf::RectangleShape rectShape(sf::Vector2f(kWidth * 50, kHeight * 50));
    rectShape.setTexture(&texture); // Apply the texture to the rectangle
    rectShape.setPosition(100, 100); // Position the rectangle in the window

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window if the close event is received
            }
        }
        window.clear(sf::Color::Black); // Clear the window with black color
        window.draw(rectShape); // Draw the rectangle shape
        window.display(); // Display everything on the window
    }

    return 0;
}
