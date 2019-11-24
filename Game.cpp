//
// Created by Luca Graziotti on 04/11/2019.
//

#include <iostream>
#include "Game.h"
#include "GameStates/MenuHomeState.h"

GameDataRef Game::gameData = std::make_shared<GameData>();

Game::Game() {
    if (Game::gameData->resources.loadEssentialResources()) {
        std::cout << "Resources loaded successfully" << std::endl;
        gameData->window.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Motocross 2D",
                                sf::Style::Close | sf::Style::Titlebar);
        gameData->window.setVerticalSyncEnabled(true);

        Game::gameData->match = std::unique_ptr<Match>(new Match());
        gameData->machine.push_state(StateRef(new MenuHomeState()));

        Game::gameData->player = std::unique_ptr<Player>(new Player("Player", 1000));
    } else {
        std::cout << "Fatal error: Cannot load essential resources" << std::endl;
    }
}

void Game::Run() {
    while (Game::gameData->window.isOpen()) {
        sf::Event event{};
        while (Game::gameData->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::gameData->window.close();
            } else {
                Game::gameData->machine.get_current_state()->handleInput(event);
            }
        }
        Game::gameData->machine.get_current_state()->update();
        Game::gameData->machine.get_current_state()->draw();
        Game::gameData->window.display();
    }
}