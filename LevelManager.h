//
// Created by davide on 29/10/19.
//

#ifndef GAME_LEVELMENAGER_H
#define GAME_LEVELMENAGER_H
#define arrayRow 13
#define arrayColumn 50
#define numberOfLevels 2

#include "Level.h"
#include "fstream"
#include "vector"

class LevelManager {
public:
    LevelManager();
    virtual ~LevelManager();

    void buildLevel();
    void resetLevel();
    void nextLevel();
public:
    Level* currentLevel;

private:
    int levelNumber;
    std::vector<std::ifstream *> levelVector;
public:
    int getLevelNumber() const;
    void setLevelNumber(int n);
private:
    int levelArray0[arrayColumn * arrayRow];
    int levelArray1[arrayColumn * arrayRow];
};


#endif //GAME_LEVELMENAGER_H
