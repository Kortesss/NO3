#ifndef LOADFILE_H
#define LOADFILE_H

#include <QObject>
#include <mainwindow.h>

class loadFile : public QObject
{
    Q_OBJECT
public:
    ~loadFile();
    explicit loadFile(Ui::MainWindow *ui, MainWindow *th);
    Ui::MainWindow *ui0;
    MainWindow *th0;
    bool Stop;
    int temp;

signals:
    void finished();
    void sendNumber(int);

public slots:
    void doWork();
    void process();
    void reciveBoolStop(bool Numb);

private:

};

#endif // LOADFILE_H
