//
// Created by matteo on 10/03/20.
//

#include <fstream>
#include <iostream>
#include "GameManager/DEFINITIONS.hpp"
#include "map.h"
#include "Random.h"
#include <cmath>

//constructor
map::map() {
    //Create Map Matrix
    int *level = new int[raws * column];

    //load map from Resources
    std::fstream fin("../Resources/Map/map.txt", std::fstream::in);
    char c;
    std::string tmp;
    int k = 0;
    while (fin >> std::noskipws >> c)
        if (c != ',') {
            tmp += c;
        } else {
            level[k] = std::stoi(tmp);
            k++;
            tmp = " ";
        }
    fin.close();


    //creazione vettore di tile
    for (int i = 0; i < raws; ++i)
        for (int j = 0; j < column; ++j) {

            if (level[(i*column) + j] == floor) {
                Tile newTile(floor);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == up_wall) {
                Tile newTile(up_wall);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == right_wall) {
                Tile newTile(right_wall);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == left_wall) {
                Tile newTile(left_wall);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == down_wall) {
                Tile newTile(down_wall);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == down_left_corner) {
                Tile newTile(down_left_corner);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == down_right_corner) {
                Tile newTile(down_right_corner);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == up_left_corner) {
                Tile newTile(up_left_corner);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == up_right_corner) {
                Tile newTile(up_right_corner);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == key_wall) {
                Tile newTile(key_wall);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == left_corridor) {
                Tile newTile(left_corridor);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == torch_wall) {
                Tile newTile(torch_wall);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == right_corridor) {
                Tile newTile(right_corridor);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i * column) + j] == bones) {
                Tile newTile(bones);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == web) {
                Tile newTile(web);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == skull) {
                Tile newTile(skull);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == torch) {
                Tile newTile(torch);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == left_front_door) {
                Tile newTile(left_front_door);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == right_front_door) {
                Tile newTile(right_front_door);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == left_side_door) {
                Tile newTile(left_side_door);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == right_side_door) {
                Tile newTile(right_side_door);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }

            if (level[(i*column) + j] == void_tile) {
                Tile newTile(void_tile);
                newTile.init(j*32*SCALE, i*32*SCALE);
                tile_vector.push_back(newTile);
            }
        }
    //creazione vettore dei nemici
    for (int i = 0; i < 10; i++) {
        Enemy newEnemy(3, 1, 10);
        newEnemy.spawnposition = generateRandomPos(tile_vector);
        newEnemy.setPosition(newEnemy.spawnposition);
        enemy_vector.push_back(newEnemy);

    }

    //creazione vettore  chest
    for (int i = 0; i < 8; i++) {
        Chest newChest;
        newChest.init(i);
        chest_vector.push_back(newChest);

    }
}

//destructor
map::~map() = default;

//function
void map::setTexture() {
    for(auto & i:tile_vector) {

        if (i.t == floor) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(0, 0, 32, 32));
        }
        if (i.t == up_wall) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32, 0, 32, 32));
        }
        if (i.t == right_wall) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 2, 0, 32, 32));
        }
        if (i.t == left_wall) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 3, 0, 32, 32));
        }
        if (i.t == down_wall) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 4, 0, 32, 32));
        }
        if (i.t == down_left_corner) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 5, 0, 32, 32));
        }
        if (i.t == down_right_corner) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 6, 0, 32, 32));
        }
        if (i.t == up_left_corner) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 7, 0, 32, 32));
        }
        if (i.t == up_right_corner) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 8, 0, 32, 32));
        }
        if (i.t == key_wall) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 9, 0, 32, 32));
        }
        if (i.t == left_corridor) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 10, 0, 32, 32));
        }
        if (i.t == torch_wall) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 11, 0, 32, 32));
        }
        if (i.t == right_corridor) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 12, 0, 32, 32));
        }
        if (i.t == bones) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 13, 0, 32, 32));
        }
        if (i.t == web) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 14, 0, 32, 32));
        }
        if (i.t == skull) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 15, 0, 32, 32));
        }
        if (i.t == torch) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 16, 0, 32, 32));
        }
        if (i.t == left_front_door) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 17, 0, 32, 32));
        }
        if (i.t == right_front_door) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 18, 0, 32, 32));
        }
        if (i.t == left_side_door) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 19, 0, 32, 32));
        }
        if (i.t == right_side_door) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 20, 0, 32, 32));
        }
        if (i.t == void_tile) {
            auto newTexture = new sf::Texture ;
            newTexture->loadFromFile("../Resources/Map/Map.png");
            i.setTexture(newTexture);
            i.setTextureRect(sf::IntRect(32 * 21, 0, 32, 32));
        }
    }
}

void map::update(std::unique_ptr<Hero>& hero, std::unique_ptr<Boss>& boss) {
    //enemy movement update
    if(!enemy_vector.empty())
        for(auto i = enemy_vector.begin(); i != enemy_vector.end(); ++i){
            i->update(hero, this->tile_vector, this->chest_vector);
            if(i->counterDeath == 11){
                enemy_vector.erase(i);
                i--;
            }
        }


    boss->update(hero, tile_vector, chest_vector, enemy_vector);

    hero->update(tile_vector, enemy_vector, &chest_vector, boss);

    //check hero projectile collision
    if(!hero->projectile_vector.empty())
    for(auto i = hero->projectile_vector.begin(); i!= hero->projectile_vector.end(); ++i) {
        auto d = i->projectile_start - i->getPosition();
        float distance = std::sqrt((d.x*d.x) + (d.y*d.y));

        if (i->checkCollision(&enemy_vector, tile_vector, *boss, hero) || distance > hero->range) {//erase the projectile if there is a collision
            hero->projectile_vector.erase(i);
            i--;
        }
    }
    //update hero projectile position
    for(auto &i : hero->projectile_vector){
            i.updatePosition();
        }
}


//draw objects
void map::drawTile(const Alpha::GameDataRef& _data) {

    for (auto &i :tile_vector)
        _data->window.draw(i);
}

void map::drawEnemy(const Alpha::GameDataRef &_data) {

    for(auto &i : enemy_vector)
        _data->window.draw(i);
}

void map::drawProjectile(const std::vector<Projectile>& projectile_vector, const Alpha::GameDataRef &_data) {

    if(!projectile_vector.empty()) {
        for (auto &i : projectile_vector)
            _data->window.draw(i);
    }
}

void map::drawChest(const Alpha::GameDataRef &_data) {
    for(auto &i: chest_vector)
        _data->window.draw(i);
}



