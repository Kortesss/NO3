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
    QVBoxLayout *verticalLayout;
    QCustomPlot *widgetCorr;
    QHBoxLayout *horizontalLayout;
    QLabel *koefCorr;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSlider *SliderTrend;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_save;
    QPushButton *pushButton_close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *correl_analysis)
    {
        if (correl_analysis->objectName().isEmpty())
            correl_analysis->setObjectName(QStringLiteral("correl_analysis"));
        correl_analysis->resize(763, 508);
        correl_analysis->setMinimumSize(QSize(0, 280));
        centralwidget = new QWidget(correl_analysis);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetCorr = new QCustomPlot(centralwidget);
        widgetCorr->setObjectName(QStringLiteral("widgetCorr"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetCorr->sizePolicy().hasHeightForWidth());
        widgetCorr->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widgetCorr);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        koefCorr = new QLabel(centralwidget);
        koefCorr->setObjectName(QStringLiteral("koefCorr"));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        koefCorr->setFont(font);

        horizontalLayout->addWidget(koefCorr);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label->setFont(font1);
        label->setCursor(QCursor(Qt::PointingHandCursor));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        SliderTrend = new QSlider(centralwidget);
        SliderTrend->setObjectName(QStringLiteral("SliderTrend"));
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

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setMinimumSize(QSize(144, 24));
        pushButton_save->setMaximumSize(QSize(16777215, 26));
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/heart-monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_save->setIcon(icon);
        pushButton_save->setAutoRepeat(false);
        pushButton_save->setAutoExclusive(false);
        pushButton_save->setAutoDefault(false);
        pushButton_save->setFlat(false);

        horizontalLayout->addWidget(pushButton_save);

        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(88, 24));
        pushButton_close->setMaximumSize(QSize(16777215, 26));
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/log-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon1);
        pushButton_close->setIconSize(QSize(18, 18));

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout->addLayout(horizontalLayout);

        correl_analysis->setCentralWidget(centralwidget);
        menubar = new QMenuBar(correl_analysis);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 763, 21));
        correl_analysis->setMenuBar(menubar);
        statusbar = new QStatusBar(correl_analysis);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        correl_analysis->setStatusBar(statusbar);

        retranslateUi(correl_analysis);

        pushButton_save->setDefault(false);


        QMetaObject::connectSlotsByName(correl_analysis);
    } // setupUi

    void retranslateUi(QMainWindow *correl_analysis)
    {
        correl_analysis->setWindowTitle(QApplication::translate("correl_analysis", "MainWindow", 0));
        koefCorr->setText(QApplication::translate("correl_analysis", "r = ", 0));
        label->setText(QApplication::translate("correl_analysis", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", 0));
#ifndef QT_NO_TOOLTIP
        SliderTrend->setToolTip(QApplication::translate("correl_analysis", "<html><head/><body><p>\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 <span style=\" font-weight:600;\">\320\273\320\270\320\275\320\270\321\216 \321\202\321\200\320\265\320\275\320\264\320\260</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_save->setText(QApplication::translate("correl_analysis", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0));
        pushButton_save->setShortcut(QApplication::translate("correl_analysis", "Ctrl+Shift+S", 0));
        pushButton_close->setText(QApplication::translate("correl_analysis", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
        pushButton_close->setShortcut(QApplication::translate("correl_analysis", "Ctrl+Q", 0));
    } // retranslateUi

};

namespace Ui {
    class correl_analysis: public Ui_correl_analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORREL_ANALYSIS_H
