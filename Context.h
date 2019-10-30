//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H


#include "Aggro.h"
#include "Enemy.h"


class Aggro;
class Enemy;

class Context {
private:
    Aggro* aggro;
public:
    //Context() = default;
    Context(Aggro* aggro);
    void executeAggro(Enemy* enemy, Hero* hero);
};


#endif //GAME_CONTEXT_H
