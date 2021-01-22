//
// Created by matteo on 08/09/20.
//
#pragma once

#ifndef PROJECT_ALPHA_OBJECT_H
#define PROJECT_ALPHA_OBJECT_H


#include "Tile.h"

class Hero;

class Object {
public:

//constructor and destructor
    Object();
    virtual ~Object();

    virtual void use(Hero* hero, std::vector<Tile>* tile_vector);


};


#endif //PROJECT_ALPHA_OBJECT_H
