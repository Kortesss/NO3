#include "loadfile.h"
#include "ui_mainwindow.h"
//#include "mainwindow.h"
#include <QDebug>

loadFile::loadFile(Ui::MainWindow *ui, MainWindow *th):ui0(ui), th0(th)
{
}
//loadFile::loadFile(MainWindow *mw, QWidget *parent):QMainWindow(parent), mW(mw)
void loadFile::doWork(){
    for(int i = 0; i <= 3; i++){
        qDebug() << i;
        Sleep(1000);
    }
    ui0->label_2->setText("dfd");
    //th0->koef=0.22l;
}

loadFile::~loadFile()
{
    qDebug() << "Деструктор loadFile";
}
