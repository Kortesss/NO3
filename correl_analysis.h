#ifndef CORREL_ANALYSIS_H
#define CORREL_ANALYSIS_H

#include <QMainWindow>

namespace Ui {
class correl_analysis;
}

class correl_analysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit correl_analysis(QWidget *parent = 0);
    ~correl_analysis();

private:
    Ui::correl_analysis *ui;
};

#endif // CORREL_ANALYSIS_H
