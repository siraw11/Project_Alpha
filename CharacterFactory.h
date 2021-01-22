//
// Created by matteo on 31/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_CHARACTERFACTORY_H
#define PROGETTO_PROVA_CHARACTERFACTORY_H


#include "Hero.h"

class CharacterFactory {
public:
    //constructor, destructor
    CharacterFactory();
    ~CharacterFactory();

    //function
    virtual std::unique_ptr<Hero> createCharacter(PlayerType type);

};


#endif //PROGETTO_PROVA_CHARACTERFACTORY_H
