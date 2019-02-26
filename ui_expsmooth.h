/********************************************************************************
** Form generated from reading UI file 'expsmooth.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPSMOOTH_H
#define UI_EXPSMOOTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_expSmooth
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget_exp;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *SpinP;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_saveTxt;
    QPushButton *ButtonCLose;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *expSmooth)
    {
        if (expSmooth->objectName().isEmpty())
            expSmooth->setObjectName(QStringLiteral("expSmooth"));
        expSmooth->resize(698, 442);
        centralwidget = new QWidget(expSmooth);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_exp = new QCustomPlot(centralwidget);
        widget_exp->setObjectName(QStringLiteral("widget_exp"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_exp->sizePolicy().hasHeightForWidth());
        widget_exp->setSizePolicy(sizePolicy);
        widget_exp->setMinimumSize(QSize(600, 300));

        verticalLayout->addWidget(widget_exp);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label);

        SpinP = new QDoubleSpinBox(centralwidget);
        SpinP->setObjectName(QStringLiteral("SpinP"));
        SpinP->setMaximumSize(QSize(50, 16777215));
        SpinP->setMaximum(1);
        SpinP->setSingleStep(0.01);
        SpinP->setValue(1);

        horizontalLayout->addWidget(SpinP);

        horizontalSpacer = new QSpacerItem(50, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_saveTxt = new QPushButton(centralwidget);
        Button_saveTxt->setObjectName(QStringLiteral("Button_saveTxt"));

        horizontalLayout->addWidget(Button_saveTxt);

        ButtonCLose = new QPushButton(centralwidget);
        ButtonCLose->setObjectName(QStringLiteral("ButtonCLose"));

        horizontalLayout->addWidget(ButtonCLose);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        expSmooth->setCentralWidget(centralwidget);
        menubar = new QMenuBar(expSmooth);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 698, 21));
        expSmooth->setMenuBar(menubar);
        statusbar = new QStatusBar(expSmooth);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        expSmooth->setStatusBar(statusbar);

        retranslateUi(expSmooth);

        QMetaObject::connectSlotsByName(expSmooth);
    } // setupUi

    void retranslateUi(QMainWindow *expSmooth)
    {
        expSmooth->setWindowTitle(QApplication::translate("expSmooth", "MainWindow", 0));
        label->setText(QApplication::translate("expSmooth", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \321\201\320\263\320\273\320\260\320\266\320\270\320\262\320\260\320\275\320\270\321\217 (0-1):", 0));
        Button_saveTxt->setText(QApplication::translate("expSmooth", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273...", 0));
        ButtonCLose->setText(QApplication::translate("expSmooth", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class expSmooth: public Ui_expSmooth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPSMOOTH_H
