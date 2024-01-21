#include "mainwindow.h"
#include "Controllers/MainController.h"
#include "Pages/ConnectingPage.h"

#include <QStackedWidget>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMembers();
    doLayout();
    makeConnections();

    init();

    m_controller->start();
}

MainWindow::~MainWindow()
{
}

void MainWindow::onConnected()
{
    m_connectingPage->setTect("Միացում");
    m_connectingPage->setPercent(0.01);
}

void MainWindow::onDisconnected()
{

}

void MainWindow::onConnectionProgress(float val)
{
    m_connectingPage->setPercent(val);
}

void MainWindow::onConnectionFinished()
{
    m_connectingPage->setTect("Բեռնում");
    m_connectingPage->setPercent(0.01);
}

void MainWindow::onLoadingProgress(float val)
{
    m_connectingPage->setPercent(val);
}

void MainWindow::onLoadingFinished()
{

}

void MainWindow::onCardsDelivered(std::vector<Card> cards)
{
    qDebug() << __FUNCTION__ << Card::toString(cards);
}

void MainWindow::createMembers()
{
    m_connectingPage = new ConnectingPage;
    m_stackedWidget = new QStackedWidget;
    m_stackedWidget->setMinimumSize(QSize(500, 400));

    m_controller = new MainController(this);
}

void MainWindow::doLayout()
{
    this->setCentralWidget(m_stackedWidget);
    m_stackedWidget->addWidget(m_connectingPage);
}

void MainWindow::makeConnections()
{
    connect(m_controller, &MainController::connected, this, &MainWindow::onConnected);
    connect(m_controller, &MainController::disconnected, this, &MainWindow::onDisconnected);
    connect(m_controller, &MainController::connectionProgress, this, &MainWindow::onConnectionProgress);
    connect(m_controller, &MainController::connectionFinished, this, &MainWindow::onConnectionFinished);
    connect(m_controller, &MainController::loadingProgress, this, &MainWindow::onLoadingProgress);
    connect(m_controller, &MainController::loadingFinished, this, &MainWindow::onLoadingFinished);
    connect(m_controller, &MainController::cardsDelivered, this, &MainWindow::onCardsDelivered);
}

void MainWindow::init()
{
    m_stackedWidget->setCurrentWidget(m_connectingPage);
}

