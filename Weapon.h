//
// Created by matteo on 18/04/20.
//

#ifndef PROGETTO_PROVA_WEAPON_H
#define PROGETTO_PROVA_WEAPON_H


class Weapon {
public:
    Weapon(int s, int l);
    ~Weapon();
    int getStrenght() const;

private:
    int strenght;
    int level;
};


#endif //PROGETTO_PROVA_WEAPON_H
