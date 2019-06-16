/********************************************************************************
** Form generated from reading UI file 'deltaSignal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELTASIGNAL_H
#define UI_DELTASIGNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deltaWin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *list1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *list2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *listR1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QListWidget *listV1;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QListWidget *listV2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QListWidget *listR2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *deltaWin)
    {
        if (deltaWin->objectName().isEmpty())
            deltaWin->setObjectName(QStringLiteral("deltaWin"));
        deltaWin->resize(490, 495);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deltaWin->sizePolicy().hasHeightForWidth());
        deltaWin->setSizePolicy(sizePolicy);
        deltaWin->setMinimumSize(QSize(490, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/set.ico"), QSize(), QIcon::Normal, QIcon::Off);
        deltaWin->setWindowIcon(icon);
        centralwidget = new QWidget(deltaWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        list1 = new QListWidget(centralwidget);
        list1->setObjectName(QStringLiteral("list1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(list1->sizePolicy().hasHeightForWidth());
        list1->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(list1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        list2 = new QListWidget(centralwidget);
        list2->setObjectName(QStringLiteral("list2"));
        sizePolicy1.setHeightForWidth(list2->sizePolicy().hasHeightForWidth());
        list2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(list2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        listR1 = new QListWidget(centralwidget);
        listR1->setObjectName(QStringLiteral("listR1"));
        sizePolicy1.setHeightForWidth(listR1->sizePolicy().hasHeightForWidth());
        listR1->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(listR1);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        listV1 = new QListWidget(centralwidget);
        listV1->setObjectName(QStringLiteral("listV1"));

        verticalLayout_4->addWidget(listV1);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_6);

        listV2 = new QListWidget(centralwidget);
        listV2->setObjectName(QStringLiteral("listV2"));

        verticalLayout_5->addWidget(listV2);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_4);

        listR2 = new QListWidget(centralwidget);
        listR2->setObjectName(QStringLiteral("listR2"));

        verticalLayout_6->addWidget(listR2);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_2);

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
        label->setText(QApplication::translate("deltaWin", "\316\224t1 - \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_2->setText(QApplication::translate("deltaWin", "\316\224t2 - \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        label_3->setText(QApplication::translate("deltaWin", "\316\224R \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_5->setText(QApplication::translate("deltaWin", "V1 - \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_6->setText(QApplication::translate("deltaWin", "V2 - \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
        label_4->setText(QApplication::translate("deltaWin", "\316\224R \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class deltaWin: public Ui_deltaWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELTASIGNAL_H
