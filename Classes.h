//
// Created by matteo on 31/10/19.
//

#ifndef PROJECT_ALPHA_CLASSES_H
#define PROJECT_ALPHA_CLASSES_H

#include "GameCharacter.h"
#include "Archer.h"

template <typename T>

class Classes: public GameCharacter{
public:
    Classes<T>(int hp, int s, int sp);

private:
    int armor{};
    int mana{};
    int arrows{};
    int range{};
};


#endif //PROJECT_ALPHA_CLASSES_H
