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

    void indexSearch(double valX1, double valX2);//ищем индекс массива выделенного интервала

    void speedSearch(); //для расчета скорости реакции и восстановления текущего графика

    void on_spinLevel_valueChanged();

    void on_doubleSpinBox1_valueChanged();

    void autoSearchSimple(); //1 способ поиска экстремумов (простой)

    void Derivat_triggered(); //расчет скорости по выделенному диапазону

    void TimerTick();

    void on_listWidget_clicked();

    void on_listWidget_doubleClicked();

    void FalseVisibleAllGraph();

    void menuRename();

    void menuReaxis();

    void EnterPressedLineEditRename();

    void on_Spin_x1_valueChanged();

    void on_Spin_x2_valueChanged();

    void on_SliderSpan_valueChanged(int value);

    void on_SliderLegend_valueChanged(int value);

    void on_checkExp_clicked(bool checked);

    void on_checkGolay_clicked(bool checked);

    void on_undo(); void on_redo();

    void on_SpinLimit_valueChanged(double arg1);

    void on_SliderPointGr_valueChanged(int value);

    void on_SpinTimeExp_valueChanged(int arg1);

    void on_btn_Manual_clicked();

    void on_btn_BildMnk_clicked();

    void on_btn_delMnk_clicked();

    void on_btn_DFT_clicked();

    void on_btn_delta_clicked();

    void on_cmbBox_Correl_activated(int index);

    void on_btn_grDerivative_clicked();

    void on_btn_autoSearch2_clicked();

    void on_btn_delExtrem_clicked();

    void on_startWork1_clicked();

    void on_startWork2_clicked();

    void on_btn_clearGraph_clicked();

    void on_btn_openFile_clicked();

    void on_btn_saveImage_clicked();

    void on_btn_saveDataGr_clicked();

    void on_btn_exit_clicked();

    void on_btn_delGraph_clicked();

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
    QCPGraph *graphic1, *graphMin, *graphMax, *graphMnkMin, *graphLevelMin,*graphMnkMax, *graphLevelMax; //все графики
    QCPItemRect *rectPoint, *rectSpan; //прямоугольник для выделения точек

    QList<QList<QCPItemText*> > textListMin, textListMax;//точки экстрем. для отображения координат
    QList<QList<QCPItemText*> > textListMNK; //для подписи точки МНК на нулевом месте будет min, а на 1 max
    QTimer timer; int t, gr_index; //таймер для добавления чисел в список на форму и переменная t для прохода по массиву
    QString sliderStyleOn, sliderStyleOff;
    QShortcut *CtrlZ, *CtrlY;

};

#endif // MAINWINDOW_H
