//
// Created by matteo on 09/03/21.
//

#ifndef PROJECT_ALPHA_OBSERVER_H
#define PROJECT_ALPHA_OBSERVER_H
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;

    bool done = false;
};



#endif //PROJECT_ALPHA_OBSERVER_H
