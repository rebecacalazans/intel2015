#ifndef UTILS_GEOM_H
#define UTILS_GEOM_H

struct Point
{
  float x, y;
};

float magnitude(Point p);
Point normalize(Point p);
Point rotate(Point p, float angle);
float dist_point(Point a, float x, float y);
bool line_intersect(Point a1, Point a2, Point b1, Point b2, Point* ret);

#endif //UTILS_GEOM_H
