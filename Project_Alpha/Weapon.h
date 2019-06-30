//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_WEAPON_H
#define EXAM_PROJECT_WEAPON_H

class Weapon{
public:
    Weapon(int s,int l);

    void setStrength(int strength);

    int getStrength() const;


private:
    int strength;
    int level;

};

#endif //EXAM_PROJECT_WEAPON_H
