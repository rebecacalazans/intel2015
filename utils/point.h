#ifndef UTILS_POINT_H
#define UTILS_POINT_H

class Point
{
public:
  Point(float x, float y) : x_{x}, y_{y}
  {}

  virtual ~Point() {}

  float magnitude();
  void normalize();
  void rotate(float angle);
  float dist_point(float x, float y);

protected:
private:
  float x_, y_;
};

#endif //UTILS_POINT_H
