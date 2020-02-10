//
// Created by andreatadde on 07/02/20.
//

#include <gtest/gtest.h>
#include <SFML/System.hpp>
#include "../Hero.h"
#include "../GameCharacter.h"
#include "../RectangleShape.h"
#include "../Bullet.h"
#include "../Platform.h"
#include "../Collision.h"
#include "../GameLogic.h"
#include "../LevelManager.h"
#include <vector>
#include <iostream>

TEST(LevelManager,TestFile){
    const int nFiles = 2;
    std::string levelName[nFiles] = {"Levels/Level1","Levels/Level2"};
    LevelManager levelManager(levelName,nFiles);
    ASSERT_TRUE(levelManager.isFound());
}

