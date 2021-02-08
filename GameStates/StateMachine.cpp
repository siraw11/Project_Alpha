#include "StateMachine.hpp"

namespace Alpha
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if (this->_isRemoving && !this->_states.empty())// toglie l'ultimo state e fa ripartire lo state successivo se il vect non è vuoto
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}

			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())// se vogliamo toglierlo allora si setta true isReplacing, altrimenti si mette in pausa lo state
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();// inizializza il nuovo state
			this->_isAdding = false;
		}
	}

	StateRef &StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}