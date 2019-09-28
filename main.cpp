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
#include "Map.cpp"
#include "Boss.h"
#include "Chest.h"




int main() {

        const int SCALE = 3;

        sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Project_Alpha");
        //set hero
        Hero hero(3,5,1,1);
        hero.setPosition(100,100);
        auto heroTexture = new sf::Texture;
        heroTexture->loadFromFile("Sprites/luca.png");
        hero.setTexture(*heroTexture);
        hero.setScale(sf::Vector2f(1.f*SCALE,1.f*SCALE));
        hero.setTextureRect(sf::IntRect(32,0,32,32));
        int counterWalking=0;

        //set map texture
        /*Map map(true,true,true,true);
        map.setPosition(0,0);
        auto mapTexture = new sf::Texture;
        mapTexture->loadFromFile("Sprites/test3.png");
        map.setTexture(*mapTexture);
        map.setScale(sf::Vector2f(1.f,1.f));

        int matMap[40][20];*/
    const int level[] =
            {
                    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
                    0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
                    2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
                    0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
            };


    // create the tilemap from the level definition
    Map map;
    if (!map.load("Sprites/tilemap.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;
    map.setScale(sf::Vector2f(1.f*SCALE,1.f*SCALE));


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

            int x = (int)(hero.getPosition().x)/32/SCALE;
            int y = (int)(hero.getPosition().y-1)/32/SCALE;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                //if(level[xy])
                if(level[16*x+y]!=3){
                    std::cout << level[16*x+y] << std::endl;
                    hero.move(0,-hero.getSpeed());
                }
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
                //if(( )
                {hero.move(hero.getSpeed(),0);
                hero.setTextureRect(sf::IntRect(32*counterWalking,32*2,32,32));}
            }


            if(counterWalking ==2){
                counterWalking = 0;
            }else{
                counterWalking++;
            }


            window.draw(map);
            window.draw(hero);
            window.display();



        }
        return 0;
    }




