//
// Created by matteo on 10/04/20.
//

#ifndef PROGETTO_PROVA_ENEMY_H
#define PROGETTO_PROVA_ENEMY_H


#include "GameCharacter.h"

class Enemy : public GameCharacter{
public:
    Enemy(int hp, int s, int sp);
    ~Enemy() override;

    void movement(map& level);
    void walkingAnimation();

    sf::Vector2f spawnposition;

private:
    int direction=0;// 1=up,2=down,3=left,4=right
    int walkingRate=0;
    int counterWalking=0;



};


#endif //PROGETTO_PROVA_ENEMY_H
