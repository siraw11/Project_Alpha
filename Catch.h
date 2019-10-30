//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_CATCH_H
#define GAME_CATCH_H

#include "Aggro.h"

class Catch : public Aggro{
public:
    void behaviour(Enemy* enemy, Hero* hero);
};


#endif //GAME_CATCH_H
