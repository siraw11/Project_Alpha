//
// Created by Magna on 2019-06-20.
//

#include "Match.h"
#include "Bike.h"
#include "Game.h"

Match::Match(std::shared_ptr<Map> _map, std::shared_ptr<Bike> _bike, int _lifes, int _money, Position _lastCheckpoint)
        : map(_map), bike(_bike), lifes(_lifes), money(_money), lastCheckpoint(_lastCheckpoint) {

    timer = std::unique_ptr<Timer>(new Timer());
}


void Match::removeLife() {
    if (Match::lifes > 0) {
        Match::lifes -= 1;
    }
}

int Match::getLifes() const {
    return lifes;
}

void Match::setLifes(int lifes) {
    Match::lifes = lifes;
}

int Match::getMoney() const {
    return money;
}

void Match::setMoney(int money) {
    Match::money = money;
}


void Match::addMoney(int _money) {
    Match::money += _money;
}


Player *Match::getPlayer() const {
    return player;
}

void Match::setPlayer(Player *player) {
    Match::player = player;
}


Match::~Match() {

}

const Position &Match::getLastCheckpoint() const {
    return lastCheckpoint;
}

void Match::setLastCheckpoint(const Position &lastCheckpoint) {
    Match::lastCheckpoint = lastCheckpoint;
}

const std::shared_ptr<Map> &Match::getMap() const {
    return map;
}

void Match::setMap(const std::shared_ptr<Map> &map) {
    Match::map = map;
}

const std::shared_ptr<Bike> &Match::getBike() const {
    return bike;
}

void Match::setBike(const std::shared_ptr<Bike> &bike) {
    Match::bike = bike;
}

const std::shared_ptr<Timer> &Match::getTimer() const {
    return timer;
}

void Match::setTimer(const std::shared_ptr<Timer> &timer) {
    Match::timer = timer;
}

