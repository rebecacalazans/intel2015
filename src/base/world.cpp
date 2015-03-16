#include <iostream>

#include <base/world.h>

void World::
load()
{
  std::cin >> field_width_ >>
              field_height_ >>
              goal_width_ >>
              center_circle_radius_ >>
              defense_radius_ >>
              defense_stretch_ >>
              free_kick_from_defense_dist_ >>
              penalty_spot_from_field_line_dist_ >>
              penalty_line_from_spot_dist_;
}
