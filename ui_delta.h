/********************************************************************************
** Form generated from reading UI file 'delta.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELTA_H
#define UI_DELTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_delta
{
public:
    QGridLayout *gridLayout;
    QListWidget *list1;
    QListWidget *list2;
    QListWidget *list3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *delta)
    {
        if (delta->objectName().isEmpty())
            delta->setObjectName(QStringLiteral("delta"));
        delta->resize(519, 383);
        gridLayout = new QGridLayout(delta);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        list1 = new QListWidget(delta);
        list1->setObjectName(QStringLiteral("list1"));

        gridLayout->addWidget(list1, 1, 0, 1, 1);

        list2 = new QListWidget(delta);
        list2->setObjectName(QStringLiteral("list2"));

        gridLayout->addWidget(list2, 1, 1, 1, 1);

        list3 = new QListWidget(delta);
        list3->setObjectName(QStringLiteral("list3"));

        gridLayout->addWidget(list3, 1, 2, 1, 1);

        label = new QLabel(delta);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(delta);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(delta);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);


        retranslateUi(delta);

        QMetaObject::connectSlotsByName(delta);
    } // setupUi

    void retranslateUi(QWidget *delta)
    {
        delta->setWindowTitle(QApplication::translate("delta", "Form", 0));
        label->setText(QApplication::translate("delta", "\316\224t1 - \320\277\320\276 \321\200\320\265\320\260\320\272\321\206\320\270\320\270", 0));
        label_2->setText(QApplication::translate("delta", "\316\224t2 - \320\262\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        label_3->setText(QApplication::translate("delta", "\316\224R", 0));
    } // retranslateUi

};

namespace Ui {
    class delta: public Ui_delta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELTA_H
