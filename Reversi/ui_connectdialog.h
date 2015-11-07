/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QStringLiteral("ConnectDialog"));
        ConnectDialog->resize(281, 143);
        horizontalLayoutWidget = new QWidget(ConnectDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 261, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(horizontalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(ConnectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "\350\277\236\346\216\245\347\216\251\345\256\266", 0));
        label->setText(QApplication::translate("ConnectDialog", "IP", 0));
        label_2->setText(QApplication::translate("ConnectDialog", "PORT", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
