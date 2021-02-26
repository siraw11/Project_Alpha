//
// Created by matteo on 31/03/20.
//



#include <bits/unique_ptr.h>
#include "CharacterFactory.h"
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"




//function
Hero* CharacterFactory::createCharacter(PlayerType type) {

    Hero *result = nullptr;

    switch(type) {
        case PlayerType::KNIGHT: {
            result = new Knight(10, 3, 50, 0, 20, 0);
            break;
        }
        case PlayerType::ARCHER: {
            result =new Archer(10, 1, 50, 20, 0, 0);
            break;
        }
        case PlayerType ::MAGE: {
            result = new Mage(10, 2, 50, 0, 0, 10);
            break;
        }
    }

    return result;
}
