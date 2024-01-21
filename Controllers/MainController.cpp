#include "MainController.h"
#include "Controllers/TcpClient.h"

#include <iostream>

MainController::MainController(QObject *parent)
    : QObject{parent}
{
    createMembers();
    makeConnections();
}

void MainController::start()
{
    std::cout << "Start" << std::endl;
    qDebug() << __FUNCTION__;
    QHostAddress hostAddress =  QHostAddress::LocalHost;
    quint16 port = 8888;
    m_client->connectToHost(hostAddress, port);
}

void MainController::createMembers()
{
    m_client = new TcpClient(this);
}

void MainController::makeConnections()
{
    connect(m_client, &TcpClient::connected, this, &MainController::connected);
    connect(m_client, &TcpClient::disconnected, this, &MainController::disconnected);
    connect(m_client, &TcpClient::connectionFinished, this, &MainController::connectionFinished);
    connect(m_client, &TcpClient::loadingFinished, this, &MainController::loadingFinished);
    connect(m_client, &TcpClient::connectionProgress, this, &MainController::connectionProgress);
    connect(m_client, &TcpClient::loadingProgress, this, &MainController::loadingProgress);
    connect(m_client, &TcpClient::cardsDelivered, this, &MainController::cardsDelivered);
}
