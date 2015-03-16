#ifndef CORE_SKILLS_PASS_H
#define CORE_SKILLS_PASS_H

#include <core/skills/skill.h>

class Pass : public Skill
{
public:
  virtual void step() override;
protected:
  int target_id_;
private:
}

#endif //CORE_SKILLS_PASS_H
