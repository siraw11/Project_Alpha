//
// Created by Magna on 2019-06-19.
//

#ifndef MOTOCROSS2D_SUBJECT_H
#define MOTOCROSS2D_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notifyObservers() = 0;

    virtual ~Subject() {}

};


#endif //MOTOCROSS2D_SUBJECT_H
