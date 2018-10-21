#ifndef SOMEWINDOW_H
#define SOMEWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui {
class SomeWindow;
}

class SomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SomeWindow(QVector<double> dirivate,double x1,double x2, double koef, QWidget *parent = 0);
    ~SomeWindow();

private:
    Ui::SomeWindow *ui;
    void graphDirivate(QVector<double> dirivate, double x1, double x2, double koef);
};

#endif // SOMEWINDOW_H
