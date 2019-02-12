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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;

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
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 231));
        label->setTextFormat(Qt::AutoText);
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/heart-monitor.png")));
        label->setScaledContents(true);
        label->setWordWrap(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 20, 201, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(260, 60, 211, 151));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setLineWrapMode(QTextEdit::NoWrap);
        about->setCentralWidget(centralwidget);

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QMainWindow *about)
    {
        about->setWindowTitle(QApplication::translate("about", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        pushButton->setText(QApplication::translate("about", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("about", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#00aa00;\">\320\241\320\270\321\201\321\202\320\265\320\274\320\260 \320\274\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263\320\260</span></p></body></html>", 0));
        textBrowser->setHtml(QApplication::translate("about", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\240\320\265\320\262\320\270\320\267\320\270\321\217 - 1.0</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320"
                        "\276\320\262\320\270\320\272\320\276\320\262 \320\241. \320\237. - <span style=\" font-family:'Verdana,sans-serif'; font-size:8pt; color:rgba(0,0,0,0.494118); background-color:#ffffff;\">n_serg7@mail.ru</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Verdana,sans-serif'; font-size:8pt; color:rgba(0,0,0,0.494118);\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
