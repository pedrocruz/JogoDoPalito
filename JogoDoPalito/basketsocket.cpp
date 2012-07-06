#include "basketsocket.h"

BasketSocket::BasketSocket(QWidget *parent)
{
    networkSession = 0;
    tcpSocket = 0;
    blockSize = 0;
    connected = false;
    this->player = new Player();
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        networkSession->open();
    }
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpSocket = new QTcpSocket(this);
}

void BasketSocket::sendMove(int hand, int guess)
{
    QString move(moveConst);
    move.append(separator);
    move.append(QString::number(this->player->index));
    move.append(separator);
    move.append(QString::number(hand));
    move.append(separator);
    move.append(QString::number(guess));
    this->sendMessage(move);
}

void BasketSocket::connectTo(QString ip, int port)
{

    tcpSocket->connectToHost(ip, port);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(sendName()));

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(messageReceived()));
    connect(tcpSocket, SIGNAL(disconnected()),tcpSocket, SLOT(deleteLater()));
}

void BasketSocket::parseMessage(QString message)
{
    QStringList list;
    Player p;
    if(message.contains(moveConst)){
        list = message.split(separator);
        for(int i=0; i<otherPlayers.size(); i++){
            p = this->otherPlayers.at(i);
            p.hand = list.at(1+(i*2)).toInt();
            p.guess = list.at(2+(i*2)).toInt();
            this->otherPlayers.replace(i,p);
        }
        emit playersListChanged();
    }else if(message.contains(indexConst)){
        std::cout<<__LINE__<<std::endl;
        list = message.split(separator);
        this->player->index = list.at(1).toInt();
        emit indexChanged();
    }else if(message.contains(playersConst)){
        list = message.split(separator);
        this->otherPlayers.clear();
        for(int i = 1; i<list.size(); i++){
            std::cout<<qPrintable(list.at(i))<<std::endl;
            this->otherPlayers.append(Player(list.at(i)));
        }
        emit playersListChanged();

    }
}

void BasketSocket::sendMessage(QString messageToSend)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out<< messageToSend;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    this->tcpSocket->write(block);
    this->tcpSocket->flush();
}

void BasketSocket::messageReceived()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }
    if (tcpSocket->bytesAvailable() < blockSize) return;
    QString inMessage;
    in >> inMessage;
    blockSize = 0;
    std::cout<< qPrintable(inMessage);
    this->parseMessage(inMessage);
}

void BasketSocket::sendName()
{
    this->connected = true;
    QString nameMessage(nameConst);
    nameMessage.append(this->player->name);
    this->sendMessage(nameMessage);

}

BasketSocket::~BasketSocket()
{
}
