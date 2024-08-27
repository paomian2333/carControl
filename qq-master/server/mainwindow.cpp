#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Server");

    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection_slot()));
}

void MainWindow::newConnection_slot(){  // 连接槽函数
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead_slot()));
}

void MainWindow::readyRead_slot(){  // 读取数据槽函数
    QString buf;
    buf=tcpSocket->readAll();
    ui->receiveEdit->appendPlainText(buf);  // 显示服务器收信
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openBt_clicked()
{
    tcpServer->listen(QHostAddress::Any, ui->portEdit->text().toUInt());
}


void MainWindow::on_closeBt_clicked()
{
    tcpServer->close();
}

