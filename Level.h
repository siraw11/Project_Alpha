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

//Classe per la creazione del livello

class Level {
public:
    Level(int levelArray[100]);//Crea il livello mettendo tutti i tipi
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
    std::vector<Object> gian;
    std::vector<Platform> vector_of_platform;
    std::vector<Enemy> vector_of_enemy;
    std::vector<PowerUp> vector_of_powerUp;
    std::vector<Bullet> vector_of_bullet;
    //--------------//
    Hero player;
    sf::Clock clock;//Clock per la frequenza di fuoco
private:
    sf::Vector2f size_of_enemy;
    sf::Vector2f size_of_platform;
    sf::Vector2f size_of_bullet;
    sf::Vector2f size_of_player;
    sf::Vector2f size_of_powerUp;

};


#endif //GAME_LEVEL_H
