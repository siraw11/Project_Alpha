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
#include "PlayerType.h"
#include "Random.h"



int main() {
//Main window creation
std::srand(std::time(nullptr));
sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Project_Alpha!");
sf::Texture texture;
sf::Texture texture1;
texture.loadFromFile("../Resources/Menu/background.jpg");
texture1.loadFromFile("../Resources/Menu/background1.jpg");
sf::Sprite sprite;
sf::Sprite sprite1;
sprite.setTexture(texture);
sprite1.setTexture(texture1);
sprite.setScale(1.f  , 1.f );
sprite1.setScale(1.f , 1.f );

//hero class choice
PlayerType playerType;
    label:
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
                        case sf::Keyboard::Escape:
                            window.close();
                            if (event.type == sf::Event::Closed)
                                window.close();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                //Play case
                                case 0:

                                    std::cout << "Play button has been pressed" << std::endl;
                                    {
                                        const int SCALE = 3;

                                        //set hero
                                        Hero hero(3, 5, 2, 16, playerType);
                                        int counterWalking = 0;

                                        //collision variable
                                        int x;
                                        int y;

                                        //vector of enemy
                                        std::vector<Enemy> enemyArray;
                                        //set enemy
                                        Enemy enemy(3, 1, 4, 0);
                                        //initializing vector



                                        //set projectile
                                        std::vector<Projectile> projectileArray;
                                        Projectile projectile(playerType);
                                       // int counterProjectile;



                                        //animation variable
                                        int attackAnimation = 0;

                                        // Create matrix
                                        int level[10080] = {};//TODO: Dynamic allocation

                                        //Load map from Resources
                                        std::fstream fin("../Resources/Map/map.txt", std::fstream::in);
                                        char c;
                                        std::string tmp;
                                        int k = 0;
                                        while (fin >> std::noskipws >> c) {
                                            if (c != ',') {
                                                tmp += c;
                                            }
                                            else
                                            {
                                                level[k] = std::stoi(tmp);
                                                k++;
                                                tmp = "";
                                            }
                                        }
                                        fin.close();

                                        //charging enemyArray
                                        if(enemyArray.empty()){
                                            for (int i = 0; i <20 ; ++i) {
                                                enemy.spawnPosition=generateRandomPos(level);
                                                enemy.setPosition(enemy.spawnPosition);
                                                enemyArray.push_back(enemy);

                                            }

                                        }

                                        // Create the Map
                                        Map map;
                                        if (!map.load("../Resources/Map/map.png",sf::Vector2u(32, 32), level, 120, 84))
                                            return -1;
                                        map.setScale(sf::Vector2f(1.f * SCALE, 1.f * SCALE));

                                        //View variable
                                        sf::View view;
                                        view.reset(sf::FloatRect(0, 0, 3840.0, 2160.0));
                                        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
                                        sf::Vector2f position(0, 0);

                                        //start gameloop
                                        while (window.isOpen()) {
                                            sf::Event event2{};
                                            while (window.pollEvent(event2)) {
                                                if (event2.type == sf::Event::Closed)
                                                    window.close();
                                                if(event2.type == sf::Event::Closed || event2.key.code == sf::Keyboard::Escape)
                                                    window.close();
                                                if (event2.type == sf::Event::Resized) {
                                                    sf::View temp = window.getView();
                                                    temp.setSize(window.getSize().x,window.getSize().y);
                                                    window.setView(temp);
                                                }
                                            }
                                            window.clear(sf::Color::Black);
                                            window.draw(map);
                                           // window.draw(enemy);

                                            //hero movement and collision
                                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                                                hero.direction=1;
                                                if (projectile.counterAttack == 0)
                                                    hero.heroMovement(level);
                                                hero.setTextureRect(sf::IntRect(64 * counterWalking, 0, 64, 64));


                                            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                                                hero.direction=2;
                                                //down movement
                                                if (projectile.counterAttack == 0)
                                                    hero.heroMovement(level);

                                                hero.setTextureRect(sf::IntRect(64*counterWalking,128,64,64));

                                            }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                                                hero.direction=3;
                                                //left movement
                                                if (projectile.counterAttack == 0)
                                                    hero.heroMovement(level);

                                                hero.setTextureRect(sf::IntRect(64 * counterWalking, 64, 64, 64));


                                            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                                                hero.direction=4;
                                                // right movement
                                                if (projectile.counterAttack == 0)
                                                    hero.heroMovement(level);

                                                hero.setTextureRect(sf::IntRect(64 * counterWalking, 192, 64, 64));
                                            }

                                            //attack animation
                                            //right attack
                                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                                                attackAnimation = 7;
                                                projectile.direction = 2;
                                                projectile.counterAttack = 1;
                                            }//down attack
                                            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                                                attackAnimation = 6;
                                                projectile.direction = 0;
                                                projectile.counterAttack = 1;
                                            }// left attack
                                            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                                                attackAnimation = 5;
                                                projectile.direction = 1;
                                                projectile.counterAttack = 1;
                                            }// up attack
                                            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                                                attackAnimation = 4;
                                                projectile.direction = 3;
                                                projectile.counterAttack = 1;
                                            }

                                            //camera settings
                                            position.x =hero.getPosition().x + 20 - (3840.0 / 2);
                                            position.y =hero.getPosition().y + 20 - (2160.0 / 2);

                                            if (position.x < 0)
                                                position.x = 0;
                                            if (position.y < 0)
                                                position.y = 0;

                                            view.reset(sf::FloatRect(position.x, position.y, 3840, 2160));


                                            projectile.counterAttack = hero.animation(projectile.counterAttack,attackAnimation);
                                            //fire projectile
                                            if ((projectile.counterAttack == 11)&&(playerType!= PlayerType::KNIGHT)) {
                                                projectile.setPosition(hero.getPosition().x, hero.getPosition().y);
                                                projectile.setTextureRect (sf::IntRect(0, 64 * projectile.direction, 64, 64));
                                                projectileArray.push_back(projectile);
                                                projectile.counterAttack = 0;
                                            }
                                            else if(projectile.counterAttack==11){
                                                projectile.counterAttack=0;
                                            }


                                            window.draw(hero);
                                            window.setFramerateLimit(30);
                                            window.setView(view);

                                            //pojectile collision and draw
                                            for (auto i = projectileArray.begin(); i != projectileArray.end() ; ++i) {
                                                i->update();
                                                window.draw(*i);

                                                if (i->counterProjectile==32){
                                                    projectileArray.erase(i);
                                                    i--;
                                                    i->counterProjectile=0;
                                                }
                                                else if(i->getGlobalBounds().intersects(enemy.getGlobalBounds()))
                                                {
                                                    projectileArray.erase(i);
                                                    i--;
                                                    hero.fightA(&enemy);
                                                }
                                                else {i->counterProjectile++;}
                                            }

                                            //draw enemy and movement
                                            for(auto & i : enemyArray){

                                                i.movement(level);
                                                window.draw(i);

                                            }
                                            //reset walking animation
                                            if (counterWalking == 8) {
                                                counterWalking = 0;
                                                //enemy.direction=0;
                                            } else {

                                                counterWalking++;
                                            }

                                            window.display();
                                        }
                                    }

                                    // Select class menu
                                case 1: {
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
                                                            menu1.MoveDown1();
                                                            break;
                                                        case sf::Keyboard::Escape:
                                                            window.close();
                                                            break;
                                                        case sf::Keyboard::Return:
                                                            switch (menu1.GetPressedItem1()){
                                                                case 0:
                                                                    playerType= PlayerType::ARCHER;
                                                                    goto label;
                                                                case 1:
                                                                    playerType= PlayerType::KNIGHT;
                                                                    goto label;
                                                                case 2:
                                                                    playerType= PlayerType ::MAGE;
                                                                    goto label;
                                                            }
                                                            break;
                                                    }
                                            }
                                        }
                                        // Draw select class menu
                                        window.clear();
                                        window.draw(sprite1);
                                        menu1.draw(window);
                                        window.display();
                                    }
                                }
                                    // Exit case
                                case 2:
                                    window.close();
                                    break;

                            }
                            break;
                    }
                    break;
                case  sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        // Draw main menu
        window.clear();
        window.draw(sprite);
        menu.draw(window);
        window.display();
    }
    return 0;
}

