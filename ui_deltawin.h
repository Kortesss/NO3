/********************************************************************************
** Form generated from reading UI file 'deltawin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELTAWIN_H
#define UI_DELTAWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deltaWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListWidget *list2;
    QListWidget *list1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QListWidget *listV1;
    QLabel *label_5;
    QLabel *label_6;
    QListWidget *listV2;
    QListWidget *listR2;
    QLabel *label_4;
    QListWidget *listR1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deltaWin)
    {
        if (deltaWin->objectName().isEmpty())
            deltaWin->setObjectName(QStringLiteral("deltaWin"));
        deltaWin->resize(490, 463);
        centralwidget = new QWidget(deltaWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        list2 = new QListWidget(centralwidget);
        list2->setObjectName(QStringLiteral("list2"));

        gridLayout->addWidget(list2, 1, 1, 3, 1);

        list1 = new QListWidget(centralwidget);
        list1->setObjectName(QStringLiteral("list1"));

        gridLayout->addWidget(list1, 1, 0, 3, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listV1 = new QListWidget(centralwidget);
        listV1->setObjectName(QStringLiteral("listV1"));

        gridLayout->addWidget(listV1, 5, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        listV2 = new QListWidget(centralwidget);
        listV2->setObjectName(QStringLiteral("listV2"));

        gridLayout->addWidget(listV2, 5, 1, 1, 1);

        listR2 = new QListWidget(centralwidget);
        listR2->setObjectName(QStringLiteral("listR2"));

        gridLayout->addWidget(listR2, 5, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 4, 2, 1, 1);

        listR1 = new QListWidget(centralwidget);
        listR1->setObjectName(QStringLiteral("listR1"));

        gridLayout->addWidget(listR1, 1, 2, 3, 1);

        deltaWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(deltaWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 490, 21));
        deltaWin->setMenuBar(menubar);
        statusbar = new QStatusBar(deltaWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        deltaWin->setStatusBar(statusbar);

        retranslateUi(deltaWin);

        QMetaObject::connectSlotsByName(deltaWin);
    } // setupUi

    void retranslateUi(QMainWindow *deltaWin)
    {
        deltaWin->setWindowTitle(QApplication::translate("deltaWin", "MainWindow", 0));
        label_2->setText(QApplication::translate("deltaWin", "\316\224t2 - \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        label_3->setText(QApplication::translate("deltaWin", "\316\224R \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label->setText(QApplication::translate("deltaWin", "\316\224t1 - \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_5->setText(QApplication::translate("deltaWin", "V1 - \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_6->setText(QApplication::translate("deltaWin", "V2 - \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        label_4->setText(QApplication::translate("deltaWin", "\316\224R \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class deltaWin: public Ui_deltaWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELTAWIN_H
