#ifndef CORE_SKILLS_DEFEND_H
#define CORE_SKILLS_DEFEND_H

#include <utils/geom.h>
#include <core/skills/skill.h>

class Defend: public Skill
{
public:
  virtual void step() override;
protected:
  Point target_;
  float radius_;
};

#endif
