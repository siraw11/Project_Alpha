//
// Created by Luca Graziotti on 25/11/2019.
//

#ifndef MOTOCROSS2D_BIKEFACTORY_H
#define MOTOCROSS2D_BIKEFACTORY_H

#include <iostream>
#include <Bike.h>

class BikeFactory {
public:
    static std::map<std::string, std::shared_ptr<Bike>> getBikes();

    static std::pair<std::string, std::unique_ptr<Bike>> getBike(std::string id);
};


#endif //MOTOCROSS2D_BIKEFACTORY_H
