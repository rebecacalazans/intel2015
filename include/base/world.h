#ifndef BASE_WORLD_H
#define BASE_WORLD_H

#include <base/ball.h>

class World
{
public:
  void load();

  float field_width() const { return field_width_; }
  float field_height() const { return field_height_; }
  float goal_width() const { return goal_width_; }
  float center_circle_radius() const { return center_circle_radius_; }
  float defense_radius() const { return defense_radius_; }
  float defense_stretch() const { return defense_stretch_; }
  float free_kick_from_defense_dist() const { return free_kick_from_defense_dist_; }
  float penalty_spot_from_field_line_dist() const { return penalty_spot_from_field_line_dist_; }
  float penalty_line_from_spot_dist() const { return penalty_line_from_spot_dist_; }

  const Ball& ball() const { return ball_; }
  Ball& ball() { return ball_; }

protected:
private:
  float field_width_,
        field_height_,
        goal_width_,
        center_circle_radius_,
        defense_radius_,
        defense_stretch_,
        free_kick_from_defense_dist_,
        penalty_spot_from_field_line_dist_,
        penalty_line_from_spot_dist_;
  Ball ball_;
};

#endif //BASE_WORLD_H
