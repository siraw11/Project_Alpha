//
// Created by matteo on 20/06/19.
//

#ifndef EXAM_PROJECT_GAMECHARACTER_H
#define EXAM_PROJECT_GAMECHARACTER_H
 private{

int Life;
int Strenght;
int Speed;


}

public{
int PosX;
int PosY;
Weapon* Weapon;

void Attack();
bool TakeDamage();

}

#endif //EXAM_PROJECT_GAMECHARACTER_H
