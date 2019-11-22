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


class Map : Observer {

public:
    Map(std::string id = "n/d", std::string name = "n/d", bool isCompleted = false, bool isUnlocked = false,
        double record = 0,
        std::list<Position> mapPoints = {}, std::list<Item *> mapItems = {});

    virtual ~Map();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

    bool getIsCompleted() const;

    void setIsCompleted(bool isCompleted);

    bool getIsUnlocked() const;

    void setIsUnlocked(bool isUnlocked);

    double getRecord() const;

    std::string getRecordString() const;

    void setRecord(double record);

    const std::list<Position> &getMapPoints() const;

    void setMapPoints(const std::list<Position> &mapPoints);

    const std::list<Item *> &getMapItems() const;

    void setMapItems(const std::list<Item *> &mapItems);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getId() const;

    void setId(const std::string &id);

    void resetItems();

private:
    std::string id;
    std::string name;
    bool isCompleted;
    bool isUnlocked;
    double record;
    std::list<Position> mapPoints;
    std::list<Item *> mapItems;
};


#endif //MOTOCROSS2D_MAP_H