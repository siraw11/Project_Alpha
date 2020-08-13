//
// Created by matteo on 31/03/20.
//

#include "CharacterFactory.h"
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"

CharacterFactory::~CharacterFactory() = default;

CharacterFactory::CharacterFactory() = default;

std::unique_ptr<Hero> CharacterFactory::createCharacter(PlayerType type) {

    std::unique_ptr<Hero> result;


    switch(type) {
        case PlayerType::KNIGHT: {
            result = std::unique_ptr<Hero>(new Knight(1, 1, 50, 1));
            break;
        }
        case PlayerType::ARCHER: {
            result = std::unique_ptr<Hero>(new Archer(1,1,50,10));
            break;
        }
        case PlayerType ::MAGE: {
            result = std::unique_ptr<Hero>(new Mage(1,1,50,10));
            break;
        }
    }

    return result;
}
