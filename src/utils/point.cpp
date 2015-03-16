#include <cmath>

#include <utils/point.h>

Point::
Point() : x_{0.0f}, y_{0.0f}
{}

Point::
Point(float x, float y) : x_{x}, y_{y}
{}

Point::
~Point()
{}

float Point::
magnitude()
{
  return std::sqrt( x_ * x_ + y_ * y_ );
}

void Point::
normalize()
{
  float mag = magnitude();
  x_ /= mag, y_ /= mag;
}

void Point::
scale(float s)
{
  x_ *= s; y_ *= s;
}

void Point::
rotate(float angle)
{
  float c = std::cos(angle * M_PI / 180.0),
        s = std::sin(angle * M_PI / 180.0);

  float x = x_, y = y_;

  x_ = x * c + y * s;
  y_ = y * c - x * s;
}

Point Point::operator+(Point rhs)
{
  return Point(x() + rhs.x(), y() + rhs.y());
}

Point Point::operator-(Point rhs)
{
  return Point(x() - rhs.x(), y() - rhs.y());
}

float
dist_point(Point a, Point b)
{
  float dx = a.x() - b.x(),
        dy = a.y() - b.y();
  return std::sqrt(dx * dx + dy * dy);
}

// TODO (naum-20150304): Verificar se essa função está certa!
bool
line_intersect(Point a1, Point a2, Point b1, Point b2, Point* ret)
{
  float dy1 = a2.y() - a1.y(),
        dx1 = a2.x() - a1.x(),
        c1  = a2.x() * a1.y() - a1.x() * a2.y();
  float dy2 = b2.y() - b1.y(),
        dx2 = b2.x() - b1.x(),
        c2  = b2.x() * b1.y() - b1.x() * b2.y();

  float denom = dy1 * dx2 - dx1 * dy2;
  if (std::abs(denom) < 0.001f)
    return false;

  *ret = Point {(dx1 * c2 - dx2 * c1) / denom, (dy1 * c2 - dy2 * c1) / denom};
  return true;
}
