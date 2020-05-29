#ifndef EXAM_PROJECT_MAP_H
#define EXAM_PROJECT_MAP_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Tile.h"

class Map : public sf::Drawable, public sf::Transformable, public Tile{
public:
    bool load(const std::string &tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif //EXAM_PROJECT_MAP_H