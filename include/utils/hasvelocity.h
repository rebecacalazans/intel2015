#ifndef UTILS_HASVELOCITY_H
#define UTILS_HASVELOCITY_H

class HasVelocity
{
public:
  inline float vx() const { return vx_; }
  inline float vy() const { return vy_; }
protected:
  float vx_, vy_;
private:
};

#endif //UTILS_HASVELOCITY_H
