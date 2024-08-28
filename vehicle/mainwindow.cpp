#include "mainwindow.h"
#include "map.h"
#include "ui_mainwindow.h"
#include "timewindow.h"
#include "musicwindow.h"
#include "weatherReport.h"
#include "imageviewer.h"
#include "chatLogin.h"
#include<QMovie>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,447);
    ui->lcdNumber_hour->setStyleSheet("color: white;");
    ui->lcdNumber_minute->setStyleSheet("color: white;");
    ui->lcdNumber_secnd->setStyleSheet("color: white;");
    auto palette=ui->label->palette();
    palette.setColor(QPalette::Text,Qt::magenta);
    ui->label->setPalette(palette);
    backgroundMovie = new QMovie(":/gif/mainwindow_image/bkgfig.gif", QByteArray(), this);
    backgroundMovie->start();

    timer=new QTimer(this);
    timer->stop();
    connect(timer,&QTimer::timeout,this,&MainWindow::do_show_time);
    timer->start();
    time=new timewindow(this);
    music=new MusicWindow(this);
    // weather=new weatherwindow(this);
    mapWidget= new Map(this);
    weather = new weatherReport(this);
    chatLogin = new Login(this);
    imageViewer = new ImageViewer();


}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::do_show_time()
{

    QTime curtime=QTime::currentTime();
    ui->lcdNumber_hour->display(curtime.hour());
    ui->lcdNumber_minute->display(curtime.minute());
    ui->lcdNumber_secnd->display(curtime.second());
    this->repaint();
}





void MainWindow::on_pushButton_music_clicked()
{
    this->hide();
    music->show();
}


void MainWindow::on_pushButton_time_clicked()
{
    this->hide();
    time->show();
}
void MainWindow::on_pushButton_map_clicked()
{
    this->hide();       // 隐藏当前窗口
    mapWidget->show();  // 显示 map 窗口
}
void MainWindow::on_pushButton_clicked(){}

void MainWindow::on_pushButton_weather_clicked()
{
    this->hide();
    weather->show();
}
void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, backgroundMovie->currentPixmap());
    QMainWindow::paintEvent(event);
}

void MainWindow::on_pushButton_chatroom_clicked()
{
    this->hide();
    chatLogin->show();
}

void MainWindow::on_pushButton_image_clicked() {
    this->hide(); // 隐藏当前窗口
    imageViewer->show(); // 显示图片浏览窗口
}
