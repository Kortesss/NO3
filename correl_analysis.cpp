#include "correl_analysis.h"
#include "ui_correl_analysis.h"
#include "mnk.h"

correl_analysis::correl_analysis(QList <double> mass1, QList <double> mass2, QString nameX, QString nameY, QWidget *parent) :
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
    graphCorr = ui->widgetCorr->addGraph(); //Добавление МНК максимумов
    graphCorr->setPen(QColor(255, 0, 0, 255));
    graphCorr->setLineStyle(QCPGraph::lsNone);
    graphCorr->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    graphTrend = ui->widgetCorr->addGraph();
    graphTrend->setPen(QColor(50, 50, 50, 255));
    graphTrend->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->widgetCorr->xAxis->setLabel(nameX);    ui->widgetCorr->yAxis->setLabel(nameY);

    draw(mass1, mass2);
}

correl_analysis::~correl_analysis()
{
    delete ui;
}

void correl_analysis::draw(QList <double> mass1, QList <double> mass2)
{
    mnk *mnk1 = new mnk(mass1, mass2, mass1.count());
    //QMessageBox::information(NULL,"Информация","Коэффициент корреляции = "+QString::number(mnk1->get_Kcor()));
    for(int i = 0; i < mass1.count(); i++){
        trendCorr.append(mnk1->get_yy(mass1[i]));
    }
    double minx = *std::min_element(mass1.begin(), mass1.end());
    double maxx = *std::max_element(mass1.begin(), mass1.end());
    double miny = *std::min_element(mass2.begin(), mass2.end());
    double maxy = *std::max_element(mass2.begin(), mass2.end());
    //Установим область, которая будет показываться на графике
    ui->widgetCorr->xAxis->setRange(minx, maxx);// Для оси Ox
    ui->widgetCorr->yAxis->setRange(miny, maxy);//Для оси Oy
    graphTrend->setData(mass1.toVector(), trendCorr.toVector());
    graphTrend->setVisible(true);
    graphCorr->setData(mass1.toVector(), mass2.toVector());
    graphCorr->setVisible(true);
    ui->widgetCorr->replot();
    delete mnk1;
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
