#include <iostream>
#include <SFML/Graphics.hpp>
#include <zconf.h>
#include "Archer.h"
#include "GameCharacter.h"
#include "Enemy.h"
#include "Hero.h"
#include "Item.h"
#include "Knight.h"
#include "Mage.h"
#include "Weapon.h"
/*
#include "Map.h"
#include "Boss.h"
#include "Chest.h"
#include "Tile.h"

 */

//enum class GameEvent {
 //   quit, left, up, down, right, fight, noop
//};

/*GameEvent getEvent(){


    char c;
    while(std::cin.get(c)){
        std::cin.ignore(100,'\n');
        switch(c){
            case 'Q':
                return GameEvent::quit;
            case 'w':
                return GameEvent::up;
            case 'a':
                return GameEvent::left ;
            case 's':
                return GameEvent::down;
            case 'd':
                return GameEvent::right;
            case 'f':
                return GameEvent::fight;
            default:
                return GameEvent::noop;
        }
    }
    return GameEvent::noop;
}


bool updateGame(const GameEvent &gameEvent, Hero &hero, Enemy &enemy, const Map &map){
    switch (gameEvent) {
        case GameEvent::quit: //
            return true;
        case GameEvent::up: {
            hero.Move(0,-1);
            break;
        }
        case GameEvent::left:{
            hero.Move(-1,0);
            break;
        }
        case GameEvent::down:{
            hero.Move(0,1);
            break;
        }
        case GameEvent::right:{
            hero.Move(1,0);
            break;
        }
        case GameEvent::fight:{
            hero.fight(enemy)//TODO:fix it setting class fight
            break;
        }
        case GameEvent::noop:{
            std::cout<<"Press: w,a,s,d,f or Q to quit"<<std::endl;
            break;
        }
    }
    return false;

}*/

int main() {


        sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Project_Alpha");
        Hero hero(3,5,1,1);
        hero.setPosition(100,100);
        auto heroTexture = new sf::Texture;
        heroTexture->loadFromFile("Sprites/luca.png");
        hero.setTexture(*heroTexture);
        hero.setScale(sf::Vector2f(2.f,2.f));
        hero.setTextureRect(sf::IntRect(32,0,32,32));
        int counterWalking=0;



        while (window.isOpen())
        {
            sf::Event event{};
            while (window.pollEvent(event))
            {
                if(event.type==sf::Event::Closed)
                    window.close();
                if(event.type==sf::Event::Resized){
                    sf::View temp=window.getView();
                    temp.setSize(window.getSize().x,window.getSize().y);
                    window.setView(temp);
                }

            }

            window.clear(sf::Color::Black);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                hero.move(0,-hero.getSpeed());

                hero.setTextureRect(sf::IntRect(32*counterWalking,32*3,32,32));

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                hero.move(0,hero.getSpeed());

                hero.setTextureRect(sf::IntRect(32*counterWalking,0,32,32));

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                hero.move(-hero.getSpeed(),0);

                hero.setTextureRect(sf::IntRect(32*counterWalking,32,32,32));

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

            {
                hero.move(hero.getSpeed(),0);

                hero.setTextureRect(sf::IntRect(32*counterWalking,32*2,32,32));

            }

            counterWalking++;
            if(counterWalking ==2)
            {counterWalking = 0;
            }

            window.draw(hero);
            window.display();



        }
        return 0;
    }




