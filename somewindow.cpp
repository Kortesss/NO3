#include "somewindow.h"
#include "ui_somewindow.h"
#include <QDebug>

SomeWindow::SomeWindow(QVector<double> &dirivate, int &x1, int &x2, double &koef, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SomeWindow)
{
    ui->setupUi(this);
    CtrlS = new QShortcut(this);
    CtrlS->setKey(Qt::CTRL + Qt::Key_S);
    CtrlQ = new QShortcut(this);
    CtrlQ->setKey(Qt::CTRL + Qt::Key_Q);
    connect(CtrlS, SIGNAL(activated()), this, SLOT(on_pushButton_save_clicked()));
    connect(CtrlQ, SIGNAL(activated()), this, SLOT(on_pushButton_close_clicked()));

    graphDirivate(dirivate, x1, x2,koef);

}
void SomeWindow::graphDirivate(QVector<double> &dirivate, int &x1, int &x2,double &koef){
    ui->widget_dir->clearGraphs();//Если нужно, о очищаем все графики
    ui->widget_dir->addGraph();
    QVector<double> x1vector;
    double miny, maxy;
    for(int i = x1; i < dirivate.count()+x1; ++i){
        x1vector.append(i*koef);
    }
        miny = *std::min_element(dirivate.begin(), dirivate.end());
        maxy = *std::max_element(dirivate.begin(), dirivate.end());
        qDebug() << "MIN Y="<<miny; qDebug() << "MAX Y="<<maxy;
        qDebug() << "x1="<<x1;
        qDebug() << "x2="<<x2;
    //}
    ui->widget_dir->graph(0)->setData(x1vector, dirivate);
    ui->widget_dir->graph(0)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    ui->widget_dir->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    //Подписываем оси Ox и Oy
    ui->widget_dir->xAxis->setLabel("t, c");
    ui->widget_dir->yAxis->setLabel("y");
    //Установим область, которая будет показываться на графике
//    ui->widget_dir->xAxis->setRange(x1, x2);//Для оси Ox
    ui->widget_dir->xAxis->setRange(x1*koef, x2*koef);//Для оси Ox
    qDebug() << "(x1)="<<x1*koef;
    qDebug() << "(x2)="<<x2*koef;

    ui->widget_dir->yAxis->setRange(miny,maxy);//Для оси Oy
    //И перерисуем график на нашем widget
    ui->widget_dir->replot();
    ui->widget_dir->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}
SomeWindow::~SomeWindow()
{
    delete ui;
}

void SomeWindow::on_pushButton_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(0, QString::fromUtf8("Сохранение графика"),
                       windowTitle(), "Изображение png (*.png);; Изображение jpg (*.jpg);; Изображение bmp(*.bmp);; Документ pdf(*.pdf)");
    if (!fileName.isNull()){
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly|QFile::WriteOnly)) QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Что-то пошло не так."));
            else if (fileName.contains(".png", Qt::CaseInsensitive)) ui->widget_dir->savePng(fileName);
                else if (fileName.contains(".jpg", Qt::CaseInsensitive)) ui->widget_dir->saveJpg(fileName);
                    else if (fileName.contains(".bmp", Qt::CaseInsensitive)) ui->widget_dir->saveBmp(fileName);
                        else ui->widget_dir->savePdf(fileName);
        file.close();
    }
}

void SomeWindow::on_pushButton_close_clicked()
{
    this->close();
}
