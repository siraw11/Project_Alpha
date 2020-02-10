#include <SFML/Graphics.hpp>
#include "LevelManager.h"
#include "GameLogic.h"
#include "StateMachine/StateManager.h"

int main() {
    const int nFiles = 2;
    std::string levelName[nFiles] = {"Levels/Level1","Levels/Level2"};

    GameLogic logic;
    LevelManager* levelManager = new LevelManager(levelName, nFiles);
    sf::Event event{};
    Input KeyBoardInput = Input::Null;
    StateManager* stateManager = new StateManager;
    bool keyPressed = false;
    sf::Image icon;
    icon.loadFromFile("textures/gameIcon.png");

    //---------Loop di gioco------------//

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Octopus Killer", sf::Style::Fullscreen);
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //----Gestione input----//
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down) {
                    KeyBoardInput = Input::Down;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    KeyBoardInput = Input::Up;
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    KeyBoardInput = Input::Enter;
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    KeyBoardInput = Input::Escape;
                }
                keyPressed = true;
            }
        }
        if (!keyPressed) {
            KeyBoardInput = Input::Null;
            keyPressed = false;
        }

        stateManager->run(&window, KeyBoardInput, levelManager, &logic);
        KeyBoardInput = Input::Null;
        window.display();
        window.clear(sf::Color(10, 108, 180));
    }
    delete levelManager;
    delete stateManager;
}
