#include "correl_analysis.h"
#include "ui_correl_analysis.h"
#include "mnk.h"
#include <QDebug>

correl_analysis::correl_analysis(QList <double> &mass1, QList <double> &mass2, QString nameX, QString nameY, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::correl_analysis)
{
    ui->setupUi(this);

    CtrlShiftS = new QShortcut(this);
    CtrlShiftS->setKey(Qt::CTRL + Qt::SHIFT + Qt::Key_S);
    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlShiftS, SIGNAL(activated()), this, SLOT(on_pushButton_save_clicked()));
    connect(CtrlQ, SIGNAL(activated()), this, SLOT(on_pushButton_close_clicked()));

    ui->widgetCorr->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    graphCorr = ui->widgetCorr->addGraph();
    graphCorr->setPen(QColor(50, 50, 50, 255));//черный
    graphCorr->setLineStyle(QCPGraph::lsNone);
    graphCorr->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 4));

    graphTrend = ui->widgetCorr->addGraph();
    graphTrend->setPen(QColor(255, 0, 0, 255));//красный
    graphTrend->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
    ui->widgetCorr->xAxis->setLabel(nameX);    ui->widgetCorr->yAxis->setLabel(nameY);
    sliderStyleOn = ".QSlider::groove:horizontal {height: 24px; background: #20B2AA; border-radius: 8px; padding:-4px 7px;}"
                    ".QSlider::handle:horizontal {background: #008080; width: 22px; margin: 0px -7px; border-radius: 11px;}";
    sliderStyleOff = ".QSlider::groove:horizontal {height: 24px; background:#696969; border-radius: 8px; padding:-4px 7px;}"
                     ".QSlider::handle:horizontal {background: #d5d5d5; width: 22px; margin: 0px -7px; border-radius: 11px;}";
    draw(mass1, mass2,nameX,nameY);
    ui->koefCovar->setText("Ковариация = " + QString::number(covar(mass1, mass2)));
    if (covar(mass1, mass2)>0)    ui->label_covar->setText(" C ростом значений параметра '" + nameX+"', \nзначения '"+ nameY+"' имеют тенденцию возрастать.");
    else  ui->label_covar->setText(" C ростом значений параметра '" + nameX+"', \nзначения '"+ nameY+"' имеют тенденцию убывать.");
    ui->SliderTrend->setValue(1);
}

correl_analysis::~correl_analysis()
{
    delete ui;
}

double correl_analysis::covar(QList <double> &mass1, QList <double> &mass2)
{
    double cov = 0, a1 = avg(mass1), a2 = avg(mass2);
    for (int i = 0; i < mass1.count(); i++){
        cov += ((mass1[i]-a1)*(mass2[i]-a2));
    }

    cov/=mass1.count()-1;
    return cov;
}

double correl_analysis::avg(QList <double> &mass)
{
    double s = 0;
    for (int i = 0; i < mass.count(); i++){
        s+=mass[i];
    }
    s/=mass.count();
    return s;
}

void correl_analysis::draw(QList <double> &mass1, QList <double> &mass2,QString name_x,QString name_y)
{
    QString clkf;
    mnk *mnk1 = new mnk(mass1, mass2, mass1.count());
    ui->koefCorr->setText("Коэффициент корреляции = "+QString::number(mnk1->get_Kcor()));
    for(int i = 0; i < mass1.count(); i++){
        trendCorr.append(mnk1->get_yy(mass1[i]));
    }
    qDebug()<<mnk1->get_Kcor();
    ui->label_koefDeteter->setText("Коэффициент детерминации = " + QString::number(mnk1->get_Kdet()));

    if (((0<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=0.2))||((-1<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=-0.9))){
        ui->label_res->setText(" Значение коэффициента корреляции, равное "+QString::number(mnk1->get_Kcor())+",\nпоказывает, что рассматриваемые параметры имеют\nочень слабую корреляцию.");
     }else if (((0.2<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=0.5))||(((-0.9<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=-0.7)))){
          ui->label_res->setText(" Значение коэффициента корреляции, равное "+QString::number(mnk1->get_Kcor())+",\nпоказывает, что рассматриваемые параметры имеют\nслабую корреляцию.");
        }else if (((0.5<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=0.7))||(((-0.7<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=-0.5)))){
            ui->label_res->setText(" Значение коэффициента корреляции, равное "+QString::number(mnk1->get_Kcor())+",\nпоказывает, что рассматриваемые параметры имеют\nсреднюю корреляцию.");
           }else if (((0.7<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=0.9))||(((-0.5<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=-0.2)))){
              ui->label_res->setText(" Значение коэффициента корреляции, равное "+QString::number(mnk1->get_Kcor())+",\nпоказывает, что рассматриваемые параметры имеют\nвысокую корреляцию.");
              }else if (((0.9<mnk1->get_Kcor()) && (mnk1->get_Kcor()<=1))||(((-0.2<mnk1->get_Kcor())&&(mnk1->get_Kcor() < 0)))){
                 ui->label_res->setText(" Значение коэффициента корреляции, равное "+QString::number(mnk1->get_Kcor())+",\nпоказывает, что рассматриваемые параметры имеют\nочень высокую корреляцию.");
                 }else if (mnk1->get_Kcor()==0){
                    ui->label_res->setText("Значение коэффициента корреляции, равное "+QString::number(mnk1->get_Kcor())+",\nпоказывает, что рассматриваемые параметры имеют\n нулевую корреляцию.");
                 }
    ui->label_deter->setText(" В "+QString::number(mnk1->get_Kdet()*100,'f',2)+"% случаев изменения значений '"+name_x+"'\nприводят к изменению значений '"+name_y+"'.");

    delete mnk1;
    double minx = *std::min_element(mass1.begin(), mass1.end());
    double maxx = *std::max_element(mass1.begin(), mass1.end());
    double miny = *std::min_element(mass2.begin(), mass2.end());
    double maxy = *std::max_element(mass2.begin(), mass2.end());
    //Установим область, которая будет показываться на графике
    ui->widgetCorr->xAxis->setRange(minx, maxx);// Для оси Ox
    ui->widgetCorr->yAxis->setRange(miny, maxy);//Для оси Oy
    graphTrend->setData(mass1.toVector(), trendCorr.toVector());
    graphCorr->setData(mass1.toVector(), mass2.toVector());
    graphCorr->setVisible(true);
}

void correl_analysis::on_pushButton_save_clicked()//сохранение полученного графика
{
    QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение графика"),
                       windowTitle(), "Изображение png (*.png);; Изображение jpg (*.jpg);; Изображение bmp(*.bmp);; Документ pdf(*.pdf)");
    if (!fileName.isNull()){
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly|QFile::WriteOnly)) QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Что-то пошло не так."));
            else if (fileName.contains(".png", Qt::CaseInsensitive)) ui->widgetCorr->savePng(fileName);
                else if (fileName.contains(".jpg", Qt::CaseInsensitive)) ui->widgetCorr->saveJpg(fileName);
                    else if (fileName.contains(".bmp", Qt::CaseInsensitive)) ui->widgetCorr->saveBmp(fileName);
                        else ui->widgetCorr->savePdf(fileName);
        file.close();
    }
}

void correl_analysis::on_pushButton_close_clicked()
{
    this->close();
}

void correl_analysis::on_SliderTrend_valueChanged(int value)
{
    if (value == 1) { //вкл
        ui->SliderTrend->setStyleSheet(sliderStyleOn);
        graphTrend->setVisible(true);
    }
    else{ //выкл
        ui->SliderTrend->setStyleSheet(sliderStyleOff);
        graphTrend->setVisible(false);
    }
    ui->widgetCorr->replot();
}
