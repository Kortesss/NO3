#ifndef CORREL_ANALYSIS_H
#define CORREL_ANALYSIS_H

#include <QMainWindow>
#include <QShortcut>
#include "qcustomplot.h"

namespace Ui {
class correl_analysis;
}

class correl_analysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit correl_analysis(QList <double> mass1, QList <double> mass2, QString nameX, QString nameY, QWidget *parent = nullptr);
    ~correl_analysis();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_close_clicked();

    void draw(QList <double> mass1, QList <double> mass2);

private:
    Ui::correl_analysis *ui;

    QShortcut *CtrlShiftS, *CtrlQ;
    QCPGraph *graphCorr, *graphTrend;
    QList <double> trendCorr;
};

#endif // CORREL_ANALYSIS_H
