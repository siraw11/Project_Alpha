//
// Created by davide on 26/10/19.
//

#ifndef GAME_ACHIEVEMENT_H
#define GAME_ACHIEVEMENT_H


#include <SFML/Graphics.hpp>

class Achievement {

public:
    Achievement();

    void update();

    void drawPopUp(sf::RenderWindow *window,sf::View* camera);

    sf::Clock *clock;
    bool achieved = false;
    sf::Text description;
    sf::Text unlocked;


protected:
    sf::Text textPopUp;

private:
    sf::Vector2i offsetPopUp;
    sf::Vector2f boxPos;
    unsigned int characterSize = 20;
    sf::Time popUpLife = sf::seconds(3);
    sf::Time firstFrame;
    sf::Font font;
    sf::Uint8 i = 50;
    sf::Uint8 opacity = 1;
    bool nodraw = false;
    bool endDraw = false;
    unsigned int sizeText = 20;

};


#endif //GAME_ACHIEVEMENT_H
