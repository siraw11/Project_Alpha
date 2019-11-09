//
// Created by davide on 29/10/19.
//

#include "LevelManager.h"
#include "stdlib.h"
#include "iostream"

LevelManager::LevelManager() {
    currentLevel = new Level(levelArray1, arrayColumn, arrayRow);
    levelNumber=1;
}

void LevelManager::resetLevel() {
    delete currentLevel;
    if(levelNumber==1){
        Level *levelS = new Level(levelArray1, arrayColumn, arrayRow);
        currentLevel=levelS;
    }
    if(levelNumber>=2){
        Level *level = new Level(levelArray2, arrayColumn, arrayRow);
        currentLevel=level;
    }
    currentLevel->reset= false;
}
void LevelManager::nextLevel() {
    levelNumber++;
    resetLevel();
}