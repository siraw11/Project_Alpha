//
// Created by Luca Graziotti on 25/11/2019.
//

#ifndef MOTOCROSS2D_LEVELFACTORY_H
#define MOTOCROSS2D_LEVELFACTORY_H

#include <iostream>
#include <Map.h>

class LevelFactory {
private:

    static std::unique_ptr<Map> loadLevel1();

    static std::unique_ptr<Map> loadLevel2();

    static std::unique_ptr<Map> loadLevel3();

    static std::unique_ptr<Map> loadLevel4();

public :
    static std::map<std::string, std::shared_ptr<Map>> getLevels();

    static std::unique_ptr<Map> getLevel(std::string id);
};


#endif //MOTOCROSS2D_LEVELFACTORY_H
