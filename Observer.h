//
// Created by Magna on 2019-06-19.
//

#ifndef MOTOCROSS2D_OBSERVER_H
#define MOTOCROSS2D_OBSERVER_H


class Observer {
public:
    virtual void update(float dt) = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;
};


#endif //MOTOCROSS2D_OBSERVER_H
