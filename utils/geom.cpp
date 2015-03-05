#include <cmath>

#include "geom.h"

float magnitude(Point p)
{
  return std::sqrt(p.x * p.x + p.y * p.y);
}

Point normalize(Point p)
{
  float mag = magnitude(p);
  return {p.x / mag, p.y / mag};
}

Point rotate(Point p, float angle)
{
  float c = std::cos(angle * M_PI / 180.0),
        s = std::sin(angle * M_PI / 180.0);
  return {p.x * c + p.y * s, p.y * c - p.x * s};
}

float dist_point(Point a, float x, float y)
{
  return std::sqrt( (a.x - x) * (a.x - x) + (a.y - y)*(a.y - y) );
}

// TODO (naum-20150304): Verificar se essa função está certa!
bool line_intersect(Point a1, Point a2, Point b1, Point b2, Point* ret)
{
  float dy1 = a2.y - a1.y,
        dx1 = a2.x - a1.x,
        c1  = a2.x * a1.y - a1.x * a2.y;
  float dy2 = b2.y - b1.y,
        dx2 = b2.x - b1.x,
        c2  = b2.x * b1.y - b1.x * b2.y;

  float denom = dy1 * dx2 - dx1 * dy2;
  if (std::abs(denom) < 0.001f)
    return false;

  *ret = Point {(dx1 * c2 - dx2 * c1) / denom, (dy1 * c2 - dy2 * c1) / denom};
  return true;
}
