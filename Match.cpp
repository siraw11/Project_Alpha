//
// Created by Magna on 2019-06-20.
//

#include "Match.h"
#include "Bike.h"

Match::Match(Map *_map, Bike *_bike, int _lifes, float _time, int _money) : map(_map), bike(_bike), lifes(_lifes),
                                                                            time(_time), money(_money) {}


int Match::getLifes() const {
    return lifes;
}

void Match::setLifes(int lifes) {
    Match::lifes = lifes;
}

float Match::getTime() const {
    return time;
}

void Match::setTime(float time) {
    Match::time = time;
}

int Match::getMoney() const {
    return money;
}

void Match::setMoney(int money) {
    Match::money = money;
}

Player *Match::getPlayer() const {
    return player;
}

void Match::setPlayer(Player *player) {
    Match::player = player;
}

Bike *Match::getB() const {
    return bike;
}

void Match::setB(Bike *b) {
    Match::bike = b;
}

Match::~Match() {

}