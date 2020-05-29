//
// Created by matteo on 31/03/20.
//

#ifndef PROGETTO_PROVA_CHARACTERFACTORY_H
#define PROGETTO_PROVA_CHARACTERFACTORY_H

#include<iostream>
#include "Hero.h"
#include "PlayerType.h"


class CharacterFactory {
public:
    CharacterFactory();
    virtual ~CharacterFactory();

    virtual std::unique_ptr<Hero> createCharacter(PlayerType type);

};


#endif //PROGETTO_PROVA_CHARACTERFACTORY_H
