#ifndef UTILS_STATEMACHINE_H
#define UTILS_STATEMACHINE_H

#include <vector>
#include <functional>

#include "steppable.h"

typedef std::function<bool ()> condition_t;

class State
{
};

class Transition
{
public:
  Transition(State* from, State* to, condition_t condition);
  virtual ~Transition();

  const State* from() const;
  const State* to() const;
  State* to();
  bool condition() const;
protected:
private:
  State* from_,
       * to_;

  //bool (*condition) ();
  condition_t condition_;
};

class Machine : public Steppable
{
public:
  Machine(State* initial_state);
  virtual ~Machine();

  void addTransition(Transition transition);
  void reset();
  virtual void step() override;
protected:
private:
  State* initial_state_,
       * current_state_;

  std::vector<Transition> transitions_;
};

#endif //UTILS_STATEMACHINE_H
