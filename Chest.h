//
// Created by matteo on 21/08/20.
//

#ifndef PROJECT_ALPHA_CHEST_H
#define PROJECT_ALPHA_CHEST_H


#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include "GameManager/DEFINITIONS.hpp"


template<typename T, int N=5>
        class Chest : public sf::RectangleShape{
public:
    Chest(bool w);
    ~Chest() override;

    void init(int counter);
    void open();

private:
    std::vector<T> elements;
    bool weapon;
    bool close;
    int posX{};
    int posY{};

};

template<typename T, int N>
void Chest<T, N>::open() {
    close=false;
}

template<typename T, int N>
void Chest<T, N>::init(int counter) {
    //si setta la posizione all'interno della mappa e ci vengono inseriti i vari item
    switch(counter){
        case 0 :{
            if(!weapon){
                posX=20*32*SCALE;
                posY=32*SCALE;
                //todo:metterci dentro 1 pozione generica e 2 pozioni buff
            }else{
                setFillColor(sf::Color::Green);
                posX=100*32*SCALE;
                posY=32*SCALE;
                //todo:metterci dentro un arma di potenza 2
            }
            setPosition(sf::Vector2f(posX,posY));
            setScale(SCALE,SCALE);
            break;
        }

        case 1 :{
            if(!weapon){
                posX=60*32*SCALE;
                posY=32*SCALE;
                //todo:metterci dentro una generica e 1 nerf
            }else{
                setFillColor(sf::Color::Green);
                posX=20*32*SCALE;
                posY=61*32*SCALE;
                //todo:metterci dentro un arma di forza 3
            }
            setPosition(sf::Vector2f(posX,posY));
            setScale(SCALE,SCALE);
            break;
        }
        case 2 :{
            posX=32*SCALE;
            posY=(63/2)*32*SCALE;
            //todo:metterci dentro una generica e 2 buff;
            setPosition(posX,posY);
            setScale(SCALE,SCALE);
            break;
        }
        case 3:{
            posX=118*32*SCALE;
            posY=(63/2)*32*SCALE;
            //todo:metterci una generica , 1 danno, 1 nerf
            setPosition(posX,posY);
            setScale(SCALE,SCALE);
            break;
        }
        case 4:{
            posX=100*32*SCALE;
            posY=61*32*SCALE;
            //todo:metterci una generica, 2 buff
            setPosition(posX,posY);
            setScale(SCALE,SCALE);
            break;
        }
        case 5:{
            posX=60*32*SCALE;
            posY=82*32*SCALE;
            //todo:due generiche, la chiave
            setPosition(posX,posY);
            setScale(SCALE,SCALE);
            break;
        }
    }
}

template<typename T, int N>
Chest<T, N>::Chest(bool w): close(true){
    weapon=w;
    setSize(sf::Vector2f(32,32));
    setFillColor(sf::Color::Cyan);


}

template<typename T, int N>
Chest<T, N>::~Chest() = default;


#endif //PROJECT_ALPHA_CHEST_H
