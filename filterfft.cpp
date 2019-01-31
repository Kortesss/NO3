#include "filterfft.h"
#include "ui_filterfft.h"

FilterFFT::FilterFFT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterFFT)
{
    ui->setupUi(this);
}

FilterFFT::~FilterFFT()
{
    delete ui;
}
