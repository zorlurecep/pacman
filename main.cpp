#include <SFML/Graphics.hpp>

#include "entities/BlueGhost.hpp"
#include "entities/PacMan.hpp"

int main()
{
    pacman::entities::PacMan pacMan;
    pacman::entities::BlueGhost blueGhost;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Pac-Man");

    // Animation variables
    int currentFrame = 0;
    sf::Clock clock;
    float frameDuration = 0.1f; // Duration of each frame in seconds

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Handle keyboard input for closing the window with CTRL+C
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            window.close();
        }

        pacMan.handleInput();
        blueGhost.handleInput();

        // Update the animation frame
        if (clock.getElapsedTime().asSeconds() > frameDuration)
        {
            pacMan.update();
            blueGhost.update();
            clock.restart();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        pacMan.render(window);
        blueGhost.render(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}