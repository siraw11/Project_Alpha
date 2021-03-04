//
// Created by matteo on 08/09/20.
//


#include <iostream>
#include "Chest.h"
#include "Item.h"
#include "Weapon.h"


//constructor
Chest::Chest():close(true){


    auto chestTexture = new sf::Texture;
    chestTexture->loadFromFile("../Resources/Sprites/item/chest.png");
    setTexture(chestTexture);
    setTextureRect(sf::IntRect(0,0,32,32));
    setSize(sf::Vector2f(32,32));
    setScale(SCALE*2,SCALE*2);
}

//destructor
Chest::~Chest() = default;


//functions
void Chest::init(int counter) {
    //si setta la posizione all'interno della mappa e ci vengono inseriti i vari item


    switch (counter){
        case 0:{
            Object *generic = new Item(false, false, true, false, false, false);

            elements.push_back(generic);

            posX = 19*32*SCALE;
            posY = 0;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 1 :{
            Object *poison = new Item(false, false, false, false, true, false);
            Object *strength = new Item(true, false, false, false, false, false);

            elements.push_back(strength);
            elements.push_back(poison);

            posX = 59*32*SCALE;
            posY = 0;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 2:{
            Object *generic = new Item(false, false, true, false, false, false);
            Object *weapon = new Weapon(4);

            elements.push_back(generic);
            elements.push_back(weapon);

            posX = 99*32*SCALE;
            posY = 0;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }

        case 3:{
            Object *exhaust = new Item(false, true, false, false, false, false);
            Object *life = new Item(false, false, false, true, false, false);


            elements.push_back(exhaust);
            elements.push_back(life);

            posX = 32*SCALE;
            posY = (61/2)*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 4:{
            Object *exhaust = new Item(false, true, false, false, false, false);
            Object *poison = new Item(false, false, false, false, true, false);


            elements.push_back(exhaust);
            elements.push_back(poison);

            posX = 118*32*SCALE;
            posY = (61/2)*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 5:{
            Object *generic = new Item(false, false, true, false, false, false);
            Object *weapon = new Weapon(5);


            elements.push_back(generic);
            elements.push_back(weapon);

            posX = 20*32*SCALE;
            posY = 60*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 6:{
            Object *generic = new Item(false, false, true, false, false, false);
            Object *life = new Item(false, false, false, true, false, false);
            Object *weapon = new Weapon(6);


            elements.push_back(generic);
            elements.push_back(life);
            elements.push_back(weapon);

            posX = 99*32*SCALE;
            posY = 60*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
        case 7:{
            Object *key = new Item(false, false, false, false, false, true);
            Object *strength = new Item(true, false, false, false, false, false);
            Object *sword = new Weapon(8);

            elements.push_back(key);
            elements.push_back(strength);
            elements.push_back(sword);

            posX = 59*32*SCALE;
            posY = 70*32*SCALE;

            setPosition(sf::Vector2f(posX,posY));
            break;
        }
    }
}


void Chest::open(Hero* hero, std::vector<Tile>* tile_vector) {
    this->setClose(false);
    for (auto i : elements){
            i->use(hero, tile_vector);
        }
       if(!elements.empty())
            for(auto i = elements.end(); i != elements.end(); ++i)
                this->elements.erase(i);
}

void Chest::setClose(bool close) {
    Chest::close = close;
}

void Chest::openingAnimation() {

    if(counterOpening == 0)
        openingSound.play();
    counterOpening++;
    setTextureRect(sf::IntRect(0,32*counterOpening,32,32));
}

void Chest::initSound(const Alpha::GameDataRef &_data) {

    openingSound.setBuffer(_data->assets.GetSound("Chest"));


}



