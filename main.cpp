#include <SFML/Graphics.hpp>
#include "Level.h"
#include "LevelManager.h"
#include "GameLogic.h"
#include "StateMachine/StateManager.h"
int main() {

    GameLogic logic;
    LevelManager levelManager;
    sf::Event event{};
    Input KeyBoardInput;
    StateManager stateManager;
    bool keypressed = false;

    //---------Loop di gioco------------//

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen);
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
                keypressed = true;
            }
        }
        if (!keypressed) {
            KeyBoardInput = Input::Null;
            keypressed = false;
        }

        stateManager.run(&window, KeyBoardInput, &levelManager, &logic);
        KeyBoardInput = Input::Null;
        window.display();
        window.clear(sf::Color(10, 108, 180));
    }
}
