#include <iostream>

#include <base/robot.h>
#include <core/skills/pass.h>

void Pass::
step()
{
  std::cout << robot_->id() << " P " << target_id_ << std::endl;
}
