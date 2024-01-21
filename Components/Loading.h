#pragma once

#include <QWidget>

class QLabel;
class Progress;
class QSvgWidget;

class Loading : public QWidget
{
    Q_OBJECT
public:
    explicit Loading(QWidget *parent = nullptr);
    void setLoadingText(const QString& text);
    void setProgress(float val);

signals:

private:
    void createMembers();
    void doLayout();

private:
    QLabel      *m_lblText;
    Progress    *m_progress;
    QLabel      *m_brand;
};
