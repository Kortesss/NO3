#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "derivative.h"
#include <QDebug>
#include "somewindow.h"
#include "about.h"
#include "deltawin.h"
#include "mnk.h"
#include "filterfft.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->widget,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(histogramMouseMoved(QMouseEvent*)));
    connect(&timer, SIGNAL(timeout()), SLOT(TimerTick()));  t = 0; gr_index = 0;
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));

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

void MainWindow::TimerTick(){ //процедура таймера для добавления в список textBrowser
    if (t < mass_x_Gr[gr_index].length()){
        //а здесь получаем значения по индексу выделенного графика
        ui->textBrowser_X->append(QString("%1").arg(mass_x_Gr[gr_index][t]));
        ui->textBrowser_Y->append(QString("%1").arg(mass_y_Gr[gr_index][t]));
        t++;
    }else {timer.stop(); t = 0;} //в конце останавливаем таймер
}

void MainWindow::slotCustomMenuRequested(QPoint pos) //контекстное меню
{
    if (ui->listWidget->count() > 0){
        on_listWidget_clicked();
        QMenu *qmenu = new QMenu(this);
        //создаем действия для контекстного меню
        QAction *rename = new QAction(trUtf8("Переименовать"), this);
        QAction *clearGr = new QAction(trUtf8("Очистить графы"), this);
        QAction *delGr = new QAction(trUtf8("Удалить график"), this);
        QAction *saveGr = new QAction(trUtf8("Сохранить график"), this);
        QAction *manualSet = new QAction(trUtf8("Скрыть точки установленне вручную"), this);
        QAction *delMinMax = new QAction(trUtf8("Удалить точки экстремумов"), this);
        QAction *deltaS = new QAction(trUtf8("Δ сигнала"), this);

        //подключаем СЛОТы обработчики для действий контекстного меню
        connect(rename, SIGNAL(triggered(bool)), this, SLOT(menuRename()));
        connect(clearGr, SIGNAL(triggered(bool)), this, SLOT(on_action_16_triggered()));
        connect(delGr, SIGNAL(triggered(bool)), this, SLOT(on_action_5_triggered()));
        connect(saveGr, SIGNAL(triggered(bool)), this, SLOT(on_action_12_triggered()));
        connect(manualSet, SIGNAL(triggered(bool)), this, SLOT(manualSetView()));
        connect(delMinMax, SIGNAL(triggered(bool)), this, SLOT(on_action_7_triggered()));
        connect(deltaS, SIGNAL(triggered(bool)), this, SLOT(on_actionD_triggered()));
        //устанавливаем действия в меню
        qmenu->addAction(rename);
        qmenu->addAction(clearGr);
        qmenu->addAction(delGr);
        qmenu->addAction(saveGr);
        qmenu->addSeparator(); //добавляем разделитель
        qmenu->addAction(manualSet);
        qmenu->addAction(delMinMax);
        qmenu->addSeparator();
        qmenu->addAction(deltaS);
        //вызываем контекстное меню
        qmenu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
    }
}

void MainWindow::menuRename() //переименование графика
{
    lineEditRename = new QLineEdit(this); //объявляем QLineEdit (текстовая строка)
    lineEditRename->setAlignment(Qt::AlignCenter);
    lineEditRename->setText(ui->listWidget->item(gr_index)->text());
    lineEditRename->selectAll();    lineEditRename->setFocus();
    itRename = new QListWidgetItem(ui->listWidget);
    ui->listWidget->takeItem(gr_index); //удаляем строку, которую будем переименовывать
    ui->listWidget->setItemWidget(itRename, lineEditRename);//связываем итем и текстовую строку
    ui->listWidget->insertItem(gr_index, itRename);//вставляем в список графиков тот итем
    connect(lineEditRename, SIGNAL(returnPressed()), SLOT(EnterPressedLineEditRename()));

}

void MainWindow::EnterPressedLineEditRename() //обработчик события нажатия Enter в текстовом поле
{
    delete itRename;
    //ui->listWidget->addItem(lineEditRename->text()); delete lineEditRename;
    QStringList qstr; qstr << lineEditRename->text(); delete lineEditRename;
    ui->listWidget->insertItems(gr_index, qstr);
    ui->listWidget->item(gr_index)->setTextAlignment(Qt::AlignCenter);
    ui->listWidget->setCurrentRow(gr_index);
    graphic1->setName(ui->listWidget->item(gr_index)->text());
    ui->widget->replot();
}

void MainWindow::manualSetView() //показать/скрыть координаты точек установленных вручную
{
    for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(false);}
    for (int i = 0; i < textListMax[gr_index].length(); i++) {textListMax[gr_index][i]->setVisible(false);}
    ui->widget->replot();
}

void MainWindow::on_action_4_triggered() //Рисуем график y=x*x
{
        double a = 0; //Начало интервала, где рисуем график по оси Ox
        double b =  0.5; //Конец интервала, где рисуем график по оси Ox
        double h = 0.001; //Шаг, с которым будем пробегать по оси Ox

        int N=((b-a)/h + 2)*2; //Вычисляем количество точек, которые будем отрисовывать (в 2 раза больше, т.к.+помеха)
        QVector<double> x(N), y(N); //Массивы координат точек
        QFile fileOut("Зашумленный_сигнал.txt");
            if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
                //Вычисляем наши данные
                int i=0; double rand;
                for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
                {
                    x[i] = X;
                    if (i%2==0){ //на четном месте идет сигнал
                        //y[i] = X*X;//Формула нашей функции
                        y[i] = 15*qSin(2*M_PI*30*X)+15*qSin(2*M_PI*40*X)+15*qSin(2*M_PI*50*X)+15*qSin(2*M_PI*60*X);
                        writeStream << x[i] << "\t" << y[i] << "\n";
                        i++;
                    }else{//а здесь бобавляется помеха
                        rand = (qrand() % ((1000 + 1) + 1000) - 1000); //рандом от -1000 до 1000
                        rand /=100; //для получения дробного числа и создания шума
                        y[i] = y[i-1]+rand;
                        writeStream << x[i] << "\t" << y[i] << "\n";
                        i++;
                    }
                }
                fileOut.close(); // Закрываем файл
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

void MainWindow::on_action_filter_triggered() //Фильрация сигнала
{
    if (ui->listWidget->count() > 0){
        FilterFFT *FFTWindow=new FilterFFT(mass_x_Gr[gr_index], mass_y_Gr[gr_index], this);
        FFTWindow->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - фильтрация сигнала");
        FFTWindow->show();
        FFTWindow->setAttribute(Qt::WA_DeleteOnClose); //деструктор
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_action_triggered() //выбор файла и заполнение массива данных
{
    QProgressBar *progBar = new QProgressBar(this); //объявляем прогресс-бар
    QListWidgetItem *it = new QListWidgetItem(ui->listWidget); //объявляем итем и связываем его со списком графиков
    //btn->animateClick();
    QWidget* wgt = new QWidget;
    QLayout* l = new QHBoxLayout;
    l->addWidget(progBar);
    //QPushButton *btn = new QPushButton("S");
    //btn->setStyleSheet("QPushButton {width:5px; height:5px;}");
    //connect(btn, SIGNAL(clicked()), SLOT(onBtnClicked()));
    //l->addWidget(btn);
    wgt->setLayout(l);
    //it->setSizeHint(20);
    QString fileName = QFileDialog::getOpenFileName(0,
                        QString::fromUtf8("Открыть файл"),
                        QDir::currentPath(),
                        "(*.txt);;All files (*.*)");
    if (fileName.length() > 0){
            QFile file(fileName);
            setWindowTitle(file.fileName());
            ui->listWidget->insertItem(ui->listWidget->count()-1,it);//вставляем в список графиков тот итем
            ui->listWidget->setItemWidget(it, progBar);//связываем итем и прогресс-бар
            progBar->setFormat("График "+QString::number(ui->listWidget->count()));//настраиваем бар.. Текст
            progBar->setAlignment(Qt::AlignCenter);//текст по центру
            progBar->setTextVisible(true);//показываем текст
            progBar->setStyleSheet("QProgressBar {border: 1px solid grey;} QProgressBar::chunk {background-color: #05B8CC;}");
            progBar->setRange(0,100);//устанавливаем его диапазон до 100%

        if(!file.open(QIODevice::ReadOnly)) {QMessageBox::information(0, "Заголовок сообщения об ошибке", file.errorString());}
        QTextStream in(&file);
        mass_x_Gr.append(QList <double>());
        mass_y_Gr.append(QList <double>());
        while(!in.atEnd()) {
            QString line = in.readLine();
            QRegExp rx("(\\ |\\t)"); //RegEx for ' ' or '\t'
            line=line.replace(',','.');
            QStringList fields = line.split(rx);
            //ui->textBrowser->append(QString("%1 %2").arg(fields[0].toDouble()).arg(fields[1].toDouble()));
            //добавляем в список X
            mass_x_Gr[ui->listWidget->count()-1].append(fields[0].toDouble()); //добавляем данные по последниему индексу списка графиков listwidget
            //добавляем в список Y
            mass_y_Gr[ui->listWidget->count()-1].append(fields[1].toDouble());
            progBar->setValue((file.pos()*100)/file.size()); //двигаем значение бара по чтению текущей позиции из файла
        }
        file.close();
        ui->textBrowser_X->clear(); ui->textBrowser_Y->clear();
        if (timer.isActive() == true) {timer.stop(); t = 0;}
        gr_index = ui->listWidget->count()-1; timer.start(); //задаем текущий индекс графика и запускаем таймер
        delete it; delete progBar;  /*delete btn;*/  delete l; delete wgt;
        ui->listWidget->addItem("График "+QString::number(gr_index+1));//+1 потому что там еще ничего нет
        ui->listWidget->item(gr_index)->setTextAlignment(Qt::AlignCenter);
        minx.append(*std::min_element(mass_x_Gr[gr_index].begin(), mass_x_Gr[gr_index].end()));
        maxx.append(*std::max_element(mass_x_Gr[gr_index].begin(), mass_x_Gr[gr_index].end()));
        miny.append(*std::min_element(mass_y_Gr[gr_index].begin(), mass_y_Gr[gr_index].end()));
        maxy.append(*std::max_element(mass_y_Gr[gr_index].begin(), mass_y_Gr[gr_index].end()));
        koef.append((maxx[gr_index] - minx[gr_index])/(mass_x_Gr[gr_index].count()));//расчет коэф. плотности данных
        ui->Browser_Max->clear(); ui->Browser_Min->clear(); ui->BrowserTime->clear();
        ui->Browser_Max->append("Мин. X:\n" + QString("%1").arg(maxx[gr_index]));
        ui->Browser_Min->append("Макс. X:\n" + QString("%1").arg(minx[gr_index]));
        on_action_3_triggered();//рисуем график
        //для каждого графика задаем ему место под массив экстремумов, мнк, линии тренда и т.д.
        mass_minX.append(QList <double>()); mass_maxX.append(QList <double>());
        mass_minY.append(QList <double>()); mass_maxY.append(QList <double>());
        trendMin.append(QList <double>()); trendMax.append(QList <double>());
        mnkStrMin.append(" ");   mnkStrMax.append(" ");
        xLevelMin.append(QList <double>()); yLevelMin.append(QList <double>());
        xLevelMax.append(QList <double>()); yLevelMax.append(QList <double>());
        textListMin.append(QList <QCPItemText*>()); textListMax.append(QList <QCPItemText*>()); //для подписи координат на графике
        textListMNK.append(QList <QCPItemText*>()); //для отображения значения МНК на графике
        textListMNK[gr_index].append(new QCPItemText(ui->widget)); textListMNK[gr_index].append(new QCPItemText(ui->widget));
        ui->listWidget->setCurrentRow(gr_index); //устанавливаем выделение последнему загруженному графику
        FalseVisibleAllGraph(); //очищаем все графы предыдущего графика
    }else {delete it; delete progBar;  /*delete btn;*/  delete l; delete wgt;}
}

void MainWindow::on_action_3_triggered() //рисуем график из загруженного массива
{
    graphic1->setData(mass_x_Gr[gr_index].toVector(), mass_y_Gr[gr_index].toVector());
    graphic1->setVisible(true);
    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(minx[gr_index], maxx[gr_index]);// Для оси Ox
    ui->widget->yAxis->setRange(miny[gr_index], maxy[gr_index]);//Для оси Oy
    graphic1->setName("График "+QString::number(gr_index+1));
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);//устанавливаем легенду в правый верхний угол
    ui->widget->legend->setVisible(true); ui->widget->replot();
}

void MainWindow::mousePress(QMouseEvent *mouseEvent) //ручная установка экстремумов
{
    if (ui->listWidget->count() > 0){
      if (mouseEvent->button() == Qt::LeftButton){
          if (ui->action_9->isChecked()&& ui->checkMin->isChecked()){//если ручная настройка.чекед и мин.чекед
              mass_minX[gr_index].append(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()));
              mass_minY[gr_index].append(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
              graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
              graphMin->setName("Минимумы"); graphMin->setVisible(true);
              textListMin[gr_index].append(new QCPItemText(ui->widget));
              textListMin[gr_index].last()->setText("("+QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',2) //округление до 2-х знаков
                            +"; "+QString::number(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()),'f',2)+")");
              textListMin[gr_index].last()->position->setCoords(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x())-5, ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y())-2);
              textListMin[gr_index].last()->setVisible(true);
              if (trendMin[gr_index].count() > 0) on_action_17_triggered(); //перестраиваем МНК мин
              ui->widget->replot();
          }
      //добавляем максимумы x, y
          if (ui->action_9->isChecked() && ui->checkMax->isChecked()){
              mass_maxX[gr_index].append(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()));
              mass_maxY[gr_index].append(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()));
              graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
              graphMax->setName("Максимумы"); graphMax->setVisible(true);
              textListMax[gr_index].append(new QCPItemText(ui->widget));
              textListMax[gr_index].last()->setText("("+QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',2)
                                +"; "+QString::number(ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y()),'f',2)+")");
              textListMax[gr_index].last()->position->setCoords(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x())-5, ui->widget->yAxis->pixelToCoord(mouseEvent->pos().y())+2);
              textListMax[gr_index].last()->setVisible(true);
              if (trendMax[gr_index].count() > 0) on_action_17_triggered(); //перестраиваем МНК макс
              ui->widget->replot();
          }
    }
    if (mouseEvent->button() == Qt::RightButton){//удаление точек
        if (ui->action_9->isChecked()&& ui->checkMin->isChecked()){
            for(int i = 0; i < mass_minX[gr_index].count(); i ++){
                if(QString::compare(QString::number(mass_minX[gr_index][i],'f',0), QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',0))==0){
                    mass_minX[gr_index].removeAt(i);   mass_minY[gr_index].removeAt(i);
                    graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
                    if (textListMin[gr_index].count()>0){
                        textListMin[gr_index][i]->setVisible(false); textListMin[gr_index].removeAt(i);
                    }
                    if (trendMin[gr_index].count() > 0) on_action_17_triggered(); //перестраиваем МНК мин
                }
            }
        }
        if (ui->action_9->isChecked() && ui->checkMax->isChecked()){
            for(int i = 0; i < mass_maxX[gr_index].count(); i ++){
                if(QString::compare(QString::number(mass_maxX[gr_index][i],'f',0), QString::number(ui->widget->xAxis->pixelToCoord(mouseEvent->pos().x()),'f',0))==0){
                    mass_maxX[gr_index].removeAt(i);   mass_maxY[gr_index].removeAt(i);
                    graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
                    if (textListMax[gr_index].count()>0){
                        textListMax[gr_index][i]->setVisible(false);  textListMax[gr_index].removeAt(i);
                    }
                    if (trendMax[gr_index].count() > 0) on_action_17_triggered(); //перестраиваем МНК макс
                }
            }
        }
        ui->widget->replot();
      }
    }
}

void MainWindow::histogramMouseMoved(QMouseEvent *event) //отображение координат в статус-баре
{
    ui->statusBar->showMessage("x="+QString::number(ui->widget->xAxis->pixelToCoord(event->pos().x()),'f',2)//округление до 2-х знаков
                               +"; y="+QString::number(ui->widget->yAxis->pixelToCoord(event->pos().y()),'f',2));
}

double MainWindow::prdelfun(double x1,double x2,double y1,double y2) //вычисление производной по 2м точкам
{
    double dx,dy,dd;
    dx=x2-x1;
    dy=y2-y1;
    dd=dy/dx;
    return dd;
}

void MainWindow::on_action_7_triggered() //удаление экстремумов
{
    if (ui->listWidget->count() > 0){
        if (ui->checkMin->isChecked()){
            mass_minX[gr_index].clear(); mass_minY[gr_index].clear();
            graphMin->setVisible(false); graphMin->setName(" ");
            for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(false);}
            textListMin[gr_index].clear();
        }
        if (ui->checkMax->isChecked()){
            mass_maxY[gr_index].clear(); mass_maxX[gr_index].clear();
            graphMax->setVisible(false); graphMax->setName(" ");
            for (int i = 0; i < textListMax[gr_index].length(); i++) {textListMax[gr_index][i]->setVisible(false);}
            textListMax[gr_index].clear();}
        if (!ui->checkMin->isChecked() && !ui->checkMax->isChecked()){
            mass_minX[gr_index].clear(); mass_minY[gr_index].clear(); graphMin->setVisible(false); graphMin->setName(" ");
            mass_maxY[gr_index].clear(); mass_maxX[gr_index].clear(); graphMax->setVisible(false); graphMax->setName(" ");
            for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(false);}
            for (int i = 0; i < textListMax[gr_index].length(); i++) {textListMax[gr_index][i]->setVisible(false);}
            textListMin[gr_index].clear(); textListMax[gr_index].clear();
        }
        ui->widget->replot();
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_action_exit_triggered() //выход из программы
{
    QApplication::quit();
}

void MainWindow::on_action_12_triggered() //Сохранение графика
{
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

void MainWindow::on_doubleSpinBox1_valueChanged() //изменение спина экстремомов
{
    on_action_10_triggered();
}

void MainWindow::on_spinLevel_valueChanged() //спин мнк
{
   on_action_17_triggered();
}

void MainWindow::on_doubleSpinBox_x1_valueChanged() //изменение спина нач. значение
{
    on_action_13_triggered();
}

void MainWindow::on_doubleSpinBox_x2_valueChanged() //изменение спина конеч. значение
{
    on_action_13_triggered();
}

void MainWindow::on_actionD_triggered() //Расчет изменения дельты сигнала
{
    if (ui->listWidget->count() > 0){
        if (mass_minX[gr_index].count()!=0 && mass_maxX[gr_index].count()!=0 && mass_minY[gr_index].count()!=0 && mass_maxY[gr_index].count()!=0){
        //сортировка экстремумов по возрастанию, вдруг мы добавили в конец списка Qlist новый экстремум, который идет не по порядку
            qSort(mass_minX[gr_index].begin(), mass_minX[gr_index].end(), qLess<double>());
            qSort(mass_maxX[gr_index].begin(), mass_maxX[gr_index].end(), qLess<double>());
        //но игрикам не подходит сортирвка, поэтому лучше строить по порядку пока что
            deltaWin *DeltaW = new deltaWin(mass_minX[gr_index], mass_maxX[gr_index], mass_minY[gr_index], mass_maxY[gr_index], this);
            DeltaW->show();
            DeltaW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
        }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Экстремумы не определены!"));
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_action_21_triggered() //отрисовка графика производной
{
    if (ui->listWidget->count() > 0){
        on_action_13_triggered(); //вызов вычисления производной кучочно-непрерывной функции
        SomeWindow *DXWindow=new SomeWindow(dirivate, x1, x2, koef[gr_index], this);
        DXWindow->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - скорость изменения параметра");
        DXWindow->show();
        DXWindow->setAttribute(Qt::WA_DeleteOnClose); //деструктор
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_checkMin_clicked(){ui->checkMax->setChecked(false);}

void MainWindow::on_checkMax_clicked(){ui->checkMin->setChecked(false);}

void MainWindow::on_action_10_triggered() //Экстремумы
{
    if (ui->listWidget->count() > 0){
        gr_index = ui->listWidget->currentRow();
        mass_minX[gr_index].clear(); mass_maxX[gr_index].clear();
        mass_minY[gr_index].clear(); mass_maxY[gr_index].clear();//чтобы память не засорять
        bool up; //переменная отвечающая за возрастание
        if (mass_x_Gr[gr_index][1] > mass_x_Gr[gr_index][0]) up = true; //смотрим, возрастает ли график
            for(int i = 0; i < mass_x_Gr[gr_index].count()-1; i ++){
                if (up){ //если возрастает
                    if (mass_y_Gr[gr_index][i + 1] < mass_y_Gr[gr_index][i]){ //ждем когда она перестанет возрастать
                        if((mass_y_Gr[gr_index][i] - mass_y_Gr[gr_index][i + 1])>ui->doubleSpinBox1->value()){
                            mass_maxX[gr_index].append(mass_x_Gr[gr_index][i]);
                            mass_maxY[gr_index].append(mass_y_Gr[gr_index][i]);
                            up = false;
                        }
                    }
                }else{
                    if (mass_y_Gr[gr_index][i + 1] > mass_y_Gr[gr_index][i]){ //ждем когда она перестанет убывать
                        if((mass_y_Gr[gr_index][i+1] - mass_y_Gr[gr_index][i])>ui->doubleSpinBox1->value()){
                            mass_minX[gr_index].append(mass_x_Gr[gr_index][i]);
                            mass_minY[gr_index].append(mass_y_Gr[gr_index][i]);
                            up = true;
                        }
                    }
                }
            }
            graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
            graphMin->setName("Минимумы");
            graphMin->setVisible(true);
            graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
            graphMax->setName("Максимумы");
            graphMax->setVisible(true);
            ui->widget->replot();
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_action_13_triggered() //вызов вычисления производной кусочно-непрерывной функции
{
    if (ui->listWidget->count() > 0){
      double x1 = ui->doubleSpinBox_x1->value();
      double x2 = ui->doubleSpinBox_x2->value();
  //расчет производной по отметкам (начало конец по Х)
      double sred=0, znpozit=0;
      dirivate.clear();
      //обработка введеных значений если они за пределами возможных
      if (x1 < minx[gr_index] || x1 > maxx[gr_index]) x1 = minx[gr_index];
      if (x2 > maxx[gr_index] || x2 < minx[gr_index]) x2 = maxx[gr_index];
      //ищем ближайшее к введеному значение из массива данных
      int i=0;
      while (x1>mass_x_Gr[gr_index][i]) { i++;}
      x1=i;
      i=0;
      while (x2>mass_x_Gr[gr_index][i]) { i++;}
      x2=i;
      int j=x1;
        for (i=x1; i<x2; i++) {
              //qDebug() << ">mass_x="<<this->mass_x[i];
              //qDebug() << ">mass_y="<<this->mass_y[j];
              znpozit=prdelfun(mass_x_Gr[gr_index][i],mass_x_Gr[gr_index][i+1], mass_y_Gr[gr_index][j], mass_y_Gr[gr_index][j+1]);
              //qDebug() << "znpozit="<<znpozit;
              dirivate.append(znpozit);
  //            Derivative *derivative = new Derivative(x1,x2,y1,y2);
  //            Derivative *derivative = new Derivative(this->mass_x[i],this->mass_x[i+1],this->mass_y[j],this->mass_y[j+1]);
  //            ui->textBrowser_4->append(QString("%1").arg(derivative->get_dd()));
              sred=sred+znpozit;
              j++;
      }
        this->x1=x1; this->x2=x2;
      ui->Browser_Derivative->clear();
      ui->Browser_Derivative->append(QString("Производная:\ndx/dy = ")+QString::number(sred));
      //delete derivative();
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_action_17_triggered() //МНК
{
    if (ui->listWidget->count() > 0){
        double xLevel = 0, yLevel = 0;
        if (ui->checkMin->isChecked()){//Метод наименьших квадратов (МНК) минимума
            if (mass_minX[gr_index].count() != 0){
                trendMin[gr_index].clear();  yLevelMin[gr_index].clear(); xLevelMin[gr_index].clear();
                mnk *mnk1 = new mnk(mass_minX[gr_index], mass_minY[gr_index], mass_minX[gr_index].count());
                //QMessageBox::information(NULL,"Информация","Коэффициент детерминации = "+QString::number(Kdet));
                for(int i = 0; i < mass_minX[gr_index].count(); i++){
                    trendMin[gr_index].append(mnk1->get_yy(mass_minX[gr_index][i]));
                }
                yLevelMin[gr_index].append(trendMin[gr_index][0] + trendMin[gr_index][0]*(ui->spinLevel->value()/100));
                yLevelMin[gr_index].append(yLevelMin[gr_index][0]+yLevelMin[gr_index][0]*0.1);
                yLevelMin[gr_index].append(yLevelMin[gr_index][0]-yLevelMin[gr_index][0]*0.1);
                xLevelMin[gr_index].append((yLevelMin[gr_index][0]- mnk1->get_b()) / mnk1->get_a());
                xLevelMin[gr_index].append((yLevelMin[gr_index][0]- mnk1->get_b()) / mnk1->get_a());
                xLevelMin[gr_index].append((yLevelMin[gr_index][0]- mnk1->get_b()) / mnk1->get_a());
                ui->BrowserTime->clear();
                xLevel = (yLevelMin[gr_index][0] - mnk1->get_b()) / mnk1->get_a();
                yLevel = yLevelMin[gr_index][0];
                ui->BrowserTime->append(QString::number(xLevel));
                textListMNK[gr_index][0]->setText("("+QString::number(xLevel) + ")");
                textListMNK[gr_index][0]->position->setCoords(xLevel+5, yLevel-2);
                textListMNK[gr_index][0]->setVisible(true);
                graphMnkMin->setData(mass_minX[gr_index].toVector(), trendMin[gr_index].toVector());
                graphMnkMin->setVisible(true);
                mnkStrMin[gr_index] = QString::number(mnk1->get_a(),'f',2)+"*x+"+QString::number(mnk1->get_b(),'f',2)+" R^2="+QString::number(mnk1->get_Kdet(),'f',2);
                graphMnkMin->setName(mnkStrMin[gr_index]);
                graphLevelMin->setData(xLevelMin[gr_index].toVector(), yLevelMin[gr_index].toVector());
                graphLevelMin->setName("Линия перегиба min");
                graphLevelMin->setVisible(true);
                ui->widget->replot();
                delete mnk1; //деструктор
            }else{QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Точки минимума не определены!"));}
        }
        if (ui->checkMax->isChecked()){//Метод наименьших квадратов (МНК)максимума
            if (mass_maxX[gr_index].count() != 0){
                trendMax[gr_index].clear(); yLevelMax[gr_index].clear(); xLevelMax[gr_index].clear();
                mnk *mnk2 = new mnk(mass_maxX[gr_index], mass_maxY[gr_index], mass_maxX[gr_index].count());
                //QMessageBox::information(NULL,"Информация","Коэффициент детерминации = "+QString::number(Kdet));
                for(int i = 0; i < mass_maxX[gr_index].count(); i++){
                    trendMax[gr_index].append(mnk2->get_yy(mass_maxX[gr_index][i]));
                }
                yLevelMax[gr_index].append(trendMax[gr_index][0] + trendMax[gr_index][0]*(ui->spinLevel->value()/100));
                yLevelMax[gr_index].append(yLevelMax[gr_index][0]+yLevelMax[gr_index][0]*0.1);
                yLevelMax[gr_index].append(yLevelMax[gr_index][0]-yLevelMax[gr_index][0]*0.1);
                xLevelMax[gr_index].append((yLevelMax[gr_index][0]-mnk2->get_b()) / mnk2->get_a());
                xLevelMax[gr_index].append((yLevelMax[gr_index][0]-mnk2->get_b()) / mnk2->get_a());
                xLevelMax[gr_index].append((yLevelMax[gr_index][0]-mnk2->get_b()) / mnk2->get_a());
                ui->BrowserTime->clear();
                xLevel = (yLevelMax[gr_index][0] - mnk2->get_b()) / mnk2->get_a();
                yLevel = yLevelMax[gr_index][0];
                ui->BrowserTime->append(QString::number(xLevel));
                textListMNK[gr_index][1]->setText("("+QString::number(xLevel) + ")");
                textListMNK[gr_index][1]->position->setCoords(xLevel+5, yLevel-2);
                textListMNK[gr_index][1]->setVisible(true);
                graphMnkMax->setData(mass_maxX[gr_index].toVector(), trendMax[gr_index].toVector());
                graphMnkMax->setVisible(true);
                mnkStrMax[gr_index] = QString::number(mnk2->get_a(),'f',2)+"*x+"+QString::number(mnk2->get_b(),'f',2)+" R^2="+QString::number(mnk2->get_Kdet(),'f',2);
                graphMnkMax->setName(mnkStrMax[gr_index]);
                graphLevelMax->setData(xLevelMax[gr_index].toVector(), yLevelMax[gr_index].toVector());
                graphLevelMax->setName("Линия перегиба max");
                graphLevelMax->setVisible(true);
                ui->widget->replot();
                delete mnk2; //деструктор
            }else{QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Точки максимума не определены!"));}
        }
        if (!ui->checkMin->isChecked() && !ui->checkMax->isChecked()) QMessageBox::information(NULL,"Внимание", "Пожалуйста, выберите минимум или максимум.");
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_action_19_triggered() //удаление МНК
{
    if (ui->listWidget->count() > 0){
        if (ui->checkMin->isChecked()){ trendMin[gr_index].clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" ");
        graphLevelMin->setVisible(false); graphLevelMin->setName(" ");   textListMNK[gr_index][0]->setVisible(false);}
        if (ui->checkMax->isChecked()){ trendMax[gr_index].clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" ");
        graphLevelMax->setVisible(false); graphLevelMax->setName(" ");   textListMNK[gr_index][1]->setVisible(false);}
        if (!ui->checkMin->isChecked() && !ui->checkMax->isChecked()){
        trendMin[gr_index].clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" ");
        graphLevelMin->setVisible(false);  graphLevelMin->setName(" ");
        trendMax[gr_index].clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" ");
        graphLevelMax->setVisible(false); graphLevelMax->setName(" ");
        textListMNK[gr_index][0]->setVisible(false);  textListMNK[gr_index][1]->setVisible(false);
    }
        ui->widget->replot();
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::FalseVisibleAllGraph() //скрытие графов
{   //если для текущего графика есть какие то графы, то показываем их
    if (mass_minX[gr_index].count() > 0){//если у графика есть граф min, то показываем его
        graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
        graphMin->setName("Минимумы");        graphMin->setVisible(true);
    } else {graphMin->setName(" ");        graphMin->setVisible(false);}
    if (mass_maxX[gr_index].count() > 0){
        graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
        graphMax->setName("Максимумы");        graphMax->setVisible(true);
    }else {graphMax->setName(" ");        graphMax->setVisible(false);}

    if (trendMin[gr_index].count() > 0){
        graphMnkMin->setData(mass_minX[gr_index].toVector(), trendMin[gr_index].toVector());
        graphMnkMin->setVisible(true);
        graphMnkMin->setName(mnkStrMin[gr_index]);
        graphLevelMin->setData(xLevelMin[gr_index].toVector(), yLevelMin[gr_index].toVector());
        graphLevelMin->setName("Линия перегиба min");
        graphLevelMin->setVisible(true);
    }else {graphMnkMin->setVisible(false); graphMnkMin->setName(" "); graphLevelMin->setVisible(false); graphLevelMin->setName(" ");}
    if (trendMax[gr_index].count() > 0){
        graphMnkMax->setData(mass_maxX[gr_index].toVector(), trendMax[gr_index].toVector());
        graphMnkMax->setVisible(true);
        graphMnkMax->setName(mnkStrMax[gr_index]);
        graphLevelMax->setData(xLevelMax[gr_index].toVector(), yLevelMax[gr_index].toVector());
        graphLevelMax->setName("Линия перегиба max");
        graphLevelMax->setVisible(true);
    }else {graphMnkMax->setVisible(false); graphMnkMax->setName(" "); graphLevelMax->setVisible(false); graphLevelMax->setName(" ");}

    for (int j = 0; j < ui->listWidget->count(); j++) {
        if (gr_index == j){ //пройдемся по всем графикам и либо установим видимость, либо снимен его координаты, если не на текущем находимся
            for (int i = 0; i < textListMin[j].length(); i++) textListMin[j][i]->setVisible(true);
            for (int i = 0; i < textListMax[j].length(); i++) textListMax[j][i]->setVisible(true);
            textListMNK[j][0]->setVisible(true);  textListMNK[j][1]->setVisible(true);
        }else{
            for (int i = 0; i < textListMin[j].length(); i++) textListMin[j][i]->setVisible(false);
            for (int i = 0; i < textListMax[j].length(); i++) textListMax[j][i]->setVisible(false);
            textListMNK[j][0]->setVisible(false);  textListMNK[j][1]->setVisible(false);
        }
    }
    ui->widget->replot();
}

void MainWindow::on_action_16_triggered() //очистка всех графов из памяти и в интерфейсе текущего графика
{
    if (ui->listWidget->count() > 0) {
        mass_minX[gr_index].clear(); mass_maxX[gr_index].clear(); mass_minY[gr_index].clear(); mass_maxY[gr_index].clear();
        graphMin->setVisible(false); graphMax->setVisible(false); graphMin->setName(" ");graphMax->setName(" ");
        trendMin[gr_index].clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" "); graphLevelMin->setVisible(false); graphLevelMin->setName(" ");
        trendMax[gr_index].clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" "); graphLevelMax->setVisible(false); graphLevelMax->setName(" ");
        for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(false);}
        for (int i = 0; i < textListMax[gr_index].length(); i++) {textListMax[gr_index][i]->setVisible(false);}
        textListMNK[gr_index][0]->setVisible(false);  textListMNK[gr_index][1]->setVisible(false);
        textListMNK[gr_index][0]->setText("");  textListMNK[gr_index][1]->setText("");
        textListMin[gr_index].clear(); textListMax[gr_index].clear();
        ui->widget->replot();
        }else{
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Отсутствуют графики!"));
    }
}

void MainWindow::on_listWidget_clicked() //для перехода по графику
{
    gr_index = ui->listWidget->currentRow();
    graphic1->setData(mass_x_Gr[gr_index].toVector(), mass_y_Gr[gr_index].toVector());
    graphic1->setVisible(true);
    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(minx[gr_index], maxx[gr_index]);// Для оси Ox
    ui->widget->yAxis->setRange(miny[gr_index], maxy[gr_index]);//Для оси Oy
    graphic1->setName(ui->listWidget->item(gr_index)->text());
    //ui->Browser_Derivative->clear();
    //ui->Browser_Derivative->append(QString("Производная:\ndx/dy = ")+QString::number(sred));
    ui->Browser_Max->clear(); ui->Browser_Min->clear();
    ui->Browser_Max->append("Мин. X:\n" + QString("%1").arg(maxx[gr_index]));
    ui->Browser_Min->append("Макс. X:\n" + QString("%1").arg(minx[gr_index]));
    FalseVisibleAllGraph();
}

void MainWindow::on_listWidget_doubleClicked() //для отображения координат графика
{
    ui->textBrowser_X->clear(); ui->textBrowser_Y->clear();
    if (timer.isActive() == true) {timer.stop(); t = 0;}
    gr_index = ui->listWidget->currentRow(); timer.start();
}

void MainWindow::on_action_5_triggered() //удаление выделеного графика
{
    if (ui->listWidget->count() > 0){
        if (timer.isActive() == true) {timer.stop(); t = 0;}
        on_action_16_triggered(); //сначала очистим всех графы из памяти и в интерфейсе текущего графика
        graphic1->setVisible(false); graphic1->setName(" ");
        mass_minX.removeAt(gr_index); mass_maxX.removeAt(gr_index);
        mass_minY.removeAt(gr_index); mass_maxY.removeAt(gr_index);
        minx.removeAt(gr_index); miny.removeAt(gr_index);
        maxx.removeAt(gr_index); maxy.removeAt(gr_index); koef.removeAt(gr_index);
        trendMin.removeAt(gr_index); trendMax.removeAt(gr_index);
        textListMin[gr_index].clear(); textListMax[gr_index].clear();
        textListMin.removeAt(gr_index); textListMax.removeAt(gr_index);
        textListMNK[gr_index].clear();  textListMNK.removeAt(gr_index);
        xLevelMin.removeAt(gr_index), yLevelMin.removeAt(gr_index),
        xLevelMax.removeAt(gr_index), yLevelMax.removeAt(gr_index);
        mass_x_Gr.removeAt(gr_index); mass_y_Gr.removeAt(gr_index);
        ui->widget->replot();
        ui->listWidget->takeItem(gr_index); //удаляем из списка строку
        gr_index = 0; //передвигаем указатель графиков в начало
        ui->textBrowser_X->clear(); ui->textBrowser_Y->clear();
        ui->Browser_Max->clear(); ui->Browser_Min->clear(); ui->BrowserTime->clear();
        ui->Browser_Max->append("Мин. X:");  ui->Browser_Min->append("Макс. X:");
        ui->Browser_Derivative->clear(); ui->Browser_Derivative->append(QString("Производная:"));
    }else{
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Отсутствуют графики!"));
    }

}

void MainWindow::on_action_manual_triggered() //запуск руководства пользователя
{
    QString path = qApp->applicationDirPath();
    QProcess::execute("hh.exe "+path+"/manual1.chm");
}

void MainWindow::on_action_about_triggered() //окно О программе
{
    about *WinAbout = new about(this);
    WinAbout->show();
    WinAbout->setAttribute(Qt::WA_DeleteOnClose); //деструктор
}
