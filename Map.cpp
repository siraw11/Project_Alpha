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


void Map::loadLevel1() {
    this->setId("lv1");
    this->setName("Level 1");
    this->setIsUnlocked(true);

    this->mapPoints = {
            {-1,  10},//back limit
            {0,   0.},
            {3,   0.},
            {8,   1},
            {11,  0},
            {15,  -1},
            {20,  0},
            {25,  0},
            {30,  0.5},
            {35,  -1},
            {40,  0},
            {43,  0},
            {45,  1},
            {100, 1},
            {100, 10}//front limit
    };

    mapItems.push_back(new Coin(5, 0.8, .7, .7, 50));
    mapItems.push_back(new Coin(7, 1, .7, .7, 30));
    mapItems.push_back(new SpeedBonus(10, 1, 10, .7, .7, .7));
    mapItems.push_back(new TimeBonus(1000, 20, 0., .7, .7));
    mapItems.push_back(new Checkpoint(25, 0, 1, 1.2));
    mapItems.push_back(new Checkpoint(95, 2, 5, 3, true));
}

std::unique_ptr<Map> Map::loadLevel(int id) {
    std::unique_ptr<Map> map(new Map());
    switch (id) {
        case 1:
            map->loadLevel1();
            break;

        case 2:
            map->loadLevel2();
            break;
    }
    return map;
}

void Map::loadLevel2() {
    this->setIsUnlocked(false);
    this->setId("lv2");
    this->setName("Level 2");
    mapPoints = {
            {-1, 10},//back limit
            {0,  0},
            {30, 0},
            {30, 10}//front limit
    };

    mapItems.push_back(new TimeBonus(1000, 3, .1, .7, .7));
    mapItems.push_back(new Coin(5, .2, .7, .7, 50));
    mapItems.push_back(new Coin(7, .1, .7, .7, 30));
    mapItems.push_back(new Checkpoint(24, 1, 5, 3, true));
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
