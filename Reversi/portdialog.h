#ifndef PORTDIALOG_H
#define PORTDIALOG_H

#include <QDialog>

namespace Ui {
class PortDialog;
}

class PortDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PortDialog(QWidget *parent = 0);
    ~PortDialog();
    int getPort();
    bool getBlack();
private:
    Ui::PortDialog *ui;
};

#endif // PORTDIALOG_H
