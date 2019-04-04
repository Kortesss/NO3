/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(489, 265);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(about->sizePolicy().hasHeightForWidth());
        about->setSizePolicy(sizePolicy);
        about->setMinimumSize(QSize(489, 265));
        about->setMaximumSize(QSize(489, 265));
        about->setMouseTracking(false);
        about->setStyleSheet(QStringLiteral("background-color:white;"));
        about->setAnimated(false);
        centralwidget = new QWidget(about);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 230, 101, 23));
        pushButton->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));
        about->setCentralWidget(centralwidget);

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QMainWindow *about)
    {
        about->setWindowTitle(QApplication::translate("about", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        pushButton->setText(QApplication::translate("about", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
