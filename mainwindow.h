#pragma once
#include "Card/Card.h"
#include <QMainWindow>

class ConnectingPage;
class MainController;

class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onConnected();
    void onDisconnected();
    void onConnectionProgress(float val);
    void onConnectionFinished();
    void onLoadingProgress(float val);
    void onLoadingFinished();
    void onCardsDelivered(std::vector<Card> cards);

private:
    void createMembers();
    void doLayout();
    void makeConnections();

    void init();

private:
    ConnectingPage *m_connectingPage;
    QStackedWidget *m_stackedWidget;

    MainController *m_controller = nullptr;
};
