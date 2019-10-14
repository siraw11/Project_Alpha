//
// Created by Luca Graziotti on 2019-10-12.
//
#include <MacTypes.h>
#include "Menu.h"

Menu::Menu(MenuType _type, std::vector<MenuOption *> _options = {}, GameEngine *_engine = nullptr) : type(_type),
                                                                                                     options(
                                                                                                             _options),
                                                                                                     engine(_engine) {
    selectedItemIndex = 0;
}


Menu::~Menu() {
}

void Menu::draw(sf::RenderWindow *window) {
    std::vector<MenuOption *>::iterator it;
    float width = window->getSize().x;
    float height = window->getSize().y;
    int i = 0;
    for (it = options.begin(); it != options.end(); it++, i++) {
        (*it)->option.setPosition(
                sf::Vector2f(width / MENU_OFFSET_X, (height / (MENU_MAX_NUMBER_OF_ITEMS + 1) * i) + MENU_OFFSET_Y));
        if (i == selectedItemIndex) {
            (*it)->option.setColor(sf::Color::Red);
        }

        window->draw((*it)->option);
    }
}

void Menu::MoveUp() {
    if (options.size() > 0) {
        if (selectedItemIndex - 1 >= 0) {
            options[selectedItemIndex]->option.setColor(sf::Color::White);
            selectedItemIndex--;
            options[selectedItemIndex]->option.setColor(sf::Color::Red);
        }
    }
}

void Menu::MoveDown() {
    if (options.size() > 0) {
        if (selectedItemIndex + 1 < 3) {
            options[selectedItemIndex]->option.setColor(sf::Color::White);
            selectedItemIndex++;
            options[selectedItemIndex]->option.setColor(sf::Color::Red);
        }
    }
}

int Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}

void Menu::setSelectedItemIndex(int selectedItemIndex) {
    Menu::selectedItemIndex = selectedItemIndex;
}


void Menu::open() {
    sf::RenderWindow *window = engine->window;
    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (true) {
                switch (event.type) {
                    case sf::Event::KeyReleased:
                        switch (event.key.code) {
                            case sf::Keyboard::Up:
                                this->MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                this->MoveDown();
                                break;

                            case sf::Keyboard::Return:
                                switch (type) {
                                    case Home:
                                        switch (this->getSelectedItemIndex()) {
                                            case 0:
                                                std::cout << "Play button has been pressed" << std::endl;
                                                engine->run();
                                                break;
                                            case 1:
                                                std::cout << "Option button has been pressed" << std::endl;
                                                break;
                                            case 2:
                                                window->close();
                                                break;
                                        }
                                        break;
                                    case Pause:
                                        switch (this->getSelectedItemIndex()) {
                                            case 0:
                                                std::cout << "Resume button has been pressed" << std::endl;
                                                engine->setPause(false);
                                                return;
                                                break;
                                            case 1:
                                                window->close();
                                                break;
                                        }
                                        break;
                                }


                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window->close();

                        break;

                }
            }

        }

        this->draw(window);


        window->display();
    }
}

MenuType Menu::getType() const {
    return type;
}

void Menu::setType(MenuType type) {
    Menu::type = type;
}

