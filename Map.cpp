//
// Created by Magna on 2019-06-06.
//

#include "Map.h"

#include <utility>
#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include "Coin.h"
#include "SpeedBonus.h"
#include "Checkpoint.h"
#include "Game.h"
#include "TimeBonus.h"


Map::Map(std::string _id, std::string _name, bool _isCompleted, bool _isUnlocked, double _record,
         std::list<Position> _mapPoints,
         std::list<Item *> _mapItems) : id(std::move(_id)), name(std::move(_name)), isCompleted(_isCompleted),
                                        record(_record),
                                        isUnlocked(_isUnlocked),
                                        mapPoints(std::move(_mapPoints)), mapItems(std::move(_mapItems)) {}


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

std::string Map::getRecordString() const {
    return Game::gameData->match->timer->elapsedString(this->record);
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

void Map::resetItems() {
    std::cout << "items reset" << std::endl;
    for (auto &item : mapItems) {
        item->setTaken(false);
    }

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

const std::string &Map::getName() const {
    return name;
}

void Map::setName(const std::string &name) {
    Map::name = name;
}

const std::string &Map::getId() const {
    return id;
}

void Map::setId(const std::string &id) {
    Map::id = id;
}
