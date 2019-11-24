//
// Created by Luca Graziotti on 19/11/2019
//

#ifndef MOTOCROSS2D_RESOURCEMANAGER_H
#define MOTOCROSS2D_RESOURCEMANAGER_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Resource.h"
#include "ResourceTexture.h"

class ResourceManager {
public:
    ResourceManager() {}

    ~ResourceManager() {}

    void add(Resource *r);

    bool loadBikes();

    bool loadLevels();

    static std::unique_ptr<Map> loadLevel(std::string id);

    bool loadEssentialResources();

    template<typename T>
    inline const T &getResource(std::string id) const {
        return dynamic_cast<T>(resources.at(id));
    };

private:


    std::map<std::string, Resource *> resources;
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;

    static std::unique_ptr<Map> loadLevel1();

    static std::unique_ptr<Map> loadLevel2();

    static std::unique_ptr<Map> loadLevel3();

    static std::unique_ptr<Map> loadLevel4();
};


#endif //MOTOCROSS2D_RESOURCEMANAGER_H
