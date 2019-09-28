    //
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_MAP_H
#define EXAM_PROJECT_MAP_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

    class Map : public sf::Drawable, public sf::Transformable
    {
    public:
         Map(){};

        bool load(const std::string &tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
    };
#endif //EXAM_PROJECT_MAP_H
