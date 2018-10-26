#ifndef DELTA_H
#define DELTA_H

#include <QWidget>

namespace Ui {
class delta;
}

class delta : public QWidget
{
    Q_OBJECT

public:
    explicit delta(QList <double> mass_minX, QList <double> mass_maxX, QList <double> mass_minY, QList <double> mass_maxY, QWidget *parent = 0);
    ~delta();

private:
    Ui::delta *ui;
    void deltaList(QList <double> mass_minX, QList <double> mass_maxX, QList <double> mass_minY, QList <double> mass_maxY);
    QList <double> deltaT1, deltaT2, deltaR;
};

#endif // DELTA_H
