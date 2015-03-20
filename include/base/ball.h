#ifndef BASE_BALL_H
#define BASE_BALL_H

#include <utils/point.h>
#include <utils/hasvelocity.h>

class Ball : public Point, public HasVelocity
{
public:
  void setup(float x, float y, float vx, float vy)
  {
    x_ = x;
    y_ = y;
    vx_ = vx;
    vy_ = vy;
  }
protected:
private:
};

#endif //BASE_BALL_H
