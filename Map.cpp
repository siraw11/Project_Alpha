//
// Created by waris on 20/06/19.
//

#include <vector>
#include "Map.h"

void Map::Create() {

    std::vector<Map> tileSET;
    tileSET.reserve(3840*2160);
}

bool Map::isWall() const {
    return wall;
}

void Map::setWall(bool wall) {
    Map::wall = wall;
}

bool Map::isPath() const {
    return path;
}

void Map::setPath(bool path) {
    Map::path = path;
}

bool Map::isChest() const {
    return chest;
}

void Map::setChest(bool chest) {
    Map::chest = chest;
}

bool Map::isObstacle() const {
    return obstacle;
}

void Map::setObstacle(bool obstacle) {
    Map::obstacle = obstacle;
}
