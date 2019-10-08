//
// Created by andreatadde on 18/09/19.
//

#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "Object.h"
#include "Animation.h"

//Classe derivata per nemici e per il player implementa il movimento e le animazioni
class GameCharacter : public Object {
public:
    GameCharacter();

    float getMoveSpeed() const;//getter velocità
    void setMoveSpeed(float moveSpeed);//setter velocità
    void setAnimation(const std::string &textureDir, unsigned int xFrames, unsigned int yFrames);//setta l'animazione
    bool isOnGround;
    sf::Vector2f velocity;
protected:
    int HP; //TODO implement Hp

    // Movement parameters
    float moveSpeed;
    float jumpPower;

    // Gravity parameters
    float gravityAcc;
    float gravityMax;

    // Animation parameters
    Animation animation;
    bool facingRight;
    int row;
    float switch_time = 1.f;
};


#endif //GAME_GAMECHARACTER_H
