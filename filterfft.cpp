#include "filterfft.h"
#include "ui_filterfft.h"
#include <qmath.h>
#include <QDebug>

FilterFFT::FilterFFT(double xLast, QList <double> y, QWidget *parent) :
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
    FFTgraph = ui->widget_fft->addGraph();	//Добавление графика БПФ
    FFTgraph->setName("Быстрое преоразование Фурье (БПФ)");
    FFTgraph->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    FFTgraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->widget_ifft->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget_ifft->xAxis->setLabel("x");
    ui->widget_ifft->yAxis->setLabel("y");
    iFFTgraph = ui->widget_ifft->addGraph();	//Добавление графика Обратного БПФ
    iFFTgraph->setName("Обратное БПФ");
    iFFTgraph->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    iFFTgraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    horizLevel = ui->widget_fft->addGraph();	//Добавление горизонтальной линии
    horizLevel->setName("Уровень шума");
    horizLevel->setPen(QColor(255, 0, 0, 255));//задаем цвет точки красный
    horizLevel->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    horizLevel->setVisible(true);
    FFT(xLast, y);
    //iFFT();
}

FilterFFT::~FilterFFT()
{
    qDebug() << "деструктор FilterFFT";
    delete ui;
}

void FilterFFT::FFT(double xLast, QList <double> y)
{
    N = y.count();
    double L = xLast; //L-длина функции на графике;
    alf.clear(); absF.clear();
    for (int i=0; i<N/2; i++) alf.append(i/L); //определяем новый масштаб для точек X после преобразования
    for(int i = 0; i < N/2; i++){ //сокращаем вдвое для избавления зеркального эффекта
        F.append(std::complex<double>(0.0, 0.0));
        for(int k = 0; k < N; k++){ //Показательная форма комплексного числа (e^i*fi) пишется при помощи polar()
            F[i] += y[k] * (std::polar<double>(1.0, -2 * M_PI * i * k / N)); //коэффициент нормализации = 1.0
        }
        absF.append(abs(F[i])); //сохраняем модуль комплексного числа
    }


    xL.append(0.0); xL.append(alf.last());
    yL.append(0.0); yL.append(0.0);
    horizLevel->setData(xL.toVector(), yL.toVector());
    horizLevel->setVisible(true);
    //----
    minx = *std::min_element(alf.begin(), alf.end());
    maxx = *std::max_element(alf.begin(), alf.end());
    miny = *std::min_element(absF.begin(), absF.end());
    maxy = *std::max_element(absF.begin(), absF.end());
    //Установим область, которая будет показываться на графике
    ui->widget_fft->xAxis->setRange(minx, maxx);// Для оси Ox
    ui->widget_fft->yAxis->setRange(miny, maxy);//Для оси Oy

    ui->Slider_level->setMaximum(maxy);
    on_Slider_sens_valueChanged(1);

    ui->widget_fft->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
    ui->widget_fft->legend->setVisible(true);
    FFTgraph->setData(alf.toVector(), absF.toVector());
    FFTgraph->setVisible(true);
    ui->widget_fft->replot();
}

void FilterFFT::iFFT()
{
    for(int i = 0; i < N/2; i++){
        iF.append(std::complex<double>(0.0, 0.0));
        for(int k = 0; k < N/2; k++){
            iF[i] += F[k] * (std::polar<double>(1.0, 2 * M_PI * i * k / N));
        }
        iabsF.append(abs(iF[i]));
    }
        //iF[i] = (1/sqrt(N))*iF[i];
        //minx = *std::min_element(alf.begin(), alf.end());
        //maxx = *std::max_element(alf.begin(), alf.end());
        //miny = *std::min_element(iabsF.begin(), iabsF.end());
        //maxy = *std::max_element(iabsF.begin(), iabsF.end());
        //Установим область, которая будет показываться на графике
        //ui->widget_ifft->xAxis->setRange(minx, maxx);// Для оси Ox
        //ui->widget_ifft->yAxis->setRange(miny, maxy);//Для оси Oy
        ui->widget_ifft->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
        ui->widget_ifft->legend->setVisible(true);
        iFFTgraph->setData(alf.toVector(), iabsF.toVector());
        iFFTgraph->setVisible(true);
        ui->widget_ifft->replot();
}

void FilterFFT::on_pushButton_close_clicked()
{
    this->close();
}

void FilterFFT::on_pushButton_saveTxt_clicked()
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

void FilterFFT::on_Slider_level_valueChanged(int value)
{
    yL[0] = yL[1] = value;
    horizLevel->setData(xL.toVector(), yL.toVector());  
    ui->widget_fft->replot();
}

void FilterFFT::on_Slider_sens_valueChanged(int value)
{
    ui->Slider_level->setPageStep(maxy /(absF.count()*value));
    ui->Slider_level->setTickInterval(maxy /(absF.count()*value));
    ui->Slider_level->setSingleStep(maxy /(absF.count()*value));
}
