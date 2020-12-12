//
// Created by matteo on 08/09/20.
//



#include <iostream>
#include "Object.h"


///constructor
Object::Object() = default;

///destructor
Object::~Object() = default;


void Object::use(Hero* hero) {
    std::cout<<"object"<<std::endl;

}
