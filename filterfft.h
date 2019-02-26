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
    explicit FilterFFT(QList <double> x, QList <double> &y, QString s1, QString s2, QWidget *parent = nullptr);
    ~FilterFFT(); //принимаем ссылки на объект, чтобы не копировать в памяти его же

private slots:
    void on_pushButton_close_clicked();
    void DFT(QList<double> &x, QList<double> &y);
    void iDFT(QList<double> &x, QList< std::complex <double> > f);

    void mousePress(QMouseEvent *event);
    void histogramMouseMoved(QMouseEvent *event);
    void spanMouseUp(QMouseEvent *mouseEvent);

    void on_pushButton_saveTxt_clicked();

    void on_Slider_level_valueChanged(int value);

    void on_Slider_sens_valueChanged(int value);

    void on_pushButton_clicked();

    void on_SliderSpan_valueChanged(int value);

private:
    Ui::FilterFFT *ui;
    QShortcut *CtrlQ;
    int N;
    double x1, x2; //для диапазонов на DFT
    bool mouseDown, left, sp; //mauseDown - при движении мыши, проверяем была ли нажата правая кнопка, left - переключатель
    QList <double> xF, yF, yFcopy, ixF, iyF, xL, yL, expY, expYcopy;
    double minX, minY, maxX, maxY, iMinX, iMinY, iMaxX, iMaxY;
    QVector<double> spanX, spanY; //данные для диапазона иксов
    QList< std::complex <double> > F, Fcopy, iF, expF, expFcopy;
    QCPGraph *DFTgraph, *iDFTgraph, *horizLevel, *graphSpan;
};

#endif // FILTERFFT_H
