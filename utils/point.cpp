#include <cmath>

#include "point.h"

float magnitude()
{
	return std::sqrt( x_ * x_ + y_ * y_ );
}

void normalized()
{
	float mag = magnitude();
	x_ /= mag, y_ /= mag;
}

void rotate(float angle)
{
	float c = std::cos(angle * M_PI / 180.0),
    	  s = std::sin(angle * M_PI / 180.0);
  
  float x = x_, y = y_;

  x_ = x * c + y * s;
  y_ = y * c - x * s;
}

float dist_point(float x, float y)
{
	return std::sqrt( (x_ - x)*(x_ - x) + (y_ - y)*(y_ - y) );
}