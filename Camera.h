#pragma once
//
// Created by matteo on 22/02/21.
//

#ifndef PROJECT_ALPHA_CAMERA_H
#define PROJECT_ALPHA_CAMERA_H


#include <SFML/Graphics/View.hpp>
#include "Hero.h"
#include "GameManager/Game.hpp"

class Camera : public sf::View{
public:
    //constructor
    Camera();
    ~Camera();

    //functions
    void update(const Hero& hero, const Alpha::GameDataRef& _data);
    void resetCamera(const Alpha::GameDataRef& _data);


private:

    sf::Vector2f position = sf::Vector2f(0,0);



};


#endif //PROJECT_ALPHA_CAMERA_H
