#ifndef FILTERFFT_H
#define FILTERFFT_H

#include <QMainWindow>

namespace Ui {
class FilterFFT;
}

class FilterFFT : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilterFFT(QWidget *parent = 0);
    ~FilterFFT();

private:
    Ui::FilterFFT *ui;
};

#endif // FILTERFFT_H
