//
// Created by Magna on 2019-06-03.
//

#ifndef MOTOCROSS2D_BIKE_H
#define MOTOCROSS2D_BIKE_H


#include <iostream>

#include <SFML/Graphics.hpp>

class Bike {
public:
    Bike(std::string id = "b1", std::string name = "n/d", std::string texture = "cart.png", float speed = 0.,
         int price = 0,
         bool isUnlocked = false);

    virtual ~Bike();

    const std::string &getName() const;

    void setName(const std::string &name);


    float getSpeed() const;

    void setSpeed(float speed);


    int getPrice() const;

    void setPrice(int price);

    bool getIsUnlocked() const;

    void setIsUnlocked(bool isUnlocked);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getTexture() const;

    void setTexture(const std::string &texture);

private:
    std::string id;
    std::string name;
    std::string texture;
    float speed;
    int price;
    bool isUnlocked;


};


#endif //MOTOCROSS2D_BIKE_H