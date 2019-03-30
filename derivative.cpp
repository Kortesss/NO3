#include "derivative.h"

Derivative::Derivative()
{

}

double Derivative::get_dd(double x1,double x2,double y1,double y2)
{
    dx = x2-x1;
    dy = y2-y1;
    dd = dy/dx;
    return dd;
}

Derivative::~Derivative()
{

}
