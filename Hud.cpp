//
// Created by waris on 25/01/21.
//

#include <iostream>
#include "Hud.h"
#include "GameManager/DEFINITIONS.hpp"
#include "sstream"


Hud::Hud(const std::unique_ptr<Hero> &hero,const Alpha::GameDataRef &_data) {

    //sf::Font font;


    _data->assets.LoadFont("font",FONT);

//    if (!font.loadFromFile(FONT)) {
//        // error...
//    }

    //UI Elements

    //Life
    _data->assets.LoadTexture("Heart", HEART_UI);
    this->_heart.setTexture(_data->assets.GetTexture("Heart"));
    this->_heart.setScale(3, 3);
    _heart.setPosition(hero->getPosition().x - 25, hero->getPosition().y - 30);

    std::ostringstream oss;
    oss << hero->getLife();
    this->life.setFont(_data->assets.GetFont("font"));
    this->life.setString(oss.str());
    this->life.setFillColor(sf::Color::White);
    this->life.setPosition(hero->getPosition().x + 25, hero->getPosition().y - 30);
    this->life.setCharacterSize(45);


    switch (hero->playerType) {
        case PlayerType::ARCHER : {
            //Arrow
            _data->assets.LoadTexture("Arrow", ARROW_UI);
            this->_arrow_1.setTexture(_data->assets.GetTexture("Arrow"));
            this->_arrow_1.setScale(3, 3);
            _arrow_1.setPosition(hero->getPosition().x + 55, hero->getPosition().y - 30);

            std::ostringstream iss;
            iss << hero->getArrow();
            this->arrow.setFont(_data->assets.GetFont("font"));
            this->arrow.setString(iss.str());
            this->arrow.setFillColor(sf::Color::White);
            this->arrow.setPosition(hero->getPosition().x + 110, hero->getPosition().y - 30);
            this->arrow.setCharacterSize(45);
            break; }


        case  PlayerType::MAGE:
        {
            //Mana
            _data->assets.LoadTexture("Mana", MANA_UI);
            this->_mana.setTexture(_data->assets.GetTexture("Mana"));
            this->_mana.setScale(3, 3);
            _mana.setPosition(hero->getPosition().x + 55, hero->getPosition().y - 30);

            std::ostringstream ess;
            ess << hero->getMana();
            this->mana.setFont(_data->assets.GetFont("font"));
            this->mana.setString(ess.str());
            this->mana.setFillColor(sf::Color::White);
            this->mana.setPosition(hero->getPosition().x + 110, hero->getPosition().y - 30);
            this->mana.setCharacterSize(45);
            break;  }

        case PlayerType::KNIGHT : {
            //Armor
            _data->assets.LoadTexture("Armor", ARMOR_UI);
            this->_armor.setTexture(_data->assets.GetTexture("Armor"));
            this->_armor.setScale(2.7, 2.7);
            _armor.setPosition(hero->getPosition().x + 55, hero->getPosition().y - 30);

            std::ostringstream ass;
            ass << hero->getArmor();
            this->armor.setFont(_data->assets.GetFont("font"));
            this->armor.setString(ass.str());
            this->armor.setFillColor(sf::Color::White);
            this->armor.setPosition(hero->getPosition().x + 110, hero->getPosition().y - 30);
            this->armor.setCharacterSize(45);
            break; }
    }
}

void Hud::update(const std::unique_ptr<Hero> &hero) {
    this->_heart.setPosition(hero->getPosition().x - 25,hero->getPosition().y - 30 );
    this->life.setPosition(hero->getPosition().x + 25,hero->getPosition().y - 30);
    std::ostringstream oss;
    oss << hero->getLife();
    this->life.setString(oss.str());


switch(hero->playerType){
    case PlayerType ::ARCHER:{
        this->_arrow_1.setPosition(hero->getPosition().x + 55,hero->getPosition().y-30 );
        this->arrow.setPosition(hero->getPosition().x+110,hero->getPosition().y-30);
        std::ostringstream iss;
        iss << hero->getArrow();
        this->arrow.setString(iss.str());
        break;
    }
    case PlayerType :: KNIGHT:{
        this->_armor.setPosition(hero->getPosition().x + 55,hero->getPosition().y-30 );
        this->armor.setPosition(hero->getPosition().x+110,hero->getPosition().y-30);
        std::ostringstream ass;
        ass << hero->getArmor();
        this->armor.setString(ass.str());
        break;
    }
    case PlayerType ::MAGE:{
        this->_mana.setPosition(hero->getPosition().x + 55,hero->getPosition().y-30 );
        this->mana.setPosition(hero->getPosition().x+110,hero->getPosition().y-30);
        std::ostringstream ess;
        ess << hero->getMana();
        this->mana.setString(ess.str());
        break;
    }

}

}

void Hud::draw(const Alpha::GameDataRef &_data) {

    _data->window.draw(_heart);
    _data->window.draw(_arrow_1);
    _data->window.draw(_mana);
    _data->window.draw(_armor);
    _data->window.draw(life);
    _data->window.draw(arrow);
    _data->window.draw(mana);
    _data->window.draw(armor);

}


Hud::~Hud() = default;


