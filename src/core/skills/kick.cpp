#include <iostream>

#include "../../base/robot.h"

#include "kick.h"

void Kick::
step()
{
  std::cout << robot_->id() << " K" << std::endl;
}
