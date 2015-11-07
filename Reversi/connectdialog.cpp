#include "connectdialog.h"
#include "ui_connectdialog.h"
#include <Windows.h>

#include <QtDebug>

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

bool ConnectDialog::getIP(QString& ss)
{
    if (inet_addr(ui->lineEdit->text().toStdString().c_str())==INADDR_NONE)
        return false;
    ss = ui->lineEdit->text();
    return true;
}

int ConnectDialog::getPort()
{
    bool ok;
    int ret = ui->lineEdit_2->text().toInt(&ok);
    if (ok)
        return ret;
    else return -1;
}
