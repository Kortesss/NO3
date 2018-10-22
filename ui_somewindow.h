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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_SomeWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *widget_dir;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SomeWindow)
    {
        if (SomeWindow->objectName().isEmpty())
            SomeWindow->setObjectName(QStringLiteral("SomeWindow"));
        SomeWindow->resize(610, 410);
        centralwidget = new QWidget(SomeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_dir = new QCustomPlot(centralwidget);
        widget_dir->setObjectName(QStringLiteral("widget_dir"));

        gridLayout->addWidget(widget_dir, 0, 0, 1, 1);

        SomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SomeWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 610, 21));
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
    } // retranslateUi

};

namespace Ui {
    class SomeWindow: public Ui_SomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOMEWINDOW_H
