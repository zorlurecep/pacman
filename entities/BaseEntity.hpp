#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <vector>

namespace pacman::entities
{

class BaseEntity
{
public:
    BaseEntity() = default;
    virtual ~BaseEntity() = default;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleInput() = 0;
    virtual void reset() = 0;
    virtual void clean() = 0;
};

} // namespace pacman::entities
