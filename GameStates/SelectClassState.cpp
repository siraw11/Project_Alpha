#include <utility>



#include <sstream>
#include "MainMenuState.hpp"
#include "SelectClassState.h"
#include "GameState.hpp"
#include "PauseState.hpp"
#include "../GameManager/DEFINITIONS.hpp"
//#include "../PlayerType.h"




#include <iostream>

namespace Alpha {
    SelectClassState::SelectClassState(GameDataRef data) : _data(std::move(data)) {

    }

    void SelectClassState::Init() {
        std::cout <<"SelectClassState";
        this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Archer", ARCHER_BUTTON_FILEPATH);
        this->_data->assets.LoadTexture("Knight", KNIGHT_BUTTON_FILEPATH);
        this->_data->assets.LoadTexture("Mage", MAGE_BUTTON_FILEPATH);
        this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_archerButton.setTexture(this->_data->assets.GetTexture("Archer"));
        this->_knightButton.setTexture(this->_data->assets.GetTexture("Knight"));
        this->_mageButton.setTexture(this->_data->assets.GetTexture("Mage"));
        this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

        this->_archerButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_archerButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 3) - (this->_archerButton.getGlobalBounds().height / 2));
        this->_knightButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_knightButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 2) - (this->_knightButton.getGlobalBounds().height / 2));
        this->_mageButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_mageButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 1.5) - (this->_mageButton.getGlobalBounds().height / 2));
        this->_title.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.5);
    }

    void SelectClassState::HandleInput() {


        sf::Event event{};
        while (this->_data->window.pollEvent(event)) {
            std::cout <<"SelectClassState \n";
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }


            if (this->_data->input.IsSpriteClicked(this->_archerButton, sf::Mouse::Left, this->_data->window)){
                Hero* hero= CharacterFactory::createCharacter(PlayerType::ARCHER);

               // this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

               this->_data->machine.AddState(StateRef(new GameState(_data,hero)), true);




            } else if (this->_data->input.IsSpriteClicked(this->_knightButton, sf::Mouse::Left, this->_data->window)) {
                Hero* hero= CharacterFactory::createCharacter(PlayerType::KNIGHT);

                //this->_data->machine.AddState(StateRef(new GameState(_data,hero)), true);
                this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
            }
            else if (this->_data->input.IsSpriteClicked(this->_mageButton, sf::Mouse::Left, this->_data->window)) {
                Hero* hero= CharacterFactory::createCharacter(PlayerType::MAGE);

                this->_data->machine.AddState(StateRef(new GameState(_data,hero)), true);
            }
        }

    }

    void SelectClassState::Update() {

    }

    void SelectClassState::Draw() {



        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_archerButton);
        this->_data->window.draw(this->_knightButton);
        this->_data->window.draw(this->_mageButton);
        this->_data->window.draw(this->_title);
        this->_data->window.display();
    }
}