#include "filterfft.h"
#include "ui_filterfft.h"
#include <qmath.h>
#include <QDebug>

FilterFFT::FilterFFT(QList <double> x, QList <double> &y, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterFFT)
{
    ui->setupUi(this);
    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlQ, SIGNAL(activated()), this, SLOT(on_pushButton_close_clicked()));

    ui->widget_dft->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget_dft->xAxis->setLabel("x");
    ui->widget_dft->yAxis->setLabel("y");
    DFTgraph = ui->widget_dft->addGraph();	//Добавление графика Фурье
    DFTgraph->setName("Дискретное преоразование Фурье");
    DFTgraph->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    DFTgraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    ui->widget_idft->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget_idft->xAxis->setLabel("x");
    ui->widget_idft->yAxis->setLabel("y");
    iDFTgraph = ui->widget_idft->addGraph();	//Добавление графика Обратного Фурье
    iDFTgraph->setName("Обратное преобразование Фурье");
    iDFTgraph->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    iDFTgraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    horizLevel = ui->widget_dft->addGraph();	//Добавление горизонтальной линии
    horizLevel->setName("Уровень шума");
    horizLevel->setPen(QColor(255, 0, 0, 255));//задаем цвет точки красный
    horizLevel->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    horizLevel->setVisible(true);
    ixF = x;
    DFT(ixF, y);
    iDFT(ixF);
}

FilterFFT::~FilterFFT()
{
    qDebug() << "деструктор FilterFFT";
    delete ui;
}

void FilterFFT::DFT(QList <double> &x, QList <double> &y) //Дискретное преобразование Фурье
{
    N = y.count();
    //xF.clear(); yF.clear(); F.clear();
    for (int i=0; i<N; i++) xF.append(i/x.last()); //определяем новый масштаб для точек X после преобразования
    for(int i = 0; i < N; i++){ //сокращаем вдвое для избавления зеркального эффекта
        F.append(std::complex<double>(0.0, 0.0));
        for(int k = 0; k < N; k++){ //Показательная форма комплексного числа (e^i*fi) пишется при помощи polar()
            F[i] += y[k] * (std::polar<double>(1.0, -(2 * M_PI * i * k / N))); //коэффициент нормализации = 1.0
        } //БПФ отличается от дискретного тем, что сумму не надо делить на N и в степени -
        yF.append(abs(F[i])); //сохраняем модуль комплексного числа
        yFcopy.append(yF[i]); Fcopy.append(F[i]);
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
    ui->widget_dft->xAxis->setRange(minX, maxX);// Для оси Ox
    ui->widget_dft->yAxis->setRange(minY, maxY);//Для оси Oy

    ui->Slider_level->setMaximum(maxY);
    on_Slider_sens_valueChanged(1);

    ui->widget_dft->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
    ui->widget_dft->legend->setVisible(true);
    DFTgraph->setData(xF.toVector(), yF.toVector());
    DFTgraph->setVisible(true);
    ui->widget_dft->replot();
}

void FilterFFT::iDFT(QList<double> &x) //Обратное преобразование Фурье
{
    iF.clear(); iyF.clear();
    for(int i = 0; i < N; i++){
        iF.append(std::complex<double>(0.0, 0.0));
        for(int k = 0; k < N; k++){
            iF[i] += F[k] * (std::polar<double>(1.0, 2 * M_PI * i * k / N));
        }
        iF[i]/= (double) N;
        if (iF[i].real()>0) iyF.append(abs(iF[i]));
        else  iyF.append(-abs(iF[i]));
    }
    if (!ui->widget_idft->legend->visible()){//чтобы постоянно не считать
        iMinX = *std::min_element(x.begin(), x.end());
        iMaxX = *std::max_element(x.begin(), x.end());
        iMinY = *std::min_element(iyF.begin(), iyF.end());
        iMaxY = *std::max_element(iyF.begin(), iyF.end());
        //Установим область, которая будет показываться на графике
        ui->widget_idft->xAxis->setRange(iMinX, iMaxX);// Для оси Ox
        ui->widget_idft->yAxis->setRange(iMinY, iMaxY);//Для оси Oy
        ui->widget_idft->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);
        ui->widget_idft->legend->setVisible(true);
    }
    iDFTgraph->setData(x.toVector(), iyF.toVector());
    iDFTgraph->setVisible(true);
    ui->widget_idft->replot();
}

void FilterFFT::on_pushButton_saveTxt_clicked() //сохранение в текстовый файл
{
    QString nameGr = "Обратное преобраз-е Фурье";
    QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение преобразованного сигнала"),
                  nameGr, "Файл txt (*.txt)");
    QFile fileOut(fileName);
        if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
            for(int i = 0; i < N; i++){
                writeStream << ixF[i] << "\t" << iyF[i] << "\n";
            }
            fileOut.close();
        }
}

void FilterFFT::on_pushButton_close_clicked()
{
    this->close();
}

void FilterFFT::on_Slider_level_valueChanged(int value) //изменение слайдера уровня шумов и фильтрация
{
    yL[0] = yL[1] = value;
    horizLevel->setData(xL.toVector(), yL.toVector());  
    /*for (int i = 0; i < N; i++){
        if (value >= yFcopy[i]) {
            yF[i] = 0.0; F[i] = 0.0;
        }else{//восстанавливаем из копии
            yF[i] = yFcopy[i]; F[i] = Fcopy[i];
        }
    }*/
    DFTgraph->setData(xF.toVector(), yF.toVector());
    ui->widget_dft->replot();
    iDFT(ixF);
}

void FilterFFT::on_Slider_sens_valueChanged(int value) //изменение чувствительности уровня шумов
{
    ui->Slider_level->setPageStep(maxY /(yF.count()*value));
    ui->Slider_level->setTickInterval(maxY /(yF.count()*value));
    ui->Slider_level->setSingleStep(maxY /(yF.count()*value));
}

void FilterFFT::on_pushButton_clicked()
{
    double sum1 = 0.0;
    int count = 0;
    std::complex <double> sum2(0.0, 0.0);
    for (int i = 0; i < N; i++){
        if (ui->Slider_level->value() >= yFcopy[i]) { //не выходим за уровень
            for (int j = 0; j <=i; j++){ //расчет скользящее среднее
                if (ui->Slider_level->value() >= yFcopy[j]){
                    sum1 += yF[j];
                    sum2 += F[j];
                    count += 1;
                }
            }
            sum1/= (double) count;
            sum2/= (double) count;
            yF[i] = sum1;
            F[i] = sum2;
            sum1 = 0.0; count = 0; sum2 = (0.0, 0.0);
        }
    }
    DFTgraph->setData(xF.toVector(), yF.toVector());
    ui->widget_dft->replot();
    iDFT(ixF);
}
