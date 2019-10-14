#include "SFML/Graphics.hpp"
#include <iostream>
#include "GameEngine.h"
#include <vector>

#include "Menu.h"

int main() {

    GameEngine *engine = new GameEngine();
    sf::RenderWindow window(engine->video, "Motocross 2D", sf::Style::Default);//Create window withe default resolution
    engine->window = &window;
    window.setFramerateLimit(engine->framerate);

    Menu menu(MenuType::Home, MenuOption::loadMainMenuOptions(), engine);
    menu.open();

}