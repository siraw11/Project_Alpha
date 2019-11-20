//
// Created by Luca Graziotti on 19/11/2019
//

#ifndef MOTOCROSS2D_RESOURCEMANAGER_H
#define MOTOCROSS2D_RESOURCEMANAGER_H


#include <SFML/Graphics.hpp>
#include <iostream>

class ResourceManager {
public:
    ResourceManager() {}

    ~ResourceManager() {}

    bool loadTexture(std::string name, std::string fileName);

    sf::Texture &getTexture(std::string name);

    bool loadFont(std::string name, std::string fileName);

    sf::Font &getFont(std::string name);

    bool loadBikes();

    bool loadEssentialResources();

private:
    static std::string readFile(std::string filePath);

    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
};


#endif //MOTOCROSS2D_RESOURCEMANAGER_H
