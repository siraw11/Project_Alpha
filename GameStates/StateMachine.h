//
// Created by Luca Graziotti on 2019-10-30.
//

#ifndef MOTOCROSS2D_STATEMACHINE_H
#define MOTOCROSS2D_STATEMACHINE_H
#pragma once

#include <memory>
#include <stack>
#include "State.h"

using StateRef = std::shared_ptr<State>;

class StateMachine {
public:
    void push_state(const StateRef &state, bool replace = false);

    StateRef pop_state();

    StateRef get_current_state() const;

    void update();

private:
    std::stack<StateRef> stack;
};

#endif //MOTOCROSS2D_STATEMACHINE_H
