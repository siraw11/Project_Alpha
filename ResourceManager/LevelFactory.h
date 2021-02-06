//
// Created by Luca Graziotti on 25/11/2019.
//

#ifndef MOTOCROSS2D_LEVELFACTORY_H
#define MOTOCROSS2D_LEVELFACTORY_H

#include <iostream>
#include <Map.h>

class LevelFactory {
public :
    static std::map<std::string, std::shared_ptr<Map>> getLevels();

    static std::shared_ptr<Map> getLevel(std::string id);
};


#endif //MOTOCROSS2D_LEVELFACTORY_H
