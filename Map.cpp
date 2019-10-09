//
// Created by Magna on 2019-06-06.
//

#include "Map.h"
#include "Observer.h"
#include "Subject.h"
#include "Player.h"


Map::Map(bool _isCompleted, bool _isUnlocked, double _record, std::list<Position> _mapPoints, Player *_p,
         std::list<Item *> _mapItems) : isCompleted(_isCompleted), record(_record), isUnlocked(_isUnlocked),
                                        mapPoints(_mapPoints), p(_p), mapItems(_mapItems) {}

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
    std::cout << "removing " << item << std::endl;
    mapItems.remove(item);
    //delete item;

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