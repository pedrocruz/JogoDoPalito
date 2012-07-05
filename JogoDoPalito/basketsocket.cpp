#include "basketsocket.h"

BasketSocket::BasketSocket()
{
    /*networkSession = 0;
    tcpSocket = 0;
    blockSize = 0;

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

        networkSession = new QNetworkSession(config);
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
    }*/


}

BasketSocket::~BasketSocket()
{
}


/*void BasketSocket::sendMove(int hand, int guess)
{
    if(this->connected){

    }
}*/

void BasketSocket::connectTo(QString ip, int port)
{
}

void BasketSocket::gotResults()
{
}

void BasketSocket::sendMessage(QString messageToSend)
{/*
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out<< messageToSend;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    this->tcpSocket->write(block);
    this->tcpSocket->flush();
*/}

void BasketSocket::receiveResults()
{
}

void BasketSocket::sessionOpened()
{
}
