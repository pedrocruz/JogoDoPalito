#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->bSocket = new BasketSocket();
    this->connectionDialog = new ConnectionDialog(this);

    connect(connectionDialog, SIGNAL(ok_clicked()), this, SLOT(connectToServer()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMove()
{
}

void MainWindow::resultsReceived()
{
}

void MainWindow::connectToServer()
{
    this->bSocket->connectTo(this->connectionDialog->ip, this->connectionDialog->port.toInt());
}
