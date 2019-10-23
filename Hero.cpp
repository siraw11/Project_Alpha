//
// Created by waris on 20/06/19.
//

#include "Hero.h"


Hero::Hero(int a,int hp, int s, float sp, PlayerType playerType):GameCharacter(hp,s,sp),Knight(a,hp,s,sp),Archer(hp,s,sp),Mage(hp,s,sp), item(nullptr){

    auto heroTexture = new sf::Texture;
    switch(playerType){
        case PlayerType ::ARCHER:
            heroTexture->loadFromFile("../Resources/Sprites/Hero/archer.png");
            setTexture(*heroTexture);
            break;
        case PlayerType::KNIGHT:
            heroTexture->loadFromFile("../Resources/Sprites/Hero/knight.png");
            setTexture(*heroTexture);
            break;
        case PlayerType ::MAGE:
            heroTexture->loadFromFile("../Resources/Sprites/Hero/mage.png");
            setTexture(*heroTexture);
    }

    setTextureRect(sf::IntRect(0, 128, 64, 64));
    setOrigin(getPosition().x +getGlobalBounds().width / 4,getPosition().y +getGlobalBounds().height / 2);
    setPosition(32*32, 32*32);
    setScale(sf::Vector2f(1.f * 2, 1.f * 2));
}

Item *Hero::getItem() const {
    return item;
}

void Hero::setItem(Item *item) {
    Hero::item = item;
}



