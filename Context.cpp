//
// Created by andreatadde on 23/10/19.
//

#include "Context.h"

void Context::executeAggro(Enemy* enemy,Hero* hero) {
    aggro->behaviour(enemy, hero);
}

Context::Context(Aggro *aggro) {
    this->aggro = aggro;
}
