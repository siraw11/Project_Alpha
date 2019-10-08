//
// Created by davide on 15/09/19.
//

#ifndef GAME_GAMESTATES_H
#define GAME_GAMESTATES_H

//Classe con i vari stati di gioco cosi da poterli cambiare all'occorrenza
class GameStates {
public:
    GameStates();

    enum States {
        Main_menu,
        Level,
        Pause,
        Dead
    };
    States states;
};


#endif //GAME_GAMESTATES_H
