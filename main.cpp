#include "SFML/Graphics.hpp"
#include <iostream>
#include "GameEngine.h"

#include "Menu.h"

int main() {

    GameEngine *engine = new GameEngine();
    sf::RenderWindow window(engine->video, "Motocross 2D", sf::Style::Default);//Create window withe default resolution
    engine->window = &window;
    window.setFramerateLimit(engine->framerate);//Set framerate limit

    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    std::cout << "Play button has been pressed" << std::endl;
                                    engine->run();
                                    break;
                                case 1:
                                    std::cout << "Option button has been pressed" << std::endl;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }

                            break;
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

            }
        }

        window.clear();

        menu.draw(window);

        window.display();
    }
}