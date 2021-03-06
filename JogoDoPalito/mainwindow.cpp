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
    connect(bSocket,SIGNAL(allPlayersReady()),this,SLOT(drawWinnersList()));
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
    QString name(this->ui->nameLabel->text());
    name.append(this->connectionDialog->name);
    this->ui->nameLabel->setText(name);
    bSocket->player->name = this->connectionDialog->name;
    this->bSocket->connectTo(this->connectionDialog->ip, this->connectionDialog->port.toInt());
    this->connectionDialog->hide();
    delete this->connectionDialog;
    this->connectionDialog = 0;
}

void MainWindow::on_guessPushButton_clicked()
{
    this->bSocket->sendMove(this->ui->handSelect->value(), this->ui->guessSelect->value());
    this->ui->guessPushButton->setEnabled(false);

}

void MainWindow::drawPlayersList()
{
    this->ui->playersTableWidget->clearContents();
    this->ui->playersTableWidget->setRowCount(this->bSocket->otherPlayers.size());
    for(int i = 0; i< this->bSocket->otherPlayers.size(); i++){
        this->ui->playersTableWidget->setItem(i,0, new QTableWidgetItem(bSocket->otherPlayers.at(i).name));
        this->ui->playersTableWidget->setItem(i,1, new QTableWidgetItem(QString::number(bSocket->otherPlayers.at(i).hand)));
        this->ui->playersTableWidget->setItem(i,2, new QTableWidgetItem(QString::number(bSocket->otherPlayers.at(i).guess)));
        this->ui->playersTableWidget->setItem(i,3, new QTableWidgetItem(QString::number(bSocket->otherPlayers.at(i).wins)));
    }
}



void MainWindow::drawWinnersList()
{
    this->drawPlayersList();
    QString winners(" ");

    if(bSocket->winnersIndexes.size()>0){
        winners= QString("Vencedores da rodada: ");
        for(int i = 0; i<bSocket->winnersIndexes.size();i++){
            if (i != 0){
                winners.append(", ");
            }

            winners.append(bSocket->otherPlayers.at(bSocket->winnersIndexes.at(i)).name);

        }
    }else{
        winners = QString("Empate");
    }
    this->ui->guessPushButton->setEnabled(true);
    this->ui->winnersLabel->setText(winners);
}
