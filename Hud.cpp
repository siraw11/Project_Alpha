//
// Created by davide on 02/11/19.
//

#include "Hud.h"
#include "SFML/Graphics.hpp"

Hud::Hud() {
    font.loadFromFile("textures/arial_narrow_7.ttf");
    playerHpTex.loadFromFile("textures/red_heart.png");
    enemyHpTex.loadFromFile("textures/green_heart.png");
    sizeHeart.x = 30;
    sizeHeart.y = 30;
    offset.x = -450;
    offset.y = -330;
    hp.setFont(font);
    hp.setCharacterSize(textSize);
    hp.setString("HP :");
    hp.setFillColor(sf::Color::Black);
    invulnerabilityTime.setFont(font);
    invulnerabilityTime.setCharacterSize(textSize);
    invulnerabilityTime.setString("Invulnerable");
    invulnerabilityTime.setFillColor(sf::Color::Black);
};

void Hud::update(sf::RenderWindow *window, Level *level) {
    while (vector_of_hearts.size() < level->player.HP) {
        sf::RectangleShape heart;
        heart.setTexture(&playerHpTex);
        heart.setSize(sizeHeart);
        vector_of_hearts.push_back(heart);
    }
    if (vector_of_hearts.size() > level->player.HP) {
        vector_of_hearts.pop_back();
    }
    if (vector_of_enemyhp.size() < level->vector_of_enemy.size()) {
        for (int i = 0; i < level->vector_of_enemy.size(); i++) {
            sf::RectangleShape heart;
            heart.setTexture(&enemyHpTex);
            heart.setSize(sizeHeart);
            vector_of_enemyhp.push_back(heart);
        }
    }
    if (vector_of_enemyhp.size() > level->vector_of_enemy.size()) {
        vector_of_enemyhp.pop_back();
    }
    for (int i = 0; i < vector_of_hearts.size(); i++) {
        vector_of_hearts[i].setPosition(level->camera.getCenter().x + (sizeHeart.x * i) + offset.x,
                                        level->camera.getCenter().y + offset.y);
        window->draw(vector_of_hearts[i]);
    }
    for (int i = 0; i < vector_of_enemyhp.size(); i++) {
        for (int j = 0; j < level->vector_of_enemy[i].HP; j++) {
            vector_of_enemyhp[i].setPosition(
                    level->vector_of_enemy[i].x + (j * sizeHeart.x) - ((level->vector_of_enemy[i].width) / 2),
                    level->vector_of_enemy[i].y - level->vector_of_enemy[i].height);
            if (j < level->vector_of_enemy[i].HP) {
                window->draw(vector_of_enemyhp[i]);
            }
        }
    }
    hp.setPosition(level->camera.getCenter().x + offset.x - 50, level->camera.getCenter().y + offset.y);
    invulnerabilityTime.setPosition(level->camera.getCenter().x + offset.x + (level->player.HP * sizeHeart.x) + 20,
                                    level->camera.getCenter().y + offset.y);
    for (int i = 0; i < level->vector_of_enemy.size(); i++) {
        if (level->clock.getElapsedTime() <
            level->vector_of_enemy[i].lastAttackTime + level->vector_of_enemy[i].attackReload
            && level->vector_of_enemy[i].lastAttackTime != sf::seconds(0)) {
            window->draw(invulnerabilityTime);
        }
    }
    window->draw(hp);
}

