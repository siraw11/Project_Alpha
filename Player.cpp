//
// Created by Magna on 2019-06-03.
//

#include "Player.h"
#include "Bike.h"

Player::Player(std::string _username, int _totalCoin, float _posX, float _posY, float _angle, Bike* _bike):username(_username),totalCoin(_totalCoin),posX(_posX),posY(_posY),angle(_angle),bike(_bike){}


const std::string &Player::getUsername() const {
    return username;
}

void Player::setUsername(const std::string &username) {
    Player::username = username;
}

int Player::getTotalCoin() const {
    return totalCoin;
}

void Player::setTotalCoin(int totalCoin) {
    Player::totalCoin = totalCoin;
}

float Player::getPosX() const {
    return posX;
}

void Player::setPosX(float posX) {
    Player::posX = posX;
}

float Player::getPosY() const {
    return posY;
}

void Player::setPosY(float posY) {
    Player::posY = posY;
}

float Player::getAngle() const {
    return angle;
}

void Player::setAngle(float angle) {
    Player::angle = angle;
}

Bike *Player::getBike() const {
    return bike;
}

void Player::setBike(Bike *bike) {
    Player::bike = bike;
}

Player::~Player() {

}

