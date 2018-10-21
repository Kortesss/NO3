#include "derivative.h"

Derivative::Derivative(double x1,double x2,double y1,double y2)
{
  dx=x2-x1;
  dy=y2-y1;
  dd=dy/dx;
}

double Derivative::get_dd()
{
    return dd;
}
