#include "basketsocket.h"

BasketSocket::BasketSocket(QWidget *parent)
{
    networkSession = 0;
    tcpSocket = 0;
    blockSize = 0;
    connected = false;
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
}

void BasketSocket::connectTo(QString ip, int port)
{
    tcpSocket->connectToHost(ip, port);
    this->connected = true;
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(messageReceived()));
}

void BasketSocket::parseMessage(QString message)
{
    if(message.contains(moveConst)){
        QStringList list = message.split(separator);
    }
}

void BasketSocket::sendMessage(QString messageToSend)
{
}

void BasketSocket::receiveResults()
{
}

void BasketSocket::sessionOpened()
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

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    QString inMessage;
    in >> inMessage;
    blockSize = 0;
    this->parseMessage(inMessage);
}

BasketSocket::~BasketSocket()
{
}
