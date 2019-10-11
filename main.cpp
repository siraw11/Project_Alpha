#include <iostream>
#include <SFML/Graphics.hpp>
#include <zconf.h>
#include <vector>
#include <fstream>
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
#include "Projectile.h"
#include "Menu.h"
#include "Menu1.h"


int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Project_Alpha!");

    sf::Texture texture;
    sf::Texture texture1;
    texture.loadFromFile("../Resources/Menu/background.jpg");
    texture1.loadFromFile("../Resources/Menu/background1.jpg");
    sf::Sprite sprite;
    sf::Sprite sprite1;
    sprite.setTexture(texture);
    sprite1.setTexture(texture1);
    sprite.setScale(1.f / 2, 1.f / 2);
    sprite1.setScale(1.f / 2, 1.f / 2);


    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;


                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    {
                                        const int SCALE = 3;

                                        //set hero
                                        Hero hero(3, 5, 1, 16);
                                        auto heroTexture = new sf::Texture;
                                        heroTexture->loadFromFile("../Resources/Sprites/Hero/archer.png");
                                        hero.setTexture(*heroTexture);
                                        hero.setTextureRect(sf::IntRect(0, 128, 64, 64));
                                        hero.setOrigin(hero.getPosition().x +
                                                       hero.getGlobalBounds().width / 4,
                                                       hero.getPosition().y +
                                                       hero.getGlobalBounds().height / 2);
                                        hero.setPosition(32 * 3, 32 * 30);
                                        hero.setScale(sf::Vector2f(1.f * 2, 1.f * 2));
                                        int counterWalking = 0;
                                        //collision variable
                                        int x;
                                        int y;

                                        //set enemy
                                        Enemy enemy(3, 1, 4, 0);
                                        auto enemyTexture = new sf::Texture;
                                        enemyTexture->loadFromFile(
                                                "../Resources/Sprites/Enemy/gargoyle.png");
                                        enemy.setTexture(*enemyTexture);
                                        enemy.setTextureRect(sf::IntRect(0, 64 * 3, 64, 64));
                                        enemy.setPosition(1200, 1200);
                                        enemy.setScale(sf::Vector2f(3.f, 3.f));

                                        //set projectile
                                        std::vector<Projectile>projectileArray;
                                        Projectile projectile;

                                        //animation variable
                                        int attackAnimation=0;



                                        //map matrix
                                        int level[10080] = {};//TODO: aggiungere riallocazione dinamica


                                        std::fstream fin("../Resources/Map/map.txt",std::fstream::in);
                                        char c;
                                        std::string tmp;
                                        int k = 0;
                                        while (fin >> std::noskipws >> c) {
                                            if (c != ',') {
                                                tmp += c;
                                                std::cout << c << std::endl;
                                            } else {
                                                level[k] = std::stoi(tmp);
                                                k++;
                                                tmp = "";
                                            }
                                        }
                                        fin.close();


                                        // create the tilemap from the level definition
                                        Map map;
                                        if (!map.load("../Resources/Map/map.png",
                                                      sf::Vector2u(32, 32), level, 120, 84))
                                            return -1;
                                        map.setScale(sf::Vector2f(1.f * SCALE, 1.f * SCALE));
                                        //view variable
                                        sf::View view;
                                        view.reset(sf::FloatRect(0, 0, 3840.0, 2160.0));
                                        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
                                        sf::Vector2f position(0, 0);


                                        while (window.isOpen()) {
                                            sf::Event event2{};
                                            while (window.pollEvent(event2)) {
                                                if (event2.type == sf::Event::Closed)
                                                    window.close();
                                                if (event2.type == sf::Event::Resized) {
                                                    sf::View temp = window.getView();
                                                    temp.setSize(window.getSize().x,
                                                                 window.getSize().y);
                                                    window.setView(temp);
                                                }

                                            }

                                            window.clear(sf::Color::Black);

                                            window.draw(map);
                                            window.draw(enemy);


                                            //hero movement and collision
                                            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                                            {
                                                if(projectile.counterAttack==0) { // up movement
                                                    x = (int) (hero.getPosition().x) / 32 / SCALE;
                                                    y = (int) ((hero.getPosition().y - 1) / 32 / SCALE);

                                                    if (level[120 * y + x] == 0) {
                                                        hero.move(0, -hero.getSpeed());
                                                    } else {//wall up problem fix
                                                        float offset = 0;
                                                        while (true) {
                                                            offset += 0.01;
                                                            y = static_cast<int>((hero.getPosition().y + offset) / 32 / SCALE);
                                                            if (level[120 * y + x] == 0) {
                                                                hero.move(0, offset);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    hero.setTextureRect(sf::IntRect(64 * counterWalking, 0, 64, 64));
                                                }

                                            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                                            {//down movement
                                                if(projectile.counterAttack==0){
                                                    x = (int)(hero.getPosition().x)/32/SCALE;
                                                    y = (int)((hero.getPosition().y)/32/SCALE)+1;
                                                    if(level[120*y+x]==0){
                                                        hero.move(0,hero.getSpeed());
                                                    }else{//wall down problem fix
                                                        float offset=0;
                                                        while(true){
                                                            offset+= 0.01;
                                                            y= static_cast<int>((hero.getPosition().y-offset)/32/SCALE);
                                                            if(level[120*y+x]==0){
                                                                hero.move(0, -offset);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    hero.setTextureRect(sf::IntRect(64*counterWalking,128,64,64));
                                                }

                                            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))

                                            {//left movement
                                                if(projectile.counterAttack==0) {
                                                    x = (int) ((hero.getPosition().x - 1) / 32 / SCALE);
                                                    y = (int) (hero.getPosition().y) / 32 / SCALE;
                                                    if (level[120 * y + x] == 0) {

                                                        hero.move(-hero.getSpeed(), 0);
                                                    } else {//wall left problem fix
                                                        float offset = 0;
                                                        while (true) {
                                                            offset += 0.01;
                                                            x = static_cast<int>((hero.getPosition().x + offset) / 32 / SCALE);
                                                            if (level[120 * y + x] == 0) {
                                                                hero.move(offset, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    hero.setTextureRect(sf::IntRect(64 * counterWalking, 64, 64, 64));
                                                }

                                            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                                            {// right movement
                                                if(projectile.counterAttack==0) {
                                                    x = (int) ((hero.getPosition().x) / 32 / SCALE) + 1;
                                                    y = (int) (hero.getPosition().y) / 32 / SCALE;
                                                    if (level[120 * y + x] == 0) {

                                                        hero.move(hero.getSpeed(), 0);
                                                    } else {//wall right problem fix
                                                        float offset = 0;
                                                        while (true) {
                                                            offset += 0.01;
                                                            x = static_cast<int>((hero.getPosition().x - offset) / 32 / SCALE);
                                                            if (level[120 * y + x] == 0) {
                                                                hero.move(-offset, 0);
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    hero.setTextureRect(sf::IntRect(64 * counterWalking, 192, 64, 64));
                                                }

                                            }
                                            //reset walking animation
                                            if(counterWalking ==8){
                                                counterWalking = 0;
                                            }else{
                                                counterWalking++;
                                            }

                                            //attack animation

                                            //right attack
                                            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                                                //hero.animationControl(7);
                                                attackAnimation=7;
                                                projectile.direction=2;

                                                projectile.counterAttack=1;

                                            }//down attack
                                            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                                                //hero.animationControl(6);
                                                attackAnimation=6;
                                                projectile.direction=0;
                                                projectile.counterAttack=1;
                                            }// left attack
                                            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                                                // hero.animationControl(5);
                                                attackAnimation=5;
                                                projectile.direction=1;
                                                projectile.counterAttack=1;
                                            }// up attack
                                            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                                                //hero.animationControl(4);
                                                attackAnimation=4;
                                                projectile.direction=3;

                                                projectile.counterAttack=1;
                                            }



                                            //camera settings
                                            position.x =
                                                    hero.getPosition().x + 20 - (3840.0 / 2);
                                            position.y =
                                                    hero.getPosition().y + 20 - (2160.0 / 2);

                                            if (position.x < 0)
                                                position.x = 0;
                                            if (position.y < 0)
                                                position.y = 0;
                                            view.reset(sf::FloatRect(position.x, position.y, 3840,2160));


                                            projectile.counterAttack=hero.animation(projectile.counterAttack,attackAnimation);
                                            window.draw(hero);
                                            window.setFramerateLimit(30);
                                            window.setView(view);
                                            //fire projectile
                                            if(projectile.counterAttack==11){
                                                projectile.setPosition(hero.getPosition().x,hero.getPosition().y);
                                                projectile.setTextureRect(sf::IntRect(0,48*projectile.direction,48,48));
                                                projectileArray.push_back(projectile);
                                                projectile.counterAttack=0;}
                                            for(auto & iter : projectileArray) {
                                                iter.update();
                                                window.draw(iter);
                                            }
                                            window.display();

                                        }
                                        return 0;
                                    }


                                case 1:{
                                    std::cout << "Select class button has been pressed"
                                              << std::endl;
                                    Menu1 menu1(window.getSize().x, window.getSize().y);
                                    while (window.isOpen()) {
                                        sf::Event event1{};

                                        while (window.pollEvent(event1)) {
                                            switch (event1.type) {
                                                case sf::Event::KeyReleased:
                                                    switch (event1.key.code) {
                                                        case sf::Keyboard::Up:
                                                            menu1.MoveUp1();
                                                            break;

                                                        case sf::Keyboard::Down:
                                                            menu1.MoveDown1 ();
                                                            break;


                                                        case sf::Keyboard::Return:
                                                            switch (menu1.GetPressedItem1())
                                                                break;
                                                    }
                                            }
                                        }


                                        window.clear();

                                        window.draw(sprite1);

                                        menu1.draw(window);

                                        window.display();

                                    }

                                }
                                case 2:
                                    window.close();
                                    std::cout << "Exit button has been pressed" << std::endl;
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear();

        window.draw(sprite);

        menu.draw(window);

        window.display();
    }
}

