#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Alpha
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() {};
		~StateMachine() {};

		void AddState(StateRef newState, bool isReplacing = true); // add a state to the stack, si rimpiazza sempre lo state corrente quando ne viene aggiunto uno nuovo
		void RemoveState();// per rimuovere manualmente uno state
		// Run at start of each loop in Game.cpp
		void ProcessStateChanges();

		StateRef &GetActiveState(); //ci restituisce lo state "più alto"

	private:
		std::stack<StateRef> _states;//tutti gli state presenti nello stack
		StateRef _newState; //latest state to add

		bool _isRemoving{}; //va rimoso lo state
		bool _isAdding{}; //va aggiunto
		bool _isReplacing{};//va rimpiazzato
	};
}