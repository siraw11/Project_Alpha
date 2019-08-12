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


bool updateGame(const GameEvent &gameEvent, Hero &hero, Enemy &enemy, const Map &map){
    switch (gameEvent) {
        case GameEvent::quit: //
            return true;
        case GameEvent::up: {
            hero.Move(0,-1);
            break;
        }
        case GameEvent::left:{
            hero.Move(-1,0);
            break;
        }
        case GameEvent::down:{
            hero.Move(0,1);
            break;
        }
        case GameEvent::right:{
            hero.Move(1,0);
            break;
        }
        case GameEvent::fight:{
            hero.fight(enemy)//TODO:fix it setting class fight
            break;
        }
        case GameEvent::noop:{
            std::cout<<"Press: w,a,s,d,f or Q to quit"<<std::endl;
            break;
        }
    }
    return false;
}

