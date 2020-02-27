//
// Created by Luca Graziotti on 25/11/2019.
//

#include "LevelFactory.h"
#include "ResourceMap.h"
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

std::shared_ptr<Map> LevelFactory::getLevel(std::string id) {
    std::shared_ptr<Map> map;
    if (id == "lv1")
        map = ResourceMap("lv1", "./resources/maps/level1.map").getMap();
    if (id == "lv2")
        map = ResourceMap("lv2", "./resources/maps/level2.map").getMap();
    if (id == "lv3")
        map = ResourceMap("lv3", "./resources/maps/level3.map").getMap();
    if (id == "lv4")
        map = ResourceMap("lv4", "./resources/maps/level4.map").getMap();
    if (id == "TestDeath")
        map = ResourceMap("TestDeath", "./resources/maps/test.map").getMap();


    return map;
}