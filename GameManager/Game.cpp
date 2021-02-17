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


        while (this->_data->window.isOpen())
        {
            this->_data->machine.ProcessStateChanges();

            this->_data->machine.GetActiveState()->HandleInput();
            this->_data->machine.GetActiveState()->Update();
            this->_data->machine.GetActiveState()->Draw();
        }
    }
}