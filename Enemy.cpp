//
// Created by waris on 20/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int s, int sp, int a) :GameCharacter(hp,s,sp), Mage(hp,s,sp),Archer(hp,s,sp),Knight(a,hp,s,sp){
    auto enemyTexture = new sf::Texture;
    enemyTexture->loadFromFile("../Resources/Sprites/Enemy/gargoyle.png");
    setTexture(*enemyTexture);
    setTextureRect(sf::IntRect(0, 64 * 3, 64, 64));
    setOrigin(getPosition().x+getGlobalBounds().width/2,getPosition().y+getGlobalBounds().height/2);
    //setPosition(1200, 1200);
    setScale(sf::Vector2f(3.f, 3.f));
}

/*void Enemy::death(){

    delete this;

}*/
Enemy::~Enemy() {}

/*void Enemy::TakeDamage(int point) {
    life -= point;
    if(life<=0)
        delete this;
}*/