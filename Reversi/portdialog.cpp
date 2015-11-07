#include "portdialog.h"
#include "ui_portdialog.h"

PortDialog::PortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortDialog)
{
    ui->setupUi(this);
}

PortDialog::~PortDialog()
{
    delete ui;
}

int PortDialog::getPort()
{
    bool ok;
    int ret = ui->lineEdit->text().toInt(&ok);
    if (ok)
        return ret;
    else return -1;
}

bool PortDialog::getBlack()
{
    return ui->radioButton->isChecked();
}
