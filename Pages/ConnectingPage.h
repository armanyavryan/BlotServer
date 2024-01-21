#pragma once
#include <QWidget>

class Loading;

class ConnectingPage : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectingPage(QWidget *parent = nullptr);

    void setTect(const QString& text);
    void setPercent(float val);

protected:
    virtual void paintEvent(QPaintEvent* e) override;
signals:

private:
    void createMembers();
    void doLayout();

private:
    Loading *m_loading;
};
