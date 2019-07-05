//
// Created by waris on 20/06/19.
//

#include "Archer.h"

Archer::Archer(int hp, int s, int sp): GameCharacter(hp, s, sp), range(3), arrows(10){
    
}






int Archer::getRange() const {
    return range;
}

void Archer::setRange(int range) {
    Archer::range = range;
}
int Archer::getArrows() const {
    return arrows;
}

void Archer::setArrows(int arrows) {
    Archer::arrows = arrows;
}

void Archer::fight(Enemy &enemy){
    if(arrows>0){
        Attack(Enemy &enemy)
        arrows--;
    }


}

