#include <iostream>

#include <base/robot.h>
#include <core/skills/kick.h>

void Kick::
step()
{
  std::cout << robot_->id() << " K" << std::endl;
}
