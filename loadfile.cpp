#include "loadfile.h"
#include "ui_mainwindow.h"
//#include "mainwindow.h"
#include <QDebug>

loadFile::loadFile(Ui::MainWindow *ui, MainWindow *th):ui0(ui), th0(th)
{
    Stop = false;
    temp = 0;
}

void loadFile::doWork(){
    //for(int i = 0; i <= 3; i++){
    //    qDebug() << i;
    //    Sleep(1000);
    //}
    //ui0->label_2->setText("dfd");
    Stop = false;
    if(!Stop == true){
        for(; temp <= 100000; temp++){
            if(!Stop == true){
                emit(sendNumber(temp));
                QProgressBar *progBar = new QProgressBar(th0); //объявляем прогресс-бар
                QListWidgetItem *it = new QListWidgetItem(ui0->listWidget); //объявляем итем и связываем его со списком графиков
                //btn->animateClick();
                QWidget* wgt = new QWidget;
                QLayout* l = new QHBoxLayout;
                l->addWidget(progBar);
                QPushButton *btn = new QPushButton("S");
                btn->setStyleSheet("QPushButton {width:5px; height:5px;}");
                //connect(btn, SIGNAL(clicked()), SLOT(onBtnClicked()));
                l->addWidget(btn);
                wgt->setLayout(l);
                //it->setSizeHint(20);
                QString fileName = QFileDialog::getOpenFileName(0,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "(*.txt);;All files (*.*)");
                if (fileName.length() > 0){
                    QFile file(fileName);
                    //setWindowTitle(file.fileName());
                    ui0->listWidget->insertItem(ui0->listWidget->count()-1,it);//вставляем в список графиков тот итем
                    ui0->listWidget->setItemWidget(it, progBar);//связываем итем и прогресс-бар
                    progBar->setFormat("График "+QString::number(ui0->listWidget->count()));//настраиваем бар.. Текст
                    progBar->setAlignment(Qt::AlignCenter);//текст по центру
                    progBar->setTextVisible(true);//показываем текст
                    progBar->setStyleSheet("QProgressBar {border: 1px solid grey;} QProgressBar::chunk {background-color: #05B8CC;}");
                    progBar->setRange(0,100);//устанавливаем его диапазон до 100%

                    if(!file.open(QIODevice::ReadOnly)) {
                        QMessageBox::information(0, "Заголовок сообщения об ошибке", file.errorString());
                    }
                QTextStream in(&file);
                while(!in.atEnd()) {
                    QString line = in.readLine();
                    QRegExp rx("(\\ |\\t)"); //RegEx for ' ' or '\t'
                    line=line.replace(',','.');
                    QStringList fields = line.split(rx);
                    ui0->textBrowser->append(QString("%1 %2").arg(fields[0].toDouble()).arg(fields[1].toDouble()));
                    //ui->textBrowser->append(line);
                    //добавляем в список X
                    th0->setMassX(fields[0].toDouble());
                    //добавляем в список Y
                    th0->setMassY(fields[1].toDouble());
                    progBar->setValue((file.pos()*100)/file.size()); //двигаем значение бара по чтению текущей позиции из файла
                }
                file.close();
                delete it; delete progBar;  delete btn;  delete l; delete wgt;
                ui0->listWidget->addItem("График "+QString::number(ui0->listWidget->count()+1));//+1 потому что там еще ничего нет
                ui0->listWidget->item(ui0->listWidget->count()-1)->setTextAlignment(Qt::AlignCenter);
            }
        }
        //else{
        //    return;
        //}
     }
  }
  emit finished(); // вызывается при завершении
}

void loadFile::reciveBoolStop(bool Numb)
{
Stop = Numb;
qDebug() << "reciveBoolStop = " << Stop;
emit finished(); // вызывается при отмене расчёта
}

loadFile::~loadFile()
{
    qDebug() << "Деструктор loadFile";
}
