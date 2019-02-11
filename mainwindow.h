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
    void spanMouseUp(QMouseEvent *mouseEvent);

    void slotCustomMenuRequested(QPoint pos); //для вызова контекстного меню

    void on_action_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_7_triggered();

    void on_action_exit_triggered();

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

    void on_listWidget_clicked();

    void on_listWidget_doubleClicked();

    void FalseVisibleAllGraph();

    void on_action_5_triggered();

    void menuRename();

    void EnterPressedLineEditRename();

    void manualSetView();

    void on_action_manual_triggered();

    void on_action_about_triggered();

    void on_Spin_x1_valueChanged();

    void on_Spin_x2_valueChanged();

    void on_action_filter_triggered();

    void on_SliderSpan_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEditRename;
    QListWidgetItem *itRename;
    bool mouseDown, left; //mauseDown - при движении мыши, проверяем была ли нажата правая кнопка, left - переключатель
    double prdelfun(double x1,double x2,double y1,double y2); //процедура для поиска предела функции
    double prfun(double px); //функции для поиска предела функции
    QList<QList<double> > mass_x_Gr, mass_y_Gr; //массив x и y каждого графика
    QList<QList<double> > mass_minX, mass_maxX, mass_minY, mass_maxY, trendMin, trendMax; //массивы мин. и макс. x, y и и точки для линии тренда для каждого графика
    QList<QList<double> > xLevelMin, yLevelMin, xLevelMax, yLevelMax;
    QList <QString> mnkStrMin, mnkStrMax; //для сохраниения легенды мнк
    QList <double> minx, miny, maxx, maxy, koef; //мин. и макс. x, y и коэффициент
    QVector<double> dirivate; //массив производных
    double x1, x2;
    QVector<double> spanX, spanY; //данные для диапазона иксов
    QCPGraph *graphic1, *graphMin, *graphMax, *graphMnkMin, *graphLevelMin,*graphMnkMax, *graphLevelMax, *graphSpan; //все графики
    QList<QList<QCPItemText*> > textListMin, textListMax;//точки экстрем. для отображения координат
    QList<QList<QCPItemText*> > textListMNK; //для подписи точки МНК на нулевом месте будет min, а на 1 max
    QTimer timer; int t, gr_index; //таймер для добавления чисел в список на форму и переменная t для прохода по массиву
};

#endif // MAINWINDOW_H
