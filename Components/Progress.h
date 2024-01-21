#pragma once

#include <QWidget>

class QLabel;


class Progress : public QWidget
{
    Q_OBJECT
public:
    explicit Progress(QWidget *parent = nullptr);
    void setProgress(float value);
    void setLoadingText(const QString&);
protected:
    virtual void paintEvent(QPaintEvent* e) override;
    virtual void resizeEvent(QResizeEvent* e) override;

signals:

private:
    QLabel * m_lblProgress;

    float m_progress = 0.01f;
};
