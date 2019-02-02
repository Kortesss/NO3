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
    explicit FilterFFT(double xLast, QList <double> y, QWidget *parent = 0);
    ~FilterFFT();

private slots:
    void on_pushButton_close_clicked();
    void FFT(double xLast, QList <double> y);
    void iFFT();

    void on_pushButton_saveTxt_clicked();

    void on_Slider_level_valueChanged(int value);

    void on_Slider_sens_valueChanged(int value);

private:
    Ui::FilterFFT *ui;
    QShortcut *CtrlQ;
    int N;
    QList <double> alf, absF, iabsF, xL, yL;
    double minx, miny, maxx, maxy;
    QList< std::complex <double> > F,iF;
    QCPGraph *FFTgraph, *iFFTgraph, *horizLevel;
};

#endif // FILTERFFT_H
