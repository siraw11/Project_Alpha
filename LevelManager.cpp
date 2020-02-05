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
        std::cerr << "File 1 non trovato" << std::endl;
        exit(3);
    } else {
        levelVector.push_back(&fileLevel1);
    }
    if (!fileLevel2) {
        std::cerr << "File 2 non trovato" << std::endl;
        exit(3);
    } else {
        levelVector.push_back(&fileLevel2);
    }

    for (int j = 0; j < levelVector.size(); j++) {
        for (int i = 0; i < (arrayColumn * arrayRow); i++) {
            *levelVector[j] >> x;
            if (!levelVector[j]->good()) {
                std::cerr << "Il file di Level " << j + 1 << " è corrotto" << std::endl;
                exit(3);
            }
        }
    }

    for (int i = 0; i < levelVector.size(); i++) {
        levelVector[i]->seekg(0, std::ios::beg);
        levelVector[i]->clear();
        int *levelArray0 = new int[arrayColumn * arrayRow];
        for (int j = 0; j < (arrayColumn * arrayRow); j++) {
            *levelVector[i] >> x;
            levelArray0[j] = x;
        }
        vectorArray.push_back(levelArray0);
    }
    currentLevel = new Level(vectorArray[levelNumber], arrayColumn, arrayRow);
}

void LevelManager::resetLevel() {
    delete currentLevel;
    currentLevel = new Level(vectorArray[levelNumber], arrayColumn, arrayRow);
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

int LevelManager::getNumberOfLevels() {
    int n = levelVector.size();

    return n;
}
