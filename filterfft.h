#ifndef FILTERFFT_H
#define FILTERFFT_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QShortcut>
#include <complex>

namespace Ui {
class FilterFFT;
}

class FilterFFT : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterFFT(QList <double> x, QList <double> &y, QWidget *parent = 0);
    ~FilterFFT(); //принимаем ссылки на объект, чтобы не копировать в памяти его же

private slots:
    void on_pushButton_close_clicked();
    void DFT(QList<double> &x, QList<double> &y);
    void iDFT(QList<double> &x);

    void on_pushButton_saveTxt_clicked();

    void on_Slider_level_valueChanged(int value);

    void on_Slider_sens_valueChanged(int value);

private:
    Ui::FilterFFT *ui;
    QShortcut *CtrlQ;
    int N;
    QList <double> xF, yF, yFcopy, ixF, iyF, xL, yL;
    double minX, minY, maxX, maxY, iMinX, iMinY, iMaxX, iMaxY;
    QList< std::complex <double> > F, Fcopy, iF;
    QCPGraph *DFTgraph, *iDFTgraph, *horizLevel;
};

#endif // FILTERFFT_H
