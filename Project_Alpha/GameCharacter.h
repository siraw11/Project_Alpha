//
// Created by matteo on 20/06/19.
//

#ifndef EXAM_PROJECT_GAMECHARACTER_H
#define EXAM_PROJECT_GAMECHARACTER_H

class GameCharacter{

private:

int life;
int strenght;
int speed;


public:

int posX;
int posY;
Weapon* weapon;

void Attack();
bool TakeDamage();

};

#endif //EXAM_PROJECT_GAMECHARACTER_H
