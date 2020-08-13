//
// Created by matteo on 22/04/20.
//

#ifndef PROGETTO_PROVA_PROJECTILE_H
#define PROGETTO_PROVA_PROJECTILE_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "PlayerType.h"
#include "Enemy.h"

class Projectile: public sf::RectangleShape {
public:
    explicit Projectile(PlayerType playerType);
    ~Projectile() override;
    void init();
    bool checkCollision( std::vector<Enemy> *enemy_vector, const std::vector<Tile> & tile_vector);

    int direction{};//0=down,1=left,2=right,3=up
    int projectile_speed=20;
    sf::Vector2f projectile_start;



    void updateProjectile();
};


#endif //PROGETTO_PROVA_PROJECTILE_H
