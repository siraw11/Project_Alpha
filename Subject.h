//
// Created by matteo on 09/03/21.
//

#ifndef PROJECT_ALPHA_SUBJECT_H
#define PROJECT_ALPHA_SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify() = 0;

    virtual ~Subject() = default;
};

#endif //PROJECT_ALPHA_SUBJECT_H
