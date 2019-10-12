//
// Created by davide on 18/09/19.
//

#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <vector>
#include "Platform.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Hero.h"
#include "PowerUp.h"
#include <SFML/Graphics.hpp>
#include "GameLogic.h"

//Classe per la creazione del livello
class GameLogic;

class Level {
public:
    explicit Level(int levelArray[], int colomun, int row);//Crea il livello mettendo tutti i tipi
    // di oggetti nei vettori assegnati e ne setta le propietà
    void Update(sf::RenderWindow *window, sf::Event *event);//Prende l'input da tastiera
    //--Draw di tutti gli oggetti--//
    void drawBullet(sf::RenderWindow *Window);

    void drawEnemy(sf::RenderWindow *Window);

    void drawPlayer(sf::RenderWindow *Window);

    void drawPlatform(sf::RenderWindow *Window);

    void drawPowerUp(sf::RenderWindow *Window);

    void setTextures();//Get texture globale
public:
    //-----Vettori di oggetti------//
    std::vector<RectangleShape> gian;
    std::vector<Platform> vector_of_platform;
    std::vector<Enemy> vector_of_enemy;
    std::vector<PowerUp> vector_of_powerUp;
    std::vector<Bullet> vector_of_bullet;
    //--------------//
    Hero player;


private:
    sf::Vector2f size_of_enemy;
    sf::Vector2f size_of_platform;
    sf::Vector2f size_of_bullet;
    sf::Vector2f size_of_player;
    sf::Vector2f size_of_powerUp;
    int size_of_tile = 32;
    int type_grass = 1;
    int type_dirt = 2;
    int type_platform_left = 10;
    int type_platform = 11;
    int type_platform_right = 12;
    int type_log = 3;
    int type_powerUpBullet = 5;
    int type_powerUpSpeed = 6;
    int type_player = 9;
    int type_enemy_octopus = 7;
    GameLogic *logic;
    sf::Clock clock;//Clock per la frequenza di fuoco
    sf::Time shoot_time;
};


#endif //GAME_LEVEL_H
