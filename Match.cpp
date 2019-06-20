//
// Created by Magna on 2019-06-20.
//

#include "Match.h"
#include "Bike.h"
#include "Player.h"

Match::Match(Position _p, int _lifes, float _time, int _money, Player *_player, Bike *_b) : p(_p), lifes(_lifes),
                                                                                            time(_time), money(_money),
                                                                                            player(_player), b(_b) {}

const Position &Match::getP() const {
    return p;
}

void Match::setP(const Position &p) {
    Match::p = p;
}

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
    return b;
}

void Match::setB(Bike *b) {
    Match::b = b;
}

Match::~Match() {

}