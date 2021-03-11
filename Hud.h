//
// Created by waris on 25/01/21.
//

#ifndef PROJECT_ALPHA_HUD_H
#define PROJECT_ALPHA_HUD_H


#include "Hero.h"
#include "GameManager/Game.hpp"

class Hud {
public:
    //constructor and destructor
    Hud( Hero* hero, const Alpha::GameDataRef &_data);
    ~Hud();

    //functions
    void update(const Hero &hero);

    void draw(const Alpha::GameDataRef &_data);

private:

    sf::Sprite _heart;

    sf::Sprite _mana;

    sf::Sprite _armor;

    sf::Sprite _arrow_1;

    sf::Text life;

    sf::Text arrow;

    sf::Text mana;

    sf::Text armor;

};




#endif //PROJECT_ALPHA_HUD_H
