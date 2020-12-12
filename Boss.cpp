//
// Created by matteo on 18/08/20.
//


#include "GameManager/DEFINITIONS.hpp"
#include "Boss.h"


///cosntructor
Boss::Boss(int hp, int s, int sp) : Enemy(hp, s, sp) {

    posx=(MAP_WIDTH/2)*SCALE;// centro della mappa
    posy=(MAP_HEIGHT/2.9)*SCALE;//centro della stanza del boss

    setPosition(posx,posy);

    auto bossTexture = new sf::Texture;
    bossTexture->loadFromFile("../Resources/Sprites/Enemy/boss.png");
    setTexture(bossTexture);
    setTextureRect(sf::IntRect(0,64*3,64,64));

    setScale(BOSS_SCALE,BOSS_SCALE);


}

///destructor
Boss::~Boss() = default;
