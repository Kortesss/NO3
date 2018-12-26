#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile> //Подключаем для работы с классом QFile
#include <QtGui> //диалог открытия файла
#include <QTextStream>
#include <QIODevice>
#include <QPoint>
#include "qcustomplot.h"

using namespace std;
namespace Ui {
class MainWindow;
}

/*class NewWindow :public QWidget
{
    public:
      QPushButton* button2;
      NewWindow(): QWidget()     {
//     ОЧЕНЬ ВАЖНО = чтобы виджеты отображались на дополнительном окне
//     на хранить указатели на них в виде полей данного окна (его класса)
//     как это сделано в данном примере,скажем, для кнопки  button2
     this->setWindowTitle("дополнительное окно");
     button2 = new QPushButton("HEllo WOrld =) !!!)))", this);
     this->show();
            //  widget.show();
     }

};*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setMassX(double massX);
    void setMassY(double massY);
    bool Stop;
    ~MainWindow();

public slots:

signals:
void sendNumberBoolStop(bool);

private slots:
    void mousePress(QMouseEvent *event);
    void histogramMouseMoved(QMouseEvent *event);

    void on_action_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_11_triggered();

    void on_action_12_triggered();

    void on_action_16_triggered();

    void on_spinLevel_valueChanged();

    void on_doubleSpinBox1_valueChanged();

    void on_actionD_triggered();

    void on_action_21_triggered();

    void on_checkMin_clicked();

    void on_checkMax_clicked();

    void on_action_10_triggered();

    void on_action_13_triggered();

    void on_action_17_triggered();

    void on_action_19_triggered();

private:
    Ui::MainWindow *ui;

    double prdelfun(double x1,double x2,double y1,double y2);
    double prfun(double px);
    QPoint pozit(QPoint p);
    QList<double> mass_x, mass_y;

    QList <double> mass_minX, mass_maxX, mass_minY, mass_maxY, trendMin, trendMax;
    double minx, miny, maxx, maxy, koef;
    QPoint press;
    QPoint release;
    QVector<double> dirivate;
    double x1, x2;
    bool axis_max, axis_min, mnkMax, mnkMin, levelMin, levelMax;
    QCPGraph *graphic1, *graphMin, *graphMax, *graphMnkMin, *graphLevelMin,*graphMnkMax, *graphLevelMax;
    QList <QCPItemText*> textListMin, textListMax;//точки экстрем. для отображения координат
};

#endif // MAINWINDOW_H
