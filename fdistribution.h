#ifndef FDISTRIBUTION_H
#define FDISTRIBUTION_H

/*
 *   F-distribution calculation
 *
 *  Originally composed by  iSuwen :
 *          http://blog.csdn.net/superwen_go/article/details/8926993
 *
 *   Modified by Mengchang Wang @ 2016
 *
*/

#include <qmath.h>
#include <QMainWindow>

class fdistribution
{
public:
    ~fdistribution();
    fdistribution(double alf, int n1, int n2);
    double betainc(double x, double a, double b);
    double FDist(double F, int m, int n);
    double betainv(double p, double a, double b);

    double beta(double z, double w);
    double gamma(double xx);
    double beta_cf(double a, double b, double x);

    double get_Fcritic();

private:
    double Fcritical, p_val;
};

#endif // FDISTRIBUTION_H

