#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_okButton_clicked()
{
    ip = this->ui->ipLineEdit->text();
    port = this->ui->portLineEdit->text();
    emit ok_clicked();
}



void ConnectionDialog::on_serverButton_clicked()
{
    emit serverBehaviorClicked();
}
