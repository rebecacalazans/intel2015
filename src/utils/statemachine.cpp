#include "statemachine.h"

Transition::
Transition(State* from, State* to, condition_t condition) :
  from_{from}, to_{to}, condition_{condition}
{}

Transition::
~Transition()
{}

const State* Transition::
from() const
{
  return from_;
}

const State* Transition::
to() const
{
  return to_;
}

State* Transition::
to()
{
  return to_;
}

bool Transition::
condition() const
{
  return condition_();
}

Machine::
Machine(State* initial_state):
  initial_state_{initial_state},
  current_state_{initial_state},
  transitions_{}
{}

Machine::
~Machine()
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
  for (unsigned int i = 0; i < transitions_.size(); i++)
  {
    if (current_state_ == transitions_[i].from() &&
        transitions_[i].condition())
    {
      current_state_ = transitions_[i].to();
      break;
    }
  }
}
