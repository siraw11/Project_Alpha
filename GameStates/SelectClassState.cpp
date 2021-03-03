#include <utility>



#include <sstream>
#include "MainMenuState.hpp"
#include "SelectClassState.h"
#include "GameState.hpp"

#include "../GameManager/DEFINITIONS.hpp"
#include "../CharacterFactory.h"
//#include "../PlayerType.h"




#include <iostream>

namespace Alpha {
    SelectClassState::SelectClassState(GameDataRef data) : _data(std::move(data)) {
        std::cout<<"select class"<<std::endl;
    }

    void SelectClassState::Init() {


        this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_archerButton.setTexture(this->_data->assets.GetTexture("Archer"));
        this->_knightButton.setTexture(this->_data->assets.GetTexture("Knight"));
        this->_mageButton.setTexture(this->_data->assets.GetTexture("Mage"));
        this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

        this->_archerMenu.setTexture(this->_data->assets.GetTexture("Archer_menu"));
        this->_knightMenu.setTexture(this->_data->assets.GetTexture("Knight_menu"));
        this->_mageMenu.setTexture(this->_data->assets.GetTexture("Mage_menu"));

        this->_knightButton.setScale(0.5,0.5);
        this->_archerButton.setScale(0.5,0.5);
        this->_mageButton.setScale(0.5,0.5);

        this->_knightMenu.setScale(1.3,1.3);
        this->_archerMenu.setScale(1.3,1.3);
        this->_mageMenu.setScale(1.3,1.3);


        this->_archerButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_archerButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 3) - (this->_archerButton.getGlobalBounds().height / 2));
        this->_knightButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_knightButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 2) - (this->_knightButton.getGlobalBounds().height / 2));
        this->_mageButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_mageButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 1.5) - (this->_mageButton.getGlobalBounds().height / 2));
        this->_title.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.5);

    this->_archerMenu.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_archerMenu.getGlobalBounds().width / 2)+ (164), (this->_data->window.getSize().y/ 3) - (this->_archerMenu.getGlobalBounds().height / 2));
        this->_knightMenu.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_knightMenu.getGlobalBounds().width / 2)+(164), (this->_data->window.getSize().y/ 2) - (this->_knightMenu.getGlobalBounds().height / 2));
        this->_mageMenu.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_mageMenu.getGlobalBounds().width / 2)+(164), (this->_data->window.getSize().y/ 1.5) - (this->_mageMenu.getGlobalBounds().height / 2));


        click.setBuffer(this->_data->assets.GetSound("Click"));
    }

    void SelectClassState::HandleInput() {


        sf::Event event{};
        while (this->_data->window.pollEvent(event)) {

            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }


            if (this->_data->input.IsSpriteClicked(this->_archerButton, sf::Mouse::Left, this->_data->window)){
                click.play();
                Hero* hero= CharacterFactory::createCharacter(PlayerType::ARCHER);

                this->_data->machine.AddState(StateRef(new GameState(_data,hero)), true);
                std::cout<<"rimpiazza select class"<<std::endl;

            } else if (this->_data->input.IsSpriteClicked(this->_knightButton, sf::Mouse::Left, this->_data->window)) {
                click.play();
                Hero* hero= CharacterFactory::createCharacter(PlayerType::KNIGHT);

                this->_data->machine.AddState(StateRef(new GameState(_data,hero)), true);
                std::cout<<"rimpiazza select class"<<std::endl;
            }
            else if (this->_data->input.IsSpriteClicked(this->_mageButton, sf::Mouse::Left, this->_data->window)) {
                click.play();
                Hero* hero= CharacterFactory::createCharacter(PlayerType::MAGE);

                this->_data->machine.AddState(StateRef(new GameState(_data,hero)), true);
                std::cout<<"rimpiazza select class"<<std::endl;
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
        this->_data->window.draw(this->_archerMenu);
        this->_data->window.draw(this->_knightMenu);
        this->_data->window.draw(this->_mageMenu);
    }

    SelectClassState::~SelectClassState() = default;
}