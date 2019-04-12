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

    void on_btn_openFile_clicked(); //выбор файла и заполнение массива данных

    void on_btn_exit_clicked(); //выход из программы

    void on_btn_saveImage_clicked(); //Сохранение изображения графика

    void on_btn_saveDataGr_clicked(); //сохранение данных графика в файл

    void TimerTick(); //процедура таймера для добавления в список textBrowser

    void on_listWidget_doubleClicked(); //для отображения координат графика

    void on_listWidget_clicked(); //для перехода по графику

    void FalseVisibleAllGraph(); //скрытие графов

    void mousePress(QMouseEvent *event); //ручная установка/удаление экстремумов
    void histogramMouseMoved(QMouseEvent *event); //координаты в статус-баре и границы интервала
    void spanMouseUp(QMouseEvent *mouseEvent);

    void slotCustomMenuRequested(QPoint pos); //для вызова контекстного меню

    void menuRename(); //переименование графика

    void EnterPressedLineEditRename(); //обработчик события нажатия Enter в текстовом поле

    void menuReaxis(); // окно для переименование осей графика

    void on_btn_clearGraph_clicked(); //очистить графы графика

    void on_btn_delGraph_clicked(); //удаление выделеного графика

    void on_startWork1_clicked(); //определение начала рабочего режима (1 метод)

    void on_SpinLimit_valueChanged(double arg1); //изменение порог. знач. (R)  для старт режима (метод 1)

    void on_startWork2_clicked(); //начало раб. режима (2 метод)

    void on_SpinTimeExp_valueChanged(int arg1); //изменение времени эксперимента

    void on_checkTimeExp_toggled(bool checked); //вкл/выкл скользящего окна

    void on_doubleSpinBox1_valueChanged();  //изменение спина экстремомов (простой)

    void autoSearchSimple(); //1 способ поиска экстремумов (простой)

    void on_btn_autoSearch2_clicked(); //2 способ экстремумов

    void on_manualExtrem_clicked(bool checked); //ручное изменение экстремумов

    void on_btn_delExtrem_clicked(); //удаление экстремумов

    void on_Spin_x1_valueChanged(); //изменение спина нач. значение

    void on_Spin_x2_valueChanged(); //изменение спина конеч. значение

    void on_btn_grDerivative_clicked(); //отрисовка графика производной

    void indexSearch(double valX1, double valX2);//ищем индекс массива выделенного интервала

    void speedSearch(); //для расчета скорости реакции и восстановления текущего графика

    void Derivat_triggered(); //расчет скорости по выделенному диапазону

    void on_checkExp_clicked(bool checked); //вкл./выкл. эксп. сглаживания

    void on_checkGolay_clicked(bool checked); //вкл./выкл. сглаживания Савицкого-Голея

    void on_undo(); void on_redo();

    void on_btn_delta_clicked(); //Расчет изменения дельты сигнала

    void on_btn_DFT_clicked(); //Фильрация сигнала: Дискретное преобразование Фурье

    void on_cmbBox_Correl_activated(int index); //Корреляционный анализ

    void on_btn_BildMnk_clicked(); //Построить МНК

    void on_btn_delMnk_clicked(); //удаление МНК

    void on_spinLevel_valueChanged(); //спин мнк

    void on_btn_Manual_clicked(); //запуск руководства пользователя

    void on_SliderSpan_valueChanged(int value); //вкл./выкл. диапазона значений

    void on_SliderLegend_valueChanged(int value); //вкл./выкл. легенды

    void on_SliderPointGr_valueChanged(int value); //показать/скрыть координаты точек установленных вручную

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
