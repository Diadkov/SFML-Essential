// This program is a simple game using SFML where a green player rectangle moves
// across the screen. The goal is to reach a blue target rectangle while avoiding
// a red enemy rectangle. The player can move up and down using the arrow keys
// and rotates as it moves. If the player reaches the target, the game ends.
// If the player collides with the enemy or goes off-screen, they are reset to the start position.

#include <SFML/Graphics.hpp>

// Function to initialize a shape with position and color
void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color);

int main(int argc, char** argv) {
    // Create a window with dimensions 480x180 pixels and title "Bad Squares"
    sf::RenderWindow window(sf::VideoMode(480, 180), "Bad Squares");
    // Set the frame rate limit to 60 frames per second
    window.setFramerateLimit(60);

    // Initialize player rectangle with size 50x50 pixels and position (50, 90)
    sf::Vector2f pos(50, 90);
    sf::RectangleShape player(sf::Vector2f(50, 50));
    initShape(player, pos, sf::Color::Green); // Green color for player

    // Initialize target rectangle with size 50x50 pixels and position (400, 90)
    sf::RectangleShape target(sf::Vector2f(50, 50));
    initShape(target, sf::Vector2f(400, 90), sf::Color::Blue); // Blue color for target

    // Initialize enemy rectangle with size 50x100 pixels and position (250, 90)
    sf::RectangleShape enemy(sf::Vector2f(50, 100));
    initShape(enemy, sf::Vector2f(250, 90), sf::Color::Red); // Red color for enemy

    // Game loop
    while (window.isOpen()) {
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close the window when the close event is received
        }

        // Rotate player and enemy for visual effect
        player.rotate(1.5f);
        enemy.rotate(5.f); // Rotate enemy faster for fun

        // Move player to the right continuously
        player.move(1, 0);

        // Handle player input for vertical movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0, 1); // Move down if Down arrow key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0, -1); // Move up if Up arrow key is pressed

        // Check for collision with target
        if (player.getGlobalBounds().intersects(target.getGlobalBounds()))
            window.close(); // Close the window if the target is reached

        // Check for collision with enemy or going off-screen
        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()) ||
            player.getPosition().x >= window.getSize().x)
            player.setPosition(pos); // Reset player position if collision occurs

        // Rendering section
        window.clear(sf::Color::Black); // Clear window with black color
        window.draw(player); // Draw player rectangle
        window.draw(target); // Draw target rectangle
        window.draw(enemy); // Draw enemy rectangle
        window.display(); // Display everything on the window
    }

    return 0; // End of program
}

// Function to initialize shape properties: color, position, and origin
void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color) {
    shape.setFillColor(color); // Set the fill color of the shape
    shape.setPosition(pos); // Set the initial position of the shape
    shape.setOrigin(shape.getSize() * 0.5f); // Set the origin to the center for rotation
}