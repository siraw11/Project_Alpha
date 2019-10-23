
#include "Random.h"
//
// Created by matteo on 22/10/19.
//


int generateRandom(int max){

    int randomNumber= std::rand();
    int random=(randomNumber % max)+1;
    return random;
}

sf::Vector2f generateRandomPos() {


    int x = generatePosX()*32*3;
    int y = generatePosY()*32*3;
    sf::Vector2f randomPos(x, y);
    return randomPos;
}

int generatePosX(){

    int randomNumber=std::rand();
    int random=(randomNumber % 84);
    return random;
}

int generatePosY(){

    int randomNumber=std::rand();
    int random=(randomNumber % 120);
    return random;
}
