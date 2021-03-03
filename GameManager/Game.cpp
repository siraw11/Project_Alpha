#include <iostream>
#include "Game.hpp"
#include "../GameStates/SplashState.hpp"
#include "../GameStates/MainMenuState.hpp"

namespace Alpha
{
    Game::Game( const std::string& title)
    {
        _data->window.create(sf::VideoMode::getDesktopMode(), title);
        _data->machine.AddState(StateRef(new MainMenuState(this->_data)));

        this->Run();
    }

    void Game::Run()
    {
        this->Load();

        while (this->_data->window.isOpen())
        {
            this->_data->machine.ProcessStateChanges();

            this->_data->machine.GetActiveState()->HandleInput();
            this->_data->machine.GetActiveState()->Update();
            this->_data->window.clear();
            this->_data->machine.GetActiveState()->Draw();
            this->_data->window.display();
        }
    }

    void Game::Load() {

        try{
            //background
            this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
            this->_data->assets.LoadTexture("GameOverBackground",MAIN_MENU_BACKGROUND_FILEPATH);
            this->_data->assets.LoadTexture("GameWinBackground",MAIN_MENU_BACKGROUND_FILEPATH);
            //title
            this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);
            this->_data->assets.LoadTexture("Win Title", WIN_TITLE_FILEPATH);
            this->_data->assets.LoadTexture("Lost Title", GAME_OVER_TITLE_FILEPATH);
            //buttons
            this->_data->assets.LoadTexture("Select Class", SELECT_CLASS);
            this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
            this->_data->assets.LoadTexture("Archer", ARCHER_BUTTON_FILEPATH);
            this->_data->assets.LoadTexture("Archer_menu", ARCHER_MENU_FILEPATH);
            this->_data->assets.LoadTexture("Knight", KNIGHT_BUTTON_FILEPATH);
            this->_data->assets.LoadTexture("Knight_menu",KNIGHT_MENU_FILEPATH);
            this->_data->assets.LoadTexture("Mage", MAGE_BUTTON_FILEPATH);
            this->_data->assets.LoadTexture("Mage_menu", MAGE_MENU_FILEPATH);
            this->_data->assets.LoadTexture("ExitButton", EXIT_BUTTON_FILEPATH);
            this->_data->assets.LoadTexture("RetryButton",RETRY_BUTTON_FILEPATH);
            //HUD
            this->_data->assets.LoadTexture("Heart", HEART_UI);
            this->_data->assets.LoadTexture("Arrow", ARROW_UI);
            this->_data->assets.LoadTexture("Mana", MANA_UI);
            this->_data->assets.LoadTexture("Armor", ARMOR_UI);
            //sound
            this->_data->assets.LoadSound("Arrow", ARROW_SOUND);
            this->_data->assets.LoadSound("Sword", SWORD_SOUND);
            this->_data->assets.LoadSound("Chest", CHEST_OPENING);
            this->_data->assets.LoadSound("FemaleHit", FEMALE_HIT_SOUND);
            this->_data->assets.LoadSound("Fireball", FIREBALL_SOUND);
            this->_data->assets.LoadSound("ManHit", MAN_HIT_SOUND);
            this->_data->assets.LoadSound("MonsterHit", MONSTER_HIT_SOUND);
            this->_data->assets.LoadSound("Ow", OW_SOUND);
            this->_data->assets.LoadSound("Scream", SCREAM_SOUND);
            this->_data->assets.LoadSound("Bone", BONE_SOUND);
            this->_data->assets.LoadSound("Click", CLICK_SOUND);
            this->_data->assets.LoadSound("Lose", YOU_LOSE_SOUND);
            this->_data->assets.LoadSound("Win", YOU_WIN_SOUND);
            this->_data->assets.LoadSound("Background", BACKGROUND_SOUND);
        }catch(const std::exception& exception) {
            std::cerr << exception.what() << std::endl;
        }
    }
}