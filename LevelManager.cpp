//
// Created by davide on 29/10/19.
//

#include "LevelManager.h"
#include "stdlib.h"
#include "iostream"

LevelManager::LevelManager() {
    int x;
    levelNumber = 0;
    std::ifstream fileLevel1("Levels/Level1");
    std::ifstream fileLevel2("Levels/Level2");
    if (!fileLevel1) {

        std::cout << "File 1 non trovato" << std::endl;
        exit(3);
    } else {
        levelVector.push_back(&fileLevel1);
    }
    if (!fileLevel2) {

        std::cout << "File 2 non trovato" << std::endl;
        exit(3);
    } else {
        levelVector.push_back(&fileLevel2);
    }

    for (int j = 0; j < levelVector.size(); j++) {
        for (int i = 0; i < (arrayColumn * arrayRow); i++) {
            *levelVector[j] >> x;
            if (!levelVector[j]->good()) {
                std::cout << "Il file di Level " << j + 1 << " è corrotto" << std::endl;
                levelVector.erase(levelVector.begin() + j);
                exit(3);
            }
        }
    }
    buildLevel();
    currentLevel = new Level(levelArray0, arrayColumn, arrayRow);
}

void LevelManager::buildLevel() {
    int x;
    for (int i = 0; i < levelVector.size(); i++) {
        levelVector[i]->seekg(0, std::ios::beg);
        levelVector[i]->clear();
        for (int j = 0; j < (arrayColumn * arrayRow); j++) {
            *levelVector[i] >> x;
            if (i == 0)
                levelArray0[j] = x;
            if (i == 1) {
                levelArray1[j] = x;
            }
        }
    }

}
void LevelManager::resetLevel() {
    int x;
    delete currentLevel;
    if (levelNumber == 0)
        currentLevel = new Level(levelArray0, arrayColumn, arrayRow);
    if (levelNumber == 1)
        currentLevel = new Level(levelArray1, arrayColumn, arrayRow);
    currentLevel->reset= false;

}
void LevelManager::nextLevel() {
    levelNumber++;
    resetLevel();
}

int LevelManager::getLevelNumber() const {
    return levelNumber;
}

void LevelManager::setLevelNumber(int n){
    levelNumber = n;
}

LevelManager::~LevelManager() {
    delete currentLevel;
}


