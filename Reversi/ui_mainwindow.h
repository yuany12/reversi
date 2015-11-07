/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *chessLabel;
    QLabel *backLabel;
    QPushButton *pushButton_set;
    QPushButton *pushButton_con;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_los;
    QPushButton *pushButton_agn;
    QPushButton *pushButton_inp;
    QPushButton *pushButton_lea;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(880, 660);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chessLabel = new QLabel(centralWidget);
        chessLabel->setObjectName(QStringLiteral("chessLabel"));
        chessLabel->setGeometry(QRect(60, 40, 488, 494));
        backLabel = new QLabel(centralWidget);
        backLabel->setObjectName(QStringLiteral("backLabel"));
        backLabel->setGeometry(QRect(-10, -10, 951, 691));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backLabel->sizePolicy().hasHeightForWidth());
        backLabel->setSizePolicy(sizePolicy1);
        pushButton_set = new QPushButton(centralWidget);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));
        pushButton_set->setGeometry(QRect(60, 560, 91, 31));
        QPalette palette;
        QBrush brush(QColor(255, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        QBrush brush1(QColor(130, 130, 130, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_set->setPalette(palette);
        pushButton_set->setStyleSheet(QString::fromUtf8("color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";\n"
""));
        pushButton_con = new QPushButton(centralWidget);
        pushButton_con->setObjectName(QStringLiteral("pushButton_con"));
        pushButton_con->setGeometry(QRect(60, 600, 91, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_con->setPalette(palette1);
        pushButton_con->setStyleSheet(QString::fromUtf8("font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";\n"
"color: rgb(255, 170, 0);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(610, 40, 251, 81));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(610, 140, 251, 81));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(610, 240, 251, 361));
        pushButton_los = new QPushButton(centralWidget);
        pushButton_los->setObjectName(QStringLiteral("pushButton_los"));
        pushButton_los->setGeometry(QRect(210, 560, 91, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_los->setPalette(palette2);
        pushButton_los->setStyleSheet(QString::fromUtf8("color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";\n"
""));
        pushButton_agn = new QPushButton(centralWidget);
        pushButton_agn->setObjectName(QStringLiteral("pushButton_agn"));
        pushButton_agn->setGeometry(QRect(210, 600, 91, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_agn->setPalette(palette3);
        pushButton_agn->setStyleSheet(QString::fromUtf8("color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";\n"
""));
        pushButton_inp = new QPushButton(centralWidget);
        pushButton_inp->setObjectName(QStringLiteral("pushButton_inp"));
        pushButton_inp->setGeometry(QRect(350, 560, 91, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_inp->setPalette(palette4);
        pushButton_inp->setStyleSheet(QString::fromUtf8("color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";\n"
""));
        pushButton_lea = new QPushButton(centralWidget);
        pushButton_lea->setObjectName(QStringLiteral("pushButton_lea"));
        pushButton_lea->setGeometry(QRect(350, 600, 91, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_lea->setPalette(palette5);
        pushButton_lea->setStyleSheet(QString::fromUtf8("color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";\n"
""));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(610, 240, 251, 361));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(610, 599, 251, 31));
        MainWindow->setCentralWidget(centralWidget);
        backLabel->raise();
        chessLabel->raise();
        pushButton_set->raise();
        pushButton_con->raise();
        label_3->raise();
        label_4->raise();
        label->raise();
        pushButton_los->raise();
        pushButton_agn->raise();
        pushButton_inp->raise();
        pushButton_lea->raise();
        textBrowser->raise();
        lineEdit->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        chessLabel->setText(QString());
        backLabel->setText(QString());
        pushButton_set->setText(QApplication::translate("MainWindow", "\345\273\272 \347\253\213", 0));
        pushButton_con->setText(QApplication::translate("MainWindow", "\351\200\243 \346\216\245", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\271\346\226\271\344\277\241\346\201\257..", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("MainWindow", "\345\257\271\350\257\235/\346\217\220\347\244\272\346\241\206", 0));
        pushButton_los->setText(QApplication::translate("MainWindow", "\350\256\244 \350\276\223", 0));
        pushButton_agn->setText(QApplication::translate("MainWindow", "\345\206\215 \346\235\245", 0));
        pushButton_inp->setText(QApplication::translate("MainWindow", "\346\217\220 \347\244\272", 0));
        pushButton_lea->setText(QApplication::translate("MainWindow", "\347\246\273 \345\274\200", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
