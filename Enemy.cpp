//
// Created by matteo on 10/04/20.
//


#include "GameManager/DEFINITIONS.hpp"
#include "Enemy.h"
#include "Random.h"
#include "Collision.h"


///constructor
Enemy::Enemy(int hp, int s, int sp) : GameCharacter(hp, s, sp) {

    auto enemyTexture = new sf::Texture;
    enemyTexture->loadFromFile("../Resources/Sprites/Enemy/orc(warhammer).png");
    setTexture(enemyTexture);
    setTextureRect(sf::IntRect(0,64*3,64,64));

    setScale(sf::Vector2f(ENEMY_SCALE,ENEMY_SCALE));
}


///destructor
Enemy::~Enemy() = default;

///functions

void Enemy::movement(const std::vector<Tile>& tile_vector, Hero &hero, const std::vector<Chest>& chest_vector) {

    //make the enemy move in random direction for n steps
    if(walkingRate==24)
    {
        direction=generateRandom(4);
        walkingRate=0;
    }else{
        walkingRate++;
    }

    //setting direction
    int x=0;
    int y=0;
    if(direction==1){//up
        x=0;
        y=-1;
    }else if(direction==2){//left
        x=-1;
        y=0;
    }else if(direction==3){//down
        x=0;
        y=1;
    } else if(direction==4){//right
        x=1;
        y=0;
    }

    sf::Vector2f movement(getSpeed()*x,getSpeed()*y);
    bool collided=false;
    if(Collision::checkCollision(const_cast<std::vector<Tile> &>(tile_vector),this, x, y)){
        movement.x=0;
        movement.y=0;
        collided=true;
    }else if( getPosition().x==spawnposition.x+(ENEMY_WALK_DISTANCE*x) && getPosition().y==spawnposition.y+(ENEMY_WALK_DISTANCE*y)){//check collision
        movement.x=0;
        movement.y=0;
        collided=true;
    }else if(Collision::heroCollision(this, hero, x, y)){
        movement.x=0;
        movement.y=0;
        collided=true;
    }else{

        for( const Chest& i : chest_vector)
            if(Collision::chestCollision( i, this, x, y )){
                movement.x=0;
                movement.y=0;
                collided=true;
                break;
            }
    }
    if(!collided) {

        walkingAnimation();
    }
    move(movement);


}

void Enemy::walkingAnimation() {
    int d=direction-1;
    if(counterWalking!=8){
        setTextureRect(sf::IntRect(64*counterWalking,64*d,64,64));
        counterWalking++;
    }else{
        counterWalking=0;
    }

}

void Enemy::deathAnimation() {
    setTextureRect(sf::IntRect(64*counterDeath,64*8,64,64));
    counterDeath++;
}
