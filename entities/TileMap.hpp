#pragma once

#include "entities/BaseEntity.hpp"

namespace pacman::entities
{
class TileMap : public BaseEntity, public sf::Drawable, public sf::Transformable
{
public:
    TileMap() = default;
    ~TileMap() = default;

    bool
    load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

    void update() override;
    void render(sf::RenderWindow& window) override;
    void handleInput() override;
    void reset() override;
    void clean() override;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

} // namespace pacman::entities