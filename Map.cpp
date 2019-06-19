//
// Created by Magna on 2019-06-06.
//

#include "Map.h"
#include "Observer.h"
#include "Subject.h"

Map::Map(bool _isCompleted, bool _isUnlocked, double _record, std::list<float> _mapPoints, Player* _p):isCompleted(_isCompleted), record(_record), isUnlocked(_isUnlocked), mapPoints(_mapPoints), p(_p) {}

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

const std::list<float> &Map::getMapPoints() const {
    return mapPoints;
}

void Map::setMapPoints(const std::list<float> &mapPoints) {
    Map::mapPoints = mapPoints;
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
