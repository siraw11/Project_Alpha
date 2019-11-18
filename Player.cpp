//
// Created by Magna on 2019-06-03.
//

#include "Player.h"
#include "Bike.h"
#include "Observer.h"
#include "Subject.h"

Player::Player(std::string _username, int _totalCoin, Bike *_bike) : username(
        _username), totalCoin(_totalCoin), bike(_bike) {}


const std::string &Player::getUsername() const {
    return username;
}

void Player::setUsername(const std::string &username) {
    Player::username = username;
}

int Player::getTotalCoin() const {
    return totalCoin;
}

void Player::addTotalCoin(int increment) {
    Player::totalCoin += increment;
}

void Player::registerObserver(Observer *o) {
    observers.push_back(o);
}

void Player::removeObserver(Observer *o) {
    observers.remove(o);
}

void Player::notifyObservers() {
    for( auto itr = std::begin(observers);itr != std::end (observers); itr++) {
        (*itr)->update();
    }
}

Player::~Player() {

}