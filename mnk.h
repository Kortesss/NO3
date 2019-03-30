#ifndef MNK_H
#define MNK_H

#include <QMainWindow>

class mnk
{
public:
    ~mnk();
    mnk(QList <double> &x, QList <double> &y, int n);
    double get_yy(double x);
    double get_Kdet();
    double get_Kcor();
    double get_a();
    double get_b();
private:
    double a, b, sigma1, sigma2, xAVG, yAVG, xyAVG, Dx, Dy, sigX, sigY, Kcor, Kdet;
};

#endif // MNK_H
