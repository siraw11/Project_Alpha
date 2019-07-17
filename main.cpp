#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "Map.h"

int main() {
    GameEngine *engine = new GameEngine();

    engine->run();
    return 0;
}

