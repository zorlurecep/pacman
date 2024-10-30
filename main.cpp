#include <SFML/Graphics.hpp>

#include "entities/PacMan.hpp"
#include "entities/TileMap.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(224, 256), "Tilemap");

    int numberOftiles = 224;
    int level[numberOftiles];
    int index = 0;

    int i = 0;
    while (i < numberOftiles)
    {
        for (int j = 0; j < 14; j++)
        {
            level[i] = index;
            index++;
            i++;
        }
        index += 9;
    }

    // create the tilemap from the level definition
    pacman::entities::TileMap map;
    if (!map.load("../assets/TileMap.png", sf::Vector2u(16, 16), level, 14, 16))
        return -1;

    pacman::entities::PacMan pacMan;
    sf::Clock clock;
    float frameDuration = 0.1f; // Duration of each frame in seconds
    // run the main loop
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
        // Update the animation frame
        if (clock.getElapsedTime().asSeconds() > frameDuration)
        {
            pacMan.update();
            clock.restart();
        }

        // draw the map
        window.clear(sf::Color::White);
        window.draw(map);
        pacMan.render(window);
        window.display();
    }

    return 0;
}