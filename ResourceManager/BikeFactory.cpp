//
// Created by Luca Graziotti on 25/11/2019.
//

#include <Map.h>
#include "BikeFactory.h"

std::map<std::string, std::shared_ptr<Bike>> BikeFactory::getBikes() {
    std::map<std::string, std::shared_ptr<Bike>> bikes;
    bikes.insert(getBike("b1"));
    bikes.insert(getBike("b2"));
    bikes.insert(getBike("b3"));

    return bikes;
}

std::pair<std::string, std::unique_ptr<Bike>> BikeFactory::getBike(std::string id) {
    if (id == "b1")
        return std::make_pair("b1", std::unique_ptr<Bike>(new Bike("b1", "Standard", "cart.png", 10, 0, true)));
    if (id == "b2")
        return std::make_pair("b2",
                              std::unique_ptr<Bike>(new Bike("b2", "Standard+", "cart_orange.png", 30, 200, false)));
    if (id == "b3")
        return std::make_pair("b3", std::unique_ptr<Bike>(new Bike("b3", "Rocket", "cart_red.png", 50, 500, false)));

    return std::make_pair("", std::unique_ptr<Bike>(new Bike()));
}




