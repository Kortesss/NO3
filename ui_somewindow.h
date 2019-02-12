/********************************************************************************
** Form generated from reading UI file 'somewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOMEWINDOW_H
#define UI_SOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_SomeWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_close;
    QPushButton *pushButton_save;
    QSpacerItem *horizontalSpacer;
    QCustomPlot *widget_dir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SomeWindow)
    {
        if (SomeWindow->objectName().isEmpty())
            SomeWindow->setObjectName(QStringLiteral("SomeWindow"));
        SomeWindow->resize(611, 410);
        centralwidget = new QWidget(SomeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
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

        gridLayout->addWidget(pushButton_close, 1, 2, 1, 1);

        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setMinimumSize(QSize(144, 24));
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
        icon.addFile(QStringLiteral(":/img/img/512px-Save_font_awesome.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_save->setIcon(icon);

        gridLayout->addWidget(pushButton_save, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget_dir = new QCustomPlot(centralwidget);
        widget_dir->setObjectName(QStringLiteral("widget_dir"));

        gridLayout->addWidget(widget_dir, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);

        SomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SomeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 611, 21));
        SomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SomeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SomeWindow->setStatusBar(statusbar);

        retranslateUi(SomeWindow);

        QMetaObject::connectSlotsByName(SomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SomeWindow)
    {
        SomeWindow->setWindowTitle(QApplication::translate("SomeWindow", "MainWindow", 0));
        pushButton_close->setText(QApplication::translate("SomeWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
        pushButton_save->setText(QApplication::translate("SomeWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0));
    } // retranslateUi

};

namespace Ui {
    class SomeWindow: public Ui_SomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOMEWINDOW_H
