#ifndef DISPERS_ANALYSIS_H
#define DISPERS_ANALYSIS_H

#include <QMainWindow>

namespace Ui {
class dispers_analysis;
}

class dispers_analysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit dispers_analysis(QWidget *parent = 0);
    ~dispers_analysis();

private:
    Ui::dispers_analysis *ui;
};

#endif // DISPERS_ANALYSIS_H
