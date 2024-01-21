#pragma once

#include "Card/Card.h"

#include <QObject>
#include <QHostAddress>

class QTcpSocket;

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);
    void connectToHost(QHostAddress addr, quint16 port);
signals:
    void connected();
    void disconnected();
    void connectionProgress(float val);
    void connectionFinished();
    void loadingProgress(float val);
    void loadingFinished();
    void cardsDelivered(std::vector<Card> cards);
private slots:
    void onReadyRead();

private:
    void createMembers();
    void makeConnections();

private:
    QTcpSocket *m_tcpSocket = nullptr;
};
