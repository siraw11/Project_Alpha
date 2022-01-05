#include <iostream>
#include "Game.hpp"
#include "../GameStates/MainMenuState.hpp"

namespace Alpha
{
    Game::Game( const std::string& title)
    {
        data->window.create(sf::VideoMode::getDesktopMode(), title);
        data->machine.AddState(StateRef(new MainMenuState(this->data)));

        this->Run();
    }

    void Game::Run()
    {
        this->Load();

        while (this->data->window.isOpen())
        {
            this->data->machine.ProcessStateChanges();

            this->data->machine.GetActiveState()->HandleInput();
            this->data->machine.GetActiveState()->Update();
            this->data->window.clear();
            this->data->machine.GetActiveState()->Draw();
            this->data->window.display();
        }
    }

    void Game::Load() {

        try{
            //background
            this->data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
            this->data->assets.LoadTexture("GameOverBackground",MAIN_MENU_BACKGROUND_FILEPATH);
            this->data->assets.LoadTexture("GameWinBackground",MAIN_MENU_BACKGROUND_FILEPATH);
            //title
            this->data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);
            this->data->assets.LoadTexture("Win Title", WIN_TITLE_FILEPATH);
            this->data->assets.LoadTexture("Lost Title", GAME_OVER_TITLE_FILEPATH);
            //buttons
            this->data->assets.LoadTexture("Select Class", SELECT_CLASS);
            this->data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
            this->data->assets.LoadTexture("Archer", ARCHER_BUTTON_FILEPATH);
            this->data->assets.LoadTexture("Archer_menu", ARCHER_MENU_FILEPATH);
            this->data->assets.LoadTexture("Knight", KNIGHT_BUTTON_FILEPATH);
            this->data->assets.LoadTexture("Knight_menu",KNIGHT_MENU_FILEPATH);
            this->data->assets.LoadTexture("Mage", MAGE_BUTTON_FILEPATH);
            this->data->assets.LoadTexture("Mage_menu", MAGE_MENU_FILEPATH);
            this->data->assets.LoadTexture("ExitButton", EXIT_BUTTON_FILEPATH);
            this->data->assets.LoadTexture("RetryButton",RETRY_BUTTON_FILEPATH);
            //HUD
            this->data->assets.LoadTexture("Heart", HEART_UI);
            this->data->assets.LoadTexture("Arrow", ARROW_UI);
            this->data->assets.LoadTexture("Mana", MANA_UI);
            this->data->assets.LoadTexture("Armor", ARMOR_UI);
            this->data->assets.LoadTexture("Trophy",TROPHY_FILEPATH);
            //sound
            this->data->assets.LoadSound("Arrow", ARROW_SOUND);
            this->data->assets.LoadSound("Sword", SWORD_SOUND);
            this->data->assets.LoadSound("Chest", CHEST_OPENING);
            this->data->assets.LoadSound("FemaleHit", FEMALE_HIT_SOUND);
            this->data->assets.LoadSound("Fireball", FIREBALL_SOUND);
            this->data->assets.LoadSound("ManHit", MAN_HIT_SOUND);
            this->data->assets.LoadSound("MonsterHit", MONSTER_HIT_SOUND);
            this->data->assets.LoadSound("Ow", OW_SOUND);
            this->data->assets.LoadSound("Scream", SCREAM_SOUND);
            this->data->assets.LoadSound("Bone", BONE_SOUND);
            this->data->assets.LoadSound("Click", CLICK_SOUND);
            this->data->assets.LoadSound("Lose", YOU_LOSE_SOUND);
            this->data->assets.LoadSound("Win", YOU_WIN_SOUND);
            this->data->assets.LoadSound("Background", BACKGROUND_SOUND);
        }catch(const std::exception& exception) {
            std::cerr << exception.what() << std::endl;
        }
    }
}