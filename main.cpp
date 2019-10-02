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

        const int SCALE = 3;

        sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Project_Alpha");
        //set hero
        Hero hero(3,5,1,3);
        auto heroTexture = new sf::Texture;
    heroTexture->loadFromFile("Sprites/luca.png");
    hero.setTexture(*heroTexture);

    hero.setTextureRect(sf::IntRect(32,0,32,32));
    hero.setOrigin(hero.getPosition().x + hero.getGlobalBounds().width/2,hero.getPosition().y + hero.getGlobalBounds().height/2);
    hero.setPosition(32*10,32*10);
    hero.setScale(sf::Vector2f(1.f*SCALE,1.f*SCALE));
        int counterWalking=0;


    const int level[] =
            {
                    7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                    5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6,
            };


    // create the tilemap from the level definition
    Map map;
    if (!map.load("Sprites/Tilemap2.png", sf::Vector2u(32, 32), level, 40, 21))
        return -1;
    map.setScale(sf::Vector2f(1.f*SCALE,1.f*SCALE));

    sf::View view;
    view.reset(sf::FloatRect(0,0,3840.0,2160.0));
    view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));
    sf::Vector2f position (0,0);



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
                int x = (int)(hero.getPosition().x)/32/SCALE;
                int y = (int)(hero.getPosition().y-1)/32/SCALE;

               if(level[40*y+x]==0){
                   std::cout<<x<<" "<<y<<std::endl;
                   hero.move(0,-hero.getSpeed());
               }


                hero.setTextureRect(sf::IntRect(32*counterWalking,32*3,32,32));

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                int x = (int)(hero.getPosition().x)/32/SCALE;
                int y = (int)(hero.getPosition().y+1)/32/SCALE;
                if(level[40*y+x]==0){

                    std::cout<<x<<" "<<y<<std::endl;
                    hero.move(0,hero.getSpeed());

                    }

                hero.setTextureRect(sf::IntRect(32*counterWalking,0,32,32));

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

            {
                int x = (int)(hero.getPosition().x-1)/32/SCALE;
                int y = (int)(hero.getPosition().y)/32/SCALE;
                if(level[40*y+x]==0){
                    std::cout<<x<<" "<<y<<std::endl;
                    hero.move(-hero.getSpeed(),0);
                }


                hero.setTextureRect(sf::IntRect(32*counterWalking,32,32,32));

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

            {
                int x = (int)(hero.getPosition().x+1)/32/SCALE;
                int y = (int)(hero.getPosition().y)/32/SCALE;
                if(level[40*y+x]==0){
                    std::cout<<x<<" "<<y<<std::endl;
                    hero.move(hero.getSpeed(),0);}
                hero.setTextureRect(sf::IntRect(32*counterWalking,32*2,32,32));
            }


            if(counterWalking ==2){
                counterWalking = 0;
            }else{
                counterWalking++;
            }

            position.x = hero.getPosition().x +20 - (3840.0/2);
            position.y = hero.getPosition().y +20 - (2160.0/2);

            if(position.x < 0)
                position.x =0;
            if (position.y < 0)
                position.y =0;
            view.reset(sf::FloatRect(position.x, position.y, 3840, 2160));

            window.setView(view);
            window.draw(map);
            window.draw(hero);
            window.display();



        }
        return 0;
    }




