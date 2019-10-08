//
// Created by andreatadde on 17/09/19.
//

#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include "Platform.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Hero.h"
#include "Level.h"

class Collision {//Classe statica per la gestione delle collisioni

public:
    //Funzione overload per i vari tipi di collisione
    static void checkCollision(std::vector<Platform> *platform, Hero *hero);//mappa-player
    static void checkCollision(std::vector<PowerUp> *powerUp, Hero *player);//powerup-player
    static void checkCollision(std::vector<Bullet> *bullet, std::vector<Platform> *platform);//proiettili-mappa
    static void checkCollision(std::vector<Bullet> *bullet, std::vector<Enemy> *enemy);//proiettili-nemici
};


#endif
