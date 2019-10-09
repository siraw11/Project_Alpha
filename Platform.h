//
// Created by davide on 25/08/19.
//

#ifndef GAME_PLATFORM_H
#define GAME_PLATFORM_H

#include "RectangleShape.h"

//Oggetto per i tile di gioco

class Platform : public RectangleShape {
public:
    Platform(int type);//Prende un intero in ingresso solo per sapere quale texture applicare
public:
    int t;
};


#endif //TESTGAME_2_PLATFORM_H
