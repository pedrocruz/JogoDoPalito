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
    connect(bSocket, SIGNAL(playersListChanged()), this, SLOT(drawPlayersList()));
    connect(bSocket, SIGNAL(indexChanged()), this, SLOT(setIndex()));
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
    bSocket->player->name = this->connectionDialog->name;
    this->bSocket->connectTo(this->connectionDialog->ip, this->connectionDialog->port.toInt());
    this->connectionDialog->hide();
    delete this->connectionDialog;
    this->connectionDialog = 0;
}

void MainWindow::on_guessPushButton_clicked()
{
    this->bSocket->sendMove(this->ui->handSelect->value(), this->ui->guessSelect->value());

}

void MainWindow::drawPlayersList()
{
    this->ui->playersTableWidget->setRowCount(this->bSocket->otherPlayers.size());
    for(int i = 0; i< this->bSocket->otherPlayers.size(); i++){
        this->ui->playersTableWidget->setItem(i,0, new QTableWidgetItem(bSocket->otherPlayers.at(i).name));
        this->ui->playersTableWidget->setItem(i,1, new QTableWidgetItem(QString::number(bSocket->otherPlayers.at(i).guess)));
        this->ui->playersTableWidget->setItem(i,2, new QTableWidgetItem(QString::number(bSocket->otherPlayers.at(i).hand)));
        this->ui->playersTableWidget->setItem(i,3, new QTableWidgetItem(QString::number(bSocket->otherPlayers.at(i).wins)));
    }
}

void MainWindow::setIndex()
{
    QString labelText = this->ui->indexLabel->text();
    labelText.append(" ");
    labelText.append(QString::number(this->bSocket->player->index));
    this->ui->indexLabel->setText(labelText);
}
