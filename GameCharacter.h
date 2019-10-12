
#ifndef GAME_GAMECHARACTER_H
#define GAME_GAMECHARACTER_H

#include "RectangleShape.h"
#include "Animation.h"

//Classe derivata per nemici e per il player implementa il movimento e le animazioni
class GameCharacter : public RectangleShape {
public:
    GameCharacter();

    float getMoveSpeed() const;//getter velocità
    void setMoveSpeed(float moveSpeed);//setter velocità
    void setAnimation(const std::string &textureDir, unsigned int xFrames, unsigned int yFrames);//setta l'animazione
    bool isOnGround;
    sf::Vector2f velocity;
protected:

    // Movement parameters
    float moveSpeed;
    float jumpPower;

    // Gravity parameters
    float gravityAcc;
    float gravityMax;

    // Animation parameters
    Animation animation;
public:
    virtual ~GameCharacter();

protected:
    bool facingRight;
    int row;
    float switch_time = 1.f;
};


#endif //GAME_GAMECHARACTER_H
