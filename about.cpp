#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint); //показать окно и на нем только кнопку закрытия
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    this->close();
}
