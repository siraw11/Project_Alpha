//
// Created by matteo on 18/04/20.
//

#ifndef PROGETTO_PROVA_WEAPON_H
#define PROGETTO_PROVA_WEAPON_H


class Weapon {
public:
    explicit Weapon(int s);
    ~Weapon();
    int getStrenght() const;

private:
    int strenght;

};


#endif //PROGETTO_PROVA_WEAPON_H
