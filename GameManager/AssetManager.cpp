//
// Created by Luca Graziotti on 19/11/2019.
//

#include "AssetManager.h"
#include <sstream>
#include <string>
#include <fstream>
#include <Game.h>


void AssetManager::LoadTexture(std::string name, std::string fileName) {
    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        this->textures[name] = texture;
    }
}

sf::Texture &AssetManager::GetTexture(std::string name) {
    return this->textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName) {
    sf::Font font;
    if (font.loadFromFile(fileName)) {
        this->fonts[name] = font;
    }
}

sf::Font &AssetManager::GetFont(std::string name) {
    return this->fonts.at(name);
}


std::string AssetManager::readFile(std::string filePath) {
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
void AssetManager::loadBikes() {
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

void AssetManager::loadBikes() {
    std::shared_ptr<Bike> bike = std::make_shared<Bike>(Bike("b1", "Standard", "red", 5, 0, true));
    Game::gameData->bikes.insert(std::make_pair(bike->getId(), bike));
    bike = std::make_shared<Bike>(Bike("b2", "Standard+", "red", 6, 200, false));
    Game::gameData->bikes.insert(std::make_pair(bike->getId(), bike));
    bike = std::make_shared<Bike>(Bike("b3", "Rocket", "red", 10, 500, false));
    Game::gameData->bikes.insert(std::make_pair(bike->getId(), bike));
}