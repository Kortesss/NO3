#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "derivative.h"
#include <QDebug>
#include "somewindow.h"
#include "delta.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(ui->widget,SIGNAL(mouseRelease(QMouseEvent*)),this,SLOT(mouseRelease(QMouseEvent*)));
    connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMove(QMouseEvent*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Рисуем график y=x*x
void MainWindow::on_action_4_triggered()
{
        double a = -1; //Начало интервала, где рисуем график по оси Ox
        double b =  1; //Конец интервала, где рисуем график по оси Ox
        double h = 0.01; //Шаг, с которым будем пробегать по оси Ox

        int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
        QVector<double> x(N), y(N); //Массивы координат точек
        //Вычисляем наши данные
        int i=0;
        for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
        {
            x[i] = X;
            y[i] = X*X;//Формула нашей функции
            i++;
        }
        ui->widget->clearGraphs();
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(x, y);
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(a, b);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double minY = y[0], maxY = y[0];
        for (int i=1; i<N; i++){
            if (y[i]<minY) minY = y[i];
            if (y[i]>maxY) maxY = y[i];
        }
        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy
        //this->graph_zero = true;
        //И перерисуем график на нашем widget
        ui->widget->replot();
}

//рисуем график из загруженного массива
void MainWindow::on_action_3_triggered()
{
    //Рисуем точки
        ui->widget->clearGraphs();//Если нужно, очищаем все графики
        //Добавляем один график в widget
        ui->widget->addGraph();
        //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        ui->widget->graph(0)->setData(this->mass_x.toVector(), this->mass_y.toVector());

        ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
        //ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
        //формируем вид точек
        ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(this->minx, this->maxx);//Для оси Ox
        //ui->widget->xAxis->setRange(200,800);//Для оси Ox
        ui->widget->yAxis->setRange(this->miny,this->maxy);//Для оси Oy
        //И перерисуем график на нашем widget
        ui->widget->replot();
        //this->graph_zero = true;
        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

//выбор файла и заполнение массива данных
void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "(*.txt);;All files (*.*)");
    if (fileName.length() > 0){
       QFile file(fileName);
       setWindowTitle(file.fileName());
       this->mass_x.clear();
       this->mass_y.clear();
       if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Заголовок сообщения об ошибке", file.errorString());
        }
        QTextStream in(&file);

        while(!in.atEnd()) {
            QString line = in.readLine();
            QRegExp rx("(\\ |\\t)"); //RegEx for ' ' or '\t'
            line=line.replace(',','.');
            QStringList fields = line.split(rx);
            ui->textBrowser->append(QString("%1 %2").arg(fields[0].toDouble()).arg(fields[1].toDouble()));
            //   ui->textBrowser->append(line);
            //добавляем в список X
            this->mass_x.append(fields[0].toDouble());
            //добавляем в список Y
            this->mass_y.append(fields[1].toDouble());
        }
        file.close();
        this->minx = *std::min_element(this->mass_x.begin(), this->mass_x.end());
        this->maxx = *std::max_element(this->mass_x.begin(), this->mass_x.end());
        this->miny = *std::min_element(this->mass_y.begin(), this->mass_y.end());
        this->maxy = *std::max_element(this->mass_y.begin(), this->mass_y.end());
        this->koef=(this->maxx-this->minx)/(this->mass_x.count());//расчет коэф. плотности данных
        ui->textBrowser_2->append(QString("%1").arg(this->maxx));
        ui->textBrowser_3->append(QString("%1").arg(this->minx));
        ui->listWidget->addItem("График "+QString::number(ui->listWidget->count()));

    }
}
//-----------------------------------------------------

//функция обработки нажатия кнопки мыши и считывание координат
  void MainWindow::mousePress(QMouseEvent *mouseEvent){
      ui->statusBar->showMessage("x = "+QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()))
                                 +"; y = "+QString::number(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y())));

      if (mouseEvent->button() == Qt::LeftButton){
          //Derivative *de = new Derivative(1.0,1.2,2.1,3.2); просто пытался обратиться к тому классу
          //qDebug() << de->get_dd();
      if(this->ui->widget->graphCount()!=0){
          if (ui->action_9->isChecked()){
              this->mass_minX.append(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()));
              this->mass_minY.append(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
              ui->widget->addGraph();
                  ui->widget->graph(1)->setData(this->mass_minX.toVector(), this->mass_minY.toVector());
                  ui->widget->graph(1)->setPen(QColor(67, 138, 0, 255));
                  ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);//убираем линии
                  ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
                  ui->widget->replot();
          }
      //добавляем максимумы x, y
          if (ui->action_10->isChecked()){
              this->mass_maxX.append(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()));
              this->mass_maxY.append(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
                ui->widget->addGraph();
                ui->widget->addGraph();
                  ui->widget->graph(2)->setData(this->mass_maxX.toVector(), this->mass_maxY.toVector());
                  ui->widget->graph(2)->setPen(QColor(255, 0, 0, 255));
                  ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone);//убираем линии
                  ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
                  ui->widget->replot();
          }
      }
      }
      //if (mouseEvent->button() == Qt::RightButton){
          //удаление точек
      //    QMutableListIterator<double> i(this->mass_minY);

      //    while(i.hasNext()) {
      //      int currentValue=i.next();
      //      qDebug() << currentValue;
      //      qDebug() << round(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
      //      if(currentValue==round(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y())))
      //        i.remove();
      //    }

      //}
}

//функция обработки отпускания кнопки мыши и зуммирования
//void MainWindow::mouseRelease(QMouseEvent *event) {}

//вычисление производной по 2м точкам
double MainWindow::prdelfun(double x1,double x2,double y1,double y2){
    double dx,dy,dd;
    dx=x2-x1;
    dy=y2-y1;
    dd=dy/dx;
    return dd;
}

//функция приближенного вычисления производной(не работает пока)
double MainWindow::prfun(double px){
  //double h, fl, fr, fc, f2;
  px = 1; // точка, в которой вычисляем производную
  //h = 0.1; // шаг, с которым вычисляем производную
  // приближенно вычисляем первую производную различными способами
/*  fl = (f(px) - f(px - h)) / h; // левая
  fr = (f(px + h) - f(px)) / h; // правая
  fc = (f(px + h) - f(px - h)) / (2 * h); // центральная
  // приближенно вычисляем вторую производную
  f2 = (f(px + h) - 2 * f(px) + f(px - h)) / (h * h);
*/
}

//------------------------------------------------------
/*void MainWindow::on_textBrowser_destroyed()
{}*/

//вызов вычисления производной кучочно-непрерывной функции
void MainWindow::on_action_2_triggered() {
  if (this->ui->widget->graphCount()!=0){
    double x1 = ui->doubleSpinBox_x1->value();
    double x2 = ui->doubleSpinBox_x2->value();
//расчет производной по отметкам (начало конец по Х)
    double sred=0, znpozit=0;
    dirivate.clear();
    //обработка введеных значений если они за пределами возможных
    if (x1<this->minx) x1=this->minx;
    if (x2>this->maxx) x2=this->maxx;
    //ищем ближайшее к введеному значение из массива данных
    int i=0;
    while (x1>this->mass_x[i]) { i++;}
    x1=i;
    i=0;
    while (x2>this->mass_x[i]) { i++;}
    x2=i;
    int j=x1;
      for (i=x1; i<x2; i++) {
            //qDebug() << ">mass_x="<<this->mass_x[i];
            //qDebug() << ">mass_y="<<this->mass_y[j];
            znpozit=prdelfun(this->mass_x[i],this->mass_x[i+1],this->mass_y[j],this->mass_y[j+1]);
            //qDebug() << "znpozit="<<znpozit;
            dirivate.append(znpozit);
//            Derivative *derivative = new Derivative(x1,x2,y1,y2);
//            Derivative *derivative = new Derivative(this->mass_x[i],this->mass_x[i+1],this->mass_y[j],this->mass_y[j+1]);

//            ui->textBrowser_4->append(QString("%1").arg(derivative->get_dd()));
            sred=sred+znpozit;
            j++;
    }
      this->x1=x1;this->x2=x2;
   // qDebug() << "sred="<<sred;
    ui->textBrowser_4->clear();
    ui->textBrowser_4->append(QString("dx/dy ")+QString::number(sred));
    /*int i,j=100,k=200;
    double sred=0, znpozit=0;
    for (i=100; i<k; i++) {
            qDebug() << ">mass_x="<<this->mass_x[i];
            qDebug() << ">mass_y="<<this->mass_y[j];
            znpozit=prdelfun(this->mass_x[i],this->mass_x[i+1],this->mass_y[j],this->mass_y[j+1]);
            qDebug() << "znpozit="<<znpozit;
            sred=sred+znpozit;
            j++;
    }
    sred=sred/100;
    qDebug() << "sred="<<sred;*/
    //delete Derivative();
  }
  else{  QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных"));}
}


void MainWindow::on_action_5_triggered()
//отрисовка графика производной
{
//    MainWindow *NewWindow=new MainWindow;
//    NewWindow->show();
//    ui->widget->addGraph();
    SomeWindow *DXWindow=new SomeWindow(dirivate,this->x1,this->x2,this->koef,this);
//    QCustomPlot object ;
    DXWindow->show();

}

void MainWindow::on_action_7_triggered()
{
    //Экстремумы
    this->mass_minX.clear(); this->mass_maxX.clear(); this->mass_minY.clear(); this->mass_maxY.clear();//чтобы память не засорять
        if ((this->mass_x.count())>0) {
           if (this->ui->widget->graphCount()!=0){//если нулевой граф построен
                bool up; //переменная отвечающая за возрастание
                if (this->mass_x[1]>this->mass_x[0]) up = true; //смотрим, возрастает ли график
                for(int i = 0; i < this->mass_x.count()-1; i ++){
                    if (up){ //если возрастает
                        if (this->mass_y[i + 1] < this->mass_y[i]){ //ждем когда она перестанет возрастать
                            if((this->mass_y[i] - this->mass_y[i + 1])>ui->doubleSpinBox1->value()){
                                this->mass_maxX.append(this->mass_x[i]);
                                this->mass_maxY.append(this->mass_y[i]);
                                up = false;
                            }
                        }
                    }
                    else{
                        if (this->mass_y[i + 1] > this->mass_y[i]){ //ждем когда она перестанет убывать
                            if((this->mass_y[i+1] - this->mass_y[i])>ui->doubleSpinBox1->value()){
                                this->mass_minX.append(this->mass_x[i]);
                                this->mass_minY.append(this->mass_y[i]);
                                up = true;
                            }
                        }
                    }
                }

                ui->widget->addGraph();
                ui->widget->graph(1)->setData(this->mass_minX.toVector(), this->mass_minY.toVector());
                ui->widget->graph(1)->setPen(QColor(67, 138, 0, 255));//задаем зеленый цвет
                ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);//убираем линии
                ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
                ui->widget->addGraph();
                ui->widget->graph(2)->setData(this->mass_maxX.toVector(), this->mass_maxY.toVector());
                ui->widget->graph(2)->setPen(QColor(255, 0, 0, 255));//задаем красный цвет точки
                ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone);//убираем линии
                ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
                ui->widget->replot();
             }
              else{
                QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("График пуст!"));
            }
        }
        else{
            QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню, а то все рухнет )"));
        }
}

void MainWindow::on_action_8_triggered()
{
    MainWindow *NewWindow=new MainWindow;
    NewWindow->show();
}

void MainWindow::on_action_9_triggered()
{
    ui->action_10->setChecked(false);
}

void MainWindow::on_action_11_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_10_triggered()
{
    ui->action_9->setChecked(false);
}

void MainWindow::on_doubleSpinBox1_editingFinished()
{
    this->on_action_7_triggered();
}

void MainWindow::on_action_12_triggered()
{//Сохранение графика
    QString nameGr = "";
    if (ui->listWidget->selectedItems().size()>0) nameGr = ui->listWidget->currentItem()->text();

    QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение графика"),
                       nameGr, "Изображение png (*.png);; Изображение jpg (*.jpg);; Изображение bmp(*.bmp);; Документ pdf(*.pdf)");
    if (!fileName.isNull()){
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly|QFile::WriteOnly)) QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Что-то пошло не так."));
            else if (fileName.contains(".png", Qt::CaseInsensitive)) ui->widget->savePng(fileName);
                else if (fileName.contains(".jpg", Qt::CaseInsensitive)) ui->widget->saveJpg(fileName);
                    else if (fileName.contains(".bmp", Qt::CaseInsensitive)) ui->widget->saveBmp(fileName);
                        else ui->widget->savePdf(fileName);
    }
}

void MainWindow::on_action_delta_triggered()
{ //Расчет изменения дельты сигнала
    delta *DeltaWin = new delta(this->mass_minX, this->mass_maxX, this->mass_minY, this->mass_maxY, this);
    DeltaWin->show();
}
