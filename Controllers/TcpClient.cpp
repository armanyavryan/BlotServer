#include "TcpClient.h"
#include "SharedData.h"

#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include <iostream>

TcpClient::TcpClient(QObject *parent)
    : QObject{parent}
{
    createMembers();
    makeConnections();
}

void TcpClient::connectToHost(QHostAddress addr, quint16 port)
{
    m_tcpSocket->connectToHost(addr, port);
}

void TcpClient::onReadyRead()
{
    QByteArray datas = m_tcpSocket->readAll();
    if(datas.size() == 0 ||
        (datas.size() == 1 && datas.at(0) == '\n')){return;}
        bool ok;
    PacketType packetType = PacketType(datas.at(0));
    QString str = QString::fromLatin1(datas.mid(1, datas.length() - 1));

//    std::cout << datas.toHex(' ').toStdString() << std::endl;
    switch (packetType) {
    case PacketType::NCommands:
    {
        std::cout << __FUNCTION__ << " " << __LINE__ << " COMMAND: " << str.toStdString() << std::endl;
        if(str == NCommands::CONNECTED){
            emit connected();
        }
        else if(str == NCommands::DISCONNECTED){
            emit disconnected();
        }
        else if(str == NCommands::CONNETION_FINISHED){
            emit connectionFinished();
        }
        else if(str == NCommands::LOADING_FINISHED){
            emit loadingFinished();
        }
    }
    break;

    case PacketType::NFloatingValues:
    {
        datas = datas.remove(0, sizeof(quint8)); // packet type

        if(str.startsWith(NFloatingValues::CONNECTION_PROGRESS)){

            auto subTypeLength = (NFloatingValues::CONNECTION_PROGRESS).toLatin1().length();

            datas = datas.remove(0, (NFloatingValues::CONNECTION_PROGRESS).toLatin1().length()); // subtype
            float value = 0;
            memcpy(&value, (void*)datas.data(), sizeof(float));
//            std::cout << datas.toHex(' ').toStdString() << " " << value << std::endl;
            datas = datas.remove(0, 5);
            emit connectionProgress(value);
        }
        else if(str.startsWith(NFloatingValues::LOADING_PROGRESS)){
            auto dataFloat = datas.remove(0, (NFloatingValues::CONNECTION_PROGRESS).toLatin1().length()); // subtype
            float value= *reinterpret_cast<const float*>(dataFloat.data());
            datas = datas.remove(0, 5);
            emit loadingProgress(value);
        }
        else{
            std::cout << __FUNCTION__ << " " << __LINE__ << " parsing error" << std::endl;
            return;
        }
    }
    break;

    case PacketType::NCards:
    {
        datas = datas.remove(0, sizeof(quint8)); // packet type

        std::cout << __FUNCTION__ << " FLOAT VALUE: " << str.toStdString() << std::endl;
        if(str.startsWith(NCards::DELIVER_8_CARDS)){

            auto subTypeLength = (NCards::DELIVER_8_CARDS).toLatin1().length();
            datas = datas.remove(0, (NFloatingValues::CONNECTION_PROGRESS).toLatin1().length()); // subtype

            std::vector<Card> cards;
            for (int i = 0; i < 8*2; ++i) {
                quint8 suit =  datas.at(0);
                datas.remove(0, sizeof(quint8)); // packet type
                quint8 rank = datas.at(0);
                datas.remove(0, sizeof(quint8)); // packet type

                CardSuits c_suit = CardSuits(suit);
                CardRanks c_rank = CardRanks(rank);

                Card card(c_suit, c_rank);
                cards.push_back(card);
                std::cout << Card::toString(card).toStdString() << std::endl;
            }
            emit cardsDelivered(cards);
        }
        else{
            std::cout << __FUNCTION__ << " Unsupported packet " << str.toStdString() << std::endl;
            return;
        }
    }
    break;
    default:
        break;
            std::cout << __FUNCTION__ << " Undefined Packet Type " << str.toStdString() << std::endl;
//    default:
//        str = QString::fromLatin1(datas);
//        std::cout << __FUNCTION__ << " Undefined Packet Type " << str.toStdString() << std::endl;
//        break;
    }

//    if(datas.size() != 0){
//        onReadyRead();
//    }

}

void TcpClient::createMembers()
{
    m_tcpSocket = new QTcpSocket;
}

void TcpClient::makeConnections()
{
    connect(m_tcpSocket, &QTcpSocket::connected,    this, &TcpClient::connected);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &TcpClient::disconnected);
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
}
