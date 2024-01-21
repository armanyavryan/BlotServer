#include "ConnectingPage.h"
#include "Components/Loading.h"

#include <QLabel>
#include <QGridLayout>
#include <QStyleOption>
#include <QPainter>

ConnectingPage::ConnectingPage(QWidget *parent)
    : QWidget{parent}
{
    createMembers();
    doLayout();
}

void ConnectingPage::setTect(const QString &text)
{
    m_loading->setLoadingText(text);
}

void ConnectingPage::setPercent(float val)
{
    m_loading->setProgress(val);
}

void ConnectingPage::paintEvent(QPaintEvent *e)
{
//    QWidget::paintEvent(e);
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);


    QRadialGradient radialGrad(this->rect().center(), this->height()/2);
    radialGrad.setColorAt(0, QColor(0,0,0, 120));
    radialGrad.setColorAt(0.5, QColor(0,0,0, 160));
    radialGrad.setColorAt(1, QColor(0,0,0, 180));
    p.fillRect(this->rect(), radialGrad);


}

void ConnectingPage::createMembers()
{
    setAutoFillBackground(true);
    m_loading = new Loading;
}

void ConnectingPage::doLayout()
{
    QGridLayout *grid = new QGridLayout;
    setLayout(grid);
    grid->addWidget(m_loading, 0, 0);

}
