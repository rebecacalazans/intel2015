#ifndef UTILS_POINT_H
#define UTILS_POINT_H

class Point
{
public:
  Point();
  Point(float x, float y);
  virtual ~Point();

  float magnitude();
  void normalize();
  void scale(float s);
  void rotate(float angle);

  // TODO (naum-20150407): Criar arquivo para inlines
  inline float x() { return x_; }
  inline float y() { return y_; }

  Point operator+(Point rhs);
  Point operator-(Point rhs);

protected:
private:
  float x_, y_;
};

float dist_point(Point a, Point b);
bool line_intersect(Point a1, Point a2, Point b1, Point b2, Point* ret);

#endif //UTILS_POINT_H
