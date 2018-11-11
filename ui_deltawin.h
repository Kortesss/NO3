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
    QListWidget *list1;
    QListWidget *list2;
    QListWidget *list3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
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
        list1 = new QListWidget(centralwidget);
        list1->setObjectName(QStringLiteral("list1"));

        gridLayout->addWidget(list1, 1, 0, 1, 1);

        list2 = new QListWidget(centralwidget);
        list2->setObjectName(QStringLiteral("list2"));

        gridLayout->addWidget(list2, 1, 1, 1, 1);

        list3 = new QListWidget(centralwidget);
        list3->setObjectName(QStringLiteral("list3"));

        gridLayout->addWidget(list3, 1, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

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
        label->setText(QApplication::translate("deltaWin", "\316\224t1 - \320\277\320\276 \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_2->setText(QApplication::translate("deltaWin", "\316\224t2 - \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        label_3->setText(QApplication::translate("deltaWin", "\316\224R", 0));
    } // retranslateUi

};

namespace Ui {
    class deltaWin: public Ui_deltaWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELTAWIN_H
