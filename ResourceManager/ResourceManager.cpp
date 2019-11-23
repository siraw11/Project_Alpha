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
    bool resourcesLoaded = true;
    loadFont("arial.ttf", "./resources/fonts/arial.ttf");


    loadTexture("wheel.png", "./resources/textures/wheel.png");
    loadTexture("cart.png", "./resources/textures/cart.png");
    loadTexture("cart_red.png", "./resources/textures/cart_red.png");
    loadTexture("cart_orange.png", "./resources/textures/cart_orange.png");

    loadTexture("arrival.png", "./resources/textures/arrival.png");
    loadTexture("checkpoint.png", "./resources/textures/checkpoint.png");
    loadTexture("coin.png", "./resources/textures/coin.png");
    loadTexture("heart.png", "./resources/textures/heart.png");
    loadTexture("cart.png", "./resources/textures/cart.png");
    loadTexture("rocket1.png", "./resources/textures/rocket1.png");
    loadTexture("timer.png", "./resources/textures/timer.png");

    loadBikes();

    return resourcesLoaded;
}

bool ResourceManager::loadTexture(std::string name, std::string fileName) {
    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        this->textures[name] = texture;
        return true;
    } else {
    }
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
                              {100, 1},
                              {100, 10}//front limit
                      });

    map->setMapItems({
                             new Coin(5, 0.8, .7, .7, 50),
                             new Coin(7, 1, .7, .7, 30),
                             new SpeedBonus(10, 100, 10, .7, .7, .7),
                             new TimeBonus(1000, 20, 0., .7, .7),
                             new Checkpoint(25, 0, 1, 1.2),
                             new Checkpoint(95, 2, 5, 3, true),   //arrivo finale
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
                             new Checkpoint(50, 2, 5, 3, true),      //arrivo finale


                     });
    return map;
}


std::unique_ptr<Map> ResourceManager::loadLevel3() {
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
                             new Coin(5, .2, .7, .7, 50),
                             new Coin(7, .1, .7, .7, 30),
                             new Checkpoint(24, 1, 5, 3, true),      //arrivo finale
                     });
    return map;
}


std::unique_ptr<Map> ResourceManager::loadLevel4() {
    std::unique_ptr<Map> map(new Map("lv4", "Level 4", false, false, 0));
    map->setMapPoints({
                              {-1,  10},//back limit
                              {0,   0},
                              {100, 0},
                              {100, 10}//front limit
                      });

    map->setMapItems({
                             new TimeBonus(1000, 3, .1, .7, .7),
                             new Coin(5, .2, .7, .7, 50),
                             new Coin(7, .1, .7, .7, 30),
                             new Checkpoint(24, 1, 5, 3, true),       //arrivo finale
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
