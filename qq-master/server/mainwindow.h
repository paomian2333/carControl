#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // 服务器对象
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

private slots:
    void newConnection_slot();  // 建立新连接
    void readyRead_slot();  // 读取数据
    void on_openBt_clicked();
    void on_closeBt_clicked();
};
#endif // MAINWINDOW_H
