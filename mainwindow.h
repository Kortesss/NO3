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
    ~MainWindow();

public slots:
//    void openNewWindow(QWidget * parent = 0) // описываем реализацию внутри тела программы
//       {
//           someNewWindow = new NewWindow(); // Be sure to destroy you window somewhere
        //  someNewWindow->show();
          //  mMyNewWindow->show();

//      }
private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

 //   void on_textBrowser_destroyed();
    void mousePress(QMouseEvent *event);

//    void on_pushButton_4_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_7_triggered();

    void on_lineEdit1_returnPressed();

    void on_action_8_triggered();

    void on_action_9_triggered();

private:
    Ui::MainWindow *ui;

    double prdelfun(double x1,double x2,double y1,double y2);
    double prfun(double px);
    QPoint pozit(QPoint p);
    QList<double> mass_x;
    QList<double> mass_y;
    QList <double> pressX, pressY;
    double minx;
    double miny;
    double maxx;
    double maxy;
    double koef;
    bool graph_zero;
    QPoint press;
    QPoint release;
    QVector<double> dirivate;
    double x1, x2;
//    NewWindow *someNewWindow;
};

#endif // MAINWINDOW_H
