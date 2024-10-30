#include "entities/PacMan.hpp"

namespace pacman::entities
{

PacMan::PacMan() : BaseEntity(), _texture(), _speed(0.1f), _currentFrame(0)
{
    std::filesystem::path sourceDir = std::filesystem::path(__FILE__).parent_path().parent_path();
    std::filesystem::path assetPath = sourceDir / "assets" / "PacMan.png";
    if (!_texture.loadFromFile(assetPath.string()))
    {
        throw std::runtime_error("Failed to load texture from file: " + assetPath.string());
    }

    _sprite.setTexture(_texture);
    _sprite.setPosition(0, 0);

    _frames.push_back(sf::IntRect(0, 0, 16, 16));   // Frame 1
    _frames.push_back(sf::IntRect(16, 0, 16, 16));  // Frame 2
    _frames.push_back(sf::IntRect(32, 0, 16, 16));  // Frame 3
    _frames.push_back(sf::IntRect(48, 0, 16, 16));  // Frame 4
    _frames.push_back(sf::IntRect(64, 0, 16, 16));  // Frame 5
    _frames.push_back(sf::IntRect(80, 0, 16, 16));  // Frame 6
    _frames.push_back(sf::IntRect(96, 0, 16, 16));  // Frame 7
    _frames.push_back(sf::IntRect(112, 0, 16, 16)); // Frame 8
}

void PacMan::update()
{
    _currentFrame = (_currentFrame + 1) % _frames.size();
    _sprite.setTextureRect(_frames[_currentFrame]);
}

void PacMan::render(sf::RenderWindow& window)
{
    window.draw(_sprite);
}

void PacMan::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _sprite.move(-_speed, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _sprite.move(_speed, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _sprite.move(0.0f, -_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _sprite.move(0.0f, _speed);
    }
}

void PacMan::reset()
{
}

void PacMan::clean()
{
}

} // namespace pacman::entities
