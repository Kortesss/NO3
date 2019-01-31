/********************************************************************************
** Form generated from reading UI file 'filterfft.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERFFT_H
#define UI_FILTERFFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FilterFFT
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_saveTxt;
    QPushButton *pushButton_close;
    QCustomPlot *widget_ifft;
    QCustomPlot *widget_fft;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FilterFFT)
    {
        if (FilterFFT->objectName().isEmpty())
            FilterFFT->setObjectName(QStringLiteral("FilterFFT"));
        FilterFFT->resize(813, 764);
        centralwidget = new QWidget(FilterFFT);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(185, 20));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(185, 0));
        horizontalSlider->setMaximumSize(QSize(185, 16777215));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        pushButton_saveTxt = new QPushButton(centralwidget);
        pushButton_saveTxt->setObjectName(QStringLiteral("pushButton_saveTxt"));
        pushButton_saveTxt->setMinimumSize(QSize(185, 24));
        pushButton_saveTxt->setMaximumSize(QSize(185, 16777215));
        pushButton_saveTxt->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-height: 20px; \n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));

        verticalLayout->addWidget(pushButton_saveTxt);

        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(185, 24));
        pushButton_close->setMaximumSize(QSize(185, 16777215));
        pushButton_close->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-height: 20px; \n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));

        verticalLayout->addWidget(pushButton_close);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        widget_ifft = new QCustomPlot(centralwidget);
        widget_ifft->setObjectName(QStringLiteral("widget_ifft"));

        gridLayout->addWidget(widget_ifft, 1, 0, 1, 1);

        widget_fft = new QCustomPlot(centralwidget);
        widget_fft->setObjectName(QStringLiteral("widget_fft"));
        widget_fft->setMinimumSize(QSize(600, 0));

        gridLayout->addWidget(widget_fft, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        FilterFFT->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FilterFFT);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 813, 21));
        FilterFFT->setMenuBar(menubar);
        statusbar = new QStatusBar(FilterFFT);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FilterFFT->setStatusBar(statusbar);

        retranslateUi(FilterFFT);

        QMetaObject::connectSlotsByName(FilterFFT);
    } // setupUi

    void retranslateUi(QMainWindow *FilterFFT)
    {
        FilterFFT->setWindowTitle(QApplication::translate("FilterFFT", "MainWindow", 0));
        label_2->setText(QApplication::translate("FilterFFT", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \321\210\321\203\320\274\320\260:", 0));
        pushButton_saveTxt->setText(QApplication::translate("FilterFFT", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273...", 0));
        pushButton_close->setText(QApplication::translate("FilterFFT", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterFFT: public Ui_FilterFFT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERFFT_H
