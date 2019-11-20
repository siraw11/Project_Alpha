//
// Created by Magna on 2019-06-03.
//

#include "Bike.h"
#include <utility>
#include "Box2D/Box2D.h"


Bike::Bike(std::string _id, std::string _name, std::string _color, float _speed, int _price, bool _isUnlocked,
           b2Body *_wheelL, b2Body *_wheelR, b2Body *_cart) : id(_id), name(std::move(
        _name)), color(std::move(_color)), speed(_speed), price(_price), isUnlocked(_isUnlocked),
                                                              wheelL(_wheelL), wheelR(_wheelR), cart(_cart) {
}


const std::string &Bike::getName() const {
    return name;
}

void Bike::setName(const std::string &_name) {
    Bike::name = _name;
}

const std::string &Bike::getColor() const {
    return color;
}

void Bike::setColor(const std::string &_color) {
    Bike::color = _color;
}

float Bike::getSpeed() const {
    return speed;
}

void Bike::setSpeed(float _speed) {
    Bike::speed = _speed;
}



int Bike::getPrice() const {
    return price;
}

void Bike::setPrice(int _price) {
    Bike::price = _price;
}

bool Bike::getIsUnlocked() const {
    return isUnlocked;
}

void Bike::setIsUnlocked(bool _isUnlocked) {
    Bike::isUnlocked = _isUnlocked;
}


Bike::~Bike() {
    //TODO: implement
}

const std::string &Bike::getId() const {
    return id;
}

void Bike::setId(const std::string &id) {
    Bike::id = id;
}
