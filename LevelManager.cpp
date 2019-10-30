//
// Created by davide on 29/10/19.
//

#include "LevelManager.h"
#include "stdlib.h"
#include "iostream"

LevelManager::LevelManager(GameLogic* gameLogic) {

    logic=gameLogic;
    currentLevel=new Level(levelArray1, arrayColumn, arrayRow, logic);
    levelNumber=1;
}

void LevelManager::resetLevel() {

    delete currentLevel;
    if(levelNumber==1){
        Level* levelS= new Level(levelArray1, arrayColumn, arrayRow, logic);
        currentLevel=levelS;
    }
    if(levelNumber>=2){
        Level *level = new Level(levelArray2, arrayColumn, arrayRow, logic);
        currentLevel=level;
    }
    currentLevel->reset= false;
}
void LevelManager::nextLevel() {
    levelNumber++;
    resetLevel();
}