#include "dispers_analysis.h"
#include "ui_dispers_analysis.h"

dispers_analysis::dispers_analysis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dispers_analysis)
{
    ui->setupUi(this);
}

dispers_analysis::~dispers_analysis()
{
    delete ui;
}
