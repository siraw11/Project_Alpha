//
// Created by Luca Graziotti on 25/11/2019.
//

#include "LevelFactory.h"
#include <Coin.h>
#include <SpeedBonus.h>
#include <TimeBonus.h>
#include <Checkpoint.h>
#include <SpeedMalus.h>

std::string levelsToLoad[] = {"lv1", "lv2", "lv3", "lv4"};

std::map<std::string, std::shared_ptr<Map>> LevelFactory::getLevels() {
    std::map<std::string, std::shared_ptr<Map>> levels;
    for (int i = 0; i <= levelsToLoad->length(); i++) {
        levels.insert(std::pair<std::string, std::shared_ptr<Map>>(levelsToLoad[i], getLevel(levelsToLoad[i])));
    }
    return levels;
}

std::unique_ptr<Map> LevelFactory::getLevel(std::string id) {
    std::unique_ptr<Map> map(new Map());
    if (id == "lv1")
        map = loadLevel1();
    if (id == "lv2")
        map = loadLevel2();
    if (id == "lv3")
        map = loadLevel3();
    if (id == "lv4")
        map = loadLevel4();
    if (id == "TestDeath")
        map = loadLevelTestDeath();
    return map;
}


std::unique_ptr<Map> LevelFactory::loadLevel1() {
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
                              {100, 1},
                              {100, 10}//front limit
                      });

    map->setMapItems({
                             new SpeedMalus(.1, 45, .6, 5, .5, 0), //speedDecrement, posX, posY, width, height, angle
                             new Coin(5, .8, .7, .7, 50),
                             new Coin(7, 1, .7, .7, 30),
                             new SpeedBonus(1, 1.5, 10, .7, .7, .7),
                             new TimeBonus(1000, 20, 0., .7, .7),
                             new Checkpoint(25, 0, 1, 1.2),
                             new Checkpoint(95, 1, 5, 3, true),   //arrivo finale
                     });
    return map;
}

std::unique_ptr<Map> LevelFactory::loadLevel2() {
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
                             new SpeedBonus(1.5, 2, 5, .5, .7, .7),
                             new Coin(33, 5.5, .7, .7, 50),
                             new Checkpoint(50, 2.5, 5, 3, true),      //arrivo finale


                     });
    return map;
}


std::unique_ptr<Map> LevelFactory::loadLevel3() {
    std::unique_ptr<Map> map(new Map("lv3", "Level 3", false, false, 0));
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
                             new Coin(7, .1, .7, .7, 30),
                             new Checkpoint(50, 2, 5, 3, true),      //arrivo finale
                     });
    return map;
}


std::unique_ptr<Map> LevelFactory::loadLevel4() {
    std::unique_ptr<Map> map(new Map("lv4", "Level 4", false, false, 0));
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
                             new Checkpoint(95, 29, 5, 3, true),       //arrivo finale
                     });
    return map;
}

std::unique_ptr<Map> LevelFactory::loadLevelTestDeath() {
    std::unique_ptr<Map> map(new Map("TestDeath", "Test Death", false, false, 0));
    map->setMapPoints({
                              {-1,  10},//back limit
                              {0,   0},
                              {5,   0},
                              {60,  10},
                              {60,  0},
                              {100, 0},
                              {100, 1000}//front limit
                      });
    map->setMapItems({
                             new Coin(3, .2, .7, .7, 50),
                     });
    return map;
}

