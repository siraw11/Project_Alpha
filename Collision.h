//
// Created by andreatadde on 17/09/19.
//

#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include "Level.h"

class Collision {//Classe statica per la gestione delle collisioni

public:
    //Funzione overload per i vari tipi di collisione
    static void checkCollision(std::vector<Platform> *platform, GameCharacter *gameCharacter);//map - hero/enemy
    static int checkCollision(std::vector<PowerUp> *powerUp, Hero *player);//powerup-player
    static int checkCollision(std::vector<Bullet> *bullet, std::vector<Platform> *platform);//proiettili-mappa
    static sf::Vector2i checkCollision(std::vector<Bullet> *bullet, std::vector<Enemy> *enemy);//proiettili-nemici
};


#endif
