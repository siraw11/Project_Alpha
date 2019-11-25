//
// Created by Luca Graziotti on 19/11/2019.
//

#include "ResourceManager.h"
#include "ResourceManagerException.h"
#include "ResourceTexture.h"
#include "Resource.h"
#include "ResourceFont.h"
#include <sstream>
#include <string>
#include <fstream>
#include <Game.h>
#include <Coin.h>
#include <SpeedBonus.h>
#include <TimeBonus.h>
#include <Checkpoint.h>
#include <SpeedMalus.h>

bool ResourceManager::loadEssentialResources() {
    try {
        add(new ResourceFont("arial.ttf", "./resources/fonts/arial.ttf"));

        add(new ResourceTexture("wheel.png", "./resources/textures/wheel.png"));
        add(new ResourceTexture("cart.png", "./resources/textures/cart.png"));
        add(new ResourceTexture("cart_red.png", "./resources/textures/cart_red.png"));
        add(new ResourceTexture("cart_orange.png", "./resources/textures/cart_orange.png"));

        add(new ResourceTexture("arrival.png", "./resources/textures/arrival.png"));
        add(new ResourceTexture("checkpoint.png", "./resources/textures/checkpoint.png"));
        add(new ResourceTexture("coin.png", "./resources/textures/coin.png"));
        add(new ResourceTexture("heart.png", "./resources/textures/heart.png"));
        add(new ResourceTexture("cart.png", "./resources/textures/cart.png"));
        add(new ResourceTexture("rocket1.png", "./resources/textures/rocket1.png"));
        add(new ResourceTexture("timer.png", "./resources/textures/timer.png"));
        add(new ResourceTexture("mud.png", "./resources/textures/mud.png"));


        loadBikes();
        loadLevels();
    } catch (ResourceManagerException &e) {
        std::cerr << e.getMsg() << std::endl;
        return false;
    }
    return true;
}

void ResourceManager::add(Resource *r) {
    this->resources.insert(std::make_pair(r->getName(), r));
}


bool ResourceManager::loadBikes() {
    std::shared_ptr<Bike> bike = std::make_shared<Bike>(Bike("b1", "Standard", "cart.png", 20, 0, true));
    Game::gameData->bikes.insert(std::make_pair(bike->getId(), bike));
    bike = std::make_shared<Bike>(Bike("b2", "Standard+", "cart_orange.png", 30, 200, false));
    Game::gameData->bikes.insert(std::make_pair(bike->getId(), bike));
    bike = std::make_shared<Bike>(Bike("b3", "Rocket", "cart_red.png", 50, 500, false));
    Game::gameData->bikes.insert(std::make_pair(bike->getId(), bike));
    return true;
}


bool ResourceManager::loadLevels() {
    std::string l[] = {"lv1", "lv2", "lv3", "lv4"};
    for (int i = 0; i <= l->length(); i++) {
        Game::gameData->levels.insert(
                std::pair<std::string, std::shared_ptr<Map>>(l[i], ResourceManager::loadLevel(l[i])));
    }
    return true;
}


std::unique_ptr<Map> ResourceManager::loadLevel1() {
    std::unique_ptr<Map> map(new Map("lv1", "Level 1", false, true, 0));
    map->setMapPoints({
                              {-1,  10},//back limit
                              {0,   0.},
                              {3,   0.},
                              {8,   1},
                              {11,  0},
                              {15,  -1},
                              {20,  0},
                              {25,  0},
                              {30,  0.5},
                              {35,  -1},
                              {40,  0},
                              {43,  0},
                              {45,  1},
                              {100, 0},
                              {100, 10}//front limit
                      });

    map->setMapItems({
                             new SpeedMalus(.1, 2, -.1, 1, .1, 90), //speedDecrement, posX, posY, width, height, angle
                             new Coin(5, 0.8, .7, .7, 50),
                             new Coin(7, 1, .7, .7, 30),
                             new SpeedBonus(10, 100, 10, .7, .7, .7),
                             new TimeBonus(1000, 20, 0., .7, .7),
                             new Checkpoint(25, 0, 1, 1.2),
                             new Checkpoint(95, 0, 5, 3, true),   //arrivo finale
                     });
    return map;
}

std::unique_ptr<Map> ResourceManager::loadLevel2() {
    std::unique_ptr<Map> map(new Map("lv2", "Level 2", false, false, 0));
    map->setMapPoints({
                              {-1, 10},//back limit
                              {0,  0},
                              {5,  0},
                              {6,  1},
                              // {6, .5},
                              {10, 1},
                              {15, 3},
                              {18, 3},
                              {23, 5},
                              {33, 5},
                              {40, 0},
                              {44, 0},
                              {50, 2.5},
                              {53, 2.5},
                              {53, 12}//front limit
                      });

    map->setMapItems({
                             new SpeedBonus(10, 1, 5, .5, .7, .7),
                             new SpeedBonus(10, 1, 10, 1, .7, .7),
                             new SpeedBonus(10, 1, 18, 3.5, .7, .7),
                             new Coin(33, 5.5, .7, .7, 50),
                             //new SpeedBonus(10, 1, 10, 1, .7, .7),
                             new Checkpoint(32, 1.5, 1, 1.2),
                             new Checkpoint(50, 2.5, 5, 3, true),      //arrivo finale


                     });
    return map;
}


std::unique_ptr<Map> ResourceManager::loadLevel3() {
    std::unique_ptr<Map> map(new Map("lv3", "Level 3", false, true, 0));
    map->setMapPoints({
                              {-1, 10},//back limit
                              {0,  0},
                              {3,  0},
                              {12, 5.5},
                              {15, 5.5},
                              {17, 6.5},
                              {17, 2},
                              {20, 3},
                              {23, 3},
                              {30, 1.5},
                              {33, 1.5},
                              {38, 2},
                              {38, 1.5},
                              {43, 1.5},
                              {48, 2},
                              {53, 2},
                              {53, 12}//front limit
                      });

    map->setMapItems({
                             new TimeBonus(1000, 3, .1, .7, .7),
                             new Coin(5, .2, .7, .7, 50),
                             new Coin(7, .1, .7, .7, 30),
                             new Checkpoint(50, 2, 5, 3, true),      //arrivo finale
                     });
    return map;
}


std::unique_ptr<Map> ResourceManager::loadLevel4() {
    std::unique_ptr<Map> map(new Map("lv4", "Level 4", false, true, 0));
    map->setMapPoints({
                              {-1,  10},//back limit
                              {0,   0},
                              {5,   0},
                              {100, 30},
                              {100, 1000}//front limit
                      });

    map->setMapItems({
                             new TimeBonus(1000, 3, .1, .7, .7),
                             new Coin(5, .2, .7, .7, 50),
                             new Coin(7, .1, .7, .7, 30),
                             new Checkpoint(95, 28, 5, 3, true),       //arrivo finale
                     });
    return map;
}


std::unique_ptr<Map> ResourceManager::loadLevel(std::string id) {
    std::unique_ptr<Map> map(new Map());
    if (id == "lv1")
        map = loadLevel1();
    if (id == "lv2")
        map = loadLevel2();
    if (id == "lv3")
        map = loadLevel3();
    if (id == "lv4")
        map = loadLevel4();
    return map;
}

