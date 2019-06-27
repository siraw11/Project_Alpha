#include <iostream>

#include "Map.h"
#include "GameCharacter.h"
#include "Archer.h"
#include "Boss.h"
#include "Chest.h"
#include "Enemy.h"
#include "Hero.h"
#include "Item.h"
#include "Knight.h"
#include "Mage.h"
#include "Tile.h"
#include "Weapon.h"

enum class GameEvent {
    quit, left, up, down, right, fight, noop
};

GameEvent getEvent(){
    char c;
    while(std::cin.get(c)){
        std::cin.ignore(100,'\n');
        switch(c){
            case 'Q':
                return GameEvent::quit;
            case 'w':
                return GameEvent::up;
            case 'a':
                return GameEvent::left ;
            case 's':
                return GameEvent::down;
            case 'd':
                return GameEvent::right;
            case 'f':
                return GameEvent::fight;
            default:
                return GameEvent::noop;
        }
    }
    return GameEvent::noop;
}


