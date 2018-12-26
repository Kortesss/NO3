#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "derivative.h"
#include <QDebug>
#include "somewindow.h"
#include "deltawin.h"
#include "mnk.h"
#include "loadfile.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->widget,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(histogramMouseMoved(QMouseEvent*)));
    axis_max=false; axis_min=false; mnkMax=false; mnkMin=false;
    levelMax=false; levelMin=false;

    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    graphMin = ui->widget->addGraph(); //Добавление минимумов
    graphMin->setPen(QColor(67, 138, 0, 255));//задаем зеленый цвет
    graphMin->setLineStyle(QCPGraph::lsNone);//убираем линии
    graphMin->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    graphMin->setName(" ");
    graphMax = ui->widget->addGraph(); //Добавление максимумов
    graphMax->setPen(QColor(255, 0, 0, 255));//задаем красный цвет точки
    graphMax->setLineStyle(QCPGraph::lsNone);//убираем линии
    graphMax->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    graphMax->setName(" ");

    graphMnkMin = ui->widget->addGraph(); //Добавление МНК мин
    graphMnkMin->setPen(QColor(67, 138, 0, 255));//задаем зеленый цвет
    graphMnkMin->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    graphMnkMin->setName(" ");
    graphLevelMin = ui->widget->addGraph(); //Добавление линии перегиба мин
    graphLevelMin->setPen(QColor(32, 154, 230, 255));//задаем синий цвет
    graphLevelMin->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 6));
    graphLevelMin->setName(" ");

    graphMnkMax = ui->widget->addGraph(); //Добавление МНК максимумов
    graphMnkMax->setPen(QColor(255, 0, 0, 255));
    graphMnkMax->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    graphMnkMax->setName(" ");
    graphLevelMax = ui->widget->addGraph(); //Добавление линии перегиба max
    graphLevelMax->setPen(QColor(2, 15, 250, 255));//задаем темно-синий цвет
    graphLevelMax->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 6));
    graphLevelMax->setName(" ");

    graphic1 = ui->widget->addGraph();	//Добавление графика 1
    graphic1->setName(" ");
    graphic1->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    //формируем вид точек
    graphic1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

}

MainWindow::~MainWindow()
{
    qDebug() << "деструктор MainWindow";
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
        ui->widget->replot();
}

void MainWindow::setMassX(double massX){this->mass_x.append(massX);}
void MainWindow::setMassY(double massY){this->mass_y.append(massY);}
//выбор файла и заполнение массива данных
void MainWindow::on_action_triggered()
{
    this->mass_x.clear();
    this->mass_y.clear();
    QThread *thread= new QThread; //создали экземпляр класса QThread для нового потока в приложении
    loadFile *loadF = new loadFile(ui, this); //cоздали экземпляр класса чтения файла

    loadF->moveToThread(thread); //переместили экземпляр нашего класса в новый поток
    //Соединили сигнал нового потока о старте работы потока с методом doWork() класса LoadFile,
    //чтобы этот метод запустился при старте потока
    connect(thread, SIGNAL(started()), loadF, SLOT(doWork()));
    // Оповещаем поток, что нужно остановиться
    connect(this, SIGNAL(sendNumberBoolStop(bool)), loadF, SLOT(reciveBoolStop(bool)), Qt::DirectConnection);
    // По завершению выходим из потока, и удаляем рабочий класс
    connect(loadF, SIGNAL(destroyed(QObject*)), thread, SLOT(quit()));  // ТАК ПРАВИЛЬНО
    connect(loadF, SIGNAL(finished()), loadF, SLOT(deleteLater()));

    // Удаляем поток, после выполнения операции
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();//запускаем поток

}

//рисуем график из загруженного массива
void MainWindow::on_action_3_triggered()
{
    this->minx = *std::min_element(this->mass_x.begin(), this->mass_x.end());
    this->maxx = *std::max_element(this->mass_x.begin(), this->mass_x.end());
    this->miny = *std::min_element(this->mass_y.begin(), this->mass_y.end());
    this->maxy = *std::max_element(this->mass_y.begin(), this->mass_y.end());
    this->koef=(this->maxx-this->minx)/(this->mass_x.count());//расчет коэф. плотности данных
    ui->textBrowser_2->append(QString("%1").arg(this->maxx));
    ui->textBrowser_3->append(QString("%1").arg(this->minx));
    //Рисуем точки
    graphic1->setData(this->mass_x.toVector(), this->mass_y.toVector());
    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(this->minx, this->maxx);// Для оси Ox
    ui->widget->yAxis->setRange(this->miny,this->maxy);//Для оси Oy
    graphic1->setName("График "+QString::number(ui->listWidget->count()));
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);//устанавливаем легенду в правый верхний угол
    ui->widget->legend->setVisible(true); ui->widget->replot();
}

//функция обработки нажатия кнопки мыши и считывание координат
  void MainWindow::mousePress(QMouseEvent *mouseEvent){

      if (mouseEvent->button() == Qt::LeftButton){
       QCPItemText *text = new QCPItemText(ui->widget);
      if(graphic1->dataCount()!=0){
          if (ui->action_9->isChecked()&& ui->checkMin->isChecked()){
              textListMin.append(text);
              textListMin.last()->setVisible(true);
              this->mass_minX.append(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()));
              this->mass_minY.append(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
              textListMin.last()->setText("("+QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',2) //округление до 2-х знаков
                            +"; "+QString::number(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()),'f',2)+")");
              textListMin.last()->position->setCoords(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x())-5, ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y())-2);
              graphMin->setData(this->mass_minX.toVector(), this->mass_minY.toVector());
              graphMin->setName("Минимумы"); graphMin->setVisible(true);
              ui->widget->replot();
          }
      //добавляем максимумы x, y
          if (ui->action_9->isChecked() && ui->checkMax->isChecked()){
              this->mass_maxX.append(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()));
              this->mass_maxY.append(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
              graphMax->setData(this->mass_maxX.toVector(), this->mass_maxY.toVector());
              graphMax->setName("Максимумы"); graphMax->setVisible(true);
              textListMax.append(text);
              textListMax.last()->setVisible(true);
              textListMax.last()->setText("("+QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',2)
                                +"; "+QString::number(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()),'f',2)+")");
              textListMax.last()->position->setCoords(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x())-5, ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y())+2);
              ui->widget->replot();
          }
      }
      }
    if (mouseEvent->button() == Qt::RightButton){//удаление точек
        if (ui->action_9->isChecked()&& ui->checkMin->isChecked()){
            for(int i = 0; i < this->mass_minX.count(); i ++){
                if(QString::compare(QString::number(this->mass_minX[i],'f',0), QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',0))==0){
                    this->mass_minX.removeAt(i);   this->mass_minY.removeAt(i);
                    graphMin->setData(this->mass_minX.toVector(), this->mass_minY.toVector());
                    if (this->textListMin.count()>0) this->textListMin[i]->setVisible(false); this->textListMin.removeAt(i);
                    on_action_17_triggered();
                }
            }
        }
        if (ui->action_9->isChecked() && ui->checkMax->isChecked()){
            for(int i = 0; i < this->mass_maxX.count(); i ++){
                if(QString::compare(QString::number(this->mass_maxX[i],'f',0), QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',0))==0){
                    this->mass_maxX.removeAt(i);   this->mass_maxY.removeAt(i);
                    graphMax->setData(this->mass_maxX.toVector(), this->mass_maxY.toVector());
                    if (this->textListMax.count()>0) this->textListMax[i]->setVisible(false); this->textListMax.removeAt(i);
                    on_action_17_triggered();
                }
            }
        }
        ui->widget->replot();
      }
}

void MainWindow::histogramMouseMoved(QMouseEvent *event){
    ui->statusBar->showMessage("x="+QString::number(ui->widget->xAxis->pixelToCoord(event->pos().x()),'f',2)//округление до 2-х знаков
                               +"; y="+QString::number(ui->widget->yAxis->pixelToCoord(event->pos().y()),'f',2));
}

//вычисление производной по 2м точкам
double MainWindow::prdelfun(double x1,double x2,double y1,double y2){
    double dx,dy,dd;
    dx=x2-x1;
    dy=y2-y1;
    dd=dy/dx;
    return dd;
}

void MainWindow::on_action_7_triggered()
{
    //удаление экстремумов
    if (ui->checkMin->isChecked()){this->mass_minX.clear(); this->mass_minY.clear();
                graphMin->setVisible(false); graphMin->setName(" ");
                for (int i = 0; i < this->textListMin.length(); i++) {this->textListMin[i]->setVisible(false);}
                textListMin.clear();}
    if (ui->checkMax->isChecked()){this->mass_maxY.clear(); this->mass_maxX.clear();
                graphMax->setVisible(false); graphMax->setName(" ");
                for (int i = 0; i < this->textListMax.length(); i++) {this->textListMax[i]->setVisible(false);}
                textListMax.clear();}
    if (!ui->checkMin->isChecked() && !ui->checkMax->isChecked()){
        this->mass_minX.clear(); this->mass_minY.clear(); graphMin->setVisible(false); graphMin->setName(" ");
        this->mass_maxY.clear(); this->mass_maxX.clear(); graphMax->setVisible(false); graphMax->setName(" ");
        for (int i = 0; i < this->textListMin.length(); i++) {this->textListMin[i]->setVisible(false);}
        for (int i = 0; i < this->textListMax.length(); i++) {this->textListMax[i]->setVisible(false);}
        this->textListMin.clear(); this->textListMax.clear();
    }
       ui->widget->replot();
}

void MainWindow::on_action_8_triggered()
{
    MainWindow *NewWindow=new MainWindow;
    NewWindow->show();
    NewWindow->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::on_action_11_triggered()
{
    QApplication::quit();
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
        file.close();
    }
}

void MainWindow::on_spinLevel_valueChanged()
{  //спин мнк
   on_action_17_triggered();
}

void MainWindow::on_doubleSpinBox1_valueChanged()
{
    //измение спина экстремомов
    on_action_10_triggered();
}

void MainWindow::on_actionD_triggered()
{
    //Расчет изменения дельты сигнала
        if (this->mass_minX.count()!=0 && this->mass_maxX.count()!=0 && this->mass_minY.count()!=0 && this->mass_maxY.count()!=0){
            //сортировка экстремумов по возрастанию, вдруг мы добавили в конец списка Qlist новый экстремум, который идет не по порядку
            qSort(this->mass_minX.begin(), this->mass_minX.end(), qLess<double>());
            qSort(this->mass_maxX.begin(), this->mass_maxX.end(), qLess<double>());
            //но игрикам не подходит сортирвка, поэтому лучше строить по порядку пока что
            deltaWin *DeltaW = new deltaWin(this->mass_minX, this->mass_maxX, this->mass_minY, this->mass_maxY, this);
            DeltaW->show();
            DeltaW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
        }else{QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Экстремумы не определены!"));}
}

void MainWindow::on_action_21_triggered()
{
    on_action_13_triggered();
    //отрисовка графика производной
        SomeWindow *DXWindow=new SomeWindow(dirivate,this->x1,this->x2,this->koef,this);
        DXWindow->show();
        DXWindow->setAttribute(Qt::WA_DeleteOnClose); //деструктор
}

void MainWindow::on_checkMin_clicked()
{
    ui->checkMax->setChecked(false);
}

void MainWindow::on_checkMax_clicked()
{
    ui->checkMin->setChecked(false);
}

void MainWindow::on_action_10_triggered()
{
    //Экстремумы
    this->mass_minX.clear(); this->mass_maxX.clear(); this->mass_minY.clear(); this->mass_maxY.clear();//чтобы память не засорять
        if ((this->mass_x.count())>0) {
           if (graphic1->dataCount()!=0){//если график1 построен
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
                graphMin->setData(this->mass_minX.toVector(), this->mass_minY.toVector());
                graphMin->setName("Минимумы");
                graphMin->setVisible(true);
                graphMax->setData(this->mass_maxX.toVector(), this->mass_maxY.toVector());
                graphMax->setName("Максимумы");
                graphMax->setVisible(true);
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

void MainWindow::on_action_13_triggered()
{ //вызов вычисления производной кучочно-непрерывной функции
    if (graphic1->dataCount()!=0){
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
      //delete derivative();
    }
    else{  QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных"));}
}

void MainWindow::on_action_17_triggered()
{
    if (ui->checkMin->isChecked()){
        //Метод наименьших квадратов (МНК) минимума
            if (this->mass_minX.count() != 0){
                trendMin.clear();
                QList<double> yLevel, xLevel;
                mnk *mnk1 = new mnk(this->mass_minX, this->mass_minY, this->mass_minX.count());
                double Kdet = mnk1->get_Kdet();
                double a = mnk1->get_a();
                double b = mnk1->get_b();
                //QMessageBox::information(NULL,"Информация","Коэффициент детерминации = "+QString::number(Kdet));
                for(int i = 0; i < this->mass_minX.count(); i++){
                    this->trendMin.append(mnk1->get_yy(this->mass_minX[i]));
                }
                yLevel.append(this->trendMin[0]+this->trendMin[0]*(ui->spinLevel->value()/100));
                yLevel.append(yLevel[0]+yLevel[0]*0.1);
                yLevel.append(yLevel[0]-yLevel[0]*0.1);
                xLevel.append((yLevel[0]-b)/a);   xLevel.append((yLevel[0]-b)/a); xLevel.append((yLevel[0]-b)/a);

                graphMnkMin->setData(this->mass_minX.toVector(), this->trendMin.toVector());
                graphMnkMin->setVisible(true);
                graphMnkMin->setName(QString::number(a,'f',2)+"*x+"+QString::number(b,'f',2)+" R^2="+QString::number(Kdet,'f',2));
                graphLevelMin->setData(xLevel.toVector(), yLevel.toVector());
                graphLevelMin->setName("Линия перегиба min");
                graphLevelMin->setVisible(true);
                //----
                yLevel.clear(); xLevel.clear();
                ui->widget->replot();
                delete mnk1; //деструктор
            }else{QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Точки минимума не определены!"));}
    }
    if (ui->checkMax->isChecked()){
        //Метод наименьших квадратов (МНК)максимума
            if (this->mass_maxX.count() != 0){
                trendMax.clear();
                QList<double> yLevel, xLevel;
                mnk *mnk2 = new mnk(this->mass_maxX, this->mass_maxY, this->mass_maxX.count());
                double Kdet = mnk2->get_Kdet();
                double a = mnk2->get_a();
                double b = mnk2->get_b();
                //QMessageBox::information(NULL,"Информация","Коэффициент детерминации = "+QString::number(Kdet));
                for(int i = 0; i < this->mass_maxX.count(); i++){
                    this->trendMax.append(mnk2->get_yy(this->mass_maxX[i]));
                }
                yLevel.append(this->trendMax[0]+this->trendMax[0]*(ui->spinLevel->value()/100));
                yLevel.append(yLevel[0]+yLevel[0]*0.1);
                yLevel.append(yLevel[0]-yLevel[0]*0.1);

                xLevel.append((yLevel[0]-b)/a);   xLevel.append((yLevel[0]-b)/a); xLevel.append((yLevel[0]-b)/a);
                graphMnkMax->setData(this->mass_maxX.toVector(), this->trendMax.toVector());
                graphMnkMax->setVisible(true);
                graphMnkMax->setName(QString::number(a,'f',2)+"*x+"+QString::number(b,'f',2)+" R^2="+QString::number(Kdet,'f',2));
                graphLevelMax->setData(xLevel.toVector(), yLevel.toVector());
                graphLevelMax->setName("Линия перегиба max");
                graphLevelMax->setVisible(true);
                //----
                yLevel.clear(); xLevel.clear();
                ui->widget->replot();
                delete mnk2; //деструктор
            }else{QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Точки максимума не определены!"));}
    }
    if (!ui->checkMin->isChecked() && !ui->checkMax->isChecked()) QMessageBox::information(NULL,"Внимание", "Пожалуйста, выберите минимум или максимум.");
}

void MainWindow::on_action_19_triggered()
{   //удаление МНК
    if (ui->checkMin->isChecked()){ this->trendMin.clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" ");
        graphLevelMin->setVisible(false); graphLevelMin->setName(" ");}
    if (ui->checkMax->isChecked()){ this->trendMax.clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" ");
        graphLevelMax->setVisible(false); graphLevelMax->setName(" ");}
    if (!ui->checkMin->isChecked() && !ui->checkMax->isChecked()){
        this->trendMin.clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" ");
        graphLevelMin->setVisible(false);  graphLevelMin->setName(" ");
        this->trendMax.clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" ");
        graphLevelMax->setVisible(false); graphLevelMax->setName(" ");
    }
    ui->widget->replot();
}

void MainWindow::on_action_16_triggered()
{   //очистка всех графиков
    this->mass_minX.clear(); this->mass_maxX.clear(); this->mass_minY.clear(); this->mass_maxY.clear();
    graphMin->setVisible(false); graphMax->setVisible(false); graphMin->setName(" ");graphMax->setName(" ");
    this->trendMin.clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" "); graphLevelMin->setVisible(false); graphLevelMin->setName(" ");
    this->trendMax.clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" "); graphLevelMax->setVisible(false); graphLevelMax->setName(" ");
    for (int i = 0; i < this->textListMin.length(); i++) {this->textListMin[i]->setVisible(false);}
    for (int i = 0; i < this->textListMax.length(); i++) {this->textListMax[i]->setVisible(false);}
    this->textListMin.clear(); this->textListMax.clear();
    ui->widget->replot();
}
