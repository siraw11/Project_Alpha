//
// Created by Luca Graziotti on 2019-10-30.
//

#include <iostream>
#include "StateMachine.h"

void StateMachine::push_state(const StateRef &state, bool replace) {
    if (replace) {
        while (!stack.empty()) {
            stack.pop();
        }
    }
    stack.push(state);
}

StateRef StateMachine::pop_state() {
    auto state = get_current_state();

    stack.pop();

    return state;
}

StateRef StateMachine::get_current_state() const {
    return stack.top();
}

void StateMachine::update() {
    if (!stack.empty()) {
        auto state = get_current_state();

        state->update();
        state->draw();
    }
}