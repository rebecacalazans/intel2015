#ifndef BASE_SKILL_H
#define BASE_SKILL_H

#include <utils/steppable.h>
#include <utils/statemachine.h>

class Robot;

class Skill : public State, public Steppable
{
public:
  virtual ~Skill() {}
  virtual void step() override =0;

protected:
  Robot* robot_;
};

#endif //BASE_SKILL_H
