//
// Created by matteo on 31/03/20.
//



#include <bits/unique_ptr.h>
#include "CharacterFactory.h"
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"


///constructor
CharacterFactory::~CharacterFactory() = default;

///destructor
CharacterFactory::CharacterFactory() = default;


///function
std::unique_ptr<Hero> CharacterFactory::createCharacter(PlayerType type) {

    std::unique_ptr<Hero> result;


    switch(type) {
        case PlayerType::KNIGHT: {
            result = std::unique_ptr<Hero>(new Knight(1, 1, 20, 0, 20, 0));
            break;
        }
        case PlayerType::ARCHER: {
            result = std::unique_ptr<Hero>(new Archer(1, 1, 20, 10, 0, 0));
            break;
        }
        case PlayerType ::MAGE: {
            result = std::unique_ptr<Hero>(new Mage(1, 1, 20, 0, 0, 10));
            break;
        }
    }

    return result;
}
