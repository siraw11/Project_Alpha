//
// Created by matteo on 08/09/20.
//


#include <iostream>
#include "Chest.h"
#include "Item.h"
#include "Weapon.h"


///constructor
Chest::Chest():close(true){


    auto chestTexture = new sf::Texture;
    chestTexture->loadFromFile("../Resources/Sprites/item/chest.png");
    setTexture(chestTexture);
    setTextureRect(sf::IntRect(0,0,32,32));
    setSize(sf::Vector2f(32,32));
    setScale(SCALE*2,SCALE*2);




}

///destructor
Chest::~Chest() = default;


///functions
void Chest::init(int counter) {
    //si setta la posizione all'interno della mappa e ci vengono inseriti i vari item


    switch (counter){
        case 0:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(8);

            elements.push_back(potion);
            elements.push_back(sword);

            posX=19*32*SCALE;
            posY=0;

            setPosition(sf::Vector2f(posX,posY));
            break;

        }
        case 1 :{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=59*32*SCALE;
            posY=0;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 2:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=99*32*SCALE;
            posY=0;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }

        case 3:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=32*SCALE;
            posY=(61/2)*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 4:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=118*32*SCALE;
            posY=(61/2)*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 5:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=20*32*SCALE;
            posY=60*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 6:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=99*32*SCALE;
            posY=60*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 7:{
            Object *potion = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(2);


            elements.push_back(potion);
            elements.push_back(sword);

            posX=59*32*SCALE;
            posY=70*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
    }



}


void Chest::open(Hero* hero) {
    this->setClose(false);
    for (auto i : elements){
            i->use(hero);
        }

       if(!elements.empty())
            for(auto i=elements.end(); i!=elements.end(); ++i)
                this->elements.erase(i);
}

void Chest::setClose(bool close) {
    Chest::close = close;
}

void Chest::openingAnimation() {
    counterOpening++;
    setTextureRect(sf::IntRect(0,32*counterOpening,32,32));
}



