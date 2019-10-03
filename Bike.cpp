//
// Created by Magna on 2019-06-03.
//

#include "Bike.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"


Bike::Bike(std::string _name, std::string _color, float _speed, int _usability, int _price, bool _isUnlocked,b2Body* _wheelL,b2Body* _wheelR,b2Body* _cart) : name(
        _name), color(_color), speed(_speed), usability(_usability), price(_price), isUnlocked(_isUnlocked),wheelL(_wheelL),wheelR(_wheelR),cart(_cart) {
}

const std::string &Bike::getName() const {
    return name;
}

void Bike::setName(const std::string &name) {
    Bike::name = name;
}

const std::string &Bike::getColor() const {
    return color;
}

void Bike::setColor(const std::string &color) {
    Bike::color = color;
}

float Bike::getSpeed() const {
    return speed;
}

void Bike::setSpeed(float speed) {
    Bike::speed = speed;
}


int Bike::getUsability() const {
    return usability;
}

void Bike::setUsability(int usability) {
    Bike::usability = usability;
}


int Bike::getPrice() const {
    return price;
}

void Bike::setPrice(int price) {
    Bike::price = price;
}

bool Bike::getIsUnlocked() const {
    return isUnlocked;
}

void Bike::setIsUnlocked(bool isUnlocked) {
    Bike::isUnlocked = isUnlocked;
}



Bike::~Bike() {
    //TODO: implement
}