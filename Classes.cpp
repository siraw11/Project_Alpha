//
// Created by matteo on 31/10/19.
//

#include "Classes.h"
template<>
Classes<Archer>::Classes(int hp, int s, int sp):Hero(hp, s, sp) {
    auto heroTexture= new sf::Texture;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/archer.png");
    setTexture(*heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));
    setOrigin(getPosition().x +getGlobalBounds().width / 4,getPosition().y +getGlobalBounds().height / 2);
    setPosition(32*32, 32*32);
    setScale(sf::Vector2f(1.f * 2, 1.f * 2));
}
template<>
Classes<Knight>::Classes(int hp, int s, int sp):Hero(hp, s, sp){
    auto heroTexture= new sf::Texture;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/knight.png");
    setTexture(*heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));
    setOrigin(getPosition().x +getGlobalBounds().width / 4,getPosition().y +getGlobalBounds().height / 2);
    setPosition(32*32, 32*32);
    setScale(sf::Vector2f(1.f * 2, 1.f * 2));

}
template<>
Classes<Mage>::Classes(int hp, int s, int sp):Hero(hp, s, sp){
    auto heroTexture= new sf::Texture ;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/mage.png");
    setTexture(*heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));
    setOrigin(getPosition().x +getGlobalBounds().width / 4,getPosition().y +getGlobalBounds().height / 2);
    setPosition(32*32, 32*32);
    setScale(sf::Vector2f(1.f * 2, 1.f * 2));

}
