#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "derivative.h"
#include <QDebug>
#include "grDerivative.h"
#include "deltaSignal.h"
#include "filterDFT.h"
#include "extrem_simple.h"
#include "correl_analysis.h"
#include "dispers_analysis.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    CtrlZ = new QShortcut(this);    CtrlZ->setKey(Qt::CTRL + Qt::Key_Z);
    connect(CtrlZ, SIGNAL(activated()), this, SLOT(on_undo()));
    CtrlY = new QShortcut(this);    CtrlY->setKey(Qt::CTRL + Qt::Key_Y);
    connect(CtrlY, SIGNAL(activated()), this, SLOT(on_redo()));

    connect(ui->widget,SIGNAL(mousePress(QMouseEvent*)),this,SLOT(mousePress(QMouseEvent*)));
    connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(histogramMouseMoved(QMouseEvent*)));
    connect(ui->widget, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(spanMouseUp(QMouseEvent*)));
    connect(&timer, SIGNAL(timeout()), SLOT(TimerTick()));

    t = 0; gr_index = 0; mouseDown = false; left = false; x1 = 0; x2 = 0;
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));

    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    graphMin = ui->widget->addGraph(); //Добавление минимумов
    graphMin->setPen(QColor(67, 138, 0, 255));//задаем зеленый цвет
    graphMin->setLineStyle(QCPGraph::lsNone);//убираем линии
    graphMin->setName(" ");   graphMin->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    graphMax = ui->widget->addGraph(); //Добавление максимумов
    graphMax->setPen(QColor(255, 0, 0, 255));//задаем красный цвет точки
    graphMax->setLineStyle(QCPGraph::lsNone);
    graphMax->setName(" ");    graphMax->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));

    graphMnkMin = ui->widget->addGraph(); //Добавление МНК мин
    graphMnkMin->setPen(QColor(67, 138, 0, 255));//задаем зеленый цвет
    graphMnkMin->setName(" ");    graphMnkMin->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    graphLevelMin = ui->widget->addGraph(); //Добавление линии перегиба мин
    graphLevelMin->setPen(QColor(32, 154, 230, 255));//задаем синий цвет
    graphLevelMin->setName(" ");   graphLevelMin->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    graphMnkMax = ui->widget->addGraph(); //Добавление МНК максимумов
    graphMnkMax->setPen(QColor(255, 0, 0, 255));
    graphMnkMax->setName(" ");   graphMnkMax->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    graphLevelMax = ui->widget->addGraph(); //Добавление линии перегиба max
    graphLevelMax->setPen(QColor(2, 15, 250, 255));//задаем темно-синий цвет
    graphLevelMax->setName(" ");    graphLevelMax->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    graphic1 = ui->widget->addGraph();	//Добавление графика 1
    graphic1->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    //формируем вид точек
    //graphic1->setLineStyle(QCPGraph::lsNone);//убираем линии
    graphic1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    QPen Pen1, Pen2;
    Pen1.setWidthF(2); Pen1.setColor(QColor(255, 0, 0, 255)); //серый цвет с непрозрачностью 200 и толщиной 2
    rectSpan = new QCPItemRect(ui->widget);//Добавление диапазона значений
    rectSpan->setPen(Pen1); rectSpan->setVisible(false);

    rectPoint = new QCPItemRect(ui->widget);//диапазон для удаления экстремумов
    Pen2.setStyle(Qt::DashLine); rectPoint->setPen(Pen2); rectPoint->setVisible(false);
    //ui->widget->plotLayout()->addElement(0, 1, xRect);

    sliderStyleOn = ".QSlider::groove:horizontal {height: 24px; background: #87CEEB; border-radius: 8px; padding:-4px 7px;}"
                    ".QSlider::handle:horizontal {background: #1E90FF; width: 22px; margin: 0px -7px; border-radius: 11px;}";
    sliderStyleOff = ".QSlider::groove:horizontal {height: 24px; background:#696969; border-radius: 8px; padding:-4px 7px;}"
                     ".QSlider::handle:horizontal {background: #d5d5d5; width: 22px; margin: 0px -7px; border-radius: 11px;}";
}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::on_btn_openFile_clicked() //выбор файла и заполнение массива данных
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
            pathFile.append(file.fileName());
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
        file.close(); ui->SliderLegend->setValue(1);
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
        ui->BrowserTime->clear();
        ui->Browser_Min->setText("Мин. X:\n" + QString("%1").arg(minx[gr_index]));
        ui->Browser_Max->setText("Макс. X:\n" + QString("%1").arg(maxx[gr_index]));
        graphic1->setName("График "+QString::number(gr_index+1));
        //настройка легенды
        ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignTop);//устанавливаем легенду в правый верхний угол
        ui->widget->legend->setVisible(true);
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
        //StWork1.append(QList <double>());  StWork2.append(QList <double>());
        speedReaction.append(QList <double>()); speedRecovery.append(QList <double>());
        axis_x_Gr.append("x");   axis_y_Gr.append("y");
        ui->listWidget->setCurrentRow(gr_index); //устанавливаем выделение последнему загруженному графику
        on_listWidget_clicked();//очищаем все графы предыдущего графика
        x2 = mass_x_Gr[gr_index].count()-1;
        ui->tabWidget->setCurrentIndex(1);
    }else {delete it; delete progBar;  /*delete btn;*/  delete l; delete wgt;}
}

void MainWindow::on_btn_exit_clicked(){ QApplication::quit(); } //выход из программы

void MainWindow::on_btn_saveImage_clicked() //Сохранение изображения графика
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

void MainWindow::on_btn_saveDataGr_clicked() //сохранение данных графика в файл
{
    if (ui->listWidget->count() > 0){
        QString nameGr = ui->listWidget->item(gr_index)->text() + "_new";
        QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение преобразованного сигнала"),
                      nameGr, "Файл txt (*.txt)");
        QFile fileOut(fileName);
            if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
                QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
                for(int i = x1; i <= x2; i++){
                    writeStream << mass_x_Gr[gr_index][i] << "\t" << expY[i] << "\n";
                }
                fileOut.close();
            }
     }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Для начала, необходимо загрузить данные."));
}

void MainWindow::TimerTick(){ //процедура таймера для добавления в список textBrowser
    if (t < mass_x_Gr[gr_index].length()){
        //а здесь получаем значения по индексу выделенного графика
        ui->textBrowser_X->append(QString("%1").arg(mass_x_Gr[gr_index][t]));
        ui->textBrowser_Y->append(QString("%1").arg(mass_y_Gr[gr_index][t]));
        t++;
    }else {timer.stop(); t = 0;} //в конце останавливаем таймер
}

void MainWindow::on_listWidget_doubleClicked() //для отображения координат графика
{
    ui->textBrowser_X->clear(); ui->textBrowser_Y->clear();
    if (timer.isActive() == true) {timer.stop(); t = 0;}
    gr_index = ui->listWidget->currentRow(); timer.start();
}

void MainWindow::on_listWidget_clicked() //для перехода по графику
{
    gr_index = ui->listWidget->currentRow();
    setWindowTitle(pathFile[gr_index]);
    graphic1->setData(mass_x_Gr[gr_index].toVector(), mass_y_Gr[gr_index].toVector());
    graphic1->setVisible(true);//показать, если до этого удаляли график
    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(minx[gr_index], maxx[gr_index]);// Для оси Ox
    ui->widget->yAxis->setRange(miny[gr_index], maxy[gr_index]);//Для оси Oy
    graphic1->setName(ui->listWidget->item(gr_index)->text()); //установка названия графика для легенды
    ui->Browser_Min->setText("Мин. X:\n" + QString("%1").arg(minx[gr_index]));
    ui->Browser_Max->setText("Макс. X:\n" + QString("%1").arg(maxx[gr_index]));
    ui->Browser_stWork->clear(); ui->Browser_stWork->append("Фазы начала рабочего режима:");
    //for(int i = 0; i < StWork1[gr_index].count(); i++){
    //    ui->Browser_stWork->append(QString::number(i+1)+" - ("+QString::number(StWork1[gr_index][i])+"; "+QString::number(StWork2[gr_index][i])+")");}
    for(int i = 0; i < mass_minX[gr_index].count(); i++){
        if (i==mass_minX[gr_index].count()-1) ui->Browser_stWork->append("Точка завершения:\n"+QString::number(i+1)+" - ("+QString::number(mass_minX[gr_index][i])+"; "+QString::number(mass_minY[gr_index][i])+")");
        else ui->Browser_stWork->append(QString::number(i+1)+" - ("+QString::number(mass_minX[gr_index][i])+"; "+QString::number(mass_minY[gr_index][i])+")");
    }
    ui->Spin_x1->setValue(0.0); ui->Spin_x2->setValue(0.0);
    ui->list_SpeedReact->clear(); ui->list_SpeedRecov->clear();
    for (int i = 0; i < speedReaction[gr_index].count(); i++)  ui->list_SpeedReact->addItem(QString::number(i+1)+ ") " + QString::number(speedReaction[gr_index][i]));
    for (int i = 0; i < speedRecovery[gr_index].count(); i++)  ui->list_SpeedRecov->addItem(QString::number(i+1)+ ") " + QString::number(speedRecovery[gr_index][i]));
    rectSpan->setVisible(false);
    ui->SliderSpan->setValue(0);
    ui->widget->xAxis->setLabel(axis_x_Gr[gr_index]);    ui->widget->yAxis->setLabel(axis_y_Gr[gr_index]);
    FalseVisibleAllGraph();
    x2 = mass_x_Gr[gr_index].count()-1;
    expY = mass_y_Gr[gr_index];
    ui->spinGolay->setMaximum(mass_x_Gr[gr_index].count()); //для сглаживания Савицкого-Голея определим пределы (r) скользящего окна
    ui->SpinTimeExp->setMaximum(mass_x_Gr[gr_index].last()); //продолжительность опыта не больше значений иксов
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
        if ((gr_index == j) && (ui->SliderPointGr->value() == 1)){ //пройдемся по всем графикам и установим видимость координаты текущ графика, если вкл. слайдер
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

void MainWindow::mousePress(QMouseEvent *event) //ручная установка/удаление экстремумов
{
    if (ui->listWidget->count() > 0){
        double currentX = ui->widget->xAxis->pixelToCoord(event->pos().x());
        double currentY = ui->widget->yAxis->pixelToCoord(event->pos().y());
        if (event->button() == Qt::LeftButton){
            if (currentX>mass_x_Gr[gr_index].last()) x2 = mass_x_Gr[gr_index].count()-1;//если текущ. X находится за пределом справа, то X2=последней
            else indexSearch(mass_x_Gr[gr_index][0], currentX);//ищем близкую точку к курсору мыши слева
            if (ui->manualExtrem->isChecked()&& ui->rbMin->isChecked()){//если ручная настройка.чекед и мин.чекед
                int i=0;
                for(i = 0; i < mass_minX[gr_index].count(); i++){
                    if (mass_minX[gr_index][i]>mass_x_Gr[gr_index][x2]) break; //необходимо для вставки минимума в нужное место списка
                }
                mass_minX[gr_index].insert(i, mass_x_Gr[gr_index][x2]);     mass_minY[gr_index].insert(i, mass_y_Gr[gr_index][x2]);
                graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
                graphMin->setName("Минимумы"); graphMin->setVisible(true);
                textListMin[gr_index].insert(i, new QCPItemText(ui->widget));//округление до 2-х знаков ниже
                textListMin[gr_index][i]->setText("("+QString::number(mass_x_Gr[gr_index][x2],'f',2)+"; "+QString::number(mass_y_Gr[gr_index][x2],'f',2)+")");
                textListMin[gr_index][i]->position->setCoords(mass_x_Gr[gr_index][x2], mass_y_Gr[gr_index][x2]);
                textListMin[gr_index][i]->setVisible(false);
                if (trendMin[gr_index].count() > 0) on_btn_BuildMnk_clicked(); //перестраиваем МНК мин
                ui->widget->replot();
                ui->btn_saveExtrem->setEnabled(true);
            }
            //добавляем максимумы x, y
            if (ui->manualExtrem->isChecked() && ui->rbMax->isChecked()){
                int i=0;
                for(i = 0; i < mass_maxX[gr_index].count(); i++){
                    if (mass_maxX[gr_index][i]>mass_x_Gr[gr_index][x2]) break;
                }
                mass_maxX[gr_index].insert(i, mass_x_Gr[gr_index][x2]);    mass_maxY[gr_index].insert(i, mass_y_Gr[gr_index][x2]);
                graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
                graphMax->setName("Максимумы"); graphMax->setVisible(true);
                textListMax[gr_index].insert(i, new QCPItemText(ui->widget));
                textListMax[gr_index][i]->setText("("+QString::number(mass_x_Gr[gr_index][x2],'f',2)+"; "+QString::number(mass_y_Gr[gr_index][x2],'f',2)+")");
                textListMax[gr_index][i]->position->setCoords(mass_x_Gr[gr_index][x2], mass_y_Gr[gr_index][x2]);
                textListMax[gr_index][i]->setVisible(false);
                if (trendMax[gr_index].count() > 0) on_btn_BuildMnk_clicked(); //перестраиваем МНК макс
                ui->widget->replot();
                ui->btn_saveExtrem->setEnabled(true);
            }
        }
        if (event->button() == Qt::RightButton){
            if (ui->manualExtrem->isChecked()){//удаление точек
                mouseDown = true;
                rectPoint->topLeft->setCoords(currentX, currentY);
                rectPoint->bottomRight->setCoords(currentX, currentY);
                rectPoint->setVisible(true);
            }
            if (!ui->manualExtrem->isChecked()){//для установки диапазона значений
                if ((currentX < minx[gr_index]) || (currentX > maxx[gr_index])){
                    rectSpan->setVisible(false); ui->widget->replot();
                    ui->Spin_x1->setValue(0.0);
                    ui->Spin_x2->setValue(0.0);
                    x1 = 0;  x2 = mass_x_Gr[gr_index].count()-1;
                    rectSpan->topLeft->setCoords(minx[gr_index], maxy[gr_index]);
                    mouseDown = true;
                }else{ //В пределах границ графика
                    ui->Spin_x1->setValue(currentX);
                    rectSpan->topLeft->setCoords(ui->Spin_x1->value(), maxy[gr_index]);
                    rectSpan->bottomRight->setCoords(ui->Spin_x1->value(), miny[gr_index]);
                    mouseDown = true;
                }
            }
            ui->widget->replot();

        }
    }
}

void MainWindow::histogramMouseMoved(QMouseEvent *event) //координаты в статус-баре и границы интервала
{
    double currentX = ui->widget->xAxis->pixelToCoord(event->pos().x());
    double currentY = ui->widget->yAxis->pixelToCoord(event->pos().y());
    if (mouseDown){
        if (!ui->manualExtrem->isChecked()){
            if (currentX < minx[gr_index]){//перед графиком
                ui->Spin_x1->setValue(minx[gr_index]);
                rectSpan->setVisible(false); ui->widget->replot();
            }else if (currentX > maxx[gr_index]){//после графика
                ui->Spin_x2->setValue(maxx[gr_index]);
                rectSpan->bottomRight->setCoords(ui->Spin_x2->value(), miny[gr_index]);
                rectSpan->setVisible(true);
                ui->widget->replot();
            }
            else{//иначе координаты мыши были в пределах границы графика
                if (currentX >= ui->Spin_x1->value() && !left){//идем вправо
                    ui->Spin_x2->setValue(currentX);
                    left = false;
                    rectSpan->bottomRight->setCoords(currentX, miny[gr_index]);
                }else{//проверяем если идем влево
                    if (!left){ //left нужен, чтобы повторно не заходить сюда
                        ui->Spin_x2->setValue(ui->Spin_x1->value());//x2 теперь становится начальным значением
                        left = true;
                    }
                    ui->Spin_x1->setValue(currentX);
                    rectSpan->bottomRight->setCoords(currentX, miny[gr_index]);
                    if (currentX >= ui->Spin_x2->value() && left) left = false;
                }
                rectSpan->setVisible(true);
                ui->widget->replot();
            }
        }else   rectPoint->bottomRight->setCoords(currentX, currentY); ui->widget->replot();
    }
    ui->statusBar->showMessage("x="+QString::number(currentX,'f',3)+"; y="+QString::number(currentY,'f',3));//округление до 3-х знаков
}

void MainWindow::spanMouseUp(QMouseEvent *event)
{
    if (ui->listWidget->count() > 0){
        if (event->button() == Qt::RightButton){
            if (rectSpan->visible()) ui->SliderSpan->setValue(1);
            else ui->SliderSpan->setValue(0);
            mouseDown = false;
            switch (ui->tabWidget->currentIndex()){
            case 2: //вкладка продолжительность раб. режима
                indexSearch(ui->Spin_x1->value(), ui->Spin_x2->value());
                if (ui->startWork1->isChecked()) ui->SpinTimeExp->setValue(x2-x1);
                else ui->SpinTimeExp->setValue(x2-((x2-x1)/2)); //x2 минус радиус
                break;
            case 3: //вкладка экстремумы
                if (ui->manualExtrem->isChecked()){//включена ручная настройка экстремумов: удаление
                    rectPoint->setVisible(false); ui->widget->replot();
                    if (ui->rbMin->isChecked()){
                        for(int i = 0; i < mass_minX[gr_index].count(); i++){
                            if(((mass_minX[gr_index][i] > rectPoint->topLeft->coords().x()) && (mass_minY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_minX[gr_index][i] < rectPoint->bottomRight->coords().x()) && (mass_minY[gr_index][i] > rectPoint->bottomRight->coords().y()))
                                || ((mass_minX[gr_index][i] < rectPoint->topLeft->coords().x()) && (mass_minY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_minX[gr_index][i] > rectPoint->bottomRight->coords().x()) && (mass_minY[gr_index][i] > rectPoint->bottomRight->coords().y()))){
                                if (textListMin[gr_index].count()>0){
                                    textListMin[gr_index][i]->setVisible(false); textListMin[gr_index].removeAt(i);
                                }
                                mass_minX[gr_index].removeAt(i);   mass_minY[gr_index].removeAt(i);
                                graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
                                i-=1;
                                if (trendMin[gr_index].count() > 0) on_btn_BuildMnk_clicked(); //перестраиваем МНК мин
                            }
                        }
                    }else if (ui->rbMax->isChecked()){
                        for(int i = 0; i < mass_maxX[gr_index].count(); i++){
                            if (((mass_maxX[gr_index][i] > rectPoint->topLeft->coords().x()) && (mass_maxY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_maxX[gr_index][i] < rectPoint->bottomRight->coords().x()) && (mass_maxY[gr_index][i] > rectPoint->bottomRight->coords().y()))
                                || ((mass_maxX[gr_index][i] < rectPoint->topLeft->coords().x()) && (mass_maxY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_maxX[gr_index][i] > rectPoint->bottomRight->coords().x()) && (mass_maxY[gr_index][i] > rectPoint->bottomRight->coords().y()))){
                                if (textListMax[gr_index].count()>0){
                                    textListMax[gr_index][i]->setVisible(false); textListMax[gr_index].removeAt(i);
                                }
                                mass_maxX[gr_index].removeAt(i);   mass_maxY[gr_index].removeAt(i);
                                graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
                                i-=1;
                                if (trendMax[gr_index].count() > 0) on_btn_BuildMnk_clicked(); //перестраиваем МНК макс
                            }
                        }
                    }else if (ui->rbAll->isChecked()){
                        for(int i = 0; i < mass_minX[gr_index].count(); i++){
                            if(((mass_minX[gr_index][i] > rectPoint->topLeft->coords().x()) && (mass_minY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_minX[gr_index][i] < rectPoint->bottomRight->coords().x()) && (mass_minY[gr_index][i] > rectPoint->bottomRight->coords().y()))
                                || ((mass_minX[gr_index][i] < rectPoint->topLeft->coords().x()) && (mass_minY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_minX[gr_index][i] > rectPoint->bottomRight->coords().x()) && (mass_minY[gr_index][i] > rectPoint->bottomRight->coords().y()))){
                                if (textListMin[gr_index].count()>0){
                                    textListMin[gr_index][i]->setVisible(false); textListMin[gr_index].removeAt(i);
                                }
                                mass_minX[gr_index].removeAt(i);   mass_minY[gr_index].removeAt(i);
                                graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
                                i-=1;
                                if (trendMin[gr_index].count() > 0) on_btn_BuildMnk_clicked(); //перестраиваем МНК мин
                            }
                        }
                        for(int i = 0; i < mass_maxX[gr_index].count(); i++){
                            if (((mass_maxX[gr_index][i] > rectPoint->topLeft->coords().x()) && (mass_maxY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_maxX[gr_index][i] < rectPoint->bottomRight->coords().x()) && (mass_maxY[gr_index][i] > rectPoint->bottomRight->coords().y()))
                                || ((mass_maxX[gr_index][i] < rectPoint->topLeft->coords().x()) && (mass_maxY[gr_index][i] < rectPoint->topLeft->coords().y()) && (mass_maxX[gr_index][i] > rectPoint->bottomRight->coords().x()) && (mass_maxY[gr_index][i] > rectPoint->bottomRight->coords().y()))){
                                if (textListMax[gr_index].count()>0){
                                    textListMax[gr_index][i]->setVisible(false); textListMax[gr_index].removeAt(i);
                                }
                                mass_maxX[gr_index].removeAt(i);   mass_maxY[gr_index].removeAt(i);
                                graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
                                i-=1;
                                if (trendMax[gr_index].count() > 0) on_btn_BuildMnk_clicked(); //перестраиваем МНК макс
                            }
                        }                      
                    }
                    if (textListMin[gr_index].count()==0 && (textListMax[gr_index].count()==0)) ui->SliderPointGr->setValue(0);
                    if (mass_minX[gr_index].count()==0) graphMin->setName(" ");
                    if (mass_maxX[gr_index].count()==0) graphMax->setName(" ");
                    if ((mass_minX[gr_index].count()<=0) && (mass_maxX[gr_index].count()<=0)) ui->btn_saveExtrem->setEnabled(false);
                    ui->widget->replot();
                }
                break;
            case 4: Derivat_triggered(0, mass_x_Gr[gr_index], mass_y_Gr[gr_index]); //вкладка скорость
                break;
            case 5: //вкладка сглаживание
                expYcopy = expY;
                QFile tempFile("tempUndo.bin");
                QDataStream stream(&tempFile);
                tempFile.open(QIODevice::WriteOnly);
                stream << expYcopy;
                tempFile.close();
                if (ui->checkExp->isChecked()){ //экспоненциальное сглаживание
                    for (int i = 1; i < mass_x_Gr[gr_index].count(); i++){
                        if ((mass_x_Gr[gr_index][i] < ui->Spin_x1->value()) || (mass_x_Gr[gr_index][i] > ui->Spin_x2->value())){
                            expY[i] = expYcopy[i];
                        }else if ((mass_x_Gr[gr_index][i] >= ui->Spin_x1->value()) && (mass_x_Gr[gr_index][i] <= ui->Spin_x2->value())){
                                expY[i] = expY[i-1] + ui->SpinExp->value() * (expYcopy[i] - expY[i-1]); //записываем сглаженное значение
                        }
                    }
                }
                if (ui->checkGolay->isChecked()){//сглаживание Савицкого-Голея
                    QList<int> h;
                    int r =  ui->spinGolay->value(), k = 0, s = 0; //с - кол-во выходов за пределы окна
                    double sum = 0;
                    if (ui->rectORtriangle->value()==0){
                        for (int g = -r; g <= r; g++)
                            if (g==0) h.append(2);
                            else h.append(1);
                    }else{
                        for (int g = 1; g <= r+1; g++)  h.append(g);
                        for (int g = r; g >= 1; g--)  h.append(g);
                    }
                    for (int i = 0; i < mass_x_Gr[gr_index].count(); i++){
                        if ((mass_x_Gr[gr_index][i] < ui->Spin_x1->value()) || (mass_x_Gr[gr_index][i] > ui->Spin_x2->value())){
                            expY[i] = expYcopy[i];
                            }else if ((mass_x_Gr[gr_index][i] >= ui->Spin_x1->value()) && (mass_x_Gr[gr_index][i] <= ui->Spin_x2->value())){
                                for (int j = i-r; j <= i+r; j++){ //для прохода по окну
                                //если окно выходит заграницы всего графика, т.к. не могу проверить границу житого элемента(из-за отрицательного значения)
                                if ((j < 0) || (j >= mass_x_Gr[gr_index].count())){
                                    k+=1;
                                }else if (( mass_x_Gr[gr_index][j] < ui->Spin_x1->value()) ||( mass_x_Gr[gr_index][j] > ui->Spin_x2->value())){//если окно выходит заграницы x1, x2, т.к. условие выше не подходит, но границы выяснить надо
                                    k+=1;
                                }else{
                                    sum += expYcopy[j]*h[k];
                                    s+=h[k];
                                    k+=1;
                                }
                                }
                            expY[i] = sum / s; //записываем сглаженное значение
                            sum = 0; k = 0; s = 0;
                            }
                    }
                }
                graphic1->setData(mass_x_Gr[gr_index].toVector(), expY.toVector());
                ui->widget->replot();
                break;
            }
        }
    }
}

void MainWindow::slotCustomMenuRequested(QPoint pos) //контекстное меню
{
    if (ui->listWidget->count() > 0){
        on_listWidget_clicked();
        QPoint gPos = ui->listWidget->mapToGlobal(pos);
        QMenu *qmenu = new QMenu(this);
        //создаем действия для контекстного меню
        QAction *rename = new QAction("Переименовать", this);
        QAction *reaxis = new QAction("Наименование осей", this);
        QAction *clearGr = new QAction("Очистить графы", this);
        QAction *delGr = new QAction("Удалить график", this);
        QAction *saveGr = new QAction("Сохранить график", this);
        QAction *delMinMax = new QAction("Удалить точки экстремумов", this);
        QAction *deltaS = new QAction("Δ сигнала", this);
        //подключаем СЛОТы обработчики для действий контекстного меню
        connect(rename, SIGNAL(triggered(bool)), this, SLOT(menuRename()));
        connect(reaxis, SIGNAL(triggered(bool)), this, SLOT(menuReaxis()));
        connect(clearGr, SIGNAL(triggered(bool)), this, SLOT(on_btn_clearGraph_clicked()));
        connect(delGr, SIGNAL(triggered(bool)), this, SLOT(on_btn_delGraph_clicked()));
        connect(saveGr, SIGNAL(triggered(bool)), this, SLOT(on_btn_saveImage_clicked()));
        connect(delMinMax, SIGNAL(triggered(bool)), this, SLOT(on_btn_delExtrem_clicked()));
        connect(deltaS, SIGNAL(triggered(bool)), this, SLOT(on_btn_delta_clicked()));
        //устанавливаем действия в меню
        qmenu->addAction(rename);        qmenu->addAction(reaxis);
        qmenu->addAction(clearGr);       qmenu->addAction(delGr);
        qmenu->addAction(saveGr);
        qmenu->addSeparator(); //добавляем разделитель
        qmenu->addAction(delMinMax);     qmenu->addSeparator();
        qmenu->addAction(deltaS);
        //вызываем контекстное меню
        if (ui->listWidget->itemAt(pos)) qmenu->exec(gPos);
        //qmenu->popup(ui->listWidget->viewport()->mapToGlobal(pos));
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
    QStringList qstr; qstr << lineEditRename->text(); delete lineEditRename;
    ui->listWidget->insertItems(gr_index, qstr);
    ui->listWidget->item(gr_index)->setTextAlignment(Qt::AlignCenter);
    ui->listWidget->setCurrentRow(gr_index);
    graphic1->setName(ui->listWidget->item(gr_index)->text());
    ui->widget->replot();
}

void MainWindow::menuReaxis() // окно для переименование осей графика
{
    QDialog *w = new QDialog(this); //this нужен, чтобы форма не плавала сама по себе и была уничтожена при закрытии главного окна программы
    w->setWindowTitle("Наименование осей графика");
    w->setMaximumHeight(100); w->setMaximumWidth(290);      w->setMinimumHeight(100); w->setMinimumWidth(290);
    w->setModal(true); //чтобы было модальным
    QString styleBut = "QPushButton {border: 2px solid #8f8f91; border-radius: 6px; background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
            "stop: 0 #f6f7fa, stop: 1 #dadbde); min-height: 18px; min-width: 80px;}"
            "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);}";
    QLineEdit *lineE1 = new QLineEdit(w);    lineE1->setText(ui->widget->xAxis->label());
    QLineEdit *lineE2 = new QLineEdit(w);    lineE2->setText(ui->widget->yAxis->label());
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttonBox->button(QDialogButtonBox::Ok)->setText("Сохранить");  buttonBox->button(QDialogButtonBox::Cancel)->setText("Закрыть");
    buttonBox->setStyleSheet(styleBut);
    connect(buttonBox, &QDialogButtonBox::accepted, w, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, w, &QDialog::reject);
    QLayout *Layout1 = new QVBoxLayout(); //вертикальное размещение для полей и кнопок
    Layout1->addWidget(lineE1);  Layout1->addWidget(lineE2);  Layout1->addWidget(buttonBox);
    //размещение на ценкральный виджет
    w->setLayout(Layout1);   w->show();
    w->setAttribute(Qt::WA_DeleteOnClose); //деструктор
    connect(w, &QDialog::finished, [=](int result){ //лямбда-выражение для кнопки Сохранить
        if (result){
            axis_x_Gr[gr_index] = lineE1->text(); axis_y_Gr[gr_index] = lineE2->text();
            ui->widget->xAxis->setLabel(axis_x_Gr[gr_index]);    ui->widget->yAxis->setLabel(axis_y_Gr[gr_index]);
            ui->widget->replot();
        }
    });
}

void MainWindow::on_btn_clearGraph_clicked() //очистить графы графика
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
        //StWork1[gr_index].clear(); StWork2[gr_index].clear();
        ui->Browser_stWork->setText("Фазы начала рабочего режима:");
        ui->widget->replot();
        }else{
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Отсутствуют графики!"));
    }
}

void MainWindow::on_btn_delGraph_clicked() //удаление выделеного графика
{
    if (ui->listWidget->count() > 0){
        if (timer.isActive() == true) {timer.stop(); t = 0;}
        if (ui->listWidget->count() == 1) ui->SliderLegend->setValue(0); //если остается последний график, то убираем легенду
        ui->SliderPointGr->setValue(0); ui->SliderSpan->setValue(0);
        on_btn_clearGraph_clicked(); //сначала очистим всех графы из памяти и в интерфейсе текущего графика
        graphic1->setVisible(false); graphic1->setName(" ");
        mass_minX.removeAt(gr_index); mass_maxX.removeAt(gr_index);
        mass_minY.removeAt(gr_index); mass_maxY.removeAt(gr_index);
        minx.removeAt(gr_index); miny.removeAt(gr_index);
        maxx.removeAt(gr_index); maxy.removeAt(gr_index); koef.removeAt(gr_index);
        speedReaction.removeAt(gr_index);  speedRecovery.removeAt(gr_index);
        trendMin.removeAt(gr_index); trendMax.removeAt(gr_index);
        textListMin[gr_index].clear(); textListMax[gr_index].clear();
        textListMin.removeAt(gr_index); textListMax.removeAt(gr_index);
        textListMNK[gr_index].clear();  textListMNK.removeAt(gr_index);
        xLevelMin.removeAt(gr_index), yLevelMin.removeAt(gr_index),
        xLevelMax.removeAt(gr_index), yLevelMax.removeAt(gr_index);
        mass_x_Gr.removeAt(gr_index); mass_y_Gr.removeAt(gr_index);
        //StWork1[gr_index].removeAt(gr_index); StWork2[gr_index].removeAt(gr_index);
        ui->widget->xAxis->setLabel("");   ui->widget->yAxis->setLabel("");//важно сделать до replot
        ui->widget->replot();
        ui->listWidget->takeItem(gr_index); //удаляем из списка строку
        axis_x_Gr.removeAt(gr_index); axis_y_Gr.removeAt(gr_index);
        pathFile.removeAt(gr_index);

        gr_index = 0; //передвигаем указатель графиков в начало
        setWindowTitle("Система мониторинга и обработки экспериментальных данных");
        ui->list_SpeedReact->clear(); ui->list_SpeedRecov->clear();
        ui->textBrowser_X->clear(); ui->textBrowser_Y->clear(); ui->BrowserTime->clear();
        ui->Browser_Max->setText("Мин. X:");  ui->Browser_Min->setText("Макс. X:");
        ui->Browser_Derivative->setText("Производная:");
        ui->Browser_stWork->setText("Фазы начала рабочего режима:");

    }else{
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Отсутствуют графики!"));
    }
}

void MainWindow::on_startWork1_clicked() //определение начала рабочего режима (1 метод)
{
    ui->startWork2->setChecked(false);
    if ((ui->listWidget->count() > 0) && (ui->tabWidget->currentIndex() == 2) && (ui->SpinTimeExp->value()!=0)){
        ui->Browser_stWork->clear(); ui->Browser_stWork->append("Фазы начала рабочего режима:");
        QList <double> tempX, tempY, mnkLine;
        mass_minX[gr_index].clear(); mass_minY[gr_index].clear();
        tempX.clear(); tempY.clear();
        tempX.append(mass_x_Gr[gr_index][0]);  tempY.append(mass_y_Gr[gr_index][0]);
        mass_minX[gr_index].append(0.0);  mass_minY[gr_index].append(0.0);
        int ind = 0;
        for(int i = 1; i < mass_x_Gr[gr_index].count(); i++){
            tempX.append(mass_x_Gr[gr_index][i]);  tempY.append(mass_y_Gr[gr_index][i]);
            mnk *mnk3 = new mnk(tempX, tempY, tempX.count());
            for(int j = 0; j < tempX.count(); j++){
                mnkLine.append(mnk3->get_yy(tempX[j]));
            }
            if (mnk3->get_Kdet() > ui->SpinLimit->value()){ // от 0.9 до 0.95, было 0.9
                mass_minX[gr_index][ind] = mass_x_Gr[gr_index][i-1];
                mass_minY[gr_index][ind] = mass_y_Gr[gr_index][i-1];
                //if (ind == 0) iWork = i-1; //запоминаем индекс только 1 первоой точки старта
            }else if (i % ui->SpinTimeExp->value() == 0){ //интервал, т.е. каждые 550 точек перестраиваемемся
                tempX.clear();    tempY.clear();
                mass_minX[gr_index].append(0.0);   mass_minY[gr_index].append(0.0);
                ind += 1;
            }
            delete mnk3; mnkLine.clear();
        }
        for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(false);}
        textListMin[gr_index].clear();
        for(int i = 0; i < mass_minX[gr_index].count(); i++){
            textListMin[gr_index].append(new QCPItemText(ui->widget));
            textListMin[gr_index][i]->setText("("+QString::number(mass_minX[gr_index][i],'f',2)+"; "+QString::number(mass_minY[gr_index][i],'f',2)+")");
            textListMin[gr_index][i]->position->setCoords(mass_minX[gr_index][i], mass_minY[gr_index][i]);
            textListMin[gr_index][i]->setVisible(false);
            if (i==mass_minX[gr_index].count()-1) ui->Browser_stWork->append("Точка завершения:\n"+QString::number(i+1)+" - ("+QString::number(mass_minX[gr_index][i])+"; "+QString::number(mass_minY[gr_index][i])+")");
            else ui->Browser_stWork->append(QString::number(i+1)+" - ("+QString::number(mass_minX[gr_index][i])+"; "+QString::number(mass_minY[gr_index][i])+")");
        }
        graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
        graphMin->setName("Минимумы"); graphMin->setVisible(true);
        ui->widget->replot();
        ui->btn_saveExtrem->setEnabled(true);
    }
}

void MainWindow::on_SpinLimit_valueChanged(double ){ on_startWork1_clicked(); } //изменение порог. знач. (R)  для старт режима (метод 1)

void MainWindow::on_startWork2_clicked() //начало раб. режима (2 метод)
{
    ui->startWork1->setChecked(false);
    if ((ui->listWidget->count() > 0) && (ui->tabWidget->currentIndex() == 2) && (ui->SpinTimeExp->value()!=0)){
        ui->Browser_stWork->clear(); ui->Browser_stWork->append("Фазы начала рабочего режима:");
        mass_minX[gr_index].clear(); mass_minY[gr_index].clear();
        int r = (x2-x1)/2, ind = 0, i = 0, k = 0;
        double minY = maxy[gr_index];
        while (i < mass_x_Gr[gr_index].count()){
            for(int j = i-r; j <= i+r; j++){
                if (j>=0 && j<mass_x_Gr[gr_index].count()){
                    if (mass_y_Gr[gr_index][j] < minY){
                        minY = mass_y_Gr[gr_index][j]; ind = j; // и индекс минимума запоминаем
                    }
                }
            }
            mass_minX[gr_index].append(mass_x_Gr[gr_index][ind]);//здесь его используем (индекс минимального)
            mass_minY[gr_index].append(minY);
            //если оно выйдет за пределы массива, то установим последний индекс в еонце цикла
            if ((i+ui->SpinTimeExp->value()) > mass_x_Gr[gr_index].count() && k==0){ i = mass_x_Gr[gr_index].count()-1; k = 1;}
            else i+=ui->SpinTimeExp->value();
            minY = maxy[gr_index];//минимум обновляетя макс, чтобы потом точно нашелся элемент меньше его
        }
        for (int i = 0; i < textListMin[gr_index].length(); i++) textListMin[gr_index][i]->setVisible(false);
        textListMin[gr_index].clear();
        for(int i = 0; i < mass_minX[gr_index].count(); i++){
            textListMin[gr_index].append(new QCPItemText(ui->widget));
            textListMin[gr_index][i]->setText("("+QString::number(mass_minX[gr_index][i],'f',2)+"; "+QString::number(mass_minY[gr_index][i],'f',2)+")");
            textListMin[gr_index][i]->position->setCoords(mass_minX[gr_index][i], mass_minY[gr_index][i]);
            textListMin[gr_index][i]->setVisible(false);
            if (i==mass_minX[gr_index].count()-1) ui->Browser_stWork->append("Точка завершения:\n"+QString::number(i+1)+" - ("+QString::number(mass_minX[gr_index][i])+"; "+QString::number(mass_minY[gr_index][i])+")");
            else ui->Browser_stWork->append(QString::number(i+1)+" - ("+QString::number(mass_minX[gr_index][i])+"; "+QString::number(mass_minY[gr_index][i])+")");
        }
        graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
        graphMin->setName("Минимумы"); graphMin->setVisible(true);
        ui->widget->replot();
        ui->btn_saveExtrem->setEnabled(true);
    }
}

void MainWindow::on_SpinTimeExp_valueChanged(int ){ //изменение времени эксперимента
    if (ui->startWork1->isChecked()) on_startWork1_clicked();
    else on_startWork2_clicked();
}

void MainWindow::on_doubleSpinBox1_valueChanged(double ){ autoSearchSimple(); } //изменение спина экстремомов

void MainWindow::autoSearchSimple() //Автопоиск экстремумов(простой)
{
    if (ui->listWidget->count() > 0){
        for (int i = 0; i < textListMin[gr_index].count(); i++) textListMin[gr_index][i]->setVisible(false);
        for (int i = 0; i < textListMax[gr_index].count(); i++) textListMax[gr_index][i]->setVisible(false);
        textListMin[gr_index].clear();        textListMax[gr_index].clear();
        extrem_simple *ex_s = new extrem_simple(mass_minX[gr_index], mass_maxX[gr_index],mass_minY[gr_index], mass_maxY[gr_index], mass_y_Gr[gr_index], mass_x_Gr[gr_index], x1, x2, ui->doubleSpinBox1->value(), (maxy[gr_index]-miny[gr_index])/mass_y_Gr.count());
        graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
        for(int i = 0; i < mass_minX[gr_index].count(); i++){
            textListMin[gr_index].append(new QCPItemText(ui->widget));
            textListMin[gr_index][i]->setText("("+QString::number(mass_minX[gr_index][i],'f',2)+"; "+QString::number(mass_minY[gr_index][i],'f',2)+")");
            textListMin[gr_index][i]->position->setCoords(mass_minX[gr_index][i], mass_minY[gr_index][i]);
            textListMin[gr_index][i]->setVisible(false);
        }
        graphMin->setName("Минимумы");  graphMin->setVisible(true);

        graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
        for(int i = 0; i < mass_maxX[gr_index].count(); i++){
            textListMax[gr_index].append(new QCPItemText(ui->widget));
            textListMax[gr_index][i]->setText("("+QString::number(mass_maxX[gr_index][i],'f',2)+"; "+QString::number(mass_maxY[gr_index][i],'f',2)+")");
            textListMax[gr_index][i]->position->setCoords(mass_maxX[gr_index][i], mass_maxY[gr_index][i]);
            textListMax[gr_index][i]->setVisible(false);
        }
        graphMax->setName("Максимумы"); graphMax->setVisible(true);
        ui->widget->replot(); delete ex_s;
        ui->btn_saveExtrem->setEnabled(true);
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_btn_autoSearch2_clicked() //2 способ экстремумов
{
    if (ui->listWidget->count() > 0){
        if (mass_minX[gr_index].count()>0){
            mass_maxX[gr_index].clear(); mass_maxY[gr_index].clear();
            int k = 0;
            double maxX = minx[gr_index], maxY = mass_y_Gr[gr_index][0];
            for(int i = 1; i < mass_minX[gr_index].count(); i++){//нужно между 0 и 1 мин найти макс, поэтому начинаем искать до 1 минимума
                for(int j = k; j < mass_x_Gr[gr_index].count(); j++){//j будет проходить по иксам, только не сначала, а от минимума
                    if (mass_x_Gr[gr_index][j] < mass_minX[gr_index][i]){ //если мы еще не встретили значение следующего минимума
                        if(mass_y_Gr[gr_index][j+1] > maxY){//а здесь уже сравнимаем на макс значение
                            maxX = mass_x_Gr[gr_index][j+1];
                            maxY = mass_y_Gr[gr_index][j+1];
                        }
                    }else {k = j; break; }//k пока стало на место мин, но потом будет проверка на [j+1]>maxY
                }
                mass_maxX[gr_index].append(maxX);     mass_maxY[gr_index].append(maxY);
                maxY = miny[gr_index];
            }
            for (int i = 0; i < textListMax[gr_index].count(); i++) textListMax[gr_index][i]->setVisible(false);
            textListMax[gr_index].clear();
            for(int i = 0; i < mass_maxX[gr_index].count(); i++){
                textListMax[gr_index].append(new QCPItemText(ui->widget));
                textListMax[gr_index][i]->setText("("+QString::number(mass_maxX[gr_index][i],'f',2)+"; "+QString::number(mass_maxY[gr_index][i],'f',2)+")");
                textListMax[gr_index][i]->position->setCoords(mass_maxX[gr_index][i], mass_maxY[gr_index][i]);
                textListMax[gr_index][i]->setVisible(false);
            }
            graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
            graphMax->setName("Максимумы"); graphMax->setVisible(true);
            ui->widget->replot();
            ui->btn_saveExtrem->setEnabled(true);
        }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Определите начало рабочего режима или точки минимумов."));
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_btn_delExtrem_clicked() //удаление экстремумов
{
    if (ui->listWidget->count() > 0){
        if (ui->rbMin->isChecked()){
            if (trendMin[gr_index].count()<=0){//если выбрали мин и линия тренда мин пуста, то можно очищать минимумы
                mass_minX[gr_index].clear(); mass_minY[gr_index].clear();
                graphMin->setVisible(false); graphMin->setName(" ");
                if (textListMin[gr_index].count()>0){
                    for (int i = 0; i < textListMin[gr_index].count(); i++) {textListMin[gr_index][i]->setVisible(false);}
                    textListMin[gr_index].clear();
                }
            }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Сначала удалите линию тренда минимумов."));
        }else if (ui->rbMax->isChecked()){
                if (trendMax[gr_index].count()<=0){
                    mass_maxY[gr_index].clear(); mass_maxX[gr_index].clear();
                    graphMax->setVisible(false); graphMax->setName(" ");
                    if (textListMax[gr_index].count()>0){
                        for (int i = 0; i < textListMax[gr_index].count(); i++) {textListMax[gr_index][i]->setVisible(false);}
                        textListMax[gr_index].clear();
                    }
                }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Сначала удалите линию тренда максимумов."));
        }else if (ui->rbAll->isChecked()){
            if (trendMin[gr_index].count()<=0){
                mass_minX[gr_index].clear(); mass_minY[gr_index].clear(); graphMin->setVisible(false); graphMin->setName(" ");
            }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Сначала удалите линию тренда минимумов."));
            if (trendMax[gr_index].count()<=0){
                mass_maxY[gr_index].clear(); mass_maxX[gr_index].clear(); graphMax->setVisible(false); graphMax->setName(" ");
            }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Сначала удалите линию тренда максимумов."));
            if (textListMin[gr_index].count()>0){
                for (int i = 0; i < textListMin[gr_index].length(); i++) textListMin[gr_index][i]->setVisible(false);
                textListMin[gr_index].clear();
            }
            if (textListMax[gr_index].count()>0){
                for (int i = 0; i < textListMax[gr_index].length(); i++) textListMax[gr_index][i]->setVisible(false);
                textListMax[gr_index].clear();
            }
        }
        ui->widget->replot();
        if ((mass_minX[gr_index].count()<=0) && (mass_maxX[gr_index].count()<=0)) ui->btn_saveExtrem->setEnabled(false);
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_btn_openExtrem_clicked() //открыть файл с экстремумами
{

    if ((ui->listWidget->count() > 0) && (trendMin[gr_index].count()<=0) && (trendMax[gr_index].count()<=0)){
        QString fileName = QFileDialog::getOpenFileName(0,
                            QString::fromUtf8("Открыть файл"),
                            QDir::currentPath(),
                            "(*.txt);;All files (*.*)");
        if (fileName.length() > 0){
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly)) {QMessageBox::information(0, "Заголовок сообщения об ошибке", file.errorString());}
            QTextStream in(&file);
            bool b = false;
            int i = 0, j = 0;
            ui->rbAll->setChecked(true);
            on_btn_delExtrem_clicked();
            while(!in.atEnd()) {
                QString line = in.readLine();
                QRegExp rx("(\\ |\\t)"); //RegEx for ' ' or '\t'
                line=line.replace(',','.');
                QStringList fields = line.split(rx);
                if (b){ //пропускаем 1 строку с подписью
                    if (fields[0]!="#") mass_minX[gr_index].append(fields[0].toDouble()); //добавляем данные по последниему индексу списка графиков listwidget
                    if (fields[1]!="#") mass_minY[gr_index].append(fields[1].toDouble());
                    if (fields[2]!="#") mass_maxX[gr_index].append(fields[2].toDouble());
                    if (fields[3]!="#") mass_maxY[gr_index].append(fields[3].toDouble());
                }
                b = true; i+=1; j+=1;
            }
            file.close();
            graphMin->setData(mass_minX[gr_index].toVector(), mass_minY[gr_index].toVector());
            graphMin->setName("Минимумы"); graphMin->setVisible(true);
            graphMax->setData(mass_maxX[gr_index].toVector(), mass_maxY[gr_index].toVector());
            graphMax->setName("Максимумы"); graphMax->setVisible(true);
            ui->widget->replot();
            ui->btn_saveExtrem->setEnabled(true);
        }
    }
}

void MainWindow::on_btn_saveExtrem_clicked() //сохранить файл с экстремумами
{
    QString nameGr = "Экстремумы - " + ui->listWidget->item(gr_index)->text() ;
    QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение значений экстремумов"),
        nameGr, "Файл txt (*.txt)");
    QFile fileOut(fileName);
    if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream writeStream(&fileOut);
        writeStream << "Min X" << "   " << "Min Y" << "   " << "Max X" << "   "<< "Max Y" << "\n";
        int i = 0, max = mass_minX[gr_index].count();
        if (mass_maxX[gr_index].count() > max) max = mass_maxX[gr_index].count();
        while (i < max){
            if (i < mass_minX[gr_index].count()) writeStream << mass_minX[gr_index][i] << "\t" << mass_minY[gr_index][i] << "\t";
            else writeStream << "#" << "\t" << "#" << "\t";
            if (i < mass_maxY[gr_index].count()) writeStream << mass_maxX[gr_index][i] << "\t" << mass_maxY[gr_index][i] << "\n";
            else writeStream << "#" << "\t" << "#" << "\n";
            i+=1;
        }
    }
    fileOut.close();
}

void MainWindow::on_btn_grDerivative_clicked() //отрисовка графика производной
{
    if (ui->listWidget->count() > 0){
        Derivat_triggered(0, mass_x_Gr[gr_index], mass_y_Gr[gr_index]); //вызов вычисления производной кучочно-непрерывной функции
        SomeWindow *DXWindow=new SomeWindow(derivate, x1, x2, koef[gr_index], this);
        DXWindow->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - скорость изменения параметра");
        DXWindow->show();
        DXWindow->setAttribute(Qt::WA_DeleteOnClose); //деструктор
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::indexSearch(double valX1, double valX2)//ищем индекс массива выделенного интервала
{
    //обработка введеных значений если они за пределами возможных
    if (valX1 < minx[gr_index] || valX1 > maxx[gr_index]) valX1 = minx[gr_index];
    if (valX2 > maxx[gr_index] || valX2 < minx[gr_index]) valX2 = maxx[gr_index];
    for (int i = 0; i < mass_x_Gr[gr_index].count(); i++){
        if (mass_x_Gr[gr_index][i] < valX1) x1 = i;
            else if (mass_x_Gr[gr_index][i] < valX2) x2 = i;
                else break;
    }
}

void MainWindow::speedSearch() //скорость реакции и восстановления
{
    if ((mass_minX[gr_index].count()>0) && (mass_maxX[gr_index].count()>0)){
        bool up = false;
        double sred = 0, znpozit = 0, valX1 = 0, valX2 = 0;
        int k = 0, h = 0;
        if (mass_maxX[gr_index][0] > mass_minX[gr_index][0]) up = true; //проверяем возрастает ли график
        speedReaction[gr_index].clear(); speedRecovery[gr_index].clear();
        Derivative *der = new Derivative();
        while((k <  mass_minX[gr_index].count()) && (h <  mass_maxX[gr_index].count())){ //k - отвечает за порядковый номер min, h - max
            if (up){ //находим скорость реакции
                valX1 = mass_minX[gr_index][k];//StWork1[gr_index][k];
                valX2 = mass_maxX[gr_index][h];
            }else{ //скорость восстановления
                valX1 = mass_maxX[gr_index][h];
                valX2 = mass_minX[gr_index][k];//StWork1[gr_index][k+1];
            }
            indexSearch(valX1, valX2); //ищем индекс диапазона
            for (int i = x1; i <= x2; i++) {
                znpozit = der->get_dd(mass_x_Gr[gr_index][i],mass_x_Gr[gr_index][i+1], mass_y_Gr[gr_index][i], mass_y_Gr[gr_index][i+1]);
                sred += znpozit;//находим скорость
            }
            if (up) { speedReaction[gr_index].append(abs(sred)); k+=1; up = false; } //записываем и меняем на восстановление  и сдвигаем поряд. номер min
            else{ speedRecovery[gr_index].append(abs(sred)); h+=1; up = true; } //записываем и меняем на реакцию и сдвигаем поряд. номер max
            sred = 0; znpozit = 0;
        }
        delete der;
    }
}

void MainWindow::Derivat_triggered(int d, QList<double> &x, QList<double> &y) //вызов вычисления производной кусочно-непрерывной функции
{
    if ((ui->listWidget->count() > 0) && (ui->Spin_x2->value()>ui->Spin_x1->value()) && (ui->tabWidget->currentIndex() == 4)){
        double sred = 0, znpozit = 0;
        indexSearch(ui->Spin_x1->value(), ui->Spin_x2->value()); //ищем индекс диапазона
        Derivative *der = new Derivative();
        if (d==0){//1-я производная
            derivate.clear();
            for (int i = x1; i <= x2; i++) {
                znpozit = der->get_dd(x[i], x[i+1], y[i], y[i+1]);
                derivate.append(znpozit); //этот список нужен для отрисовки графика производной
                sred += znpozit;
            }
            ui->Browser_Derivative->setText("Производная:\ndx/dy = "+QString::number(abs(sred)));
        }else{//2-я производная

        }
    delete der;
    }
}

void MainWindow::on_btn_calcSpeed_clicked() //кнопка Вычислить скорость реакции и восстановления
{
    if (ui->listWidget->count() > 0){
        ui->list_SpeedReact->clear(); ui->list_SpeedRecov->clear();
        if ((mass_minX[gr_index].count()>0) && (mass_maxX[gr_index].count()>0)){
            if (check_extrem()){
                speedSearch();
                for (int i = 0; i < speedReaction[gr_index].count(); i++)  ui->list_SpeedReact->addItem(QString::number(i+1)+ ") " + QString::number(speedReaction[gr_index][i]));
                for (int i = 0; i < speedRecovery[gr_index].count(); i++)  ui->list_SpeedRecov->addItem(QString::number(i+1)+ ") " + QString::number(speedRecovery[gr_index][i]));
                ui->btn_saveSpeed->setEnabled(true);
            }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Экстремумы идут не по порядку. Значит и расчеты будут не правильные. Исправьте, пожалуйста."));
        }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Экстремумы не определены!"));
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Список графиков пуст!"));
}

void MainWindow::on_btn_openSpeed_clicked() //кнопка Открыть файл со скоростьюи размахом
{
    if (ui->listWidget->count() > 0){
        QString fileName = QFileDialog::getOpenFileName(0,
                            QString::fromUtf8("Открыть файл"),
                            QDir::currentPath(),
                            "(*.txt);;All files (*.*)");
        if (fileName.length() > 0){
            speedReaction[gr_index].clear();  mass_maxY[gr_index].clear(); speedRecovery[gr_index].clear();
            ui->list_SpeedReact->clear(); ui->list_SpeedRecov->clear();
            QFile file(fileName);
            if(!file.open(QIODevice::ReadOnly)) {QMessageBox::information(0, "Заголовок сообщения об ошибке", file.errorString());}
            QTextStream in(&file);
            bool b = false;
            int i = 0, j = 0;
            while(!in.atEnd()) {
                QString line = in.readLine();
                QRegExp rx("(\\ |\\t)"); //RegEx for ' ' or '\t'
                line=line.replace(',','.');
                QStringList fields = line.split(rx);
                if (b){ //пропускаем 1 строку с подписью
                    if (fields[0]!="#"){
                        speedReaction[gr_index].append(fields[0].toDouble()); //добавляем данные по последниему индексу списка графиков listwidget
                        ui->list_SpeedReact->addItem(QString::number(i)+ ") " + fields[0]);
                    }
                    if (fields[1]!="#")  mass_maxY[gr_index].append(fields[1].toDouble());

                    if (fields[2]!="#"){
                        speedRecovery[gr_index].append(fields[2].toDouble());
                        ui->list_SpeedRecov->addItem(QString::number(j)+ ") " + fields[2]);
                    }
                }
                b = true; i+=1; j+=1;
            }
            file.close();
            ui->btn_saveSpeed->setEnabled(true);
        }
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Список графиков пуст."));
}

void MainWindow::on_btn_saveSpeed_clicked() //кнопка Сохранить в файл скорости
{
    QString nameGr = "Скорость - " + ui->listWidget->item(gr_index)->text() ;
    QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение значений скорости"),
        nameGr, "Файл txt (*.txt)");
    QFile fileOut(fileName);
    if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream writeStream(&fileOut);
        writeStream << "V reac." << " " << "Max" << "      " << "V recov." << "\n";
        int i = 0, max = speedReaction[gr_index].count();
        if (mass_maxY[gr_index].count() > max) max = mass_maxY[gr_index].count();
        if (speedRecovery[gr_index].count() > max) max = speedRecovery[gr_index].count();
        while (i < max){
            if (i < speedReaction[gr_index].count()) writeStream << speedReaction[gr_index][i] << "\t";
            else writeStream << "#" << "\t";
            if (i < mass_maxY[gr_index].count()) writeStream << mass_maxY[gr_index][i] << "\t";
            else writeStream << "#" << "\t";
            if (i < speedRecovery[gr_index].count()) writeStream << speedRecovery[gr_index][i] << "\n";
            else writeStream << "#" << "\n";
            i+=1;
        }
    }
    fileOut.close();
}

void MainWindow::on_checkExp_clicked(bool checked) //вкл./выкл. эксп. сглаживания
{
    ui->SpinExp->setEnabled(checked); ui->checkGolay->setChecked(false); ui->spinGolay->setEnabled(false);
}

void MainWindow::on_checkGolay_clicked(bool checked) //вкл./выкл. сглаживания Савицкого-Голея
{
    ui->spinGolay->setEnabled(checked); ui->checkExp->setChecked(false); ui->SpinExp->setEnabled(false);
}

void MainWindow::on_undo()
{
    if (expY.count() > 0){
        //перед тем, как возвращать обратно, нужно сохранить текущее для последующего возврата
        QFile tempRedo("tempRedo.bin");        QDataStream streamRedo(&tempRedo);
        tempRedo.open(QIODevice::WriteOnly);        streamRedo << expY;
        tempRedo.close();
        QFile tempUndo("tempUndo.bin");        QDataStream streamUndo(&tempUndo);
        tempUndo.open(QIODevice::ReadOnly);        expY.clear();
        streamUndo >> expY;        tempUndo.close();
        graphic1->setData(mass_x_Gr[gr_index].toVector(), expY.toVector());
        ui->widget->replot();
    }
}

void MainWindow::on_redo()
{
    if (expY.count() > 0){
        //перед тем, как возвращать прямо, нужно сохранить текущее
        QFile tempUndo("tempUndo.bin");        QDataStream streamUndo(&tempUndo);
        tempUndo.open( QIODevice::WriteOnly);        streamUndo << expY;
        tempUndo.close();
        QFile tempRedo("tempRedo.bin");        QDataStream streamRedo(&tempRedo);
        tempRedo.open(QIODevice::ReadOnly);        expY.clear();
        streamRedo >> expY;        tempRedo.close();
        graphic1->setData(mass_x_Gr[gr_index].toVector(), expY.toVector());
        ui->widget->replot();
    }
}

bool MainWindow::check_extrem() //Проверка экстремумов, чтобы они чередовались между собой
{
    bool b = true;
    if (mass_minX[gr_index][0] < mass_maxX[gr_index][0]){//график возрастает изначально
        if ((mass_maxX[gr_index].count()==mass_minX[gr_index].count()-1) || (mass_minX[gr_index].count()==mass_maxX[gr_index].count())){
            for(int i = 0; ((i < mass_minX[gr_index].count()-1) && (i < mass_maxX[gr_index].count()-1)); i++){
                if (i <  mass_minX[gr_index].count()-1){
                    if ((mass_minX[gr_index][i] < mass_maxX[gr_index][i]) && (mass_maxX[gr_index][i] < mass_minX[gr_index][i+1]) && (mass_minX[gr_index][i+1] < mass_maxX[gr_index][i+1])){
                        b = true;
                    }else{
                        b = false; break;
                    }
                }
            }
        }else b = false;
    }else{ //график убывает
            if ((mass_minX[gr_index].count()==mass_maxX[gr_index].count()-1) || (mass_maxX[gr_index].count()==mass_minX[gr_index].count())){
            for(int i = 0; ((i < mass_minX[gr_index].count()-1) && (i < mass_maxX[gr_index].count()-1)); i++){
                if ((mass_maxX[gr_index][i] < mass_minX[gr_index][i]) && (mass_minX[gr_index][i] < mass_maxX[gr_index][i+1])&& (mass_maxX[gr_index][i+1] < mass_minX[gr_index][i+1])){
                    b = true;
                }else{
                    b = false; break;
                }
            }
        }else b = false;
    }
    return b;
}

void MainWindow::on_btn_delta_clicked() //Расчет изменения дельты сигнала
{
    if (ui->listWidget->count() > 0){
        if ((mass_minX[gr_index].count()>0) && (mass_maxX[gr_index].count()>0)){
            if (check_extrem()){
                deltaWin *DeltaW = new deltaWin(mass_minX[gr_index], mass_maxX[gr_index], mass_minY[gr_index], mass_maxY[gr_index], speedReaction[gr_index], speedRecovery[gr_index], this);
                DeltaW->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - Δ сигнала");
                DeltaW->show();
                DeltaW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
            }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Экстремумы идут не по порядку. Значит и расчеты будут не правильные. Исправьте, пожалуйста."));
        }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Экстремумы не определены!"));
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_btn_DFT_clicked() //Фильрация сигнала: Дискретное преобразование Фурье
{
    if (ui->listWidget->count() > 0){
        if (ui->Spin_x1->value() < ui->Spin_x2->value()){
            QList <double> tempX, tempY;
            FilterFFT *FFTWindow;
            if (rectSpan->visible()){
                for (int i = 0; i < mass_x_Gr[gr_index].count(); i++){
                    if (mass_x_Gr[gr_index][i] >= ui->Spin_x1->value() && (mass_x_Gr[gr_index][i] <= ui->Spin_x2->value())){
                        tempX.append(mass_x_Gr[gr_index][i]);  tempY.append(mass_y_Gr[gr_index][i]);
                    }
                }
                FFTWindow = new FilterFFT(tempX, tempY, axis_x_Gr[gr_index], axis_y_Gr[gr_index], this);
            }else FFTWindow = new FilterFFT(mass_x_Gr[gr_index], mass_y_Gr[gr_index], axis_x_Gr[gr_index], axis_y_Gr[gr_index], this);

            FFTWindow->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - фильтрация сигнала");
            FFTWindow->show();
            FFTWindow->setAttribute(Qt::WA_DeleteOnClose); //деструктор
        }else QMessageBox::critical(NULL,QObject::tr("Внимание"),tr("Интервал значений не определен."));
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_cmbBox_Correl_activated(int index) //Корреляционный анализ
{
    if (ui->listWidget->count() > 0){        
            switch (index){
                case 0 : if (speedReaction[gr_index].count()>0){ //если выбрали скорость реакции/размах и скорость нашли, то хорошо. И т.д.
                    correl_analysis *CorrelW;
                    CorrelW = new correl_analysis(speedReaction[gr_index], mass_maxY[gr_index], "Скорость реакции V, м/с", "Размах сигнала R, Ом", this);
                    CorrelW->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - Корреляционный анализ");
                    CorrelW->show();
                    CorrelW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
                }else QMessageBox::critical(NULL,QObject::tr("Внимание"),tr("Скорость реакции не определена."));
                break;
                case 1 :if (speedRecovery[gr_index].count()>0){
                    correl_analysis *CorrelW;
                    CorrelW = new correl_analysis(speedRecovery[gr_index], mass_maxY[gr_index], "Скорость восстановления V, м/с", "Размах сигнала R, Ом", this);
                    CorrelW->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - Корреляционный анализ");
                    CorrelW->show();
                    CorrelW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
                }else QMessageBox::critical(NULL,QObject::tr("Внимание"),tr("Скорость восстановления не определена."));
                break;
                default: if (speedReaction[gr_index].count()>0){
                    correl_analysis *CorrelW;
                    CorrelW = new correl_analysis(speedRecovery[gr_index],speedReaction[gr_index], "Скорость реакции V1, м/с", "Скорость восстановления V2, м/с", this);
                    CorrelW->setWindowTitle(ui->listWidget->item(gr_index)->text() + " - Корреляционный анализ");
                    CorrelW->show();
                    CorrelW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
                }else QMessageBox::critical(NULL,QObject::tr("Внимание"),tr("Скорость реакции или восстановления не определены."));
            }       
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_btn_BuildMnk_clicked() //Построить МНК
{
    if (ui->listWidget->count() > 0){
        double xLevel = 0, yLevel = 0;
        if (ui->rbMinMnk->isChecked()){//Метод наименьших квадратов (МНК) минимума
            if (mass_minX[gr_index].count() != 0){
                trendMin[gr_index].clear();  yLevelMin[gr_index].clear(); xLevelMin[gr_index].clear();
                mnk *mnk1 = new mnk(mass_minX[gr_index], mass_minY[gr_index], mass_minX[gr_index].count());
                //QMessageBox::information(NULL,"Информация","Коэффициент детерминации = "+QString::number(Kdet));
                for(int i = 0; i < mass_minX[gr_index].count(); i++){
                    trendMin[gr_index].append(mnk1->get_yy(mass_minX[gr_index][i]));
                }
                if (trendMin[gr_index][1]>trendMin[gr_index][0]){
                    yLevelMin[gr_index].append(trendMin[gr_index][0] + trendMin[gr_index][0]*(ui->spinLevel->value()/100));
                }else{
                    yLevelMin[gr_index].append(trendMin[gr_index][0] - trendMin[gr_index][0]*(ui->spinLevel->value()/100));
                }
                yLevelMin[gr_index].append(yLevelMin[gr_index][0]+yLevelMin[gr_index][0]*0.1);
                yLevelMin[gr_index].append(yLevelMin[gr_index][0]-yLevelMin[gr_index][0]*0.1);
                xLevelMin[gr_index].append((yLevelMin[gr_index][0]- mnk1->get_b()) / mnk1->get_a());
                xLevelMin[gr_index].append((yLevelMin[gr_index][0]- mnk1->get_b()) / mnk1->get_a());
                xLevelMin[gr_index].append((yLevelMin[gr_index][0]- mnk1->get_b()) / mnk1->get_a());
                xLevel = (yLevelMin[gr_index][0] - mnk1->get_b()) / mnk1->get_a();
                yLevel = yLevelMin[gr_index][0];
                ui->BrowserTime->setText(QString::number(xLevel));
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
        if (ui->rbMaxMnk->isChecked()){//Метод наименьших квадратов (МНК)максимума
            if (mass_maxX[gr_index].count() != 0){
                trendMax[gr_index].clear(); yLevelMax[gr_index].clear(); xLevelMax[gr_index].clear();
                mnk *mnk2 = new mnk(mass_maxX[gr_index], mass_maxY[gr_index], mass_maxX[gr_index].count());
                //QMessageBox::information(NULL,"Информация","Коэффициент детерминации = "+QString::number(Kdet));
                for(int i = 0; i < mass_maxX[gr_index].count(); i++){
                    trendMax[gr_index].append(mnk2->get_yy(mass_maxX[gr_index][i]));
                }
                if (trendMax[gr_index][1]>trendMax[gr_index][0]){
                    yLevelMax[gr_index].append(trendMax[gr_index][0] + trendMax[gr_index][0]*(ui->spinLevel->value()/100));
                }else{
                    yLevelMax[gr_index].append(trendMax[gr_index][0] - trendMax[gr_index][0]*(ui->spinLevel->value()/100));
                }
                yLevelMax[gr_index].append(yLevelMax[gr_index][0] + yLevelMax[gr_index][0]*0.1);
                yLevelMax[gr_index].append(yLevelMax[gr_index][0] - yLevelMax[gr_index][0]*0.1);
                xLevelMax[gr_index].append((yLevelMax[gr_index][0]-mnk2->get_b()) / mnk2->get_a());
                xLevelMax[gr_index].append((yLevelMax[gr_index][0]-mnk2->get_b()) / mnk2->get_a());
                xLevelMax[gr_index].append((yLevelMax[gr_index][0]-mnk2->get_b()) / mnk2->get_a());
                xLevel = (yLevelMax[gr_index][0] - mnk2->get_b()) / mnk2->get_a();
                yLevel = yLevelMax[gr_index][0];
                ui->BrowserTime->setText(QString::number(xLevel));
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
        if (ui->rbAllMnk->isChecked()) QMessageBox::information(NULL,"Внимание", "Пожалуйста, выберите только минимум или максимум.");
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_btn_delMnk_clicked() //удаление МНК
{
    if (ui->listWidget->count() > 0){
        if (ui->rbMin->isChecked()){ trendMin[gr_index].clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" ");
            graphLevelMin->setVisible(false); graphLevelMin->setName(" ");   textListMNK[gr_index][0]->setVisible(false);
        }else if (ui->rbMaxMnk->isChecked()){
            trendMax[gr_index].clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" ");
            graphLevelMax->setVisible(false); graphLevelMax->setName(" ");   textListMNK[gr_index][1]->setVisible(false);
        }else if (ui->rbAllMnk->isChecked()){
            trendMin[gr_index].clear(); graphMnkMin->setVisible(false); graphMnkMin->setName(" ");
            graphLevelMin->setVisible(false);  graphLevelMin->setName(" ");
            trendMax[gr_index].clear(); graphMnkMax->setVisible(false); graphMnkMax->setName(" ");
            graphLevelMax->setVisible(false); graphLevelMax->setName(" ");
            textListMNK[gr_index][0]->setVisible(false);  textListMNK[gr_index][1]->setVisible(false);
        }
        ui->widget->replot();
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_spinLevel_valueChanged(double ){ on_btn_BuildMnk_clicked(); } //спин мнк

void MainWindow::on_btn_Manual_clicked() //запуск руководства пользователя
{
    QString path = qApp->applicationDirPath();
    QProcess::execute("hh.exe "+path+"/manual.chm");
}

void MainWindow::on_SliderSpan_valueChanged(int value) //вкл./выкл. диапазона значений
{
    if ((value == 1) && (ui->Spin_x2->value()>0.0)) { //вкл   
        ui->SliderSpan->setStyleSheet(sliderStyleOn);  rectSpan->setVisible(true);
    }
    else{ //выкл
        ui->SliderSpan->setStyleSheet(sliderStyleOff);  rectSpan->setVisible(false);
        ui->SliderSpan->setValue(0);
    }
    ui->widget->replot();
}

void MainWindow::on_SliderLegend_valueChanged(int value) //вкл./выкл. легенды
{
    if (ui->listWidget->count() > 0) {
        if (value == 1) { //вкл
            ui->SliderLegend->setStyleSheet(sliderStyleOn);
            ui->widget->legend->setVisible(true);
        }
        else{ //выкл
            ui->SliderLegend->setStyleSheet(sliderStyleOff);
            ui->widget->legend->setVisible(false);
        }
        ui->widget->replot();
    }else {ui->statusBar->showMessage("График пуст"); ui->SliderLegend->setValue(0);}
}

void MainWindow::on_SliderPointGr_valueChanged(int value) //показать/скрыть координаты точек установленных вручную
{
    if (ui->listWidget->count() > 0){
        if (value == 1) { //вкл
            ui->SliderPointGr->setStyleSheet(sliderStyleOn);
            for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(true);}
            for (int i = 0; i < textListMax[gr_index].length(); i++) {textListMax[gr_index][i]->setVisible(true);}
        }
        else{ //выкл
            ui->SliderPointGr->setStyleSheet(sliderStyleOff);
            for (int i = 0; i < textListMin[gr_index].length(); i++) {textListMin[gr_index][i]->setVisible(false);}
            for (int i = 0; i < textListMax[gr_index].length(); i++) {textListMax[gr_index][i]->setVisible(false);}
        }
        ui->widget->replot();
    }else ui->SliderPointGr->setValue(0);
}

void MainWindow::on_cmbBox_dispers_activated(int index)
{
    if (ui->listWidget->count() > 0) {
            int g = gr_index;
            gr_index = 0;
            QList <QString> list;
            for (int j = 0; j < ui->listWidget->count(); j++){ //считаю скорости всех графиков
                if (speedReaction[gr_index].count() == 0){
                    speedSearch(); //если скоростей нет и их из файла не загружали, то попробуем рассчитать
                    for (int i = 0; i < speedReaction[gr_index].count(); i++)  ui->list_SpeedReact->addItem(QString::number(i+1)+ ") " + QString::number(speedReaction[gr_index][i]));
                    for (int i = 0; i < speedRecovery[gr_index].count(); i++)  ui->list_SpeedRecov->addItem(QString::number(i+1)+ ") " + QString::number(speedRecovery[gr_index][i]));
                }
                gr_index +=1;
            }
            gr_index = g;
            for (int i = 0; i < ui->listWidget->count(); i++) list.append(ui->listWidget->item(i)->text());
            if (index == 0){
                dispers_analysis *DispersW = new dispers_analysis(ui->cmbBox_dispers->currentText(), list, speedReaction, this);
                DispersW->show();
                DispersW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
            }else{
                dispers_analysis *DispersW = new dispers_analysis(ui->cmbBox_dispers->currentText(), list, speedRecovery, this);
                DispersW->show();
                DispersW->setAttribute(Qt::WA_DeleteOnClose); //деструктор
            }
    }else QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Выберите файл с данными через диалог в меню для загрузки данных."));
}

void MainWindow::on_tabWidget_currentChanged(int index)//когда выбираем скользящее окно, чтобы кнопка ручной настройки экстр. отжималась
{
    if (ui->listWidget->count() > 0){
        if (index == 2){
            ui->manualExtrem->setChecked(false);
            ui->widget->setCursor(QCursor(Qt::SplitHCursor));
        }else{
            ui->widget->setCursor(QCursor(Qt::ArrowCursor));
            ui->manualExtrem->setChecked(false);
        }
        if ((index == 4) && (speedReaction[gr_index].count() > 0)) ui->btn_saveSpeed->setEnabled(true);
    }
}
