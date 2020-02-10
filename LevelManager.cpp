//
// Created by davide on 29/10/19.
//

#include "LevelManager.h"
#include "stdlib.h"
#include "iostream"

LevelManager::LevelManager(std::string* levelName,const int nFiles) {

    int x;
    levelNumber = 0;
    std::ifstream fileLevel[nFiles];
    for (int i = 0; i < nFiles; i++) {
        fileLevel[i].open(levelName[i]);
        if(!fileLevel[i]){
            found = false;
            std::cerr << "File "<< i+1 <<" non trovato" << std::endl;
            exit(3);
        }
        else{
            found = true;
            levelVector.push_back(&fileLevel[i]);
        }
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
        levelArray = new int[arrayColumn * arrayRow]; //TODO Memory Leak!
        for (int j = 0; j < (arrayColumn * arrayRow); j++) {
            *levelVector[i] >> x;
            levelArray[j] = x;
        }
        vectorArray.push_back(levelArray);
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

    delete levelArray;
    delete currentLevel;
}

int LevelManager::getNumberOfLevels() {
    return levelVector.size();
}

bool LevelManager::isFound() const {
    return found;
}
