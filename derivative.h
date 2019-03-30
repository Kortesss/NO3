#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include <QMainWindow>
//#include <QObject>
//#include <QWidget>

class Derivative
{

public:
    ~Derivative();
    Derivative();
    double get_dd(double x1,double x2,double y1,double y2);
private:
    double dx;
    double dy;
    double dd;
};

#endif // DERIVATIVE_H
