#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile> //Подключаем для работы с классом QFile
#include <QtGui> //диалог открытия файла
#include <QTextStream>
#include <QIODevice>
#include <QPoint>
#include "qcustomplot.h"
#include <QTimer>

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
    ~MainWindow();

public slots:

signals:

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

    void TimerTick();

    void on_pushButton_clicked();

    void on_listWidget_clicked();

    void on_listWidget_doubleClicked();

    void FalseVisibleAllGraph();

private:
    Ui::MainWindow *ui;

    double prdelfun(double x1,double x2,double y1,double y2); //процедура для поиска предела функции
    double prfun(double px); //функции для поиска предела функции
    //QList <double> mass_x, mass_y; //массив x,y
    QList<QList<double> > mass_x_Gr, mass_y_Gr; //массив x и y каждого графика
    QList<QList<double> > mass_minX, mass_maxX, mass_minY, mass_maxY, trendMin, trendMax; //массивы мин. и макс. x, y и и точки для линии тренда для каждого графика
    double minx, miny, maxx, maxy, koef; //мин. и макс. x, y и коэффициент
    QPoint press; //для обработки нажатия кнопки мыши и считывание координат
    QVector<double> dirivate; //массив производных
    double x1, x2;
    bool mnkMax, mnkMin, levelMin, levelMax; //для нахождения МНК мин. и макс. и вертикальная линия для этих точек
    QCPGraph *graphic1, *graphMin, *graphMax, *graphMnkMin, *graphLevelMin,*graphMnkMax, *graphLevelMax; //все графики
    QList <QCPItemText*> textListMin, textListMax;//точки экстрем. для отображения координат
    QTimer timer; int t, gr_index; //таймер для добавления чисел в список на форму и переменная t для прохода по массиву
};

#endif // MAINWINDOW_H
