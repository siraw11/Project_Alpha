//
// Created by Magna on 2019-06-20.
//

#ifndef MOTOCROSS2D_MATCH_H
#define MOTOCROSS2D_MATCH_H
#include "Bike.h"
#include "Player.h"
#include "Map.h"


class Match {
public:
    Match(Map *map = {}, Bike *b = {}, int lifes = 3, float time = 0.f, int money = 0);

    Map *map;

    virtual ~Match();


    int getLifes() const;

    void setLifes(int lifes);

    float getTime() const;

    void setTime(float time);

    int getMoney() const;

    void setMoney(int money);

    Player *getPlayer() const;

    void setPlayer(Player *player);

    Bike *getB() const;

    void setB(Bike *b);

    Bike *getBike() const;

    void setBike(Bike *bike);

    Map *getMap() const;

    void setMap(Map *map);

private:
    int lifes;
    float time;
    int money;
    Player* player;
    Bike *bike;

};


#endif //MOTOCROSS2D_MATCH_H
