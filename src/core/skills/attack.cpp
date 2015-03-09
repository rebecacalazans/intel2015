#include <iostream>

#include "../../base/robot.h"

#include "attack.h"

void Attack::
step()
{
  std::cout << robot_->id() << " A " << target_.x() << " " << target_.y() << std::endl;
}
