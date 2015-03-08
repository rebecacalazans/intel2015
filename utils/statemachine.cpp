#include "statemachine.h"

Transition::
Transition(State* from, State* to, condition_t condition) :
  from_{from}, to_{to}, condition_{condition}
{}

Machine::
Machine(State* initial_state):
  initial_state_{initial_state},
  current_state_{initial_state},
  transitions_{}
{}

void Machine::
addTransition(Transition transition)
{
  transitions_.push_back(transition);
}

void Machine::
reset()
{
  current_state_ = initial_state_;
}

void Machine::
step()
{
}
