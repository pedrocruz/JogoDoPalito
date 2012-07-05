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
    move.append(this->player->index);
    move.append(separator);
    move.append(hand);
    move.append(separator);
    move.append(guess);
    this->sendMessage(move);
}

void BasketSocket::connectTo(QString ip, int port)
{

    tcpSocket->connectToHost(ip, port);

    this->connected = true;
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(messageReceived()));
    connect(tcpSocket, SIGNAL(disconnected()),tcpSocket, SLOT(deleteLater()));
}

void BasketSocket::parseMessage(QString message)
{
    QStringList list;
    if(message.contains(moveConst)){
        list = message.split(separator);
        for(int i=0; i<list.size()/2; i++){
            this->player->hand = list.at(1+(i*2)).toInt();
            this->player->guess = list.at(2+(i*2)).toInt();
        }
    }else if(message.contains(indexConst)){
        std::cout<<__LINE__<<std::endl;
        list = message.split(separator);
        this->player->index = list.at(1).toInt();
        std::cout<<"Index = "<<this->player->index<<std::endl;
        emit indexChanged();
    }else if(message.contains(playersConst)){
        list = message.split(separator);
        for(int i = 1; i<list.size(); i++){
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

void BasketSocket::receiveResults()
{
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

BasketSocket::~BasketSocket()
{
}
