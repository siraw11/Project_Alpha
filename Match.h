//
// Created by Magna on 2019-06-20.
//

#ifndef MOTOCROSS2D_MATCH_H
#define MOTOCROSS2D_MATCH_H
#include "Bike.h"
#include "Player.h"




class Match {
public:
    Match(Position p, int lifes, float time, int money, Player* player, Bike* b);

    virtual ~Match();

    const Position &getP() const;

    void setP(const Position &p);

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

private:
    Position p;
    int lifes;
    float time;
    int money;
    Player* player;
    Bike* b;

};


#endif //MOTOCROSS2D_MATCH_H
