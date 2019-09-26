    //
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_MAP_H
#define EXAM_PROJECT_MAP_H


#include <SFML/Graphics/Sprite.hpp>

    class Map : public sf::Sprite{
public:
    void Create();

    bool isObstacle() const;

    void setObstacle(bool obstacle);

    bool isChest() const;

    void setChest(bool chest);

    bool isPath() const;

    void setPath(bool path);

    bool isWall() const;

    void setWall(bool wall);
    private:
        bool wall, path, chest, obstacle;
    };
#endif //EXAM_PROJECT_MAP_H
