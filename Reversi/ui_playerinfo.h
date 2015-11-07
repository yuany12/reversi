/********************************************************************************
** Form generated from reading UI file 'playerinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERINFO_H
#define UI_PLAYERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerInfo
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *PlayerInfo)
    {
        if (PlayerInfo->objectName().isEmpty())
            PlayerInfo->setObjectName(QStringLiteral("PlayerInfo"));
        PlayerInfo->resize(251, 81);
        label = new QLabel(PlayerInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 61, 61));
        label_2 = new QLabel(PlayerInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 20, 121, 16));
        label_2->setStyleSheet(QString::fromUtf8("Color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";"));
        label_3 = new QLabel(PlayerInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 50, 61, 16));
        label_3->setStyleSheet(QString::fromUtf8("Color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";"));
        label_4 = new QLabel(PlayerInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 50, 61, 16));
        label_4->setStyleSheet(QString::fromUtf8("Color:rgb(255, 170, 0);\n"
"font: 9pt \"\350\217\257\345\272\267\345\250\203\345\250\203\351\253\224(P)\";"));

        retranslateUi(PlayerInfo);

        QMetaObject::connectSlotsByName(PlayerInfo);
    } // setupUi

    void retranslateUi(QWidget *PlayerInfo)
    {
        PlayerInfo->setWindowTitle(QApplication::translate("PlayerInfo", "Form", 0));
        label->setText(QApplication::translate("PlayerInfo", "TextLabel", 0));
        label_2->setText(QApplication::translate("PlayerInfo", "TextLabel", 0));
        label_3->setText(QApplication::translate("PlayerInfo", "TextLabel", 0));
        label_4->setText(QApplication::translate("PlayerInfo", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class PlayerInfo: public Ui_PlayerInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERINFO_H
