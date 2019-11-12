//
// Created by Magna on 2019-06-06.
//

#ifndef MOTOCROSS2D_MAP_H
#define MOTOCROSS2D_MAP_H

#include <iostream>
#include <list>
#include "Player.h"
#include "Observer.h"
#include "Subject.h"
#include "Item.h"



class Map:Observer {

public:
    Map(bool isCompleted = 0, bool isUnlocked = 0, double record = 0, std::list<Position> mapPoints = {},
        Player *p = nullptr, std::list<Item *> mapItems = {});

    virtual ~Map();
    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

public:
    bool getIsCompleted() const;

    void setIsCompleted(bool isCompleted);

    bool getIsUnlocked() const;

    void setIsUnlocked(bool isUnlocked);

    double getRecord() const;

    void setRecord(double record);

    const std::list<Position> &getMapPoints() const;

    void setMapPoints(const std::list<Position> &mapPoints);

    const std::list<Item *> &getMapItems() const;

    void setMapItems(const std::list<Item *> &mapItems);

    bool removeMapItem(Item *item);

    void loadLevel1();

    void loadLevel2();


private:
    bool isCompleted;
    bool isUnlocked;
    double record;
    std::list<Position> mapPoints;
    std::list<Item *> mapItems;
    Player* p;

};


#endif //MOTOCROSS2D_MAP_H