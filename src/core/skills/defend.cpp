#include <iostream>

#include <base/robot.h>
#include <core/skills/defend.h>

void Defend:::
step()
{
  std::cout << robot_->id() << " D " << target_.x() << " " << target_.y() << " " << radius_ << std::endl;
}
