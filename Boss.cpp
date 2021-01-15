//
// Created by matteo on 18/08/20.
//


#include "GameManager/DEFINITIONS.hpp"
#include "Boss.h"
#include "Random.h"
#include "Collision.h"
#include <cmath>

///cosntructor
Boss::Boss(int hp, int s, int sp) : Enemy(hp, s, sp) {

    posx = (MAP_WIDTH/2)*SCALE;// centro della mappa
    posy = (MAP_HEIGHT/2.9)*SCALE;//centro della stanza del boss

    setPosition(posx,posy);

    auto bossTexture = new sf::Texture;
    bossTexture->loadFromFile("../Resources/Enemy/boss.png");
    setTexture(bossTexture);
    setTextureRect(sf::IntRect(0,64*3,64,64));

    setScale(BOSS_SCALE,BOSS_SCALE);

    dead = false;
}

///functions
void Boss::movement(const std::vector<Tile> &tile_vector, Hero &hero, const std::vector<Chest> &chest_vector) {
    auto d = hero.getPosition() - this->getPosition();
    float distanza = std::sqrt((d.x*d.x) + (d.y*d.y));
    d /= distanza;

    sf::Vector2f movement;

    //make the boss move in random direction for n steps
    if(walkingRate == 24 && distanza > 800){
        direction = generateRandom(4);
        walkingRate = 0;
    }else{
        movement.y = getSpeed()*walkingDirection().y;
        walkingRate++;
    }

    bool collided=false;
    if(distanza < 800){ //the boss stop moving and start shooting projectile
        movement.x = 0;
        movement.y = 0;

        collided = true;
    }else if(dead){
        movement.x = 0;
        movement.y = 0;
    }else if( Collision::checkCollision(const_cast<std::vector<Tile> &>(tile_vector),this, walkingDirection().x, walkingDirection().y )){
        movement.x = 0;
        movement.y = 0;
        collided = true;
    }else if( getPosition().x==spawnposition.x+(ENEMY_WALK_DISTANCE*walkingDirection().x ) && getPosition().y==spawnposition.y+(ENEMY_WALK_DISTANCE*walkingDirection().y )){//check collision
        movement.x = 0;
        movement.y = 0;
        collided = true;
    }else if( Collision::heroCollision(this, hero, walkingDirection().x, walkingDirection().y )){
        movement.x = 0;
        movement.y = 0;
        hero.hit = true;
        this->heroHitted = true;
        collided = true;
    }else{
        for(const Chest& i : chest_vector)
            if( Collision::chestCollision( i, this, walkingDirection().x, walkingDirection().y )){
                movement.x = 0;
                movement.y = 0;
                collided = true;
                break;
            }
    }
    if(!collided) {
        walkingAnimation();
    }
    move(movement);
}



void Boss::update( Hero hero, const std::vector<Tile>& tile_vector, const std::vector<Chest>& chest_vector ) {
    auto d = hero.getPosition() - this->getPosition();
    float distance = std::sqrt((d.x*d.x) + (d.y*d.y));

    this->movement(tile_vector, hero, chest_vector);

    if(distance < 800)
        if(attackRate==20){
            if (counterAttack == 11){
                this->attack(hero);
                this->counterAttack = 0;
                this->attackRate=0;
            } else {
                this->aggro(d);
                counterAttack++;
            }
        } else {
            attackRate++;
        }

    //boss projectile update
    if(!projectile_vector.empty())
        for(auto &i : projectile_vector)
            i.updatePosition();

    //boss damage
    if(this->hit)
    {
        this->takeDamage(hero.damage());
        this->hit = false;
    }

    if(this->getLife() <= 0){
        this->dead = true;
        this->deathAnimation();
        if(this->counterDeath == 11){
            //todo: si deve vincere
        }
    }
}


//boss attack
void Boss::attack(const Hero& hero) {
   sf::Vector2f d;
    d.x = hero.getPosition().x - (this->getPosition().x);
    d.y = hero.getPosition().y - (this->getPosition().y + getGlobalBounds().height/10 * BOSS_SCALE);
    float distance = std::sqrt((d.x*d.x) + (d.y*d.y));
    d /= distance;

    Projectile newProjectile(PlayerType::BOSS);
    newProjectile.projectile_start.x = getPosition().x;
    newProjectile.projectile_start.y = getPosition().y + getGlobalBounds().height/10 * BOSS_SCALE;
    newProjectile.direction = 4;
    newProjectile.directionVector.x = d.x;
    newProjectile.directionVector.y = d.y;
    newProjectile.init();
    projectile_vector.push_back(newProjectile);
}

void Boss::aggro(sf::Vector2f d) {
    if(d.x < 0){
        this->setTextureRect(sf::IntRect(64*counterAttack,64*4,64,64));
    } else {
        this->setTextureRect(sf::IntRect(64*counterAttack,64*5,64,64));
    }
}



///destructor
Boss::~Boss() = default;
