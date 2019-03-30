#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile> //Подключаем для работы с классом QFile
#include <QtGui> //диалог открытия файла
#include <QTextStream>
#include <QDataStream>
#include <QIODevice>
#include <QPoint>
#include "qcustomplot.h"
#include <QTimer>
#include <QShortcut>
#include "mnk.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

signals:

private slots:
    void mousePress(QMouseEvent *event);
    void histogramMouseMoved(QMouseEvent *event);
    void spanMouseUp(QMouseEvent *mouseEvent);

    void slotCustomMenuRequested(QPoint pos); //для вызова контекстного меню

    void on_action_7_triggered();

    void indexSearch(double valX1, double valX2);//ищем индекс массива выделенного интервала

    void on_action_exit_triggered();

    void on_spinLevel_valueChanged();

    void on_doubleSpinBox1_valueChanged();

    void on_actionD_triggered();

    void on_action_GrDerivative_triggered();

    void on_checkMin_clicked();

    void on_checkMax_clicked();

    void on_action_10_triggered();

    void on_action_Derivat_triggered();

    void TimerTick();

    void on_listWidget_clicked();

    void on_listWidget_doubleClicked();

    void FalseVisibleAllGraph();

    void menuRename();

    void menuReaxis();

    void EnterPressedLineEditRename();

    void on_action_manual_triggered();

    void on_action_about_triggered();

    void on_Spin_x1_valueChanged();

    void on_Spin_x2_valueChanged();

    void on_action_filter_triggered();

    void on_SliderSpan_valueChanged(int value);

    void on_SliderLegend_valueChanged(int value);

    void on_startWork_triggered(double limit);

    void on_action_SaveDataGr_triggered();

    void on_checkExp_clicked(bool checked);

    void on_checkGolay_clicked(bool checked);

    void on_undo(); void on_redo();

    void on_action_DelGraph_triggered();

    void on_action_ClearGraph_triggered();

    void on_action_OpenFile_triggered();

    void on_action_DelMnk_triggered();

    void on_action_SaveImage_triggered();

    void on_action_BildMnk_triggered();

    void on_action_autoSearch2_triggered();

    void on_SpinLimit_valueChanged(double arg1);

    void on_action_Correl_triggered();

    void on_SliderPointGr_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEditRename;
    QListWidgetItem *itRename;
    bool mouseDown, left; //mauseDown - при движении мыши, проверяем была ли нажата правая кнопка, left - переключатель
    QList<QList<double> > mass_x_Gr, mass_y_Gr; //массив x и y каждого графика
    QList<QList<double> > mass_minX, mass_maxX, mass_minY, mass_maxY, trendMin, trendMax; //массивы мин. и макс. x, y и и точки для линии тренда для каждого графика
    QList<QList<double> > xLevelMin, yLevelMin, xLevelMax, yLevelMax, StWork1,StWork2;
    QList <QString> mnkStrMin, mnkStrMax; //для сохраниения легенды мнк
    QList <double> minx, miny, maxx, maxy, koef; //мин. и макс. x, y и коэффициент
    QList <double> expY, expYcopy, speedReaction, speedRecovery; //для экспоненциального сглаживания
    QList <QString> axis_x_Gr, axis_y_Gr; //наименования осей каждого графика
    QVector<double> dirivate; //массив производных
    int x1, x2; //индексы значений выделенного интервала
    int iWork;//индекс значения начала рабочего режима
    QVector<double> spanX, spanY; //данные для диапазона иксов
    QCPGraph *graphic1, *graphMin, *graphMax, *graphMnkMin, *graphLevelMin,*graphMnkMax, *graphLevelMax, *graphSpan; //все графики

    QList<QList<QCPItemText*> > textListMin, textListMax;//точки экстрем. для отображения координат
    QList<QList<QCPItemText*> > textListMNK; //для подписи точки МНК на нулевом месте будет min, а на 1 max
    QTimer timer; int t, gr_index; //таймер для добавления чисел в список на форму и переменная t для прохода по массиву
    QString sliderStyleOn, sliderStyleOff;
    QShortcut *CtrlZ, *CtrlY;
};

#endif // MAINWINDOW_H
