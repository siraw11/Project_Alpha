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



class Map:Observer {
public:
    Map(bool isCompleted=0, bool isUnlocked=0, double record=1, std::list<float> mapPoints = {}, Player* p= nullptr);
    //TODO smart pointer Item
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

    const std::list<float> &getMapPoints() const;

    void setMapPoints(const std::list<float> &mapPoints);

private:
    bool isCompleted;
    bool isUnlocked;
    double record;
    std::list<float> mapPoints;
    Player* p;

};


#endif //MOTOCROSS2D_MAP_H