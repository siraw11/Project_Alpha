//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_ARCHER_H
#define EXAM_PROJECT_ARCHER_H

#include "GameCharacter.h"


class Archer {
public:
    Archer();

    int getArrows() const;

    void setArrows(int arrows);

    void setRange(int range);

    int getRange() const;

    void fightA(GameCharacter *enemy);




private:

    int range;
    int arrows;

};
#endif //EXAM_PROJECT_ARCHER_H
