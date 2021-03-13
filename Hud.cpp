//
// Created by waris on 25/01/21.
//

#include <iostream>
#include "Hud.h"
#include "GameManager/DEFINITIONS.hpp"
#include "sstream"


Hud::Hud(Hero* hero, const Alpha::GameDataRef &data) {
    data->assets.LoadFont("font",FONT);

     //life
    this->_heart.setTexture(data->assets.GetTexture("Heart"));
    this->_heart.setScale(3, 3);
    _heart.setPosition(hero->getPosition().x - 25, hero->getPosition().y - 30);
    std::ostringstream oss;
    oss << hero->getLife();
    this->life.setFont(data->assets.GetFont("font"));
    this->life.setString(oss.str());
    this->life.setFillColor(sf::Color::White);
    this->life.setPosition(hero->getPosition().x + 25, hero->getPosition().y - 30);
    this->life.setCharacterSize(45);


    switch (hero->playerType) {
        case PlayerType::ARCHER : {
            //Arrow
            this->_arrow_1.setTexture(data->assets.GetTexture("Arrow"));
            this->_arrow_1.setScale(3, 3);
            _arrow_1.setPosition(hero->getPosition().x + 55, hero->getPosition().y - 30);

            std::ostringstream iss;
            iss << hero->getArrow();
            this->arrow.setFont(data->assets.GetFont("font"));
            this->arrow.setString(iss.str());
            this->arrow.setFillColor(sf::Color::White);
            this->arrow.setPosition(hero->getPosition().x + 110, hero->getPosition().y - 30);
            this->arrow.setCharacterSize(45);
            break; }


        case  PlayerType::MAGE:
        {
            //Mana
            this->_mana.setTexture(data->assets.GetTexture("Mana"));
            this->_mana.setScale(3, 3);
            _mana.setPosition(hero->getPosition().x + 55, hero->getPosition().y - 30);

            std::ostringstream ess;
            ess << hero->getMana();
            this->mana.setFont(data->assets.GetFont("font"));
            this->mana.setString(ess.str());
            this->mana.setFillColor(sf::Color::White);
            this->mana.setPosition(hero->getPosition().x + 110, hero->getPosition().y - 30);
            this->mana.setCharacterSize(45);
            break;  }

        case PlayerType::KNIGHT : {
            //Armor
            this->_armor.setTexture(data->assets.GetTexture("Armor"));
            this->_armor.setScale(2.7, 2.7);
            _armor.setPosition(hero->getPosition().x + 55, hero->getPosition().y - 30);

            std::ostringstream ass;
            ass << hero->getArmor();
            this->armor.setFont(data->assets.GetFont("font"));
            this->armor.setString(ass.str());
            this->armor.setFillColor(sf::Color::White);
            this->armor.setPosition(hero->getPosition().x + 110, hero->getPosition().y - 30);
            this->armor.setCharacterSize(45);
            break; }
    }
}

void Hud::update(const Hero &hero) {
    this->_heart.setPosition(hero.getPosition().x - 25,hero.getPosition().y - 30 );
    this->life.setPosition(hero.getPosition().x + 25,hero.getPosition().y - 30);
    std::ostringstream oss;
    oss << hero.getLife();
    this->life.setString(oss.str());


switch(hero.playerType){
    case PlayerType ::ARCHER:{
        this->_arrow_1.setPosition(hero.getPosition().x + 55,hero.getPosition().y-30 );
        this->arrow.setPosition(hero.getPosition().x+110,hero.getPosition().y-30);
        std::ostringstream iss;
        iss << hero.getArrow();
        this->arrow.setString(iss.str());
        break;
    }
    case PlayerType :: KNIGHT:{
        this->_armor.setPosition(hero.getPosition().x + 55,hero.getPosition().y-30 );
        this->armor.setPosition(hero.getPosition().x+110,hero.getPosition().y-30);
        std::ostringstream ass;
        ass << hero.getArmor();
        this->armor.setString(ass.str());
        break;
    }
    case PlayerType ::MAGE:{
        this->_mana.setPosition(hero.getPosition().x + 55,hero.getPosition().y-30 );
        this->mana.setPosition(hero.getPosition().x+110,hero.getPosition().y-30);
        std::ostringstream ess;
        ess << hero.getMana();
        this->mana.setString(ess.str());
        break;
    }

}

}

void Hud::draw(const Alpha::GameDataRef &data) {

    data->window.draw(_heart);
    data->window.draw(_arrow_1);
    data->window.draw(_mana);
    data->window.draw(_armor);
    data->window.draw(life);
    data->window.draw(arrow);
    data->window.draw(mana);
    data->window.draw(armor);

}


Hud::~Hud() = default;


