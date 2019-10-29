//
// Created by matteo on 22/10/19.
//

#ifndef PROJECT_ALPHA_RANDOM_H
#define PROJECT_ALPHA_RANDOM_H
#include <cstdlib>
#include <SFML/System.hpp>
#include <iostream>
#include <ctime>

int generateRandom(int max);

sf::Vector2f generateRandomPos(int *level);

int generatePosX();

int generatePosY();
#endif //PROJECT_ALPHA_RANDOM_H
