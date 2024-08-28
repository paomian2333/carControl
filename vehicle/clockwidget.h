#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

#include <QWidget>

class clockwidget : public QWidget
{
    Q_OBJECT
public:
    explicit clockwidget(QWidget *parent = nullptr);

    void setLocal(const QString &newLocal);

signals:


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
private:
    QString local;
};


#endif // CLOCKWIDGET_H
