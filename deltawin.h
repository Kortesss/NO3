#ifndef DELTAWIN_H
#define DELTAWIN_H

#include <QMainWindow>

namespace Ui {
class deltaWin;
}

class deltaWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit deltaWin(QList <double> &mass_minX, QList <double> &mass_maxX, QList <double> &mass_minY, QList <double> &mass_maxY, QWidget *parent = 0);
    ~deltaWin();

private:
    Ui::deltaWin *ui;
    void deltaList(QList <double> &mass_minX, QList <double> &mass_maxX, QList <double> &mass_minY, QList <double> &mass_maxY);
    QList <double> deltaT1, deltaT2, deltaR;
};

#endif // DELTAWIN_H
