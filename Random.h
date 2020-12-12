//
// Created by matteo on 22/10/19.
//
#pragma once

#ifndef PROJECT_ALPHA_RANDOM_H
#define PROJECT_ALPHA_RANDOM_H
#include <cstdlib>
#include <SFML/System.hpp>
#include <iostream>
#include <ctime>
#include "Tile.h"

int generateRandom(int max);

sf::Vector2f generateRandomPos(std::vector<Tile>& tile_vector);

int generatePosX();

int generatePosY();
#endif //PROJECT_ALPHA_RANDOM_H
