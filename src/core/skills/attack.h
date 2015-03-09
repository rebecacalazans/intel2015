#ifndef CORE_SKILLS_ATTACK_H
#define CORE_SKILLS_ATTACK_H

#include "../../utils/geom.h"

#include "skill.h"

class Attack : public Skill
{
public:
  virtual void step() override;
protected:
  Point target_;
};

#endif
