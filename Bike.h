//
// Created by Magna on 2019-06-03.
//

#ifndef MOTOCROSS2D_BIKE_H
#define MOTOCROSS2D_BIKE_H


#include <iostream>


class Bike {
public:
    Bike(std::string nam = "n/d", std::string color = "red", float speed = 0., int usability = 0, int price = 0, bool isUnlocked = false);

    virtual ~Bike();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    float getSpeed() const;

    void setSpeed(float speed);

    int getUsability() const;

    void setUsability(int usability);

    int getPrice() const;

    void setPrice(int price);

    bool getIsUnlocked() const;

    void setIsUnlocked(bool isUnlocked);


private:
    std::string name;
    std::string color;
    float speed;
    int usability;
    int price;
    bool isUnlocked;
};


#endif //MOTOCROSS2D_BIKE_H
