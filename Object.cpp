//
// Created by matteo on 08/09/20.
//



#include <iostream>
#include "Object.h"


//constructor
Object::Object() = default;

//destructor
Object::~Object() = default;


void Object::use(Hero* hero, std::vector<Tile>* tile_vector) {
    std::cout<<"object"<<std::endl;

}
