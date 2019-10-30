//
// Created by andreatadde on 23/10/19.
//

#include "Context.h"

void Context::executeAggro(Enemy* enemy,Hero* hero, std::vector<Platform> *platform) {
    aggro->behaviour(enemy, hero, platform);
}

Context::Context(Aggro *aggro) {
    this->aggro = aggro;
}
