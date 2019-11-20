//
// Created by Luca Graziotti on 19/11/2019
//

#ifndef MOTOCROSS2D_ASSETMANAGER_H
#define MOTOCROSS2D_ASSETMANAGER_H


#include <SFML/Graphics.hpp>
#include <iostream>

class AssetManager {
public:
    AssetManager() {}

    ~AssetManager() {}

    void LoadTexture(std::string name, std::string fileName);

    sf::Texture &GetTexture(std::string name);

    void LoadFont(std::string name, std::string fileName);

    sf::Font &GetFont(std::string name);

    void loadBikes();

private:
    static std::string readFile(std::string filePath);

    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
};


#endif //MOTOCROSS2D_ASSETMANAGER_H
