//
// Created by Magna on 2019-06-06.
//

#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Observer.h"
#include "Subject.h"


Map::Map(bool _isCompleted, bool _isUnlocked, double _record, std::list<float> _mapPoints):isCompleted(_isCompleted), record(_record), isUnlocked(_isUnlocked), mapPoints(_mapPoints) {}

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

Map::~Map() {
    detach();
}
