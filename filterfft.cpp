#include "filterfft.h"
#include "ui_filterfft.h"
#include <qmath.h>
#include <QDebug>

FilterFFT::FilterFFT(QList <double> &x, QList <double> &y, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterFFT)
{
    ui->setupUi(this);
    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlQ, SIGNAL(activated()), this, SLOT(on_pushButton_close_clicked()));

    ui->widget_fft->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget_fft->xAxis->setLabel("x");
    ui->widget_fft->yAxis->setLabel("y");
    DFTgraph = ui->widget_fft->addGraph();	//Добавление графика Фурье
    DFTgraph->setName("Дискретное преоразование Фурье");
    DFTgraph->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    DFTgraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->widget_ifft->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget_ifft->xAxis->setLabel("x");
    ui->widget_ifft->yAxis->setLabel("y");
    iDFTgraph = ui->widget_ifft->addGraph();	//Добавление графика Обратного Фурье
    iDFTgraph->setName("Обратное преобразование Фурье");
    iDFTgraph->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    iDFTgraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    horizLevel = ui->widget_fft->addGraph();	//Добавление горизонтальной линии
    horizLevel->setName("Уровень шума");
    horizLevel->setPen(QColor(255, 0, 0, 255));//задаем цвет точки красный
    horizLevel->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    horizLevel->setVisible(true);
    DFT(x, y);
    iDFT(x);
}

FilterFFT::~FilterFFT()
{
    qDebug() << "деструктор FilterFFT";
    delete ui;
}

void FilterFFT::DFT(QList <double> &x, QList <double> &y) //Дискретное преобразование Фурье
{
    N = y.count();
    xF.clear(); yF.clear();
    for (int i=0; i<N; i++) xF.append(i/x.last()); //определяем новый масштаб для точек X после преобразования
    for(int i = 0; i < N; i++){ //сокращаем вдвое для избавления зеркального эффекта
        F.append(std::complex<double>(0.0, 0.0));
        for(int k = 0; k < N; k++){ //Показательная форма комплексного числа (e^i*fi) пишется при помощи polar()
            F[i] += y[k] * (std::polar<double>(1.0, -(2 * M_PI * i * k / N))); //коэффициент нормализации = 1.0
        } //БПФ отличается от дискретного тем, что сумму не надо делить на N и в степени -
        yF.append(abs(F[i])); //сохраняем модуль комплексного числа
    }
    xL.append(0.0); xL.append(xF.last()); //x, y уровня(Level)
    yL.append(0.0); yL.append(0.0);
    horizLevel->setData(xL.toVector(), yL.toVector());
    horizLevel->setVisible(true);
    //----
    minX = *std::min_element(xF.begin(), xF.end());
    maxX = *std::max_element(xF.begin(), xF.end());
    minY = *std::min_element(yF.begin(), yF.end());
    maxY = *std::max_element(yF.begin(), yF.end());
    //Установим область, которая будет показываться на графике
    ui->widget_fft->xAxis->setRange(minX, maxX);// Для оси Ox
    ui->widget_fft->yAxis->setRange(minY, maxY);//Для оси Oy

    ui->Slider_level->setMaximum(maxY);
    on_Slider_sens_valueChanged(1);

    ui->widget_fft->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
    ui->widget_fft->legend->setVisible(true);
    DFTgraph->setData(xF.toVector(), yF.toVector());
    DFTgraph->setVisible(true);
    ui->widget_fft->replot();
}

void FilterFFT::iDFT(QList<double> &x) //Обратное Фурье
{
    for(int i = 0; i < N; i++){
        iF.append(std::complex<double>(0.0, 0.0));
        for(int k = 0; k < N; k++){
            iF[i] += F[k] * (std::polar<double>(1.0, 2 * M_PI * i * k / N));
        }
        iF[i]/= (double) N;
        if (iF[i].real()>0) iyF.append(abs(iF[i]));
        else  iyF.append(-abs(iF[i]));
    }
    iMinX = *std::min_element(x.begin(), x.end());
    iMaxX = *std::max_element(x.begin(), x.end());
    iMinY = *std::min_element(iyF.begin(), iyF.end());
    iMaxY = *std::max_element(iyF.begin(), iyF.end());
    //Установим область, которая будет показываться на графике
    ui->widget_ifft->xAxis->setRange(iMinX, iMaxX);// Для оси Ox
    ui->widget_ifft->yAxis->setRange(iMinY, iMaxY);//Для оси Oy
    ui->widget_ifft->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
    ui->widget_ifft->legend->setVisible(true);
    iDFTgraph->setData(x.toVector(), iyF.toVector());
    iDFTgraph->setVisible(true);
    ui->widget_ifft->replot();
}

void FilterFFT::on_pushButton_saveTxt_clicked() //сохранение в текстовый файл
{
    QFile fileOut("Обратное преобраз-е Фурье.txt");
        if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream writeStream(&fileOut);
            for(int i = 0; i < N; i++){
                //iF.append(std::complex<double>(0.0, 0.0));
                for(int k = 0; k < N; k++){
                    //iF[i] += F[k] * std::polar<double>(1.0, -2 * M_PI * i * k / N);
                }
                //iF[i] = (1/sqrt(N))*iF[i];
                //writeStream << mass_x_Gr[gr_index][i] << "\t" << abs(iF[i]) << "\n";
            }
            fileOut.close();
        }
}

void FilterFFT::on_pushButton_close_clicked()
{
    this->close();
}

void FilterFFT::on_Slider_level_valueChanged(int value) //изменение слайдера уровня шумов
{
    yL[0] = yL[1] = value;
    horizLevel->setData(xL.toVector(), yL.toVector());  
    ui->widget_fft->replot();
}

void FilterFFT::on_Slider_sens_valueChanged(int value) //изменение чувствительности уровня шумов
{
    ui->Slider_level->setPageStep(maxY /(yF.count()*value));
    ui->Slider_level->setTickInterval(maxY /(yF.count()*value));
    ui->Slider_level->setSingleStep(maxY /(yF.count()*value));
}
