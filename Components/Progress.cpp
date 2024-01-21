#include "Progress.h"

#include <QResizeEvent>
#include <QStyleOption>
#include <QLabel>
#include <QPainter>

Progress::Progress(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumWidth(200);
    this->setFixedHeight(25);
    this->setAutoFillBackground(true);

    m_lblProgress = new QLabel(this);
    m_lblProgress->setObjectName("ProgressFill");
}

void Progress::setProgress(float value)
{
    qDebug() << __FUNCTION__ << value;
    m_progress = value;
    auto size = this->size();
    int m = 5;
    auto w = std::max((size.width() - 2 * m) * m_progress, 10.0f);
    m_lblProgress->setGeometry(m, m, w, size.height() - m * 2);
}

void Progress::setLoadingText(const QString &text)
{
    m_lblProgress->setText(text);
}

void Progress::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

}

void Progress::resizeEvent(QResizeEvent *e)
{
    auto size = e->size();
    int m = 5;
    auto w = std::max((size.width() - 2 * m) * m_progress, 10.0f);
    m_lblProgress->setGeometry(m, m, w, size.height() - m * 2);
}
