#pragma once

#include "Card/Card.h"

#include <QObject>

class TcpClient;

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    void start();

signals:
    void connected();
    void disconnected();
    void connectionProgress(float val);
    void connectionFinished();
    void loadingProgress(float val);
    void loadingFinished();
    void cardsDelivered(std::vector<Card> cards);

private:
    void createMembers();
    void makeConnections();

private:
    TcpClient *m_client = nullptr;
};
