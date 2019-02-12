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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QCustomPlot *widget_idft;
    QCustomPlot *widget_dft;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSlider *Slider_level;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSlider *Slider_sens;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *sigma;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QSlider *SliderSpan;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_saveTxt;
    QPushButton *pushButton_close;
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
        widget_idft = new QCustomPlot(centralwidget);
        widget_idft->setObjectName(QStringLiteral("widget_idft"));
        widget_idft->setMinimumSize(QSize(0, 310));

        gridLayout->addWidget(widget_idft, 1, 0, 1, 1);

        widget_dft = new QCustomPlot(centralwidget);
        widget_dft->setObjectName(QStringLiteral("widget_dft"));
        widget_dft->setMinimumSize(QSize(600, 310));

        gridLayout->addWidget(widget_dft, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(185, 20));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        Slider_level = new QSlider(centralwidget);
        Slider_level->setObjectName(QStringLiteral("Slider_level"));
        Slider_level->setMinimumSize(QSize(185, 0));
        Slider_level->setMaximumSize(QSize(185, 16777215));
        Slider_level->setPageStep(1);
        Slider_level->setOrientation(Qt::Horizontal);
        Slider_level->setTickPosition(QSlider::NoTicks);
        Slider_level->setTickInterval(1);

        verticalLayout->addWidget(Slider_level);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(185, 20));
        label->setFont(font);

        verticalLayout->addWidget(label);

        Slider_sens = new QSlider(centralwidget);
        Slider_sens->setObjectName(QStringLiteral("Slider_sens"));
        Slider_sens->setMinimumSize(QSize(185, 0));
        Slider_sens->setMaximumSize(QSize(185, 16777215));
        Slider_sens->setMinimum(1);
        Slider_sens->setMaximum(8);
        Slider_sens->setSingleStep(1);
        Slider_sens->setPageStep(1);
        Slider_sens->setValue(1);
        Slider_sens->setSliderPosition(1);
        Slider_sens->setTracking(true);
        Slider_sens->setOrientation(Qt::Horizontal);
        Slider_sens->setTickPosition(QSlider::TicksBelow);
        Slider_sens->setTickInterval(1);

        verticalLayout->addWidget(Slider_sens);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(90, 15));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(90, 15));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        sigma = new QDoubleSpinBox(centralwidget);
        sigma->setObjectName(QStringLiteral("sigma"));
        sigma->setEnabled(false);
        sigma->setMinimumSize(QSize(50, 0));
        sigma->setMaximumSize(QSize(60, 16777215));
        sigma->setDecimals(2);
        sigma->setMinimum(0);
        sigma->setMaximum(1000);
        sigma->setValue(1);

        verticalLayout->addWidget(sigma);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setMinimumSize(QSize(185, 24));
        pushButton->setMaximumSize(QSize(185, 16777215));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        SliderSpan = new QSlider(centralwidget);
        SliderSpan->setObjectName(QStringLiteral("SliderSpan"));
        SliderSpan->setMinimumSize(QSize(0, 24));
        SliderSpan->setMaximumSize(QSize(48, 24));
        SliderSpan->setStyleSheet(QLatin1String(".QSlider::groove:horizontal {\n"
"    height: 24px; \n"
"    background:#696969; \n"
"    border-radius: 8px;\n"
"    padding:-4px 7px;\n"
"} \n"
"\n"
".QSlider::handle:horizontal {\n"
"    background: #d5d5d5; \n"
"    width: 22px; \n"
"    margin: 0px -7px; \n"
"    border-radius: 11px;\n"
"} "));
        SliderSpan->setMaximum(1);
        SliderSpan->setPageStep(1);
        SliderSpan->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(SliderSpan);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(135, 16777215));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);

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
        label->setText(QApplication::translate("FilterFFT", "\320\247\321\203\320\262\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214:", 0));
        label_3->setText(QApplication::translate("FilterFFT", "\320\235\320\276\321\200\320\274.", 0));
        label_4->setText(QApplication::translate("FilterFFT", "\320\222\321\213\321\201.", 0));
        pushButton->setText(QApplication::translate("FilterFFT", "\320\241\320\272\320\276\320\273\321\214\320\267\321\217\321\211\320\260\321\217 \321\201\321\200\320\265\320\264\320\275\321\217\321\217", 0));
        label_5->setText(QApplication::translate("FilterFFT", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", 0));
        pushButton_saveTxt->setText(QApplication::translate("FilterFFT", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273...", 0));
        pushButton_close->setText(QApplication::translate("FilterFFT", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterFFT: public Ui_FilterFFT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERFFT_H
