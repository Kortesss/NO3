#ifndef EXTREM_SIMPLE_H
#define EXTREM_SIMPLE_H

#include <QMainWindow>

class extrem_simple
{
public:
    extrem_simple(QList<double> &mass_minX, QList<double> &mass_maxX, QList<double> &mass_minY, QList<double> &mass_maxY, QList<double> &mass_y_Gr, QList<double> &mass_x_Gr, int x1, int x2, double limit);
};

#endif // EXTREM_SIMPLE_H
