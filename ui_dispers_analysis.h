/********************************************************************************
** Form generated from reading UI file 'dispers_analysis.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPERS_ANALYSIS_H
#define UI_DISPERS_ANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dispers_analysis
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_1;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QListWidget *listGr;
    QTableView *tableResult;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_2;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableDispers;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *SpinAlpha;
    QPushButton *pushButton_Calculate;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QLabel *lab_warning;
    QLabel *lab_opis;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dispers_analysis)
    {
        if (dispers_analysis->objectName().isEmpty())
            dispers_analysis->setObjectName(QStringLiteral("dispers_analysis"));
        dispers_analysis->resize(700, 490);
        dispers_analysis->setMinimumSize(QSize(700, 490));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/set.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dispers_analysis->setWindowIcon(icon);
        centralwidget = new QWidget(dispers_analysis);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lab_1 = new QLabel(centralwidget);
        lab_1->setObjectName(QStringLiteral("lab_1"));
        QFont font;
        font.setPointSize(10);
        lab_1->setFont(font);

        horizontalLayout_2->addWidget(lab_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listGr = new QListWidget(centralwidget);
        listGr->setObjectName(QStringLiteral("listGr"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listGr->sizePolicy().hasHeightForWidth());
        listGr->setSizePolicy(sizePolicy);
        listGr->setMinimumSize(QSize(130, 0));
        listGr->setMaximumSize(QSize(250, 260));
        listGr->setAlternatingRowColors(true);
        listGr->setSelectionMode(QAbstractItemView::MultiSelection);

        horizontalLayout->addWidget(listGr);

        tableResult = new QTableView(centralwidget);
        tableResult->setObjectName(QStringLiteral("tableResult"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableResult->sizePolicy().hasHeightForWidth());
        tableResult->setSizePolicy(sizePolicy1);
        tableResult->setMinimumSize(QSize(522, 0));
        tableResult->setMaximumSize(QSize(16777215, 260));
        tableResult->setFrameShape(QFrame::StyledPanel);
        tableResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableResult->setSelectionMode(QAbstractItemView::NoSelection);
        tableResult->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableResult);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lab_2 = new QLabel(centralwidget);
        lab_2->setObjectName(QStringLiteral("lab_2"));
        lab_2->setFont(font);

        horizontalLayout_3->addWidget(lab_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        tableDispers = new QTableView(centralwidget);
        tableDispers->setObjectName(QStringLiteral("tableDispers"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableDispers->sizePolicy().hasHeightForWidth());
        tableDispers->setSizePolicy(sizePolicy2);
        tableDispers->setMaximumSize(QSize(16777215, 87));
        tableDispers->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableDispers->setSelectionMode(QAbstractItemView::NoSelection);
        tableDispers->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableDispers);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        SpinAlpha = new QDoubleSpinBox(centralwidget);
        SpinAlpha->setObjectName(QStringLiteral("SpinAlpha"));
        SpinAlpha->setMinimum(0.01);
        SpinAlpha->setMaximum(0.99);
        SpinAlpha->setSingleStep(0.01);
        SpinAlpha->setValue(0.05);

        horizontalLayout_4->addWidget(SpinAlpha);

        pushButton_Calculate = new QPushButton(centralwidget);
        pushButton_Calculate->setObjectName(QStringLiteral("pushButton_Calculate"));
        pushButton_Calculate->setEnabled(false);
        sizePolicy2.setHeightForWidth(pushButton_Calculate->sizePolicy().hasHeightForWidth());
        pushButton_Calculate->setSizePolicy(sizePolicy2);
        pushButton_Calculate->setMinimumSize(QSize(144, 24));
        pushButton_Calculate->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-height: 20px;\n"
"     min-width: 140px;\n"
" }\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Calculate->setIcon(icon1);

        horizontalLayout_4->addWidget(pushButton_Calculate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        sizePolicy2.setHeightForWidth(pushButton_close->sizePolicy().hasHeightForWidth());
        pushButton_close->setSizePolicy(sizePolicy2);
        pushButton_close->setMinimumSize(QSize(88, 24));
        pushButton_close->setStyleSheet(QLatin1String(" QPushButton {\n"
"     border: 2px solid #8f8f91;\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-height: 20px; \n"
"     min-width: 84px;\n"
"}\n"
"QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/log-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon2);
        pushButton_close->setIconSize(QSize(18, 18));

        horizontalLayout_4->addWidget(pushButton_close);


        verticalLayout->addLayout(horizontalLayout_4);

        lab_warning = new QLabel(centralwidget);
        lab_warning->setObjectName(QStringLiteral("lab_warning"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        lab_warning->setFont(font1);
        lab_warning->setWordWrap(true);

        verticalLayout->addWidget(lab_warning);

        lab_opis = new QLabel(centralwidget);
        lab_opis->setObjectName(QStringLiteral("lab_opis"));
        sizePolicy.setHeightForWidth(lab_opis->sizePolicy().hasHeightForWidth());
        lab_opis->setSizePolicy(sizePolicy);
        lab_opis->setMinimumSize(QSize(0, 64));
        lab_opis->setFont(font);
        lab_opis->setFrameShape(QFrame::StyledPanel);
        lab_opis->setWordWrap(true);

        verticalLayout->addWidget(lab_opis);

        dispers_analysis->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(dispers_analysis);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        dispers_analysis->setStatusBar(statusbar);

        retranslateUi(dispers_analysis);

        QMetaObject::connectSlotsByName(dispers_analysis);
    } // setupUi

    void retranslateUi(QMainWindow *dispers_analysis)
    {
        dispers_analysis->setWindowTitle(QApplication::translate("dispers_analysis", "\320\236\320\264\320\275\320\276\321\204\320\260\320\272\321\202\320\276\321\200\320\275\321\213\320\271 \320\264\320\270\321\201\320\277\320\265\321\200\321\201\320\270\320\276\320\275\320\275\321\213\320\271 \320\260\320\275\320\260\320\273\320\270\320\267", 0));
        lab_1->setText(QString());
        lab_2->setText(QApplication::translate("dispers_analysis", "\320\224\320\270\321\201\320\277\320\265\321\200\321\201\320\270\320\276\320\275\320\275\321\213\320\271 \320\260\320\275\320\260\320\273\320\270\320\267:", 0));
        label->setText(QApplication::translate("dispers_analysis", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\267\320\275\320\260\321\207\320\270\320\274\320\276\321\201\321\202\320\270 (\320\260\320\273\321\214\321\204\320\260):", 0));
        pushButton_Calculate->setText(QApplication::translate("dispers_analysis", "  \320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", 0));
        pushButton_close->setText(QApplication::translate("dispers_analysis", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
        pushButton_close->setShortcut(QApplication::translate("dispers_analysis", "Ctrl+Q", 0));
        lab_warning->setText(QString());
        lab_opis->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dispers_analysis: public Ui_dispers_analysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPERS_ANALYSIS_H
