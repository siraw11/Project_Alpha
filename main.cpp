#include <iostream>
#include <SFML/Graphics.hpp>
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
        sf::CircleShape shape(400.f);
        Hero hero(3,5,1,1);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(600,500);


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
                if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::RShift)
                        hero.Move(1,2);
                    if(event.key.code== sf::Keyboard::Tab)
                        shape.move(sf::Vector2f(-30.f,30.f));
                    if(event.key.code == sf::Keyboard::A )
                        hero.Move(-10,0);
                    if(event.key.code== sf::Keyboard::S)
                        hero.Move(0,10);
                    if(event.key.code== sf::Keyboard::D)
                        hero.Move(10,0);
                    if(event.key.code==sf::Keyboard::W)
                        hero.Move(0,-10);

                }
            }

            window.clear(sf::Color::White);
            window.draw(shape);

            window.display();



        }
        return 0;
    }




