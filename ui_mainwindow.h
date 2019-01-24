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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
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
    QAction *action_6;
    QAction *action_exit;
    QAction *action_12;
    QAction *action_16;
    QAction *action_21;
    QAction *actionD;
    QAction *action_24;
    QAction *action_26;
    QAction *action_7;
    QAction *action_9;
    QAction *action_10;
    QAction *action_13;
    QAction *action_17;
    QAction *action_19;
    QAction *action_4;
    QAction *action_5;
    QAction *action_manual;
    QAction *action_about;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QDoubleSpinBox *spinLevel;
    QLabel *label_3;
    QCheckBox *checkMin;
    QDoubleSpinBox *doubleSpinBox_x2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_x1;
    QLabel *label;
    QCheckBox *checkMax;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox1;
    QTextBrowser *BrowserTime;
    QListWidget *listWidget;
    QGridLayout *gridLayout_3;
    QTextBrowser *Browser_Min;
    QTextBrowser *Browser_Derivative;
    QTextBrowser *Browser_Max;
    QGridLayout *gridLayout_2;
    QCustomPlot *widget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser_Y;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser_X;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_3;
    QMenu *menu_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(617, 499);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon1);
        action_12 = new QAction(MainWindow);
        action_12->setObjectName(QStringLiteral("action_12"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/512px-Save_font_awesome.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_12->setIcon(icon2);
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QStringLiteral("action_16"));
        action_21 = new QAction(MainWindow);
        action_21->setObjectName(QStringLiteral("action_21"));
        actionD = new QAction(MainWindow);
        actionD->setObjectName(QStringLiteral("actionD"));
        action_24 = new QAction(MainWindow);
        action_24->setObjectName(QStringLiteral("action_24"));
        action_26 = new QAction(MainWindow);
        action_26->setObjectName(QStringLiteral("action_26"));
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_9->setCheckable(true);
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QStringLiteral("action_10"));
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QStringLiteral("action_13"));
        action_17 = new QAction(MainWindow);
        action_17->setObjectName(QStringLiteral("action_17"));
        action_19 = new QAction(MainWindow);
        action_19->setObjectName(QStringLiteral("action_19"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_4->setCheckable(false);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_manual = new QAction(MainWindow);
        action_manual->setObjectName(QStringLiteral("action_manual"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 0, -1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(153, 16777215));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        spinLevel = new QDoubleSpinBox(centralWidget);
        spinLevel->setObjectName(QStringLiteral("spinLevel"));
        spinLevel->setDecimals(1);
        spinLevel->setValue(1);

        gridLayout->addWidget(spinLevel, 1, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(153, 16777215));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        checkMin = new QCheckBox(centralWidget);
        checkMin->setObjectName(QStringLiteral("checkMin"));
        checkMin->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkMin, 6, 0, 1, 1);

        doubleSpinBox_x2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_x2->setObjectName(QStringLiteral("doubleSpinBox_x2"));
        doubleSpinBox_x2->setMaximumSize(QSize(80, 20));
        doubleSpinBox_x2->setDecimals(3);
        doubleSpinBox_x2->setMaximum(9999.99);

        gridLayout->addWidget(doubleSpinBox_x2, 5, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(153, 16777215));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        doubleSpinBox_x1 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_x1->setObjectName(QStringLiteral("doubleSpinBox_x1"));
        doubleSpinBox_x1->setMinimumSize(QSize(0, 0));
        doubleSpinBox_x1->setMaximumSize(QSize(80, 20));
        doubleSpinBox_x1->setDecimals(3);
        doubleSpinBox_x1->setMaximum(9999.99);

        gridLayout->addWidget(doubleSpinBox_x1, 3, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(153, 16777215));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        checkMax = new QCheckBox(centralWidget);
        checkMax->setObjectName(QStringLiteral("checkMax"));

        gridLayout->addWidget(checkMax, 6, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(153, 16777215));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBox1 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox1->setObjectName(QStringLiteral("doubleSpinBox1"));
        doubleSpinBox1->setFocusPolicy(Qt::WheelFocus);
        doubleSpinBox1->setDecimals(2);
        doubleSpinBox1->setMaximum(99.99);
        doubleSpinBox1->setSingleStep(0.01);
        doubleSpinBox1->setValue(0.05);

        gridLayout->addWidget(doubleSpinBox1, 0, 1, 1, 1);

        BrowserTime = new QTextBrowser(centralWidget);
        BrowserTime->setObjectName(QStringLiteral("BrowserTime"));
        BrowserTime->setMaximumSize(QSize(80, 20));
        BrowserTime->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(BrowserTime, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(130, 0));
        listWidget->setMaximumSize(QSize(140, 150));
        listWidget->setSortingEnabled(false);

        horizontalLayout->addWidget(listWidget);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Browser_Min = new QTextBrowser(centralWidget);
        Browser_Min->setObjectName(QStringLiteral("Browser_Min"));
        Browser_Min->setMaximumSize(QSize(113, 40));

        gridLayout_3->addWidget(Browser_Min, 1, 0, 1, 1);

        Browser_Derivative = new QTextBrowser(centralWidget);
        Browser_Derivative->setObjectName(QStringLiteral("Browser_Derivative"));
        Browser_Derivative->setMaximumSize(QSize(113, 40));
        Browser_Derivative->setSizeIncrement(QSize(0, 0));
        Browser_Derivative->setBaseSize(QSize(0, 0));

        gridLayout_3->addWidget(Browser_Derivative, 0, 0, 1, 1);

        Browser_Max = new QTextBrowser(centralWidget);
        Browser_Max->setObjectName(QStringLiteral("Browser_Max"));
        Browser_Max->setMinimumSize(QSize(20, 20));
        Browser_Max->setMaximumSize(QSize(113, 40));

        gridLayout_3->addWidget(Browser_Max, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 230));

        gridLayout_2->addWidget(widget, 0, 1, 2, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(150, 16777215));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        textBrowser_Y = new QTextBrowser(groupBox_2);
        textBrowser_Y->setObjectName(QStringLiteral("textBrowser_Y"));

        verticalLayout_4->addWidget(textBrowser_Y);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(150, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textBrowser_X = new QTextBrowser(groupBox);
        textBrowser_X->setObjectName(QStringLiteral("textBrowser_X"));

        verticalLayout_3->addWidget(textBrowser_X);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 617, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menu_4);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_3 = new QMenu(menu_5);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_6 = new QMenu(menuBar);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(doubleSpinBox1, spinLevel);
        QWidget::setTabOrder(spinLevel, BrowserTime);
        QWidget::setTabOrder(BrowserTime, doubleSpinBox_x1);
        QWidget::setTabOrder(doubleSpinBox_x1, doubleSpinBox_x2);
        QWidget::setTabOrder(doubleSpinBox_x2, checkMin);
        QWidget::setTabOrder(checkMin, checkMax);
        QWidget::setTabOrder(checkMax, listWidget);
        QWidget::setTabOrder(listWidget, Browser_Derivative);
        QWidget::setTabOrder(Browser_Derivative, Browser_Min);
        QWidget::setTabOrder(Browser_Min, Browser_Max);
        QWidget::setTabOrder(Browser_Max, textBrowser_X);
        QWidget::setTabOrder(textBrowser_X, textBrowser_Y);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_6->menuAction());
        menu->addAction(action);
        menu->addAction(action_16);
        menu->addAction(action_5);
        menu->addAction(action_12);
        menu->addAction(action_exit);
        menu_2->addAction(action_10);
        menu_2->addAction(action_9);
        menu_2->addAction(action_7);
        menu_2->addAction(action_13);
        menu_2->addAction(action_21);
        menu_4->addAction(menu_5->menuAction());
        menu_4->addAction(actionD);
        menu_5->addAction(menu_3->menuAction());
        menu_3->addAction(action_17);
        menu_3->addAction(action_19);
        menu_6->addAction(action_manual);
        menu_6->addAction(action_about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263\320\260", 0));
        action->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        action->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\260\321\217", 0));
        action_3->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        action_6->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", 0));
#ifndef QT_NO_TOOLTIP
        action_6->setToolTip(QApplication::translate("MainWindow", "\320\262\321\213\320\261\320\276\321\200 \321\204\320\270\320\273\321\214\321\202\321\200\320\260 \320\270\320\273\320\270 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0));
#endif // QT_NO_TOOLTIP
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        action_12->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_12->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_16->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\321\213", 0));
        action_21->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        actionD->setText(QApplication::translate("MainWindow", "\316\224 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", 0));
        action_24->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260", 0));
        action_26->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260", 0));
        action_7->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\320\270 \321\215\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\320\276\320\262", 0));
        action_9->setText(QApplication::translate("MainWindow", "\320\240\321\203\321\207\320\275\320\260\321\217 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0));
        action_10->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\277\320\276\320\270\321\201\320\272", 0));
        action_13->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        action_17->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", 0));
        action_19->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_4->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_5->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_5->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        action_manual->setText(QApplication::translate("MainWindow", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        action_manual->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        action_about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\276\320\274 %", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", 0));
        checkMin->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \321\215\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\320\276\320\262", 0));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", 0));
        checkMax->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\320\276\320\263 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \321\202\321\200\320\265\320\275\320\264\320\260, %", 0));
        Browser_Min->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\234\320\270\320\275. X: </p></body></html>", 0));
        Browser_Derivative->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\260\321\217: </p></body></html>", 0));
        Browser_Max->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\234\320\260\320\272\321\201. X: </p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 Y:", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 X:", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\255\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\321\213 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\260\320\275\320\260\320\273\320\270\320\267", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\321\217 \321\202\321\200\320\265\320\275\320\264\320\260", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\275\320\260\320\270\320\274\320\265\320\275\321\214\321\210\320\270\321\205 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262", 0));
        menu_6->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
