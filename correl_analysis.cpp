#include "correl_analysis.h"
#include "ui_correl_analysis.h"
#include "mnk.h"

correl_analysis::correl_analysis(QList <double> mass1, QList <double> mass2, QString nameX, QString nameY, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::correl_analysis)
{
    ui->setupUi(this);

    ui->widgetCorr->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    graphCorr = ui->widgetCorr->addGraph();
    graphCorr->setPen(QColor(50, 50, 50, 255));//черный
    graphCorr->setLineStyle(QCPGraph::lsNone);
    graphCorr->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    graphTrend = ui->widgetCorr->addGraph();
    graphTrend->setPen(QColor(255, 0, 0, 255));//красный
    graphTrend->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->widgetCorr->xAxis->setLabel(nameX);    ui->widgetCorr->yAxis->setLabel(nameY);
    sliderStyleOn = ".QSlider::groove:horizontal {height: 24px; background: #87CEEB; border-radius: 8px; padding:-4px 7px;}"
                    ".QSlider::handle:horizontal {background: #1E90FF; width: 22px; margin: 0px -7px; border-radius: 11px;}";
    sliderStyleOff = ".QSlider::groove:horizontal {height: 24px; background:#696969; border-radius: 8px; padding:-4px 7px;}"
                     ".QSlider::handle:horizontal {background: #d5d5d5; width: 22px; margin: 0px -7px; border-radius: 11px;}";
    draw(mass1, mass2);
    ui->SliderTrend->setValue(1);
}

correl_analysis::~correl_analysis()
{
    delete ui;
}

void correl_analysis::draw(QList <double> mass1, QList <double> mass2)
{
    mnk *mnk1 = new mnk(mass1, mass2, mass1.count());
    ui->koefCorr->setText("Коэффициент корреляции = "+QString::number(mnk1->get_Kcor()));
    for(int i = 0; i < mass1.count(); i++){
        trendCorr.append(mnk1->get_yy(mass1[i]));
    }
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

void correl_analysis::on_pushButton_save_clicked()
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
