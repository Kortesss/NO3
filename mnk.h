#ifndef MNK_H
#define MNK_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
class mnk
{
public:
    mnk(QList <double> x, QList <double> y, int n);
    double get_yy(double x);
private:
    double a;
    double b;
};

#endif // MNK_H
