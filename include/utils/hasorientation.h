#ifndef UTILS_HASORIENTATION_H
#define UTILS_HASORIENTATION_H

class HasOrientation
{
public:
  inline float w() const { return w_; }
  inline float vw() const { return vw_; }
protected:
  float w_, vw_;
private:
};

#endif //UTILS_HASORIENTATION_H
