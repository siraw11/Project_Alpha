//
// Created by davide on 18/09/19.
//

#include "GameLogic.h"
#include <iostream>
#include "Input.h"

Level::Level(int levelArray[], int column, int row, GameLogic *gameLogic) {

    size_of_enemy.x = 32;
    size_of_enemy.y = 32;
    size_of_platform.x = 32;
    size_of_platform.y = 32;
    size_of_bullet.x = 10;
    size_of_bullet.y = 10;
    size_of_player.x = 32;
    size_of_player.y = 32;
    size_of_powerUp.x = 32;
    size_of_powerUp.y = 32;
    //TODO Riordinare i vari numeri per l'assegnazione delle texture

//-----Creazione vettori di oggetti----------------//

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (levelArray[(i * column) + j] == type_enemy_octopus) {
                Enemy newEnemy;
                newEnemy.init(j * size_of_tile, i * size_of_tile, size_of_enemy);
                vector_of_enemy.push_back(newEnemy);
            }

            if (levelArray[(i * column) + j] == type_grass) {
                Platform newPlatform(type_grass);
                newPlatform.init(j * size_of_tile, i * size_of_tile, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }

            if (levelArray[(i * column) + j] == type_dirt) {
                Platform newPlatform(type_dirt);
                newPlatform.init(j * size_of_tile, i * size_of_tile, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }

            if (levelArray[(i * column) + j] == type_platform_left) {
                Platform newPlatform(type_platform_left);
                newPlatform.init(j * size_of_tile, i * size_of_tile, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }
            if (levelArray[(i * column) + j] == type_platform) {
                Platform newPlatform(type_platform_right);
                newPlatform.init(j * size_of_tile, i * size_of_tile, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }
            if (levelArray[(i * column) + j] == type_platform_right) {
                Platform newPlatform(type_platform_right);
                newPlatform.init(j * size_of_tile, i * size_of_tile, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }
            if (levelArray[(i * column) + j] == type_log) {
                Platform newPlatform(type_log);
                newPlatform.init(j * size_of_tile, i * size_of_tile, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }

            if (levelArray[(i * column) + j] == type_powerUpBullet) {
                PowerUp newPowerUp(type_powerUpBullet);
                newPowerUp.init(j * size_of_tile, i * size_of_tile, size_of_powerUp);
                vector_of_powerUp.push_back(newPowerUp);
            }
            if (levelArray[(i * column) + j] == type_powerUpSpeed) {
                PowerUp newPowerUp(type_powerUpSpeed);
                newPowerUp.init(j * size_of_tile, i * size_of_tile, size_of_powerUp);
                vector_of_powerUp.push_back(newPowerUp);
            }

            if (levelArray[(i * column) + j] == type_player) {
                player.init(j * size_of_tile, i * size_of_tile, size_of_player);
            }
        }
    }
    reset = false;
    this->logic = gameLogic;
    shoot_time = sf::seconds(0);
    clock.restart();

    cameraSize.x=1300;
    cameraSize.y=1000;
    camera.setSize(cameraSize);
    camera.zoom(cameraZoom);
    setTextures();
}

void Level::Update(sf::RenderWindow *window, Input *input, GameStates *state) {

    sf::Time shoot_delay;
    sf::Vector2f shotDir;
    shoot_delay = sf::seconds(0.5);
    bool shoot = false;

//----Aggiornamento parametri da input-----//

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shotDir.x = 1;
        shotDir.y = 0;
        shoot = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shotDir.x = -1;
        shotDir.y = 0;
        shoot = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        shotDir.x = 0;
        shotDir.y = -1;
        shoot = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        shotDir.x = 0;
        shotDir.y = 1;
        shoot = true;
    }
    //-----Creazione priettili------------//
    if (shoot && clock.getElapsedTime() - shoot_time >= shoot_delay) {
        Bullet newBullet(player.getIsPowerBullet(), shotDir);
        newBullet.init(player.rectShape.getPosition().x + player.rectShape.getSize().x / 2 -
                       newBullet.rectShape.getSize().x / 2,
                       player.rectShape.getPosition().y + player.rectShape.getSize().y / 2 -
                       newBullet.rectShape.getSize().y / 2, size_of_bullet);
        vector_of_bullet.push_back(newBullet);
        setTextures();
        shoot_time = clock.getElapsedTime();
    }

    /*
    sf::Texture textureBack;
    sf::Vector2u textureSize;
    textureBack.loadFromFile("../textures/Back.png");
    sf::Sprite spiteBack;
    spiteBack.setPosition(0,0);
    textureSize = textureBack.getSize();
    float scaleX = (float) 500*32 / textureSize.x; //TODO set a background image to place clouds an other not colliding obj
    float scaleY = (float) 320 / textureSize.y;
    spiteBack.setTexture(textureBack);
    spiteBack.setScale(scaleX,scaleY);
    */

    //------Passa gli oggetti al gestore della logica di gioco (per collisioni ed eventi)-------//
    logic->Update(this, state, input, window);

    //----Draw globale-----------//

    //window->draw(spiteBack);
    drawBullet(window);
    drawPlatform(window);
    drawEnemy(window);
    drawPowerUp(window);
    drawPlayer(window);
}

void Level::drawBullet(sf::RenderWindow *Window) {
    for (int i = 0; i < vector_of_bullet.size(); i++) {
        Window->draw(vector_of_bullet[i].rectShape);
    }

}

void Level::drawEnemy(sf::RenderWindow *Window) {
    for (int i = 0; i < vector_of_enemy.size(); i++) {
        Window->draw(vector_of_enemy[i].rectShape);
    }
}

void Level::drawPlatform(sf::RenderWindow *Window) {
    for (int i = 0; i < vector_of_platform.size(); i++) {
        Window->draw(vector_of_platform[i].rectShape);
    }
}

void Level::drawPlayer(sf::RenderWindow *Window) {
    Window->setView(camera);
    Window->draw(player.rectShape);
}

void Level::drawPowerUp(sf::RenderWindow *Window) {
    for (int i = 0; i < vector_of_powerUp.size(); i++) {
        Window->draw(vector_of_powerUp[i].rectShape);
    }
}

void Level::setTextures() {
    for (int i = 0; i < vector_of_enemy.size(); i++) {
        vector_of_enemy[i].setTexture("../textures/octopus-4.png");
    }

    for (int i = 0; i < vector_of_platform.size(); i++) {
        if (vector_of_platform[i].t == type_dirt)
            vector_of_platform[i].setTexture("../textures/Platform/4.png");
        if (vector_of_platform[i].t == type_grass)
            vector_of_platform[i].setTexture("../textures/Platform/2.png");
        if (vector_of_platform[i].t == type_log)
            vector_of_platform[i].setTexture("../textures/Platform/49.png");
        if (vector_of_platform[i].t == type_platform_left)
            vector_of_platform[i].setTexture("../textures/Platform/26.png");
        if (vector_of_platform[i].t == type_platform)
            vector_of_platform[i].setTexture("../textures/Platform/28.png");
        if (vector_of_platform[i].t == type_platform_right)
            vector_of_platform[i].setTexture("../textures/Platform/29.png");
    }


    for (int i = 0; i < vector_of_powerUp.size(); i++) {
        if (vector_of_powerUp[i].type == type_powerUpBullet)
            vector_of_powerUp[i].setTexture("../textures/Antidote 1.png");
        if (vector_of_powerUp[i].type == type_powerUpSpeed)
            vector_of_powerUp[i].setTexture("../textures/Health Potion 1.png");
    }
    for (int i = 0; i < vector_of_bullet.size(); i++) {
        vector_of_bullet[i].setTexture("../textures/bullet3.png");
    }
    //player.setTexture("../textures/tux_from_linux.png"); // TODO try to set the textures into the c-tor, don't update here otherwise animation won't work
}