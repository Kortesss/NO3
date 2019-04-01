#include "correl_analysis.h"
#include "ui_correl_analysis.h"

correl_analysis::correl_analysis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::correl_analysis)
{
    ui->setupUi(this);
}

correl_analysis::~correl_analysis()
{
    delete ui;
}
