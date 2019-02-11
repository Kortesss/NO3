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
    connect(ui->widget_dft,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(ui->widget_dft, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(histogramMouseMoved(QMouseEvent*)));
    connect(ui->widget_dft, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(spanMouseUp(QMouseEvent*)));
    mouseDown = false; left = false; sp = false;

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

    graphSpan = ui->widget_dft->addGraph(); //Добавление диапазона значений
    QPen Pen1; Pen1.setWidthF(2); Pen1.setColor(QColor(192,192,192, 200)); //серый цвет с непрозрачностью 200
    graphSpan->setPen(Pen1);
    graphSpan->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    graphSpan->setName("Диапазон значений");
    for (int i = 0; i < 4 ; i++) spanX.append(0.0);

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
    x1 = minX; x2 = maxX;
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

void FilterFFT::mousePress(QMouseEvent *event) //событие для нажатия правой конпки мыши и установки границы иксов
{
    if (event->button() == Qt::RightButton){
        spanY.clear();
        spanY.append(maxY); spanY.append(minY);
        spanY.append(minY); spanY.append(maxY);
        double currentX = ui->widget_dft->xAxis->pixelToCoord(event->pos().x());
        if ((currentX < minX) || (currentX > maxX)){
            graphSpan->setVisible(false); ui->widget_dft->replot();
            x1 = minX; x2 = maxX;
            spanX[0] = spanX[1] = x1;
            mouseDown = true; sp = false;
        }else{//В пределах границ графика
            x1 = currentX;
            spanX[0] = spanX[1] = x1;
            mouseDown = true; sp = true;
        }
    }
    ui->widget_dft->replot();
}

void FilterFFT::histogramMouseMoved(QMouseEvent *event) //передвижение мышки на графике DFD
{
    double currentX = ui->widget_dft->xAxis->pixelToCoord(event->pos().x());
    if (mouseDown){
        if (currentX < minX){//перед графиком
            graphSpan->setVisible(false); ui->widget_dft->replot(); sp = false;
            }else if (currentX > maxX){//после графика
                spanX[2] = spanX[3] = maxX;
                graphSpan->setData(spanX, spanY);
                graphSpan->setVisible(true);
                ui->widget_dft->replot(); sp = true;
            }
            else{//иначе координаты мыши были в пределах границы графика
                if (currentX > x1){//идем вправо
                    x2 = currentX; left = false;
                    spanX[2] = spanX[3] = x2;//точка, в которой две коррдинаты x2=СпинX2
                    spanY[1] = spanY[2] = minY; spanY [0] = spanY[3] = maxY;
                }
                else {//проверяем если идем влево
                    if (!left){ //left нужен, чтобы повторно нне заходить сюда
                         x2 = x1;//x2 теперь становится начальным значением
                         left = true;
                    }
                    x1 = currentX; //а x1 текучим и движется влево (убывает)
                    spanX[0] = spanX[1] = x2;
                    spanX[2] = spanX[3] = x1;
                    spanY[0] = spanY[3] = minY; spanY [1] = spanY[2] = maxY;
                }
                graphSpan->setData(spanX, spanY);
                graphSpan->setVisible(true);
                ui->widget_dft->replot(); sp = true;
           }
    }
    ui->statusbar->showMessage("x="+QString::number(currentX,'f',2)+"; y="+QString::number(ui->widget_dft->yAxis->pixelToCoord(event->pos().y()),'f',2));//округление до 2-х знаков
}

void FilterFFT::spanMouseUp(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton){
        mouseDown = false;
        if (graphSpan->visible()) ui->SliderSpan->setValue(1);
        else ui->SliderSpan->setValue(0);
        if (sp) ui->Slider_level->setValue(0);
    }
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

void FilterFFT::on_pushButton_close_clicked() //закрытие окна
{
    this->close();
}

void FilterFFT::on_Slider_level_valueChanged(int value) //изменение слайдера уровня шумов и фильтрация
{
    yL[0] = yL[1] = value;
    horizLevel->setData(xL.toVector(), yL.toVector());
    for (int i = 0; i < N; i++){
        if ((xF[i]>=x1) && (xF[i]<=x2)){
            if (value >= yFcopy[i]) {
                yF[i] = 0.0; F[i] = 0.0;
            }else{//восстанавливаем из копии
                yF[i] = yFcopy[i]; F[i] = Fcopy[i];
            }
        }
    }
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
            sum1 = 0.0; count = 0; sum2 = (0.0);
        }
    }
    DFTgraph->setData(xF.toVector(), yF.toVector());
    ui->widget_dft->replot();
    iDFT(ixF);
}

void FilterFFT::on_SliderSpan_valueChanged(int value)
{
    if ((value == 1) && (sp)) { //вкл
        ui->SliderSpan->setStyleSheet(".QSlider::groove:horizontal {height: 24px; background: #20B2AA; border-radius: 8px; padding:-4px 7px;}"
                                                  ".QSlider::handle:horizontal {background: #008080; width: 22px; margin: 0px -7px; border-radius: 11px;}");
        graphSpan->setVisible(true); ui->widget_dft->replot();
    }
    else{ //выкл
        ui->SliderSpan->setStyleSheet(".QSlider::groove:horizontal {height: 24px; background:#696969; border-radius: 8px; padding:-4px 7px;}"
                                       ".QSlider::handle:horizontal {background: #d5d5d5; width: 22px; margin: 0px -7px; border-radius: 11px;}");
        graphSpan->setVisible(false); ui->widget_dft->replot();
        ui->SliderSpan->setValue(0);
    }
}
