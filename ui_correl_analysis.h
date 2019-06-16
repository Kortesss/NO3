/********************************************************************************
** Form generated from reading UI file 'correl_analysis.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORREL_ANALYSIS_H
#define UI_CORREL_ANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_correl_analysis
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *widgetCorr;
    QVBoxLayout *verticalLayout;
    QLabel *koefCorr;
    QLabel *koefCovar;
    QLabel *label_koefDeteter;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_res;
    QLabel *label_covar;
    QLabel *label_deter;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *koefCorr_2;
    QSlider *SliderTrend;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_save;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *correl_analysis)
    {
        if (correl_analysis->objectName().isEmpty())
            correl_analysis->setObjectName(QStringLiteral("correl_analysis"));
        correl_analysis->resize(900, 515);
        correl_analysis->setMinimumSize(QSize(0, 280));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/set.ico"), QSize(), QIcon::Normal, QIcon::Off);
        correl_analysis->setWindowIcon(icon);
        centralwidget = new QWidget(correl_analysis);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widgetCorr = new QCustomPlot(centralwidget);
        widgetCorr->setObjectName(QStringLiteral("widgetCorr"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetCorr->sizePolicy().hasHeightForWidth());
        widgetCorr->setSizePolicy(sizePolicy);
        widgetCorr->setMinimumSize(QSize(400, 200));

        horizontalLayout_3->addWidget(widgetCorr);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        koefCorr = new QLabel(centralwidget);
        koefCorr->setObjectName(QStringLiteral("koefCorr"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(koefCorr->sizePolicy().hasHeightForWidth());
        koefCorr->setSizePolicy(sizePolicy1);
        koefCorr->setMinimumSize(QSize(300, 0));
        koefCorr->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        koefCorr->setFont(font);

        verticalLayout->addWidget(koefCorr);

        koefCovar = new QLabel(centralwidget);
        koefCovar->setObjectName(QStringLiteral("koefCovar"));
        sizePolicy1.setHeightForWidth(koefCovar->sizePolicy().hasHeightForWidth());
        koefCovar->setSizePolicy(sizePolicy1);
        koefCovar->setMinimumSize(QSize(300, 0));
        koefCovar->setMaximumSize(QSize(16777215, 16777215));
        koefCovar->setFont(font);

        verticalLayout->addWidget(koefCovar);

        label_koefDeteter = new QLabel(centralwidget);
        label_koefDeteter->setObjectName(QStringLiteral("label_koefDeteter"));
        QFont font1;
        font1.setPointSize(11);
        label_koefDeteter->setFont(font1);

        verticalLayout->addWidget(label_koefDeteter);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label_res = new QLabel(centralwidget);
        label_res->setObjectName(QStringLiteral("label_res"));
        label_res->setFont(font1);

        verticalLayout->addWidget(label_res);

        label_covar = new QLabel(centralwidget);
        label_covar->setObjectName(QStringLiteral("label_covar"));
        label_covar->setFont(font1);

        verticalLayout->addWidget(label_covar);

        label_deter = new QLabel(centralwidget);
        label_deter->setObjectName(QStringLiteral("label_deter"));
        label_deter->setFont(font1);

        verticalLayout->addWidget(label_deter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(179, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        koefCorr_2 = new QLabel(centralwidget);
        koefCorr_2->setObjectName(QStringLiteral("koefCorr_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(koefCorr_2->sizePolicy().hasHeightForWidth());
        koefCorr_2->setSizePolicy(sizePolicy2);
        koefCorr_2->setMaximumSize(QSize(60, 16777215));
        koefCorr_2->setFont(font);

        horizontalLayout->addWidget(koefCorr_2);

        SliderTrend = new QSlider(centralwidget);
        SliderTrend->setObjectName(QStringLiteral("SliderTrend"));
        sizePolicy1.setHeightForWidth(SliderTrend->sizePolicy().hasHeightForWidth());
        SliderTrend->setSizePolicy(sizePolicy1);
        SliderTrend->setMinimumSize(QSize(48, 24));
        SliderTrend->setMaximumSize(QSize(48, 24));
        SliderTrend->setCursor(QCursor(Qt::PointingHandCursor));
        SliderTrend->setStyleSheet(QLatin1String(".QSlider::groove:horizontal {\n"
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
        SliderTrend->setMaximum(1);
        SliderTrend->setPageStep(1);
        SliderTrend->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(SliderTrend);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        sizePolicy2.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy2);
        pushButton_save->setMinimumSize(QSize(144, 24));
        pushButton_save->setMaximumSize(QSize(150, 24));
        pushButton_save->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-height: 20px;\n"
"     min-width: 140px;\n"
" }\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/512px-Save_font_awesome.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_save->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_save);

        horizontalSpacer_2 = new QSpacerItem(53, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_close->sizePolicy().hasHeightForWidth());
        pushButton_close->setSizePolicy(sizePolicy3);
        pushButton_close->setMaximumSize(QSize(90, 24));
        pushButton_close->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-height: 20px; \n"
"     min-width: 84px;\n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));

        horizontalLayout_2->addWidget(pushButton_close);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        correl_analysis->setCentralWidget(centralwidget);
        menubar = new QMenuBar(correl_analysis);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 21));
        correl_analysis->setMenuBar(menubar);
        statusbar = new QStatusBar(correl_analysis);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        correl_analysis->setStatusBar(statusbar);

        retranslateUi(correl_analysis);

        QMetaObject::connectSlotsByName(correl_analysis);
    } // setupUi

    void retranslateUi(QMainWindow *correl_analysis)
    {
        correl_analysis->setWindowTitle(QApplication::translate("correl_analysis", "MainWindow", 0));
        koefCorr->setText(QApplication::translate("correl_analysis", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\272\320\276\321\200\321\200\320\265\320\273\321\217\321\206\320\270\320\270 = ", 0));
        koefCovar->setText(QApplication::translate("correl_analysis", "\320\232\320\276\320\262\320\260\321\200\320\270\320\260\321\206\320\270\321\217 =", 0));
        label_koefDeteter->setText(QApplication::translate("correl_analysis", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\264\320\265\321\202\320\265\321\200\320\274\320\270\320\275\320\260\321\206\320\270\320\270 = ", 0));
        label_res->setText(QApplication::translate("correl_analysis", "TextLabel", 0));
        label_covar->setText(QApplication::translate("correl_analysis", "TextLabel", 0));
        label_deter->setText(QApplication::translate("correl_analysis", "TextLabel", 0));
        koefCorr_2->setText(QApplication::translate("correl_analysis", "\320\237\321\200\321\217\320\274\320\260\321\217:", 0));
#ifndef QT_NO_TOOLTIP
        SliderTrend->setToolTip(QApplication::translate("correl_analysis", "<html><head/><body><p>\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 <span style=\" font-weight:600;\">\320\273\320\270\320\275\320\270\321\216 \321\202\321\200\320\265\320\275\320\264\320\260</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_save->setText(QApplication::translate("correl_analysis", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0));
        pushButton_close->setText(QApplication::translate("correl_analysis", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class correl_analysis: public Ui_correl_analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORREL_ANALYSIS_H
