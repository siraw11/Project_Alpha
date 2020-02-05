//
// Created by davide on 29/10/19.
//

#ifndef GAME_LEVELMENAGER_H
#define GAME_LEVELMENAGER_H
#define arrayRow 13
#define arrayColumn 50

#include "Level.h"
#include "fstream"
#include "vector"

class LevelManager {
public:
    LevelManager();
    virtual ~LevelManager();

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

    int getNumberOfLevels();
private:
    std::vector<int *> vectorArray;
};


#endif //GAME_LEVELMENAGER_H
