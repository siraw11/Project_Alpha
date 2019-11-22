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
    Match(std::shared_ptr<Map> = {}, std::shared_ptr<Bike> = {}, int lifes = 3, int money = 0,
          Position lastCheckpoint = {0, 0});

    const std::shared_ptr<Bike> &getBike() const;

    void setBike(const std::shared_ptr<Bike> &bike);

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

    const std::shared_ptr<Timer> &getTimer() const;

    void setTimer(const std::shared_ptr<Timer> &timer);

private:
    int lifes;
    int money;
    std::shared_ptr<Timer> timer;
    Player* player;
    Position lastCheckpoint;
    std::shared_ptr<Map> map;
    std::shared_ptr<Bike> bike;
};


#endif //MOTOCROSS2D_MATCH_H
