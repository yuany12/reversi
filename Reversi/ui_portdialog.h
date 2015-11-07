/********************************************************************************
** Form generated from reading UI file 'portdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTDIALOG_H
#define UI_PORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PortDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PortDialog)
    {
        if (PortDialog->objectName().isEmpty())
            PortDialog->setObjectName(QStringLiteral("PortDialog"));
        PortDialog->resize(337, 145);
        horizontalLayoutWidget = new QWidget(PortDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 311, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(66);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 30, 89, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 30, 89, 16));

        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(horizontalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(PortDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PortDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PortDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PortDialog);
    } // setupUi

    void retranslateUi(QDialog *PortDialog)
    {
        PortDialog->setWindowTitle(QApplication::translate("PortDialog", "\346\226\260\345\273\272\346\270\270\346\210\217", 0));
        label->setText(QApplication::translate("PortDialog", "\350\257\267\350\276\223\345\205\245\344\275\240\350\246\201\345\273\272\347\253\213\347\232\204\347\253\257\345\217\243\345\217\267\357\274\232", 0));
        lineEdit->setText(QApplication::translate("PortDialog", "4000", 0));
        groupBox->setTitle(QApplication::translate("PortDialog", "\351\200\211\346\213\251\351\242\234\350\211\262", 0));
        radioButton->setText(QApplication::translate("PortDialog", "\351\273\221\346\226\271", 0));
        radioButton_2->setText(QApplication::translate("PortDialog", "\347\231\275\346\226\271", 0));
    } // retranslateUi

};

namespace Ui {
    class PortDialog: public Ui_PortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTDIALOG_H
