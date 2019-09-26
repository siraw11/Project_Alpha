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
#include "Map.h"
#include "Boss.h"
#include "Chest.h"




int main() {


        sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Project_Alpha");
        //set hero
        Hero hero(3,5,1,6);
        hero.setPosition(100,100);
        auto heroTexture = new sf::Texture;
        heroTexture->loadFromFile("Sprites/luca.png");
        hero.setTexture(*heroTexture);
        hero.setScale(sf::Vector2f(4.f,4.f));
        hero.setTextureRect(sf::IntRect(32,0,32,32));
        int counterWalking=0;

        //set map texture
        Map map;
        map.setPosition(0,0);
        auto mapTexture = new sf::Texture;
        mapTexture->loadFromFile("Sprites/test3.png");
        map.setTexture(*mapTexture);
        map.setScale(sf::Vector2f(3.f,3.f));



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




