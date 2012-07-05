#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->bSocket = new BasketSocket();
    this->connectionDialog = new ConnectionDialog(this);
    this->connectionDialog->show();

    connect(connectionDialog, SIGNAL(ok_clicked()), this, SLOT(connectToServer()));
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::resultsReceived()
{
}

void MainWindow::connectToServer()
{
    this->bSocket->connectTo(this->connectionDialog->ip, this->connectionDialog->port.toInt());
    this->connectionDialog->hide();
    delete this->connectionDialog;
    this->connectionDialog = 0;
}

void MainWindow::on_guessPushButton_clicked()
{
    this->bSocket->sendMove(this->ui->handSelect->value(), this->ui->guessSelect->value());

}
