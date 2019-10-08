//
// Created by davide on 18/09/19.
//

#include "Level.h"
#include "GameLogic.h"

Level::Level(int levelArray[500]) {

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

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            if (levelArray[(i * 50) + j] == 7) {
                Enemy newEnemy;
                newEnemy.init(j * 32, i * 32, size_of_enemy);
                vector_of_enemy.push_back(newEnemy);
            }

            if (levelArray[(i * 50) + j] == 2) {
                Platform newPlatform(2);
                newPlatform.init(j * 32, i * 32, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }

            if (levelArray[(i * 50) + j] == 3) {
                Platform newPlatform(3);
                newPlatform.init(j * 32, i * 32, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }

            if (levelArray[(i * 50) + j] == 10) {
                Platform newPlatform(10);
                newPlatform.init(j * 32, i * 32, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }
            if (levelArray[(i * 50) + j] == 11) {
                Platform newPlatform(11);
                newPlatform.init(j * 32, i * 32, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }
            if (levelArray[(i * 50) + j] == 12) {
                Platform newPlatform(12);
                newPlatform.init(j * 32, i * 32, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }
            if (levelArray[(i * 50) + j] == 1) {
                Platform newPlatform(1);
                newPlatform.init(j * 32, i * 32, size_of_platform);
                vector_of_platform.push_back(newPlatform);
            }

            if (levelArray[(i * 50) + j] == 5) {
                PowerUp newPowerUp(5);
                newPowerUp.init(j * 32, i * 32, size_of_powerUp);
                vector_of_powerUp.push_back(newPowerUp);
            }
            if (levelArray[(i * 50) + j] == 6) {
                PowerUp newPowerUp(6);
                newPowerUp.init(j * 32, i * 32, size_of_powerUp);
                vector_of_powerUp.push_back(newPowerUp);
            }

            if (levelArray[(i * 50) + j] == 9) {
                player.init(j * 32, i * 32, size_of_player);
            }
        }
    }
}

void Level::Update(sf::RenderWindow *window, sf::Event *event) {


    sf::Time shoot_time;
    sf::Vector2f shotDir;
    shoot_time = sf::seconds(0.5);
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

    if (shoot && shoot_time <= clock.getElapsedTime()) {

        Bullet newBullet(player.getIsPowerBullet(), shotDir);
        newBullet.init(player.rectShape.getPosition().x + player.rectShape.getSize().x / 2 -
                       newBullet.rectShape.getSize().x / 2,
                       player.rectShape.getPosition().y + player.rectShape.getSize().y / 2 -
                       newBullet.rectShape.getSize().y / 2, size_of_bullet);
        vector_of_bullet.push_back(newBullet);
        clock.restart();
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

    GameLogic gameLogic(&vector_of_enemy, &vector_of_bullet, &vector_of_platform, &player, &vector_of_powerUp);

    //----Draw globale-----------//

    window->clear(sf::Color(10, 108, 180));
    setTextures();
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
    sf::View viewPlayer;
    /*
    if(player.velocity.y == 0) viewPlayer.setCenter(player.x + player.width / 2, player.y + player.height / 2);
    else viewPlayer.setCenter(player.x + player.width / 2, 0);

    viewPlayer.setCenter(player.x + player.width / 2, player.y + player.height / 2);    //TODO camera follows player
    viewPlayer.zoom(0.3f);
    Window->setView(viewPlayer);
    */
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
        if (vector_of_platform[i].t == 2)
            vector_of_platform[i].setTexture("../textures/Platform/4.png");
        if (vector_of_platform[i].t == 1)
            vector_of_platform[i].setTexture("../textures/Platform/2.png");
        if (vector_of_platform[i].t == 3)
            vector_of_platform[i].setTexture("../textures/Platform/49.png");
        if (vector_of_platform[i].t == 10)
            vector_of_platform[i].setTexture("../textures/Platform/26.png");
        if (vector_of_platform[i].t == 11)
            vector_of_platform[i].setTexture("../textures/Platform/28.png");
        if (vector_of_platform[i].t == 12)
            vector_of_platform[i].setTexture("../textures/Platform/29.png");
    }

    for (int i = 0; i < vector_of_powerUp.size(); i++) {
        if (vector_of_powerUp[i].type == 5)
            vector_of_powerUp[i].setTexture("../textures/Antidote 1.png");
        if (vector_of_powerUp[i].type == 6)
            vector_of_powerUp[i].setTexture("../textures/Health Potion 1.png");
    }
    for (int i = 0; i < vector_of_bullet.size(); i++) {
        vector_of_bullet[i].setTexture("../textures/bullet3.png");
    }
    //player.setTexture("../textures/tux_from_linux.png"); // TODO try to set the textures into the c-tor, don't update here otherwise animation won't work
}