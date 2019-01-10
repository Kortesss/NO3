#include "loadfile.h"
//#include "ui_mainwindow.h"
//#include "mainwindow.h"
#include <QDebug>

//loadFile::loadFile(Ui::MainWindow *ui, MainWindow *th):ui0(ui), th0(th)
//{
//}

void loadFile::doWork(){

  emit finished(); // вызывается при завершении
}

loadFile::~loadFile()
{
    qDebug() << "Деструктор loadFile";
}


