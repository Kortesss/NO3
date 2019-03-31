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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_OpenFile;
    QAction *action_GrFunc;
    QAction *action_exit;
    QAction *action_SaveImage;
    QAction *action_ClearGraph;
    QAction *actionD;
    QAction *delExtrem;
    QAction *manualExtrem;
    QAction *autoSearchSimple;
    QAction *action_BildMnk;
    QAction *action_DelMnk;
    QAction *action_DelGraph;
    QAction *action_manual;
    QAction *action_about;
    QAction *action_filter;
    QAction *startWork1;
    QAction *action_SaveDataGr;
    QAction *action_autoSearch2;
    QAction *action_Derivat;
    QAction *action_GrDerivative;
    QAction *action_Correl;
    QAction *startWork2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_1;
    QDoubleSpinBox *SpinLimit;
    QCheckBox *checkMax;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_13;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox1;
    QTextBrowser *BrowserTime;
    QDoubleSpinBox *Spin_x2;
    QDoubleSpinBox *spinLevel;
    QCheckBox *checkMin;
    QDoubleSpinBox *Spin_x1;
    QDoubleSpinBox *SpinTimeExp;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkExp;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QDoubleSpinBox *SpinExp;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkGolay;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_rect;
    QSlider *rectORtriangle;
    QLabel *label_triangle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QSpinBox *spinGolay;
    QGridLayout *gridLayout_3;
    QTextBrowser *Browser_Min;
    QListWidget *listWidget;
    QTextBrowser *Browser_stWork;
    QTextBrowser *Browser_Derivative;
    QTextBrowser *Browser_Max;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QSlider *SliderPointGr;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QSlider *SliderLegend;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSlider *SliderSpan;
    QGridLayout *gridLayout_5;
    QCustomPlot *widget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser_X;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *textBrowser_Y;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_3;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_8;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(993, 620);
        action_OpenFile = new QAction(MainWindow);
        action_OpenFile->setObjectName(QStringLiteral("action_OpenFile"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_OpenFile->setIcon(icon);
        action_GrFunc = new QAction(MainWindow);
        action_GrFunc->setObjectName(QStringLiteral("action_GrFunc"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon1);
        action_SaveImage = new QAction(MainWindow);
        action_SaveImage->setObjectName(QStringLiteral("action_SaveImage"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/Line-Chart-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveImage->setIcon(icon2);
        action_ClearGraph = new QAction(MainWindow);
        action_ClearGraph->setObjectName(QStringLiteral("action_ClearGraph"));
        actionD = new QAction(MainWindow);
        actionD->setObjectName(QStringLiteral("actionD"));
        delExtrem = new QAction(MainWindow);
        delExtrem->setObjectName(QStringLiteral("delExtrem"));
        manualExtrem = new QAction(MainWindow);
        manualExtrem->setObjectName(QStringLiteral("manualExtrem"));
        manualExtrem->setCheckable(true);
        autoSearchSimple = new QAction(MainWindow);
        autoSearchSimple->setObjectName(QStringLiteral("autoSearchSimple"));
        action_BildMnk = new QAction(MainWindow);
        action_BildMnk->setObjectName(QStringLiteral("action_BildMnk"));
        action_DelMnk = new QAction(MainWindow);
        action_DelMnk->setObjectName(QStringLiteral("action_DelMnk"));
        action_DelGraph = new QAction(MainWindow);
        action_DelGraph->setObjectName(QStringLiteral("action_DelGraph"));
        action_manual = new QAction(MainWindow);
        action_manual->setObjectName(QStringLiteral("action_manual"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_filter = new QAction(MainWindow);
        action_filter->setObjectName(QStringLiteral("action_filter"));
        startWork1 = new QAction(MainWindow);
        startWork1->setObjectName(QStringLiteral("startWork1"));
        action_SaveDataGr = new QAction(MainWindow);
        action_SaveDataGr->setObjectName(QStringLiteral("action_SaveDataGr"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/img/512px-Save_font_awesome.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveDataGr->setIcon(icon3);
        action_autoSearch2 = new QAction(MainWindow);
        action_autoSearch2->setObjectName(QStringLiteral("action_autoSearch2"));
        action_Derivat = new QAction(MainWindow);
        action_Derivat->setObjectName(QStringLiteral("action_Derivat"));
        action_GrDerivative = new QAction(MainWindow);
        action_GrDerivative->setObjectName(QStringLiteral("action_GrDerivative"));
        action_Correl = new QAction(MainWindow);
        action_Correl->setObjectName(QStringLiteral("action_Correl"));
        startWork2 = new QAction(MainWindow);
        startWork2->setObjectName(QStringLiteral("startWork2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        gridLayout_1 = new QGridLayout();
        gridLayout_1->setSpacing(6);
        gridLayout_1->setObjectName(QStringLiteral("gridLayout_1"));
        gridLayout_1->setContentsMargins(-1, -1, 0, -1);
        SpinLimit = new QDoubleSpinBox(centralWidget);
        SpinLimit->setObjectName(QStringLiteral("SpinLimit"));
        SpinLimit->setMaximumSize(QSize(16777215, 16777215));
        SpinLimit->setDecimals(3);
        SpinLimit->setMinimum(0);
        SpinLimit->setMaximum(1);
        SpinLimit->setSingleStep(0.01);
        SpinLimit->setValue(0.92);

        gridLayout_1->addWidget(SpinLimit, 0, 1, 1, 1);

        checkMax = new QCheckBox(centralWidget);
        checkMax->setObjectName(QStringLiteral("checkMax"));

        gridLayout_1->addWidget(checkMax, 8, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(153, 16777215));

        gridLayout_1->addWidget(label_5, 4, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(153, 16777215));

        gridLayout_1->addWidget(label_2, 2, 0, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(153, 16777215));

        gridLayout_1->addWidget(label_13, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(153, 16777215));

        gridLayout_1->addWidget(label, 5, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(153, 16777215));

        gridLayout_1->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(153, 16777215));

        gridLayout_1->addWidget(label_3, 7, 0, 1, 1);

        doubleSpinBox1 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox1->setObjectName(QStringLiteral("doubleSpinBox1"));
        doubleSpinBox1->setFocusPolicy(Qt::WheelFocus);
        doubleSpinBox1->setDecimals(3);
        doubleSpinBox1->setMaximum(300);
        doubleSpinBox1->setSingleStep(0.01);
        doubleSpinBox1->setValue(0);

        gridLayout_1->addWidget(doubleSpinBox1, 2, 1, 1, 1);

        BrowserTime = new QTextBrowser(centralWidget);
        BrowserTime->setObjectName(QStringLiteral("BrowserTime"));
        BrowserTime->setMaximumSize(QSize(80, 20));
        BrowserTime->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_1->addWidget(BrowserTime, 4, 1, 1, 1);

        Spin_x2 = new QDoubleSpinBox(centralWidget);
        Spin_x2->setObjectName(QStringLiteral("Spin_x2"));
        Spin_x2->setMaximumSize(QSize(80, 20));
        Spin_x2->setDecimals(4);
        Spin_x2->setMaximum(9999.99);

        gridLayout_1->addWidget(Spin_x2, 7, 1, 1, 1);

        spinLevel = new QDoubleSpinBox(centralWidget);
        spinLevel->setObjectName(QStringLiteral("spinLevel"));
        spinLevel->setDecimals(1);
        spinLevel->setValue(1);

        gridLayout_1->addWidget(spinLevel, 3, 1, 1, 1);

        checkMin = new QCheckBox(centralWidget);
        checkMin->setObjectName(QStringLiteral("checkMin"));
        checkMin->setLayoutDirection(Qt::RightToLeft);

        gridLayout_1->addWidget(checkMin, 8, 0, 1, 1);

        Spin_x1 = new QDoubleSpinBox(centralWidget);
        Spin_x1->setObjectName(QStringLiteral("Spin_x1"));
        Spin_x1->setMinimumSize(QSize(0, 0));
        Spin_x1->setMaximumSize(QSize(80, 20));
        Spin_x1->setDecimals(4);
        Spin_x1->setMaximum(9999.99);

        gridLayout_1->addWidget(Spin_x1, 5, 1, 1, 1);

        SpinTimeExp = new QDoubleSpinBox(centralWidget);
        SpinTimeExp->setObjectName(QStringLiteral("SpinTimeExp"));
        SpinTimeExp->setDecimals(4);

        gridLayout_1->addWidget(SpinTimeExp, 1, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_1->addWidget(label_7, 1, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(180, 82));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkExp = new QCheckBox(frame);
        checkExp->setObjectName(QStringLiteral("checkExp"));
        checkExp->setMaximumSize(QSize(120, 16777215));
        checkExp->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(checkExp);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(56, 16777215));

        horizontalLayout->addWidget(label_9);

        SpinExp = new QDoubleSpinBox(frame);
        SpinExp->setObjectName(QStringLiteral("SpinExp"));
        SpinExp->setEnabled(false);
        SpinExp->setMaximumSize(QSize(55, 16777215));
        SpinExp->setDecimals(2);
        SpinExp->setMaximum(1);
        SpinExp->setSingleStep(0.01);
        SpinExp->setValue(0.5);

        horizontalLayout->addWidget(SpinExp);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_7->addWidget(frame);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMaximumSize(QSize(180, 107));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_6 = new QVBoxLayout(frame_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        checkGolay = new QCheckBox(frame_2);
        checkGolay->setObjectName(QStringLiteral("checkGolay"));
        checkGolay->setMaximumSize(QSize(120, 16777215));

        verticalLayout_5->addWidget(checkGolay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_rect = new QLabel(frame_2);
        label_rect->setObjectName(QStringLiteral("label_rect"));
        label_rect->setMaximumSize(QSize(30, 16));
        label_rect->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(label_rect);

        rectORtriangle = new QSlider(frame_2);
        rectORtriangle->setObjectName(QStringLiteral("rectORtriangle"));
        rectORtriangle->setMaximumSize(QSize(32, 17));
        rectORtriangle->setMaximum(1);
        rectORtriangle->setSingleStep(1);
        rectORtriangle->setPageStep(1);
        rectORtriangle->setValue(0);
        rectORtriangle->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(rectORtriangle);

        label_triangle = new QLabel(frame_2);
        label_triangle->setObjectName(QStringLiteral("label_triangle"));
        label_triangle->setMaximumSize(QSize(19, 16));
        QFont font;
        font.setFamily(QStringLiteral("MS Gothic"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_triangle->setFont(font);
        label_triangle->setLayoutDirection(Qt::LeftToRight);
        label_triangle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_triangle);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(56, 16777215));

        horizontalLayout_3->addWidget(label_10);

        spinGolay = new QSpinBox(frame_2);
        spinGolay->setObjectName(QStringLiteral("spinGolay"));
        spinGolay->setEnabled(false);
        spinGolay->setMaximumSize(QSize(55, 16777215));
        spinGolay->setMinimum(1);
        spinGolay->setValue(1);
        spinGolay->setDisplayIntegerBase(10);

        horizontalLayout_3->addWidget(spinGolay);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addWidget(frame_2);


        horizontalLayout_7->addLayout(verticalLayout_7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Browser_Min = new QTextBrowser(centralWidget);
        Browser_Min->setObjectName(QStringLiteral("Browser_Min"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Browser_Min->sizePolicy().hasHeightForWidth());
        Browser_Min->setSizePolicy(sizePolicy1);
        Browser_Min->setMaximumSize(QSize(113, 38));

        gridLayout_3->addWidget(Browser_Min, 1, 1, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(130, 0));
        listWidget->setMaximumSize(QSize(140, 16777215));
        listWidget->setSortingEnabled(false);

        gridLayout_3->addWidget(listWidget, 0, 0, 4, 1);

        Browser_stWork = new QTextBrowser(centralWidget);
        Browser_stWork->setObjectName(QStringLiteral("Browser_stWork"));
        sizePolicy1.setHeightForWidth(Browser_stWork->sizePolicy().hasHeightForWidth());
        Browser_stWork->setSizePolicy(sizePolicy1);
        Browser_stWork->setMinimumSize(QSize(142, 0));
        Browser_stWork->setMaximumSize(QSize(144, 16777215));

        gridLayout_3->addWidget(Browser_stWork, 0, 2, 4, 1);

        Browser_Derivative = new QTextBrowser(centralWidget);
        Browser_Derivative->setObjectName(QStringLiteral("Browser_Derivative"));
        sizePolicy1.setHeightForWidth(Browser_Derivative->sizePolicy().hasHeightForWidth());
        Browser_Derivative->setSizePolicy(sizePolicy1);
        Browser_Derivative->setMinimumSize(QSize(106, 0));
        Browser_Derivative->setMaximumSize(QSize(113, 50));
        Browser_Derivative->setSizeIncrement(QSize(0, 0));
        Browser_Derivative->setBaseSize(QSize(0, 0));

        gridLayout_3->addWidget(Browser_Derivative, 0, 1, 1, 1);

        Browser_Max = new QTextBrowser(centralWidget);
        Browser_Max->setObjectName(QStringLiteral("Browser_Max"));
        sizePolicy1.setHeightForWidth(Browser_Max->sizePolicy().hasHeightForWidth());
        Browser_Max->setSizePolicy(sizePolicy1);
        Browser_Max->setMinimumSize(QSize(20, 20));
        Browser_Max->setMaximumSize(QSize(113, 38));

        gridLayout_3->addWidget(Browser_Max, 2, 1, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);
        label_12->setMinimumSize(QSize(103, 0));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_12);

        SliderPointGr = new QSlider(centralWidget);
        SliderPointGr->setObjectName(QStringLiteral("SliderPointGr"));
        sizePolicy1.setHeightForWidth(SliderPointGr->sizePolicy().hasHeightForWidth());
        SliderPointGr->setSizePolicy(sizePolicy1);
        SliderPointGr->setMinimumSize(QSize(48, 24));
        SliderPointGr->setMaximumSize(QSize(48, 24));
        SliderPointGr->setCursor(QCursor(Qt::PointingHandCursor));
        SliderPointGr->setStyleSheet(QLatin1String(".QSlider::groove:horizontal {\n"
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
        SliderPointGr->setMaximum(1);
        SliderPointGr->setPageStep(1);
        SliderPointGr->setValue(0);
        SliderPointGr->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(SliderPointGr);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(0, 80));

        gridLayout->addWidget(widget_2, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(103, 0));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_11);

        SliderLegend = new QSlider(centralWidget);
        SliderLegend->setObjectName(QStringLiteral("SliderLegend"));
        sizePolicy1.setHeightForWidth(SliderLegend->sizePolicy().hasHeightForWidth());
        SliderLegend->setSizePolicy(sizePolicy1);
        SliderLegend->setMinimumSize(QSize(48, 24));
        SliderLegend->setMaximumSize(QSize(48, 24));
        SliderLegend->setCursor(QCursor(Qt::PointingHandCursor));
        SliderLegend->setStyleSheet(QLatin1String(".QSlider::groove:horizontal {\n"
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
        SliderLegend->setMaximum(1);
        SliderLegend->setPageStep(1);
        SliderLegend->setValue(0);
        SliderLegend->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(SliderLegend);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(103, 0));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_6);

        SliderSpan = new QSlider(centralWidget);
        SliderSpan->setObjectName(QStringLiteral("SliderSpan"));
        sizePolicy1.setHeightForWidth(SliderSpan->sizePolicy().hasHeightForWidth());
        SliderSpan->setSizePolicy(sizePolicy1);
        SliderSpan->setMinimumSize(QSize(48, 24));
        SliderSpan->setMaximumSize(QSize(48, 24));
        SliderSpan->setCursor(QCursor(Qt::PointingHandCursor));
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
        SliderSpan->setValue(0);
        SliderSpan->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(SliderSpan);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout);


        verticalLayout_8->addLayout(horizontalLayout_7);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMouseTracking(true);

        gridLayout_5->addWidget(widget, 0, 1, 2, 1);

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


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

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


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);


        verticalLayout_8->addLayout(gridLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 993, 21));
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
        menu_7 = new QMenu(menuBar);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        menu_8 = new QMenu(menuBar);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(SpinLimit, doubleSpinBox1);
        QWidget::setTabOrder(doubleSpinBox1, spinLevel);
        QWidget::setTabOrder(spinLevel, BrowserTime);
        QWidget::setTabOrder(BrowserTime, Spin_x1);
        QWidget::setTabOrder(Spin_x1, Spin_x2);
        QWidget::setTabOrder(Spin_x2, checkMin);
        QWidget::setTabOrder(checkMin, checkMax);
        QWidget::setTabOrder(checkMax, checkExp);
        QWidget::setTabOrder(checkExp, SpinExp);
        QWidget::setTabOrder(SpinExp, checkGolay);
        QWidget::setTabOrder(checkGolay, rectORtriangle);
        QWidget::setTabOrder(rectORtriangle, spinGolay);
        QWidget::setTabOrder(spinGolay, listWidget);
        QWidget::setTabOrder(listWidget, Browser_Derivative);
        QWidget::setTabOrder(Browser_Derivative, Browser_Min);
        QWidget::setTabOrder(Browser_Min, Browser_Max);
        QWidget::setTabOrder(Browser_Max, Browser_stWork);
        QWidget::setTabOrder(Browser_stWork, SliderSpan);
        QWidget::setTabOrder(SliderSpan, SliderLegend);
        QWidget::setTabOrder(SliderLegend, SliderPointGr);
        QWidget::setTabOrder(SliderPointGr, textBrowser_X);
        QWidget::setTabOrder(textBrowser_X, textBrowser_Y);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_8->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_7->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_6->menuAction());
        menu->addAction(action_OpenFile);
        menu->addAction(action_ClearGraph);
        menu->addAction(action_DelGraph);
        menu->addAction(action_SaveImage);
        menu->addAction(action_SaveDataGr);
        menu->addAction(action_exit);
        menu_2->addAction(autoSearchSimple);
        menu_2->addAction(action_autoSearch2);
        menu_2->addAction(manualExtrem);
        menu_2->addAction(delExtrem);
        menu_4->addAction(menu_5->menuAction());
        menu_4->addAction(actionD);
        menu_4->addAction(action_filter);
        menu_4->addAction(action_Correl);
        menu_5->addAction(menu_3->menuAction());
        menu_3->addAction(action_BildMnk);
        menu_3->addAction(action_DelMnk);
        menu_6->addAction(action_manual);
        menu_6->addAction(action_about);
        menu_7->addAction(action_Derivat);
        menu_7->addAction(action_GrDerivative);
        menu_8->addAction(startWork1);
        menu_8->addAction(startWork2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263\320\260", 0));
        action_OpenFile->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", 0));
        action_OpenFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        action_GrFunc->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        action_SaveImage->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", 0));
        action_SaveImage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        action_ClearGraph->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\321\213", 0));
        actionD->setText(QApplication::translate("MainWindow", "\316\224 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", 0));
        delExtrem->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\320\270 \321\215\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\320\276\320\262", 0));
        manualExtrem->setText(QApplication::translate("MainWindow", "\320\240\321\203\321\207\320\275\320\260\321\217 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0));
        autoSearchSimple->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\277\320\276\320\270\321\201\320\272 (\320\277\321\200\320\276\321\201\321\202\320\276\320\271)", 0));
        action_BildMnk->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", 0));
        action_DelMnk->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        action_DelGraph->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0));
        action_DelGraph->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        action_manual->setText(QApplication::translate("MainWindow", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\321\202\320\262\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", 0));
        action_manual->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        action_about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        action_filter->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \321\201\320\270\320\263\320\275\320\260\320\273\320\260", 0));
        startWork1->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 1", 0));
        action_SaveDataGr->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", 0));
        action_SaveDataGr->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        action_autoSearch2->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\277\320\276\320\270\321\201\320\272 (\320\277\320\276\321\201\320\273\320\265 \320\275\320\260\321\207\320\260\320\273\320\260 \321\200\320\260\320\261. \321\200\320\265\320\266\320\270\320\274\320\260)", 0));
        action_Derivat->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        action_GrDerivative->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        action_Correl->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\200\321\200\320\265\320\273\321\217\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\260\320\275\320\260\320\273\320\270\320\267", 0));
        startWork2->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 2", 0));
        checkMax->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\276\320\274 %", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \321\215\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\320\276\320\262", 0));
        label_13->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265, R ", 0));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\320\276\320\263 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \321\202\321\200\320\265\320\275\320\264\320\260, %", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\207\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", 0));
        checkMin->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", 0));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\276\320\277\321\213\321\202\320\260 \342\211\210", 0));
        checkExp->setText(QApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\320\275\320\265\320\275\321\206\320\270\320\260\320\273\321\214\320\275\320\276\320\265\n"
"\321\201\320\263\320\273\320\260\320\266\320\270\320\262\320\260\320\275\320\270\320\265", 0));
        label_9->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204-\321\202, p", 0));
        checkGolay->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\273\320\260\320\266\320\270\320\262\320\260\320\275\320\270\320\265\n"
"\320\241\320\260\320\262\320\270\321\206\320\272\320\276\320\263\320\276-\320\223\320\260\320\273\320\265\321\217", 0));
        label_rect->setText(QString());
        label_triangle->setText(QApplication::translate("MainWindow", "\316\224", 0));
        label_10->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201, r", 0));
        Browser_Min->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\234\320\270\320\275. X: </p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        listWidget->setToolTip(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\263\321\200\320\260\321\204\320\270\320\272\320\276\320\262", 0));
#endif // QT_NO_TOOLTIP
        Browser_stWork->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\244\320\260\320\267\321\213 \320\275\320\260\321\207\320\260\320\273\320\260 \321\200\320\260\320\261\320\276\321\207\320\265\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260:</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        Browser_Derivative->setToolTip(QString());
#endif // QT_NO_TOOLTIP
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
        label_12->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\202\320\276\321\207\320\265\320\272:", 0));
#ifndef QT_NO_TOOLTIP
        SliderPointGr->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 <span style=\" font-weight:600;\">\320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271</span></p><p><br/></p><p>\320\225\321\201\320\273\320\270 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\274\320\265\321\210\320\260\320\265\321\202</p><p>\320\270\320\273\320\270 \320\275\320\265 \320\275\321\203\320\266\320\265\320\275 \320\277\321\200\320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\270 \320\263\321\200\320\260\321\204\320\270\320\272\320\260, </p><p>\320\265\320\263\320\276 \320\274\320\276\320\266\320\275\320\276 \321\201\320\272\321\200\321\213\321\202\321\214.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\263\320\265\320\275\320\264\320\260:", 0));
#ifndef QT_NO_TOOLTIP
        SliderLegend->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 <span style=\" font-weight:600;\">\320\273\320\265\320\263\320\265\320\275\320\264\321\203</span></p><p><br/></p><p>\320\225\321\201\320\273\320\270 \320\276\320\275\320\260 \320\267\320\260\320\272\321\200\321\213\320\262\320\260\320\265\321\202 \321\207\320\260\321\201\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272\320\260</p><p>\320\270\320\273\320\270 \320\275\320\265 \320\275\321\203\320\266\320\275\320\260 \320\277\321\200\320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\270 </p><p>\320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\263\321\200\320\260\321\204\320\270\320\272\320\260.</p><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271:", 0));
#ifndef QT_NO_TOOLTIP
        SliderSpan->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214/\321\201\320\272\321\200\321\213\321\202\321\214 <span style=\" font-weight:600;\">\320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271</span></p><p><br/></p><p>\320\225\321\201\320\273\320\270 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\274\320\265\321\210\320\260\320\265\321\202</p><p>\320\270\320\273\320\270 \320\275\320\265 \320\275\321\203\320\266\320\265\320\275 \320\277\321\200\320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\270 \320\263\321\200\320\260\321\204\320\270\320\272\320\260, </p><p>\320\265\320\263\320\276 \320\274\320\276\320\266\320\275\320\276 \321\201\320\272\321\200\321\213\321\202\321\214.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\276\321\201\320\270 \320\260\320\261\321\201\321\206\320\270\321\201\321\201:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\276\321\201\320\270 \320\276\321\200\320\264\320\270\320\275\320\260\321\202:", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\255\320\272\321\201\321\202\321\200\320\265\320\274\321\203\320\274\321\213 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\260\320\275\320\260\320\273\320\270\320\267", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\321\217 \321\202\321\200\320\265\320\275\320\264\320\260", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\275\320\260\320\270\320\274\320\265\320\275\321\214\321\210\320\270\321\205 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\276\320\262", 0));
        menu_6->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
        menu_7->setTitle(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0));
        menu_8->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276 \321\200\320\260\320\261. \321\200\320\265\320\266\320\270\320\274\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
