#ifndef SOMEWINDOW_H
#define SOMEWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QShortcut>

namespace Ui {
class SomeWindow;
}

class SomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SomeWindow(QVector<double> &dirivate, int &x1, int &x2, double &koef, QWidget *parent = nullptr);
    ~SomeWindow();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::SomeWindow *ui;
    void graphDirivate(QVector<double> &dirivate, int &x1, int &x2, double &koef);
    QShortcut *CtrlS, *CtrlQ;
};

#endif // SOMEWINDOW_H
