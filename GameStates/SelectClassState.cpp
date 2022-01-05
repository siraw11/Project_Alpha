#include <utility>




#include "MainMenuState.hpp"
#include "SelectClassState.h"
#include "GameState.hpp"
#include "../CharacterFactory.h"





#include <iostream>

namespace Alpha {
    SelectClassState::SelectClassState(GameDataRef data) : data(std::move(data)) {

    }

    void SelectClassState::Init() {


        this->_background.setTexture(this->data->assets.GetTexture("Background"));
        this->_archerButton.setTexture(this->data->assets.GetTexture("Archer"));
        this->_knightButton.setTexture(this->data->assets.GetTexture("Knight"));
        this->_mageButton.setTexture(this->data->assets.GetTexture("Mage"));
        this->_title.setTexture(this->data->assets.GetTexture("Game Title"));

        this->_archerMenu.setTexture(this->data->assets.GetTexture("Archer_menu"));
        this->_knightMenu.setTexture(this->data->assets.GetTexture("Knight_menu"));
        this->_mageMenu.setTexture(this->data->assets.GetTexture("Mage_menu"));

        this->_knightButton.setScale(0.5,0.5);
        this->_archerButton.setScale(0.5,0.5);
        this->_mageButton.setScale(0.5,0.5);

        this->_knightMenu.setScale(1.3,1.3);
        this->_archerMenu.setScale(1.3,1.3);
        this->_mageMenu.setScale(1.3,1.3);


        this->_archerButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_archerButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 3) - (this->_archerButton.getGlobalBounds().height / 2));
        this->_knightButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_knightButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 2) - (this->_knightButton.getGlobalBounds().height / 2));
        this->_mageButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_mageButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 1.5) - (this->_mageButton.getGlobalBounds().height / 2));
        this->_title.setPosition((this->data->window.getSize().x/ 2.0) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.5);

    this->_archerMenu.setPosition((this->data->window.getSize().x/ 2.0) - (this->_archerMenu.getGlobalBounds().width / 2)+ (164), (this->data->window.getSize().y/ 3) - (this->_archerMenu.getGlobalBounds().height / 2));
        this->_knightMenu.setPosition((this->data->window.getSize().x/ 2.0) - (this->_knightMenu.getGlobalBounds().width / 2)+(164), (this->data->window.getSize().y/ 2) - (this->_knightMenu.getGlobalBounds().height / 2));
        this->_mageMenu.setPosition((this->data->window.getSize().x/ 2.0) - (this->_mageMenu.getGlobalBounds().width / 2)+(164), (this->data->window.getSize().y/ 1.5) - (this->_mageMenu.getGlobalBounds().height / 2));


        click.setBuffer(this->data->assets.GetSound("Click"));
    }

    void SelectClassState::HandleInput() {


        sf::Event event{};
        while (this->data->window.pollEvent(event)) {

            if (sf::Event::Closed == event.type) {
                this->data->window.close();
            }


            if (this->data->input.IsSpriteClicked(this->_archerButton, sf::Mouse::Left, this->data->window)){
                click.play();
                Hero* hero= CharacterFactory::createCharacter(PlayerType::ARCHER);

                this->data->machine.AddState(StateRef(new GameState(data, hero)), true);

            } else if (this->data->input.IsSpriteClicked(this->_knightButton, sf::Mouse::Left, this->data->window)) {
                click.play();
                Hero* hero= CharacterFactory::createCharacter(PlayerType::KNIGHT);

                this->data->machine.AddState(StateRef(new GameState(data, hero)), true);
            }
            else if (this->data->input.IsSpriteClicked(this->_mageButton, sf::Mouse::Left, this->data->window)) {
                click.play();
                Hero* hero= CharacterFactory::createCharacter(PlayerType::MAGE);

                this->data->machine.AddState(StateRef(new GameState(data, hero)), true);
            }
        }

    }

    void SelectClassState::Update() {

    }

    void SelectClassState::Draw() {

        this->data->window.draw(this->_background);
        this->data->window.draw(this->_archerButton);
        this->data->window.draw(this->_knightButton);
        this->data->window.draw(this->_mageButton);
        this->data->window.draw(this->_title);
        this->data->window.draw(this->_archerMenu);
        this->data->window.draw(this->_knightMenu);
        this->data->window.draw(this->_mageMenu);
    }

    SelectClassState::~SelectClassState() = default;
}