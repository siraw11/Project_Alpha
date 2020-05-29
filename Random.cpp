

//
// Created by matteo on 22/10/19.
//


#include <cstdlib>
#include <SFML/System.hpp>
#include "Random.h"
#include <ctime>


int generateRandom(int max){

    int randomNumber= std::rand();
    int random=(randomNumber % max)+1;
    return random;
}

sf::Vector2f generateRandomPos(std::vector<Tile>& tile_vector) {
    bool test=false;
    int x;
    int y;

    while(!test){
        x = generatePosX();
        y = generatePosY();
        if(tile_vector[120*y+x].t==0)
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
