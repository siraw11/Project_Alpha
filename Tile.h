//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_TILE_H
#define EXAM_PROJECT_TILE_H

#include <SFML/Graphics/Sprite.hpp>

class Tile : public sf::Sprite{
public:
    Tile();
    void isLegalCell(Tile &tile );

protected:
    bool wall;
    bool path;
    bool null;
};
#endif //EXAM_PROJECT_TILE_H
