#include "Loading.h"
#include "Components/Progress.h"

#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>
#include <QtSvgWidgets/QSvgWidget>

Loading::Loading(QWidget *parent)
    : QWidget{parent}
{
    createMembers();
}

void Loading::setLoadingText(const QString &text)
{
    m_lblText->setText(text);
}

void Loading::setProgress(float val)
{
    m_progress->setProgress(val);
}


void Loading::createMembers()
{
    QLabel *m_lblAngleLeft = new QLabel;
    QLabel *m_lblAngleRight = new QLabel;
    m_lblAngleLeft->setObjectName("RoyalBracket");
    m_lblAngleRight->setObjectName("RoyalBracket");
    QPixmap pixmap(":/Images/ROYAL-BRACKET");

    QPixmap angleLeft(600, 588);
    QPixmap angleRight(600, 588);
    angleLeft.fill(Qt::transparent);
    angleRight.fill(Qt::transparent);

    QPainter painter(&angleLeft);
    painter.translate(pixmap.width() / 2, pixmap.height() / 2);
    painter.rotate(-90);
    painter.translate(-pixmap.width() / 2, -pixmap.height() / 2);
    painter.drawImage(0, 0, pixmap.toImage());

    QPainter painter2(&angleRight);
    painter2.translate(pixmap.width() / 2, pixmap.height() / 2);
    painter2.rotate(90);
    painter2.translate(-pixmap.width() / 2, -pixmap.height() / 2);
    painter2.drawImage(0, 0, pixmap.toImage());

    m_lblAngleLeft->setPixmap(angleLeft.scaled(QSize(25, 25), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_lblAngleRight->setPixmap(angleRight.scaled(QSize(25, 25), Qt::KeepAspectRatio, Qt::SmoothTransformation));


    m_lblText  = new QLabel("Բեռնում");
    m_lblText->setAlignment(Qt::AlignHCenter);
    m_lblText->setObjectName("LoadingText");
    m_progress = new Progress;


//    m_svgBrand = new QSvgWidget;
    QPixmap brand(":/Images/BRAND");
    brand = brand.scaled(QSize(100, 100), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_brand = new QLabel;
    m_brand->setPixmap(brand);
    m_brand->setFixedSize(brand.size());
    QHBoxLayout * loadingLay = new QHBoxLayout;
    loadingLay->setAlignment(Qt::AlignHCenter);
    loadingLay->addWidget(m_lblAngleLeft);
    loadingLay->addWidget(m_progress);
    loadingLay->addWidget(m_lblAngleRight);


    QVBoxLayout * lay = new QVBoxLayout;
    lay ->setAlignment(Qt::AlignCenter);
    this->setLayout(lay);
    lay->addWidget(m_brand, 0, Qt::AlignHCenter);
    lay->addLayout(loadingLay);
    lay->addWidget(m_lblText);

}

void Loading::doLayout()
{
 }
