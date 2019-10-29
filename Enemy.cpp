//
// Created by waris on 20/06/19.
//

#include <iostream>
#include "Enemy.h"
#include "Random.h"

Enemy::Enemy(int hp, int s, int sp, int a) :GameCharacter(hp,s,sp), Mage(hp,s,sp),Archer(hp,s,sp),Knight(a,hp,s,sp){
    auto enemyTexture = new sf::Texture;
    enemyTexture->loadFromFile("../Resources/Sprites/Enemy/skeleton2.png");
    setTexture(*enemyTexture);
    setTextureRect(sf::IntRect(0,64*3,64,64));
    setOrigin(getPosition().x+getGlobalBounds().width/5,getPosition().y+getGlobalBounds().height/2);
    setScale(sf::Vector2f(3.f, 3.f));

}


//Enemy::~Enemy() {}

void Enemy::movement(int *level){
    //enemy movement, random direction
    if(walkingRate==24)
    {
        direction= generateRandom(4);//1=right, 2=down, 3=left, 4=up
        walkingRate=0;
    }
    else{
        walkingRate++;
    }
    int x, y;

    //right movement
    if(getPosition().x!=spawnPosition.x+64*5 && direction==1 && counterDeath==0) {
        x = (int) ((getPosition().x) / 32 / 3) + 1;
        y = (int) (getPosition().y) / 32 / 3;
        if (level[120 * y + x] == 0) {
            move(32, 0);
            setTextureRect(sf::IntRect(64 * counterWalking, 64 * 3, 64, 64));
        }
    }
    //down movement
    if(getPosition().y!=spawnPosition.y+64*5 && direction==2 && counterDeath==0){
        x = (int) (getPosition().x) / 32 / 3;
        y = (int) ((getPosition().y) / 32 / 3) + 1;
        if (level[120 * y + x] == 0) {
            move(0, 32);
            setTextureRect(sf::IntRect(64 * counterWalking, 64 * 2, 64, 64));
        }
    }
    //left movement
    if(getPosition().x!=spawnPosition.x-64*5 && direction==3 && counterDeath==0) {
        x = (int) ((getPosition().x - 1) / 32 / 3);
        y = (int) (getPosition().y) / 32 / 3;
        if (level[120 * y + x] == 0) {
            move(-32, 0);
            setTextureRect(sf::IntRect(64 * counterWalking, 64, 64, 64));
        }
    }//
    //up movement
    if(getPosition().y!=spawnPosition.y-64*5 && direction==4 && counterDeath==0){
        x = (int) (getPosition().x) / 32 / 3;
        y = (int) ((getPosition().y - 1) / 32 / 3);
        if (level[120 * y + x] == 0) {
            move(0, -32);
            setTextureRect(sf::IntRect(64 * counterWalking, 0, 64, 64));
        }
    }

    if(counterWalking==8){
        counterWalking=0;
        direction=0;
    }else{
        counterWalking++;
    }


}