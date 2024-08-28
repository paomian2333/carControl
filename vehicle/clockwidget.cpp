#include "clockwidget.h"
#include<QPainter>
#include<QTime>
#include<QDebug>
#include<QTimeZone>
clockwidget::clockwidget(QWidget *parent)
    : QWidget{parent}
{

}
void clockwidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿

    // 获取当前时间
    QDateTime curdatetime=QDateTime::currentDateTime();
    QTime currentTime=curdatetime.toTimeZone(QTimeZone(local.toLocal8Bit().data())).time();
    int hour = currentTime.hour();
    int minute = currentTime.minute();
    int second = currentTime.second();

    // 绘制表盘
    int side = qMin(width(), height());
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawEllipse(-95, -95, 190, 190);

    // 绘制刻度
    painter.setPen(Qt::black);
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(75, 0, 90, 0);
        painter.rotate(6.0);
        for(int j=0;j<4;j++){
            painter.drawLine(85, 0, 90, 0);
            painter.rotate(6.0);
        }

    }

    // 绘制时针
    painter.save();

    painter.rotate(30.0 * (hour%12 + minute / 60.0)-90);
    painter.setPen(Qt::blue);
    painter.drawLine(0, 0, 40, 0); // 缩短时针长度，以更好地显示
    painter.restore();

    // 绘制分针
    painter.save();
    painter.rotate(6.0 * (minute + second / 60.0)-90);
    painter.setPen(Qt::black);
    painter.drawLine(0, 0, 60, 0); // 缩短分针长度，以更好地显示
    painter.restore();

    // 绘制秒针
    painter.save();
    painter.rotate(6.0 * second-90);
    painter.setPen(Qt::red);
    painter.drawLine(0, 0, 70, 0);
    painter.restore();
    QWidget::paintEvent(event);
}

void clockwidget::setLocal(const QString &newLocal)
{
    local = newLocal;
}
