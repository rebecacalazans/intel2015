#include <iostream>

#include <base/robot.h>
#include <core/skills/attack.h>

void Attack::
step()
{
  std::cout << robot_->id() << " A " << target_.x() << " " << target_.y() << " " << radius_ << std::endl;
}
