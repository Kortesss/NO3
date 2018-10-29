#include "mnk.h"
#include <qmath.h>

double sumXY(QList <double> x, QList <double> y)
{
    double res = 0;
    for(int i = 0; i < x.count(); i++){ res += x[i]*y[i]; }
    return res;
}

double sum(QList <double> k)
{
    double res = 0;
    for(int i = 0; i < k.count(); i++){ res += k[i]; }
    return res;
}

double sumXsqr(QList <double> k)
{
    double res = 0;
    for(int i = 0; i < k.count(); i++){ res += qPow(k[i], 2); }
    return res;
}

mnk::mnk(QList <double> x, QList <double> y, int n)
{
    //Найходим a и b.  n-количество точек
    a = (n*sumXY(x,y) - sum(x)*sum(y))/(n*sumXsqr(x) - qPow(sum(x), 2));
    b = (sum(y) - a*sum(x))/n;
    //Оценка погрешности МНК

    //Так как формула сигма1<сигма2, то прямая y лучше приближает исходные данные
}

double mnk::get_yy(double x)
{  //y=ax+b
    double yy = 0;
    yy = a*x+b;
    return yy;
}
