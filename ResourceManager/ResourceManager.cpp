//
// Created by Luca Graziotti on 19/11/2019.
//

#include "ResourceManager.h"
#include "ResourceManagerException.h"
#include "ResourceTexture.h"
#include "Resource.h"
#include "ResourceFont.h"
#include "LevelFactory.h"
#include "BikeFactory.h"
#include <sstream>
#include <string>
#include <fstream>
#include <Game.h>

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
        add(new ResourceTexture("flip.png", "./resources/textures/flip.png"));

        Game::gameData->bikes = BikeFactory::getBikes();
        Game::gameData->levels = LevelFactory::getLevels();
    } catch (ResourceManagerException &e) {
        std::cerr << e.getMsg() << std::endl;
        return false;
    }
    return true;
}

void ResourceManager::add(Resource *r) {
    this->resources.insert(std::make_pair(r->getName(), r));
}

int ResourceManager::getSize() {
    return resources.size();
}

void ResourceManager::remove(std::string id) {
    this->resources.erase(id);
}