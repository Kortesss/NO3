#ifndef DISPERS_ANALYSIS_H
#define DISPERS_ANALYSIS_H

#include <QMainWindow>
#include "QStandardItemModel"
#include "QStandardItem"

namespace Ui {
class dispers_analysis;
}

class dispers_analysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit dispers_analysis(QString typeD, QList <QString> listWidget, QList<QList<double> > &arr, QWidget *parent = nullptr);
    ~dispers_analysis();

private slots:
    void on_listGr_clicked(const QModelIndex &);

    void on_pushButton_close_clicked();

    void on_pushButton_Calculate_clicked();

    void on_SpinAlpha_valueChanged(double arg1);

    double sum(QList <double> &k); //сумма значений

    double avg(QList <double> &g); //среднее значение выборки

    double dispers(QList <double> &d); //дисперсия градации фактора (группы)

    double SSa(QList <double> ni); //объяснённая влиянием фактора a сумма квадратов отклонений

    double SSe(QList <double> ni); //необъяснённая сумма квадратов отклонений или сумма квадратов отклонений ошибки

private:
    Ui::dispers_analysis *ui;

    QStandardItemModel *model1, *model2;
    QString typeA;
    double X; //общее среднее
    double Va, Ve, V; //Число степеней свободы

    QList<QList<double> > arr;
};

#endif // DISPERS_ANALYSIS_H
