//
// Created by davide on 29/10/19.
//

#include "LevelManager.h"
#include "stdlib.h"
#include "iostream"

LevelManager::LevelManager() {
    int x;
    levelNumber=1;
    fileLevel1.open("Level1");
    if(!fileLevel1){
        std::cout<<"File non trovato"<<std::endl;
    }
    for(int i=0;i<(arrayColumn*arrayRow);i++){
        fileLevel1>>x;
        levelArray1[i]=x;
    }
    fileLevel1.close();
    fileLevel2.open("Level2");
    if(!fileLevel2){
        std::cout<<"File non trovato"<<std::endl;
    }
    for(int i=0;i<(arrayColumn*arrayRow);i++){
        fileLevel2>>x;
        levelArray2[i]=x;
    }
    fileLevel2.close();

    currentLevel = new Level(levelArray1, arrayColumn, arrayRow);
}

void LevelManager::resetLevel() {
    delete currentLevel;
    if(levelNumber==1){
        currentLevel = new Level(levelArray1, arrayColumn, arrayRow);
    }
    if(levelNumber>=2){
        currentLevel =new Level(levelArray2, arrayColumn, arrayRow);
    }
    currentLevel->reset= false;
}
void LevelManager::nextLevel() {
    levelNumber++;
    resetLevel();
}

int LevelManager::getLevelNumber() const {
    return levelNumber;
}
