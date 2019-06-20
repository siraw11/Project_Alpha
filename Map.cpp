//
// Created by Magna on 2019-06-06.
//

#include "Map.h"
#include "Observer.h"
#include "Subject.h"
#include "Player.h"

const float SCALE = 200.f;

Map::Map(bool _isCompleted, bool _isUnlocked, double _record, std::list<Position> _mapPoints, Player* _p):isCompleted(_isCompleted), record(_record), isUnlocked(_isUnlocked), mapPoints(_mapPoints), p(_p) {}

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

void Map::draw(sf::RenderWindow *window) {
    sf::ConvexShape terrain;

    terrain.setPosition(0, window->getSize().y/1.3);
    terrain.setPointCount(mapPoints.size()+2);

    int i = 0;
    for(Position point : mapPoints) {
        terrain.setPoint(i, sf::Vector2f((point.posX-=0.1) * SCALE, -point.posY * SCALE));
        i++;
    }
    terrain.setPoint(i, sf::Vector2f(50*SCALE,0));
    terrain.setPoint(i+1, sf::Vector2f(0, 50*SCALE));
    terrain.setFillColor(sf::Color(168, 75, 0));

    window->draw(terrain);
}

