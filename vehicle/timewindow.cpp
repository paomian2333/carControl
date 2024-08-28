#include "timewindow.h"
#include "ui_timewindow.h"
#include<QTimer>
#include<QTimer>
#include<QDate>
#include<QDateTime>
#include <QTimeZone>
timewindow::timewindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::timewindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    QDate date=QDate::currentDate();
    ui->label_date->setText(date.toString("yy-MM-dd"));
    timer->stop();
    ui->label_pic->setFixedSize(33,33);
    ui->label_pic->setScaledContents(true);
    // 设置 centralWidget 的 objectName
    centralWidget()->setObjectName("centralWidgetBackground");

    // 然后使用 objectName 在样式表中指定背景图只应用于 centralWidget

    setStyleSheet("#centralWidgetBackground { background-image: url(:/image/images/timeback.png); }");
    connect(timer,&QTimer::timeout,this,&timewindow::do_show_time);
    timer->start();
}

timewindow::~timewindow()
{
    delete ui;
}

void timewindow::do_show_time()
{
    QDateTime curdatetime=QDateTime::currentDateTime();
    QTime curtime=curdatetime.toTimeZone(QTimeZone(local.toLocal8Bit().data())).time();
    ui->label_time->setText(curtime.toString("HH:mm"));
    if(curtime.hour()>=18||curtime.hour()<=6) ui->label_pic->setPixmap(QPixmap(":/image/images/moon.png"));
    else ui->label_pic->setPixmap(QPixmap(":/image/images/sun.png"));
    ui->widget->repaint();
}


void timewindow::on_pushButton_clicked()
{
    QMainWindow *parent=static_cast<QMainWindow *>(this->parent());
    this->hide();
    parent->show();
}


void timewindow::on_comboBox_currentIndexChanged(int index)
{
    QDateTime curdatetime=QDateTime::currentDateTime();
    local=zone.value(index);
    QTimeZone tz(local.toLocal8Bit().data());
    QDate curtime=curdatetime.toTimeZone(tz).date();
    ui->calendarWidget->setSelectedDate(curtime);
    ui->label_date->setText(curtime.toString("yy-MM-dd"));
    ui->widget->setLocal(this->local);
}

