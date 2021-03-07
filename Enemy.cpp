#include <cmath>

//
// Created by matteo on 10/04/20.
//


#include "GameManager/DEFINITIONS.hpp"
#include "Enemy.h"
#include "Random.h"
#include "Collision.h"
#include <cmath>


//constructor
Enemy::Enemy(int hp, int s, int sp) : GameCharacter(hp, s, sp) {

    auto enemyTexture = new sf::Texture;
    enemyTexture->loadFromFile("./Resources/Sprites/Enemy/orc(warhammer).png");
    setTexture(enemyTexture);
    setTextureRect(sf::IntRect(0,64*3,64,64));

    setScale(sf::Vector2f(ENEMY_SCALE,ENEMY_SCALE));

    heroHitted = false;
}


//destructor
Enemy::~Enemy() = default;

//functions

void Enemy::movement(const std::vector<Tile>& tile_vector, Hero &hero, const std::vector<Chest>& chest_vector) {

    auto d = hero.getPosition() - this->getPosition();
    float distanza = std::sqrt((d.x*d.x) + (d.y*d.y));
    d /= distanza;


    if(this->getPosition().x!= hero.getPosition().x && distanza<600){ //enemy aggro
        movementvect.x = getSpeed()*d.x;
        movementvect.y = getSpeed()*d.y;
        aggro(d);
    }
    //make the enemy move in random direction for n steps
    else if(walkingRate == 24){

        direction = generateRandom(4);
        walkingRate = 0;
    }else{
        movementvect.x = getSpeed()*walkingDirection().x;
        movementvect.y = getSpeed()*walkingDirection().y;
        walkingRate++;
    }


    bool collided = false;
    if(hero.getLife()<=0){
        movementvect.x = 0;
        movementvect.y = 0;
        collided = true;
    }else if(dead){
        movementvect.x = 0;
        movementvect.y = 0;
    }else if(Collision::checkCollision( const_cast<std::vector<Tile> &>(tile_vector),this, walkingDirection().x, walkingDirection().y )){
        movementvect.x = 0;
        movementvect.y = 0;
        collided = true;
    }else if( getPosition().x == spawnposition.x + (ENEMY_WALK_DISTANCE*walkingDirection().x) && getPosition().y == spawnposition.y + (ENEMY_WALK_DISTANCE*walkingDirection().y)){//check collision
        movementvect.x = 0;
        movementvect.y = 0;
        collided = true;
    }else if(Collision::heroCollision( this, hero, walkingDirection().x, walkingDirection().y )){
        movementvect.x = 0;
        movementvect.y = 0;
        hero.hit = true;
        this->heroHitted = true;
        collided = true;
    }else{
        for( const Chest& i : chest_vector)
            if(Collision::chestCollision( i, this, walkingDirection().x, walkingDirection().y )){
                movementvect.x = 0;
                movementvect.y = 0;
                collided = true;
                break;
            }
    }
    if(!collided) {
        walkingAnimation();
    }

    move(movementvect);


}

void Enemy::walkingAnimation() {
    int d = direction-1;
    if(counterWalking != 8){
        setTextureRect(sf::IntRect(64*counterWalking,64*d,64,64));
        counterWalking++;
    }else{
        counterWalking = 0;
    }

}

void Enemy::deathAnimation() {
    setTextureRect(sf::IntRect(64*counterDeath,64*4,64,64));
    counterDeath++;
}

sf::Vector2i Enemy::walkingDirection() {
    sf::Vector2i walkingDirection;
    switch(direction){
        case 1: {
            walkingDirection.x = 0;
            walkingDirection.y = -1;
            break;
        }
        case 2: {
            walkingDirection.x = -1;
            walkingDirection.y = 0;
            break;
        }
        case 3: {
            walkingDirection.x = 0;
            walkingDirection.y = 1;
            break;
        }
        case 4: {
            walkingDirection.x = 1;
            walkingDirection.y = 0;
            break;
        }
    }

    return walkingDirection;
}

void Enemy::aggro(sf::Vector2f d) {

    if(d.x < 0){
        direction = 2;
    }else {
        direction = 4;
    }
}

void Enemy::update(std::unique_ptr<Hero>& hero, const std::vector<Tile> &tile_vector, const std::vector<Chest> &chest_vector) {
    movement(tile_vector, *hero, chest_vector);
    if(this->hit) {
        monsterHitSound.play();
        if(hero->playerType == PlayerType::KNIGHT)
            move(60*hero->direction().x,60*hero->direction().y);

        takeDamage(hero->damage());
        hit = false;
    }
    if(getLife()<=0){
        dead = true;
        deathAnimation();
    }

}

void Enemy::initSound(const Alpha::GameDataRef &_data) {
    monsterHitSound.setBuffer(_data->assets.GetSound("MonsterHit"));

}


