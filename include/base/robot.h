#ifndef BASE_ROBOT_H
#define BASE_ROBOT_H

#include <utils/point.h>
#include <utils/hasvelocity.h>
#include <utils/hasorientation.h>

class Robot : public Point, public HasVelocity, public HasOrientation
{
public:
  Robot() {}

  void setup(int id, float x, float y, float w, float vx, float vy, float vw)
  {
    id_ = id;
    x_ = x; y_ = y; w_ = w;
    vx_ = vx; vy_ = vy; vw_ = vw;
  }

  inline int id() const { return id_; }
protected:
private:
  int id_;
};

#endif //BASE_ROBOT_H
