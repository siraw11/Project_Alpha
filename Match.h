//
// Created by Magna on 2019-06-20.
//

#ifndef MOTOCROSS2D_MATCH_H
#define MOTOCROSS2D_MATCH_H
#include "Bike.h"
#include "Player.h"
#include "Map.h"
#include "Timer.h"


class Match {
public:
    Match(std::shared_ptr<Map> = {}, Bike *b = {}, int lifes = 3, int money = 0,
          Position lastCheckpoint = {});

    std::unique_ptr<Timer> timer;

    std::shared_ptr<Map> map;

    const Position &getLastCheckpoint() const;

    void setLastCheckpoint(const Position &lastCheckpoint);

    virtual ~Match();

    const std::shared_ptr<Map> &getMap() const;

    void setMap(const std::shared_ptr<Map> &map);

    int getLifes() const;

    void setLifes(int lifes);


    void removeLife();


    int getMoney() const;

    void setMoney(int money);

    void addMoney(int money);

    Player *getPlayer() const;

    void setPlayer(Player *player);

    Bike *getB() const;

    void setB(Bike *b);

    Bike *getBike() const;

    void setBike(Bike *bike);


private:
    int lifes;
    float time;
    int money;
    Player* player;
    Bike *bike;
    Position lastCheckpoint;

};


#endif //MOTOCROSS2D_MATCH_H
