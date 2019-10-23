
#include "Random.h"
//
// Created by matteo on 22/10/19.
//


int generateRandom(int max){

    int randomNumber= std::rand();
    int random=(randomNumber % max)+1;
    return random;
}

sf::Vector2f generateRandomPos(int *level) {
    bool test=false;
    int x;
    int y;

    while(!test){
        x = generatePosX();
        y = generatePosY();
        if(level[120 * y + x]==0)
            test=true;
    }
    sf::Vector2f randomPos(x*32*3, y*32*3);
    return randomPos;
}

int generatePosX(){

    int randomNumber=std::rand();
    int random=(randomNumber % 120);
    return random;
}

int generatePosY(){

    int randomNumber=std::rand();
    int random=(randomNumber % 84);
    return random;
}
