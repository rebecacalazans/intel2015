#ifndef CORE_SKILLS_KICK_H
#define CORE_SKILLS_KICK_H

#include <core/skills/skill.h>

class Kick : public Skill
{
public:
  virtual void step() override;
};

#endif
