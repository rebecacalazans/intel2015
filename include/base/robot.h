#ifndef BASE_ROBOT_H
#define BASE_ROBOT_H

class Robot
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
  inline float x() const { return x_; }
  inline float y() const { return y_; }
  inline float w() const { return w_; }
  inline float vx() const { return vx_; }
  inline float vy() const { return vy_; }
  inline float vw() const { return vw_; }
protected:
private:
  int id_;
  float x_, y_, w_,
        vx_, vy_, vw_;
};

#endif //BASE_ROBOT_H
