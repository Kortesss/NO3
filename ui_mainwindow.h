/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_9;
    QAction *action_10;
    QAction *action_8;
    QAction *action_11;
    QAction *action_12;
    QAction *action_delta;
    QAction *action_13;
    QAction *action_18;
    QAction *action_20;
    QAction *action_22;
    QAction *action_23;
    QAction *action_25;
    QAction *action_14;
    QAction *action_15;
    QAction *action_16;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_x1;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_x2;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox1;
    QListWidget *listWidget;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_4;
    QTextBrowser *textBrowser;
    QCustomPlot *widget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_7;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(578, 421);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_4->setCheckable(false);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_9->setCheckable(true);
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QStringLiteral("action_10"));
        action_10->setCheckable(true);
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QStringLiteral("action_11"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_11->setIcon(icon1);
        action_12 = new QAction(MainWindow);
        action_12->setObjectName(QStringLiteral("action_12"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/512px-Save_font_awesome.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_12->setIcon(icon2);
        action_delta = new QAction(MainWindow);
        action_delta->setObjectName(QStringLiteral("action_delta"));
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QStringLiteral("action_13"));
        action_18 = new QAction(MainWindow);
        action_18->setObjectName(QStringLiteral("action_18"));
        action_20 = new QAction(MainWindow);
        action_20->setObjectName(QStringLiteral("action_20"));
        action_22 = new QAction(MainWindow);
        action_22->setObjectName(QStringLiteral("action_22"));
        action_23 = new QAction(MainWindow);
        action_23->setObjectName(QStringLiteral("action_23"));
        action_25 = new QAction(MainWindow);
        action_25->setObjectName(QStringLiteral("action_25"));
        action_14 = new QAction(MainWindow);
        action_14->setObjectName(QStringLiteral("action_14"));
        action_15 = new QAction(MainWindow);
        action_15->setObjectName(QStringLiteral("action_15"));
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QStringLiteral("action_16"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 0, -1);
        doubleSpinBox_x1 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_x1->setObjectName(QStringLiteral("doubleSpinBox_x1"));
        doubleSpinBox_x1->setMinimumSize(QSize(0, 0));
        doubleSpinBox_x1->setMaximumSize(QSize(80, 20));
        doubleSpinBox_x1->setDecimals(3);
        doubleSpinBox_x1->setMaximum(9999.99);

        gridLayout->addWidget(doubleSpinBox_x1, 2, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        doubleSpinBox_x2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_x2->setObjectName(QStringLiteral("doubleSpinBox_x2"));
        doubleSpinBox_x2->setMaximumSize(QSize(80, 20));
        doubleSpinBox_x2->setDecimals(3);
        doubleSpinBox_x2->setMaximum(9999.99);

        gridLayout->addWidget(doubleSpinBox_x2, 4, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(20, 16777215));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        doubleSpinBox1 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox1->setObjectName(QStringLiteral("doubleSpinBox1"));
        doubleSpinBox1->setDecimals(2);
        doubleSpinBox1->setMaximum(99.99);
        doubleSpinBox1->setSingleStep(0.01);
        doubleSpinBox1->setValue(0.05);

        gridLayout->addWidget(doubleSpinBox1, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(116, 76));

        horizontalLayout_3->addWidget(listWidget);

        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setMaximumSize(QSize(60, 40));
        textBrowser_4->setSizeIncrement(QSize(0, 0));
        textBrowser_4->setBaseSize(QSize(0, 0));

        horizontalLayout_3->addWidget(textBrowser_4);

        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setMaximumSize(QSize(60, 40));

        horizontalLayout_3->addWidget(textBrowser_3);

        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setMinimumSize(QSize(20, 20));
        textBrowser_2->setMaximumSize(QSize(60, 40));

        horizontalLayout_3->addWidget(textBrowser_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_4->addWidget(textBrowser);

        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));

        horizontalLayout_4->addWidget(widget);


        verticalLayout_2->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menu_4);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menu_5);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_7 = new QMenu(menu_5);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_16);
        menu->addAction(action_delta);
        menu->addAction(action_12);
        menu->addAction(action_8);
        menu->addAction(action_11);
        menu_2->addAction(action_7);
        menu_2->addAction(menu_3->menuAction());
        menu_2->addAction(action_13);
        menu_3->addAction(action_9);
        menu_3->addAction(action_10);
        menu_4->addAction(menu_5->menuAction());
        menu_5->addAction(menu_6->menuAction());
        menu_5->addAction(menu_7->menuAction());
        menu_6->addAction(action_18);
        menu_6->addAction(action_20);
        menu_6->addSeparator();
        menu_6->addAction(action_22);
        menu_6->addAction(action_23);
        menu_6->addSeparator();
        menu_6->addAction(action_25);
        menu_7->addAction(action_14);
        menu_7->addAction(action_15);
        mainToolBar->addAction(action_2);
        mainToolBar->addAction(action_3);
        mainToolBar->addAction(action_16);
        mainToolBar->addAction(action_5);
        mainToolBar->addAction(action_delta);
        mainToolBar->addAction(action_8);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\244\320\260\320\271\320\273", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\260\321\217", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        action_4->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_5->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\276\320\271", 0));
#ifndef QT_NO_TOOLTIP
        action_5->setToolTip(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\276\320\271", 0));
#endif // QT_NO_TOOLTIP
        action_6->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", 0));
#ifndef QT_NO_TOOLTIP
        action_6->setToolTip(QApplication::translate("MainWindow", "\320\262\321\213\320\261\320\276\321\200 \321\204\320\270\320\273\321\214\321\202\321\200\320\260 \320\270\320\273\320\270 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
#endif // QT_NO_TOOLTIP
        action_7->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", 0));
#ifndef QT_NO_TOOLTIP
        action_7->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \321\215\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\321\213", 0));
#endif // QT_NO_TOOLTIP
        action_9->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", 0));
        action_10->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", 0));
        action_8->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\272\321\201\320\277\320\265\321\200\320\265\320\274\320\265\320\275\321\202", 0));
        action_11->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_12->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_delta->setText(QApplication::translate("MainWindow", "\316\224 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", 0));
        action_13->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_18->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\275\320\260\320\270\320\274\320\265\320\275\321\214\321\210\320\270\321\205 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262", 0));
        action_20->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_22->setText(QApplication::translate("MainWindow", "\320\224\321\200\321\203\320\263\320\276\320\271 \320\274\320\265\321\202\320\276\320\264", 0));
        action_23->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_25->setText(QApplication::translate("MainWindow", "...", 0));
        action_14->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\275\320\260\320\270\320\274\320\265\320\275\321\214\321\210\320\270\321\205 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262", 0));
        action_15->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_16->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272\320\270", 0));
        label_3->setText(QApplication::translate("MainWindow", "x2", 0));
        label->setText(QApplication::translate("MainWindow", "x1", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \321\215\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\320\276\320\262", 0));
        textBrowser_4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Derivative</p></body></html>", 0));
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Minimum</p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Maximum</p></body></html>", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\255\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\321\213", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262\321\200\321\203\321\207\320\275\321\203\321\216", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\220\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\321\217", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\321\217 \321\202\321\200\320\265\320\275\320\264\320\260", 0));
        menu_6->setTitle(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274\320\276\320\262", 0));
        menu_7->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274\320\276\320\262", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
