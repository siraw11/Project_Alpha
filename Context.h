//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H


#include "Aggro.h"
#include "Enemy.h"
#include "Platform.h"


class Aggro;
class Enemy;

class Context {
private:
    Aggro* aggro;
public:
    //Context() = default;
    Context(Aggro* aggro);
    void executeAggro(Enemy* enemy, Hero* hero, std::vector<Platform> *platform);
};


#endif //GAME_CONTEXT_H
