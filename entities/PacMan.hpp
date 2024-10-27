#pragma once

#include "entities/BaseEntity.hpp"

namespace pacman::entities
{
class PacMan : public BaseEntity
{
public:
    PacMan();
    ~PacMan() = default;

    void update() override;
    void render(sf::RenderWindow& window) override;
    void handleInput() override;
    void reset() override;
    void clean() override;

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    std::vector<sf::IntRect> _frames;
    float _speed;

    int _currentFrame;
};

} // namespace pacman::entities
