//
// Created by Luca Graziotti on 19/11/2019.
//

#include "ResourceManager.h"
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <Game.h>
#include <Coin.h>
#include <SpeedBonus.h>
#include <TimeBonus.h>
#include <Checkpoint.h>
#include "Item.h"

bool ResourceManager::loadEssentialResources() {
    std::vector<bool> loads;
    loads.push_back(loadFont("arial.ttf", "./resources/fonts/arial.ttf"));

    loads.push_back(loadTexture("wheel.png", "./resources/textures/wheel.png"));
    loads.push_back(loadTexture("cart.png", "./resources/textures/cart.png"));
    loads.push_back(loadTexture("cart_red.png", "./resources/textures/cart_red.png"));
    loads.push_back(loadTexture("cart_orange.png", "./resources/textures/cart_orange.png"));

    loads.push_back(loadTexture("arrival.png", "./resources/textures/arrival.png"));
    loads.push_back(loadTexture("checkpoint.png", "./resources/textures/checkpoint.png"));
    loads.push_back(loadTexture("coin.png", "./resources/textures/coin.png"));
    loads.push_back(loadTexture("cart.png", "./resources/textures/cart.png"));
    loads.push_back(loadTexture("rocket1.png", "./resources/textures/rocket1.png"));
    loads.push_back(loadTexture("timer.png", "./resources/textures/timer.png"));

    loads.push_back(loadBikes());

    if (std::find(loads.begin(), loads.end(), false) != loads.end()) {
        return false;
    } else {
        return true;
    }
}

bool ResourceManager::loadTexture(std::string name, std::string fileName) {
    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        this->textures[name] = texture;
        return true;
    }
    return false;
}

sf::Texture &ResourceManager::getTexture(std::string name) {
    return this->textures.at(name);
}

bool ResourceManager::loadFont(std::string name, std::string fileName) {
    sf::Font font;
    if (font.loadFromFile(fileName)) {
        this->fonts[name] = font;
        return true;
    }
    return false;
}

sf::Font &ResourceManager::getFont(std::string name) {
    return this->fonts.at(name);
}


std::string ResourceManager::readFile(std::string filePath) {
    std::ifstream infile(filePath);
    std::string line;
    std::string total = "";
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (!iss) {
            break;
        }
        total += line + "\n";
    }
    return total;

}

/*
void ResourceManager::loadBikes() {
    //TODO: da usare serializzazione
    std::istringstream dataString(readFile("./resources/data/bikes.data"));
    std::string line;
    while (std::getline(dataString, line)) {
        std::string name = line.substr(0, line.find("|"));
        std::string color = line.substr(1, line.find("|"));
        float speed = std::stof(line.substr(2, line.find("|")));
        int price = std::stoi(line.substr(3, line.find("|")));
        bool isUnlocked = std::stoi(line.substr(4, line.find("|")));
    }
    return;
}
*/

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
    Game::gameData->levels.insert(
            std::pair<std::string, std::shared_ptr<Map>>("lv1", ResourceManager::loadLevel("lv1")));
    Game::gameData->levels.insert(
            std::pair<std::string, std::shared_ptr<Map>>("lv2", ResourceManager::loadLevel("lv2")));
    Game::gameData->levels.insert(
            std::pair<std::string, std::shared_ptr<Map>>("lv3", ResourceManager::loadLevel("lv3")));
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
                              {100, 1},
                              {100, 10}//front limit
                      });

    map->setMapItems({
                             new Coin(5, 0.8, .7, .7, 50),
                             new Coin(7, 1, .7, .7, 30),
                             new SpeedBonus(10, 100, 10, .7, .7, .7),
                             new TimeBonus(1000, 20, 0., .7, .7),
                             new Checkpoint(25, 0, 1, 1.2),
                             new Checkpoint(95, 2, 5, 3, true),
                     });
    return map;
}

std::unique_ptr<Map> ResourceManager::loadLevel2() {
    std::unique_ptr<Map> map(new Map("lv2", "Level 2", false, false, 0));
    map->setMapPoints({
                              {-1, 10},//back limit
                              {0,  0},
                              {30, 0},
                              {30, 10}//front limit
                      });

    map->setMapItems({
                             new TimeBonus(1000, 3, .1, .7, .7),
                             new Coin(5, .2, .7, .7, 50),
                             new Coin(7, .1, .7, .7, 30),
                             new Checkpoint(24, 1, 5, 3, true)
                     });
    return map;
}

std::unique_ptr<Map> ResourceManager::loadLevel3() {
    std::unique_ptr<Map> map(new Map("lv3", "Level 3", false, true, 0));
    map->setMapPoints({
                              {-1, 10},//back limit
                              {0,  0},
                              {5,  0},
                              {10, 3.5},
                              {15, 3.5},
                              {17, 4.5},
                              {17, 0},
                              {20, 1},
                              {23, 1},
                              {30, -1.5},
                              {33, -1.5},
                              {38, -1},
                              {38, -1.5},
                              {43, -1.5},
                              {48, 0},
                              {53, 0},
                              {53, 10}//front limit
                      });

    map->setMapItems({

                             new Coin(5, .4, .5, .5, 25),
                             new Coin(7.5, 2.3, .7, .7, 50),
                             new SpeedBonus(10, 1, 14, 3.8, .7, .7),
                             new SpeedBonus(10, 1, 34, -1, .7, .7),
                             new Checkpoint(32, -1.5, 1, 1.2),
                             new Checkpoint(50, 0, 5, 3, true),


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
    return map;
}
