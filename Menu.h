//
// Created by Luca Graziotti on 2019-10-12.
//
#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "MenuOption.h"
#include "GameEngine.h"

#define MENU_MAX_NUMBER_OF_ITEMS 3
#define MENU_OFFSET_X  1.5 //margine x
#define MENU_OFFSET_Y  200 //margine y
enum MenuType {
    Home, Pause
};

class Menu {
public:
    Menu(MenuType type, std::vector<MenuOption *> options);

    ~Menu();


    void MoveUp();

    void MoveDown();

    void draw();

    int getSelectedItemIndex() const;

    void setSelectedItemIndex(int selectedItemIndex);

    const sf::Font &getFont() const;

    void setFont(const sf::Font &font);

    const sf::Text *getMenu() const;

    void open();

    std::vector<MenuOption *> options;

private:
    MenuType type;
    int selectedItemIndex;
};
