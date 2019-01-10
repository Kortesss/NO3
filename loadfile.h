#ifndef LOADFILE_H
#define LOADFILE_H

#include <QObject>
//#include <mainwindow.h>

class loadFile : public QObject
{
    Q_OBJECT
public:
    ~loadFile();
    //explicit loadFile(Ui::MainWindow *ui, MainWindow *th);
    //Ui::MainWindow *ui0;
    //MainWindow *th0;

signals:
    void finished();

public slots:
    void doWork();

private slots:

private:

};

#endif // LOADFILE_H
