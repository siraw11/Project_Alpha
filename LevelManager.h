//
// Created by davide on 29/10/19.
//

#ifndef GAME_LEVELMENAGER_H
#define GAME_LEVELMENAGER_H
#define arrayRow 13
#define arrayColumn 50

#include "Level.h"
#include "fstream"

class LevelManager {
public:
    LevelManager();
    void resetLevel();
    void nextLevel();
public:
    Level* currentLevel;

private:
    std::ifstream fileLevel1;
    std::ifstream fileLevel2;
    int levelNumber;
public:
    int getLevelNumber() const;
    void setLevelNumber(int n);
private:
    int levelArray1[arrayColumn * arrayRow];
    int levelArray2[arrayColumn * arrayRow];
};


#endif //GAME_LEVELMENAGER_H
