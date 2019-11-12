//
// Created by Magna on 2019-06-06.
//

#include "Map.h"
#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include "Coin.h"
#include "SpeedBonus.h"
#include "Checkpoint.h"


Map::Map(bool _isCompleted, bool _isUnlocked, double _record, std::list<Position> _mapPoints, Player *_p,
         std::list<Item *> _mapItems) : isCompleted(_isCompleted), record(_record), isUnlocked(_isUnlocked),
                                        mapPoints(_mapPoints), p(_p), mapItems(_mapItems) {}


void Map::loadLevel1() {

    this->mapPoints = {
            {-1, 10},//back limit
            {0,  0.},
            {3,  0.},
            {8,  1},
            {11, 0},
            {15, -1},
            {20, 0},
            {25, 0},
            {30, 0.5},
            {35, -1},
            {40, 0},
            {43, 0},
            {45, 1},
            {55, 1},
            {55, 10}//front limit
    };

    mapItems.push_back(new Coin(5, 0.8, .7, .7, 50));
    mapItems.push_back(new Coin(7, 1, .7, .7, 30));
    mapItems.push_back(new SpeedBonus(10, 1, 10, .7, .7, .7));
    mapItems.push_back(new Checkpoint(52, 1, 1, 5, true));
}

void Map::loadLevel2() {
    mapPoints = {
            {-1, 10},//back limit
            {0,  0},
            {30, 0},
            {30, 10}//front limit
    };

    mapItems.push_back(new Coin(5, .2, .7, .7, 50));
    mapItems.push_back(new Coin(7, .1, .7, .7, 30));
    mapItems.push_back(new Checkpoint(28, 0, 1, 5, true));
}

bool Map::getIsCompleted() const {
    return isCompleted;
}

void Map::setIsCompleted(bool isCompleted) {
    Map::isCompleted = isCompleted;
}

bool Map::getIsUnlocked() const {
    return isUnlocked;
}

void Map::setIsUnlocked(bool isUnlocked) {
    Map::isUnlocked = isUnlocked;
}

double Map::getRecord() const {
    return record;
}

void Map::setRecord(double record) {
    Map::record = record;
}

const std::list<Position> &Map::getMapPoints() const {
    return mapPoints;
}

void Map::setMapPoints(const std::list<Position> &mapPoints) {
    Map::mapPoints = mapPoints;
}


const std::list<Item *> &Map::getMapItems() const {
    return mapItems;
}

void Map::setMapItems(const std::list<Item *> &mapItems) {
    Map::mapItems = mapItems;
}

bool Map::removeMapItem(Item *item) {
    mapItems.remove(item);
    delete item;
}


void Map::update() {

}

void Map::attach() {
    //TODO:implement
}

void Map::detach() {
    //TODO:implement
}

Map::~Map() {
    detach();
}