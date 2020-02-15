//
// Created by andreatadde on 07/02/20.
//

#include <gtest/gtest.h>
#include "../LevelManager.h"
#include <vector>
#include <iostream>

TEST(LevelManager,TestFile){
    const int nFiles = 2;
    std::string levelName[nFiles] = {"Levels_Google_Test/Level1_t","Levels_Google_Test/Level2_t"};
    LevelManager levelManager(levelName,nFiles);
    ASSERT_TRUE(levelManager.isFound());
}

TEST(LevelManager,TestMissingFile){
    const int nFiles = 3;
    std::string levelName[nFiles] = {"Levels_Google_Test/Level1_t","Levels_Google_Test/Level2_t","Levels_Google_Test/Level3_t"};
    LevelManager levelManager(levelName,nFiles);
    ASSERT_FALSE(levelManager.isFound());
    ASSERT_TRUE(levelManager.getNumberOfLevels()<3);
}

TEST(LevelManager,TestCorrupedFile){
    const int nFiles = 2;
    std::string levelName[nFiles] = {"Levels_Google_Test/Level1_t","Levels_Google_Test/Level2_t_corrupted"};
    LevelManager levelManager(levelName,nFiles);
    ASSERT_TRUE(levelManager.getNumberOfLevels()<2);
}