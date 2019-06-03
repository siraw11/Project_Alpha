//
// Created by Magna on 2019-06-03.
//

#include "Bike.h"

Bike::Bike(std::string _name, std::string _color, int _speed, int _usability, int _price, bool _isUnlocked):name(_name),color(_color),speed(_speed),usability(_usability),price(_price),isUnlocked(_isUnlocked){}

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

int Bike::getSpeed() const {
    return speed;
}

void Bike::setSpeed(int speed) {
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
