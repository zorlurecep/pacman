#include <SFML/Graphics.hpp>
#include <filesystem>
#include <vector>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pac-Man");

    // Load the sprite sheet
    sf::Texture texture;
    std::filesystem::path sourceDir = std::filesystem::path(__FILE__).parent_path();
    std::filesystem::path assetPath = sourceDir / "assets" / "pacman.png";
    if (!texture.loadFromFile(assetPath.string()))
    {
        return EXIT_FAILURE;
    }

    // Define the frames of the animation
    std::vector<sf::IntRect> frames;
    frames.push_back(sf::IntRect(0, 0, 16, 16));   // Frame 1
    frames.push_back(sf::IntRect(16, 0, 16, 16));  // Frame 2
    frames.push_back(sf::IntRect(32, 0, 16, 16));  // Frame 3
    frames.push_back(sf::IntRect(48, 0, 16, 16));  // Frame 4
    frames.push_back(sf::IntRect(64, 0, 16, 16));  // Frame 5
    frames.push_back(sf::IntRect(80, 0, 16, 16));  // Frame 6
    frames.push_back(sf::IntRect(96, 0, 16, 16));  // Frame 7
    frames.push_back(sf::IntRect(112, 0, 16, 16)); // Frame 8

    // Create a sprite
    sf::Sprite sprite(texture);
    sprite.setPosition(400, 300);

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

        // Handle keyboard input for moving Pac-Man
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.move(-0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.move(0.1f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.move(0.0f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.move(0.0f, 0.1f);
        }

        // Update the animation frame
        if (clock.getElapsedTime().asSeconds() > frameDuration)
        {
            currentFrame = (currentFrame + 1) % frames.size();
            sprite.setTextureRect(frames[currentFrame]);
            clock.restart();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}